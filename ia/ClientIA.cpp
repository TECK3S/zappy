//
// newClientIA.cpp for zappy/ia in /home/louis-_c//svn/zappy_delamort/ia
// 
// Made by anthony louis-regis
// Login   <louis-_c@epitech.net>
// S
// Started on  Mon Jun 13 20:42:09 2011 anthony louis-regis
// Last update Sun Jul 10 20:35:08 2011 anthony louis-regis
//

#include	<string>
#include	<cstring>
#include	<iostream>
#include	"ClientIA.hh"


// preparation de Lunar
const char ClientIA::className[] = "ClientIA";
// Lunar<ClientIA>::RegType ClientIA::methods[] =
//   {
//     method(ClientIA, startLua),
//     method(ClientIA, setCommand),
//     method(ClientIA, sendCommand),
//     //    method(ClientIA, analyseResponse),
//     {0,0}
//   };

// Constructors
ClientIA::ClientIA()
  : _started(false)
{
  std::cout << "**** constructor 1" << std::endl;
  this->_command.opcode = 0;
  this->_command.msg = NULL;
  this->_response.opcode = 0;
  this->_response.data = "";// char* -> NULL

  std::cout << "**** out constructor" << std::endl;
}

ClientIA::ClientIA(const std::string &name)
  : _teamName(name), _started(false)
{
  std::cout << "**** constructor 2" << std::endl;
  this->_command.opcode = 0;
  this->_command.msg = NULL;
  this->_response.opcode = 0;
  this->_response.data = "";// char* -> NULL

  std::cout << "**** out constructor" << std::endl;
}


ClientIA::ClientIA(lua_State * L)
 : _started(false)
{
  std::cout << "**** constructor 3" << std::endl;
  this->_response.opcode = 0;
  this->_response.data = ""; // char* -> NULL
  this->_state = L;
  std::cout << "**** out constructor" << std::endl;
}


// Destructor
ClientIA::~ClientIA()
{
  if (this->_started == true)
    lua_close(this->_state);
  std::cout << "end" << std::endl;
}


// Getters setters
void		ClientIA::setTeamName(const std::string &name)
{
  this->_teamName = name;
}

void		ClientIA::setSingleton(SingletonIa *sing)
{
  this->_sIa = sing;
}

void		ClientIA::setCommand(int op, const char *cmd)
{
  this->_command.opcode = op;
  this->_command.msg = new char[strlen(cmd)];
  strcpy(this->_command.msg, cmd);
}

int		ClientIA::setCommand(lua_State * L)
{
  std::cout << "**** cpp setCommand" << std::endl;

  int nbArgs = lua_gettop(L);

  if (nbArgs == 2 && lua_isnumber(L,1) &&
      lua_isstring(L,2))
    {
      this->_command.opcode = lua_tonumber(L,1);
      this->_command.msg = (char *)lua_tostring(L,2);
      std::cout << "**** command.opcode = " << this->_command.opcode << " command.msg = " << this->_command.msg << std::endl;
    }
  else
    {
      this->_command.opcode = 0;
      this->_command.msg = NULL;
      std::cerr << "setCommand : mauvais parametres" << std::endl;
    }
  std::cout << "**** out of sendCommand" << std::endl;
  return 0;
}


// Functions
void		ClientIA::start()
{
  std::cout << "start" << std::endl;

  // lua state initialized
  this->_state = lua_open();
  luaL_openlibs(this->_state);

  Lunar<ClientIA>::Register(this->_state);
  this->_started = true;
  /*
  lua_settop(this->_state,0);
  Lunar<ClientIA>::push(this->_state, this);
  */
  //  lua_setglobal(this->_state, "CLientIA");///

  //luaL_loadfile(this->_state, "ia.lua");
  if (luaL_dofile(this->_state, "ia.lua") != 0) //ia.lua
    {
      // il y a eut une erreur dans le script
      fprintf(stderr,"%s\n",lua_tostring(this->_state,-1));
      exit(0);
    }
  this->startLua(this->_state);
  std::cout << "out of start" << std::endl;
}

int		ClientIA::startLua(lua_State * L)
{
  std::cout << "startLua" << std::endl;
  lua_settop(L,0);
  Lunar<ClientIA>::push(L, this);
  lua_pushstring(this->_state, this->_teamName.c_str());
  Lunar<ClientIA>::call(L,"start",1,0);
  std::cout << "out of startLua" << std::endl;
  return (0);
}

void		ClientIA::sendCommand()
{
  std::cout << "**** sendCommand\nargs:" << this->_command.opcode << " " << this->_command.msg << std::endl; ///
  if (this->_command.opcode != 0 && this->_command.msg != NULL)
    this->notify(this->_command);
  std::cout << "***** out of sendCommand" << std::endl;
  return;
}

void		ClientIA::sendCommand(int op, char *cmd)
{
  std::cout << "**** sendCommand\nargs:" << op << " " << cmd << std::endl;///
  if (cmd != NULL)
    {
      this->_command.opcode = op;
      this->_command.msg = new char[strlen(cmd)];
      strcpy(this->_command.msg, cmd);
      this->notify(this->_command);
    }
  std::cout << "***** out sendCommand" << std::endl;
  return;
}

int		ClientIA::sendCommand(lua_State * L)
{
  std::cout << "**** cpp sendCommand" << std::endl;
  int nbArgs = lua_gettop(L);

  if (nbArgs == 0)
    if (this->_command.opcode != 0 && this->_command.msg != NULL)
      this->notify(this->_command);
  std::cout << "**** out of sendCommand" << std::endl;
  return 0;
}

void		ClientIA::catchResponse()
{
  std::cout << "**** catchResponse" << std::endl;
  this->_response = this->_sIa->getResponse();
  if (!this->_response.data.empty()) //!= NULL
    {
      lua_settop(this->_state,0);
      Lunar<ClientIA>::push(this->_state, this);
      lua_pushnumber(this->_state, this->_response.opcode);
      lua_pushstring(this->_state, this->_response.data.c_str());//char *
      Lunar<ClientIA>::call(this->_state,"setResponse", 2, 0);

      lua_settop(this->_state,0);
      Lunar<ClientIA>::push(this->_state, this);
      Lunar<ClientIA>::call(this->_state,"analyseResponse", 0, 0);
    }
  //  this->analyseResponse(this->_state);
  std::cout << "**** out of catchResponse" << std::endl;
}

// int           analyseResponse(lua_State * L)
// {

// }


// end of class ClientIA
