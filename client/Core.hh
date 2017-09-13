//
// Core.hh for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Thu Jun  2 12:12:53 2011 damien benloukil
//
//


#ifndef CORE__
#define CORE__

#include  <vector>
#include  <queue>
#include  <list>
#include  <map>
#include  <string>
#include  <iostream>
#include  <sstream>
#include  <QString>
#include  "IObserver.hh"
#include  "Observable.hh"
#include  "IARessources.hh"
#include  "bucketsingleton.hpp"
#include  "iaclientsingleton.hpp"
#include  "TcpSocket.hh"


class Core : public IObserver
{
private:
  std::vector<std::string> keyWord;
  std::vector<std::string> objs;
  std::queue<std::string> queueToParse;
  std::list<vis> listToParse;
  std::map<std::string, std::string> obje;
  std::list<int> code;
  std::queue<int> opCode;
  std::string dropobj;
  std::string takeobj;
  SingletonBucket *s;
  SingletonIa *sIa;
  op *o;
  SendResponse *sd;
  bool sndIa;
  std::string teamName;
  IARessources  * ia;
   std::map<std::string, int> _cmdQueue;
  TCP::Socket	sock;
  int		_opcode;

public:
  Core(std::string const &);
  virtual ~Core();
  void update(std::string const &);
  void updateIa(std::string const &);
  void update(Command const &);
  void lexing(std::string const &, int);
  void checkobjs();
  void parser(int);
  void distrib(QString, int);
  void ex(lua_State * L);
  
  /* receive ptr sur fct membre */
  void vision(std::string const &);
  void objet(std::string const &);
  void ok(std::string const &);
  void ko(std::string const &);
  void slot(std::string const &);
  void message(std::string const &);
  void elevation(std::string const &);
  void deplacement(std::string const &);
  void mort(std::string const &);
  void bienvenue(std::string const &);
  void gagner(std::string const &);
  void equipe(std::string const &);
};

namespace Token
{
  const char virg = ',';
  const char louisTiret = '-';
  const char openAc = '{';
  const char closeAc = '}';
  const char space = ' ';
}

namespace opcode
{
  const int avance = 0x01;
  const int droite = 0x02;
  const int gauche = 0x03;
  const int voir = 0x04;
  const int inventaire = 0x05;
  const int prend = 0x06;
  const int pose = 0x07;
  const int expulse = 0x08;
  const int broadcast = 0x09;
  const int incantation = 0x0A;
  const int fork = 0x0B;
  const int connect_nbr = 0x0C;
  const int mort = 0x0D;
  const int bienvenue = 0x0E;
  const int equipe = 0x0F;
  const int gagner = 0x10;
};

namespace objects
{
  const std::string nourriture = "nourriture";
  const std::string linemate = "linemate";
  const std::string deraumere = "deraumere";
  const std::string sibur = "sibur";
  const std::string mendiane = "mendiane";
  const std::string phiras = "phiras";
  const std::string thystame = "thystame";
  const std::string joueur = "joueur";
  const std::string oeuf = "oeuf";
}

namespace KeyWords
{
  const std::string ok = "ok";
  const std::string ko = "ko";
  const std::string vision = "vision";
  const std::string objet = "objets";
  const std::string deplacement = "deplacement";
  const std::string message = "message";
  const std::string elevation = "elevation";
  const std::string slot = "slot";
  const std::string gagner = "gagner";
  const std::string mort = "mort";
  const std::string bienvenue = "bienvenue";
}

#endif
