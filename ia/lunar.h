
/*  gnu/BankiZ :: common
 *	Copyright (C) 2002-2004 The contributors of the Bankiz project
 *	WebSite : http://www.bankiz.org/
 *
 *  This file is part of BANKIZ.
 *	BANKIZ is free software; you can redistribute it and/or modify 
 *	it under the terms of the GNU General Public Licenseas published 
 *	by the Free Software Foundation; either version 2 of the License, 
 *	or (at your option) any later version.
 *
 *	BANKIZ is distributed in the hope that it will be useful,	but
 *	WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	GNU
 *	General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with BANKIZ; see the file COPYING. If not, write to the 
 *	Free Software	Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 *	MA  02111-1307, USA.
 */



#ifndef BK_COMMON_LUNAR_
#define BK_COMMON_LUNAR_

/**
 * For info, see: http://lua-users.org/wiki/CppBindingWithLunar
 */


#define LUA_BIND_METHOD(class, name) {#name, &class::name}


extern "C" {

#   include "lua.h"
#   include "lauxlib.h"

}

template <typename T> class Lunar {

    typedef struct { T *pT; } userdataType;

 public:

    typedef int (T::*mfp)(lua_State *L);
    typedef struct { const char *name; mfp mfunc; } RegType;

    // Bind a new C++ class to LUA.
    static void Register(lua_State *L) {

        lua_newtable(L);
        int methods = lua_gettop(L);

        luaL_newmetatable(L, T::className);
        int metatable = lua_gettop(L);

        // Store method table in globals so that
        // scripts can add functions written in Lua.
        lua_pushvalue(L, methods);
        set(L, LUA_GLOBALSINDEX, T::className);

        // Hide metatable from Lua getmetatable().
        lua_pushvalue(L, methods);
        set(L, metatable, "__metatable");

        lua_pushvalue(L, methods);
        set(L, metatable, "__index");

        lua_pushcfunction(L, tostring_T);
        set(L, metatable, "__tostring");

        lua_pushcfunction(L, gc_T);
        set(L, metatable, "__gc");

        lua_newtable(L);                        // mt for method table
        lua_pushcfunction(L, new_T);
        lua_pushvalue(L, -1);                   // dup new_T function
        set(L, methods, "new");                 // add new_T to method table
        set(L, -3, "__call");                   // mt.__call = new_T
        lua_setmetatable(L, methods);

        // Fill method table with methods from class T.
        for (RegType *l = T::methods; l->name; l++) {
            lua_pushstring(L, l->name);
            lua_pushlightuserdata(L, (void *)l);
            lua_pushcclosure(L, thunk, 1);
            lua_settable(L, methods);
        }

        lua_pop(L, 2);  // Drop metatable and method table.

    }

    // Call named lua method from userdata method table.
    static int call(lua_State *L, const char *method, int nargs=0, int nresults=LUA_MULTRET, int errfunc=0) {

        int base = lua_gettop(L) - nargs;       // userdata index

        // If wrong, drop userdata and args
        if (!luaL_checkudata(L, base, T::className)) {
            lua_settop(L, base - 1);
            lua_pushfstring(L, "not a valid %s userdata", T::className);
            return -1;
        }

        // Try to get method from userdata, and put method under userdata, args
        lua_pushstring(L, method);
        lua_gettable(L, base);
        if (lua_isnil(L, -1)) {
            lua_settop(L, base - 1);
            lua_pushfstring(L, "%s missing method '%s'", T::className, method);
            return -1;
        }
        lua_insert(L, base);

        // Final call
        int status = lua_pcall(L, 1 + nargs, nresults, errfunc);
        if (status) {
            const char *msg = lua_tostring(L, -1);
            if (msg == NULL) msg = "(error with no message)";
            lua_pushfstring(L, "%s:%s status = %d\n%s", T::className, method, status, msg);
            lua_remove(L, base);                // Remove old message
            return -1;
        }

        // Return the number of results
        return lua_gettop(L) - base + 1;

    }

    // Push onto the Lua stack a userdata containing a pointer to T object.
    static int push(lua_State *L, T *obj, bool gc=false) {

        if (!obj) {
            lua_pushnil(L);
            return 0;
        }

        // Lookup metatable in Lua registry
        luaL_getmetatable(L, T::className);
        if (lua_isnil(L, -1)) luaL_error(L, "%s missing metatable", T::className);


        int mt = lua_gettop(L);
        subtable(L, mt, "userdata", "v");

        userdataType *ud =
            static_cast<userdataType*>(pushuserdata(L, obj, sizeof(userdataType)));


        if (ud) {
            ud->pT = obj;                       // Store pointer to object in userdata
            lua_pushvalue(L, mt);
            lua_setmetatable(L, -2);
            if (gc == false) {
                lua_checkstack(L, 3);
                subtable(L, mt, "do not trash", "k");
                lua_pushvalue(L, -2);
                lua_pushboolean(L, 1);
                lua_settable(L, -3);
                lua_pop(L, 1);
            }
        }

        lua_replace(L, mt);
        lua_settop(L, mt);

        // Return the index of userdata containing pointer to T object
        return mt;

    }

    // Get userdata from Lua stack and return pointer to T object.
    static T *check(lua_State *L, int narg) {

        userdataType *ud = static_cast<userdataType *>(luaL_checkudata(L, narg, T::className));

        if (!ud) {
            luaL_typerror(L, narg, T::className);
            return NULL;
        }

        return ud->pT;

    }

 private:

    // Hidden default constructor.
    Lunar();

    // Member function dispatcher.
    static int thunk(lua_State *L) {

        // Stack has userdata, followed by method args
        T *obj = check(L, 1);                   // Get 'self' / 'this'
        lua_remove(L, 1);                       // Remove self so member function args start at index 1

        // Get member function from upvalue.
        RegType *l = static_cast<RegType *>(lua_touserdata(L, lua_upvalueindex(1)));

        // Return the result from the call member function.
        return (obj->*(l->mfunc))(L);

    }

    // Create a new T object and  push onto the Lua stack a userdata containing a pointer to T object.
    static int new_T(lua_State *L) {

        lua_remove(L, 1);                       // Use classname:new(), instead of classname.new()
        T *obj = new T(L);                      // Call constructor for T objects
        push(L, obj, true);                     // gc_T will delete this object

        return 1;                               // Userdata containing pointer to T object

    }

    // Garbage collection metamethod.
    static int gc_T(lua_State *L) {

        if (luaL_getmetafield(L, 1, "do not trash")) {
            lua_pushvalue(L, 1);                // Dup userdata
            lua_gettable(L, -2);
            if (!lua_isnil(L, -1)) return 0;    // Do not delete object
        }

        userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
        T *obj = ud->pT;

        if (obj) delete obj;                    // Call destructor for T objects

        return 0;

    }

    // Create a descriptor for class instance.
    static int tostring_T (lua_State *L) {

        char buff[65];

        userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
        T *obj = ud->pT;

        sprintf(buff, "%p", obj);
        lua_pushfstring(L, "%s (%s)", T::className, buff);

        return 1;

    }

    // Set a value in the metatable.
    static void set(lua_State *L, int table_index, const char *key) {

        lua_pushstring(L, key);
        lua_insert(L, -2);                      // Swap value and key
        lua_settable(L, table_index);

    }

    // ...
    static void weaktable(lua_State *L, const char *mode) {

        lua_newtable(L);
        lua_pushvalue(L, -1);                   // table is its own metatable
        lua_setmetatable(L, -2);
        lua_pushliteral(L, "__mode");
        lua_pushstring(L, mode);
        lua_settable(L, -3);                    // metatable.__mode = mode

    }

    // ...
    static void subtable(lua_State *L, int tindex, const char *name, const char *mode) {

        lua_pushstring(L, name);
        lua_gettable(L, tindex);

        if (lua_isnil(L, -1)) {
            lua_pop(L, 1);
            lua_checkstack(L, 3);
            weaktable(L, mode);
            lua_pushstring(L, name);
            lua_pushvalue(L, -2);
            lua_settable(L, tindex);
        }

    }

    // Push a user data onto LUA stack.
    static void *pushuserdata(lua_State *L, void *key, size_t sz) {

        void *ud = 0;
        lua_pushlightuserdata(L, key);
        lua_gettable(L, -2);                    // Lookup[key]

        if (lua_isnil(L, -1)) {
            lua_pop(L, 1);                      // Drop nil
            lua_checkstack(L, 3);
            ud = lua_newuserdata(L, sz);        // Create new userdata
            lua_pushlightuserdata(L, key);
            lua_pushvalue(L, -2);               // Dup userdata
            lua_settable(L, -4);                // Lookup[key] = userdata
        }

        return ud;

    }

};



#endif  /* BK_COMMON_LUNAR_ */


