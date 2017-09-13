//
// Observable.hh for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Wed Jun  1 19:24:39 2011 damien benloukil
// Last update Wed Jun 22 20:06:51 2011 damien benloukil
//

#ifndef OBSERVABLE__
#define OBSERVABLE__

#include <string>
#include <list>
#include "IObserver.hh"

class Observable
{
private:
  std::list<IObserver*> obsList;

public:
  void notify(std::string const &);	//gui
  void addObserver(IObserver *obs);
};

#endif
