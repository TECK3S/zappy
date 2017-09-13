//
// bucketsingleton.hpp for  in /home/souman_a//Desktop/my_project/zappy_delamort/client
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Thu Jun  2 16:24:36 2011 damien benloukil
//
//

#ifndef BUCKET__
#define BUCKET__

#include <string>
#include <list>
#include <queue>

struct op
{
  int opcode;
  const  char * data;
};

struct vis
{
  std::string ob;
  int cas;
};

class SingletonBucket
{
private:
  std::string address;
  int	      port;
  std::string status;
  op  interpretation;

  static SingletonBucket *singlet;
  char *send;

  SingletonBucket() : address(""), port(0), status(""), send(NULL)
  {}
  ~SingletonBucket()
  {}

public:
  void setAddress(std::string const & addr);
  void setPort(int p);
  void setStatus(std::string const & status);
  std::string &getAddress();
  int &getPort();
  std::string const &getstatus() const;
  static SingletonBucket *getInstance();
  /** receive serveur to client **/
  void setInterpretation(op &data);
  op & getInterpretation();

  /** send client to server **/
  void setSend(char * data);
  char *getSend();  
};

#endif
