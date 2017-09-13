//
// Observable.cpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Wed Jun  1 19:54:05 2011 damien benloukil
//

#include <iostream>
#include "Observable.hh"

void Observable::notify(std::string const &data, bool tcp)
{
  for (std::list<IObserver*>::const_iterator it = obsList.begin();
       it != obsList.end(); ++it)
    {
      if (tcp == true)
	(*it)->update(data.substr(0, data.size() - 1));
      else
	(*it)->updateIa(data);
    }
}

void Observable::notify(Command const &cmd)
{
  for (std::list<IObserver*>::const_iterator it = obsList.begin();
       it != obsList.end(); ++it)
    (*it)->update(cmd);
}

void Observable::addObserver(IObserver *obs)
{
  this->obsList.push_back(obs);
}
