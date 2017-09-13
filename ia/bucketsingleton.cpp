//
// bucketsingleton.cpp for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Thu Jun  2 17:22:04 2011 damien benloukil
// Last update Tue Jul  5 20:12:07 2011 eugene-valentin ngontang-tchiadjie
//

#include "bucketsingleton.hpp"


void  SingletonBucket::setAddress(std::string const & addr)
{
  this->address = addr;
}

void SingletonBucket::setPort(int p)
{
  this->port = p;
}

void SingletonBucket::setStatus(std::string const & status)
{
  this->address = status;
}

std::string & SingletonBucket::getAddress()
{
  return this->address;
}

int& SingletonBucket::getPort()
{
  return this->port;
}

std::string const & SingletonBucket::getstatus() const
{
  return this->status;
}

SingletonBucket * SingletonBucket::getInstance ()
{
  if (NULL == singlet)
    singlet =  new SingletonBucket;
  return singlet;
}

void SingletonBucket::setInterpretation(op & data)
{
  this->interpretation = data;
}

op & SingletonBucket::getInterpretation()
{
  return (this->interpretation);
}

void SingletonBucket::setSend(char * data)
{
  this->send = data;
}

char *SingletonBucket::getSend()
{
  return (this->send);
}

SingletonBucket *SingletonBucket::singlet = NULL;
