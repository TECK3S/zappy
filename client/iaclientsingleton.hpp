//
// ioaclientsingleton.hpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Mon Jun 13 17:32:38 2011 damien benloukil
// Last update Sat Jul  9 19:18:24 2011 eugene-valentin ngontang-tchiadjie
//

#ifndef IACLIENT__
#define IACLIENT__

#include <cstdlib>
#include <vector>


struct SendResponse
{
  int	 opcode;
  std::string data;
};

class SingletonIa
{
private:
  SendResponse resp;
  static SingletonIa *singletia;

  SingletonIa()
  {
    this->resp.opcode = 0;
    this->resp.data = "";
  }

  ~SingletonIa()
  {}

public:
  static SingletonIa *getInstance();  
  void setResponse(SendResponse const &);
  SendResponse & getResponse();

};

#endif
