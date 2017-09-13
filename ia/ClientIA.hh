//
// newClientIA.hh for zappy/ia in /home/louis-_c//svn/zappy_delamort/ia
// 
// Made by anthony louis-regis
// Login   <louis-_c@epitech.net>
// 
// Started on  Mon Jun 13 20:37:38 2011 anthony louis-regis
// Last update Sun Jul 10 19:54:59 2011 anthony louis-regis
//

#ifndef		CLIENT_IA_HH
#define		CLIENT_IA_HH

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include	<vector>
#include	"lua/lua.hpp"
#include	"lua/lunar.h"

//#include	"lunar.h"

#include	"IObserver.hh"
#include	"Observable.hh"
#include	"iaclientsingleton.hpp"

#define method(class, name) {#name, &class::name}

class		ClientIA : public Observable
{
private:
  std::string	_teamName;
  Command	_command;
  SendResponse	_response;
  SingletonIa	*_sIa;
  lua_State	*_state;
  bool		_started;

  //Lunar
  friend class	Lunar<ClientIA>;
  static const	char className[];
  static Lunar<ClientIA>::RegType methods[];

public:
  //Constructor
  ClientIA();
  ClientIA(const std::string &);
  ClientIA(lua_State * L);

  //Destructor
  ~ClientIA();

  //setter
  void		setTeamName(const std::string &);
  void		setSingleton(SingletonIa *sing);
  void		setCommand(int, const char *);
  int		setCommand(lua_State * L);

  //Functions
  void		start();
  int		startLua(lua_State * L);//Lua
  void		sendCommand();
  void		sendCommand(int, char*);
  int		sendCommand(lua_State * L);
  void		catchResponse();
  //  int		analyseResponse(lua_State * L);//Lua
  //  int 		analyseCurrentState(lua_State * L);//lua
  //  void		doCurrentState();//
};
// end of class ClientIA

#endif
