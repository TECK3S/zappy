//
// main.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 14:12:25 2011 abd-el-moxine soumanou
// Last update Sun Jul 10 20:19:59 2011 anthony louis-regis
//

#include	"Core.hh"
#include	"Gui.hh"
#include	"IObserver.hh"
#include	"Observable.hh"
//#include	"ClientIA.hh"

// static void	loadIAModule(lua_State *L)
// {
//   luabind::module(L)
//     [
//      luabind::class_<IARessources, IARessourcesWrapper>("IARessources")
//      .def(luabind::constructor<const std::string&>())
//      .def("doNotify", &IARessources::doNotify)
//      .def("checkMsg", &IARessources::checkMsg)
//      .property("_teamName", &IARessources::getTeamName)
//      .property("_opcode", &IARessources::getOpcode)
//      .property("_msg", &IARessources::getMsg)
//      ];
// }

int		main(int argc, char **argv)
{
  if (argc == 2)
    {
      QApplication  app(argc, argv);
      Core core(argv[1]);
      //      lua_State * L;

      core.ex();
      // if ((L = lua_open()) != NULL)
      // 	{
      // 	  luabind::open(L);
      // 	  luaL_openlibs(L);
      // 	  loadIAModule(L);
      // 	  if (luaL_dofile(L, "scriptIA.lua") != 0)
      // 	    std::cout << lua_tostring(L, -1) << std::endl;
      // 	  core.ex(L);
      // 	  lua_close(L);
      // 	}
    }
  else
    std::cout << "USAGE: ./client 'teamname'" << std::endl;
  return (0);
}
