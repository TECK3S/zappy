//
// IARessources.cpp<2> for IARessources.cpp in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/ia_new
// 
// Made by eugene-valentin ngontang-tchiadjie
// Login   <ngonta_e@epitech.net>
// 
// Started on  Mon Jul  4 21:23:15 2011 eugene-valentin ngontang-tchiadjie
// Last update Sat Jul  9 17:26:06 2011 eugene-valentin ngontang-tchiadjie
//

#include <iostream>
#include <sstream>
#include "IARessources.hh"

IARessources::IARessources(std::string const & name)
  :_teamName(name),
   _opcode(0),
   _msg(""),
   _sing(SingletonIa::getInstance())
{
  std::cout << "New IA have been created with name " << this->_teamName << std::endl;
}

IARessources::~IARessources()
{
}

void IARessources::setTeamName(std::string const name)
{
  this->_teamName = name;
}

void IARessources::checkMsg()
{
  SendResponse & msg = this->_sing->getResponse();
  
  this->_opcode = msg.opcode;
  this->_msg = msg.data;
}

void IARessources::doNotify(std::string const & msg)
{
  this->notify(msg);
}

std::string const  IARessources::getTeamName() const
{
  return (this->_teamName);
}

int  IARessources::getOpcode() const
{
  return (this->_opcode);
}

std::string const  IARessources::getMsg() const
{
  return (this->_teamName);
}
