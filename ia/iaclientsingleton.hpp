//
// ioaclientsingleton.hpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Mon Jun 13 17:32:38 2011 damien benloukil
// Last update Mon Jun 20 21:40:49 2011 anthony louis-regis
//

#ifndef			IACLIENT__
#define			IACLIENT__

#include		<cstdlib>

struct			SendResponse
{
  int			opcode;
  char			*data;
};


class			SingletonIa
{
private:
  SendResponse		resp;
  static SingletonIa	*singletia;

public:
  SingletonIa()
  {
    this->resp.opcode = 0;
    this->resp.data = NULL;
  }

  ~SingletonIa()
  {}

  static SingletonIa	*getInstance();
  void			setResponse(SendResponse const &);
  SendResponse &	getResponse();
};

#endif
