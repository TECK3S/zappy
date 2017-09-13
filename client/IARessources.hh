//
// Ressources.hh for Ressources.hh in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/ia_new
// 
// Made by eugene-valentin ngontang-tchiadjie
// Login   <ngonta_e@epitech.net>
// 
// Started on  Wed Jun 29 13:41:12 2011 eugene-valentin ngontang-tchiadjie
// Last update Sat Jul  9 17:29:05 2011 eugene-valentin ngontang-tchiadjie
//

#ifndef IARESSOURCES_HH__
# define IARESSOURCES_HH__

extern "C"
{
#include <lua.h>
}

#include <lua.hpp>
#include <luabind.hpp>
#include <string>

#include "iaclientsingleton.hpp"
#include "Observable.hh"

class IARessources : public Observable
{
public:
  IARessources(std::string const & name);
  IARessources(IARessources const &);
  virtual ~IARessources();
  void setTeamName(std::string const name);
  void checkMsg();
  void doNotify(std::string const & msg);

  std::string const  getTeamName() const;
  int  getOpcode() const;
  std::string const  getMsg() const;

public:
  virtual void checkRessources() = 0;
  virtual void start() = 0;
    
private:
  std::string _teamName;
  int _opcode;
  std::string _msg;
  SingletonIa * _sing;
};

class IARessourcesWrapper : public IARessources, public luabind::wrap_base
{
public:
  IARessourcesWrapper(std::string const & name)
    : IARessources(name) 
  { 
  }

  virtual void checkRessources() 
  { 
    call<void>("checkRessources"); 
  }
  
  virtual void start()
  {
    call<void>("start");
  }
};

#endif // !IARESSOURCES_HH__
