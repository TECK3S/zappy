//
// bucketsingleton.cpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client_graphic
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Wed Jun 15 20:07:20 2011 damien benloukil
//

#include <iostream>
#include "bucketsingleton.hpp"

SingletonBucket * SingletonBucket::getInstance ()
{
  if (NULL == singlet)
    singlet =  new SingletonBucket;
  return singlet;
}

void SingletonBucket::setVal()
{
  this->click = new Click;
  this->beginGame = new BeginGame;

  this->click->level = 0;
  this->click->nb_player = 0;
  this->beginGame->width = 0;
  this->beginGame->height = 0;
  this->beginGame->time = 0;
}

void SingletonBucket::setClick(Click *c)
{
  this->click = c;
}

void SingletonBucket::setCaseContent(std::list<CaseContent> const & c)
{
  this->caseContentList = c;
}

void SingletonBucket::setBeginGame(BeginGame *b)
{
  this->beginGame = b;
}

void SingletonBucket::setOpcode(std::string const & op)
{
  this->opcode = op;
}

Click * SingletonBucket::getClick()
{
  return (this->click);
}

std::list<CaseContent> & SingletonBucket::getCaseContent()
{
  return (this->caseContentList);
}


BeginGame * SingletonBucket::getBeginGame()
{
  return (this->beginGame);
}

std::string & SingletonBucket::getOpcode()
{
  return (this->opcode);
}

void SingletonBucket::setSend(const char * const  data)
{
  this->send = data;
}

const char *SingletonBucket::getSend() const 
{
  return (this->send);
}

bool SingletonBucket::getSendingState() const
{
  return (this->sendingState);
}

void SingletonBucket::setSendingState(bool boule)
{
  this->sendingState = boule;
}

SingletonBucket *SingletonBucket::singlet = NULL;
