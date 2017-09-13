//
// Observer.hh for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Wed Jun  1 19:19:02 2011 damien benloukil
// Last update Tue Jun 21 20:31:20 2011 damien benloukil
//

#ifndef OBSERVER__
#define OBSERVER__

#include <string>

class IObserver
{
public:
  virtual void update(std::string const & data) = 0;
};

#endif
