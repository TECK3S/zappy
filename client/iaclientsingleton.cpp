//
// ioaclientsingleton.cpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Mon Jun 13 17:41:01 2011 damien benloukil
// Last update Tue Jul  5 19:15:34 2011 damien benloukil
//

#include <iostream>
#include "iaclientsingleton.hpp"

void SingletonIa::setResponse(SendResponse const & data)
{
  this->resp = data;
}

SendResponse & SingletonIa::getResponse()
{
  return (this->resp);
}

SingletonIa * SingletonIa::getInstance ()
{
  if (NULL == singletia)
    singletia =  new SingletonIa;
  return singletia;
}


SingletonIa *SingletonIa::singletia = NULL;

