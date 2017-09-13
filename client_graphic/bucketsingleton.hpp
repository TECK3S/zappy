//
// bucketsingleton.hpp<2> for  in /home/benlou_d//proj/zappy/zappy_delamort/client_graphic
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Wed Jun 15 19:05:49 2011 damien benloukil
//

#ifndef BUCKET__
#define BUCKET__

#include <string>
#include <list>
#include <queue>

struct BeginGame
{
  int width;
  int height;
  int time;
  std::list<std::string> teamName;
};

struct CaseContent
{
  int x;
  int y;
  std::list<int> object;
};

struct Click
{
  int level;
  int nb_player;
  std::list<int> inventory;
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

namespace request
{
  const char * const graphic = "graphic\n";
  const char * const msz = "msz\n";
  const char * const tna = "tna\n";
  const char * const sgt = "sgt\n";
}

class SingletonBucket
{
private:

  Click *click;
  BeginGame *beginGame;  
  std::string opcode;
  const char * send;
  bool sendingState;
  std::list<CaseContent> caseContentList;
  static SingletonBucket *singlet;

  SingletonBucket() : click(NULL), beginGame(NULL), opcode(""), send(NULL), sendingState(false)
  {}
  ~SingletonBucket()
  {}

public:
  static SingletonBucket *getInstance();
  
  void setClick(Click *);
  void setCaseContent(std::list<CaseContent> const &);
  void setBeginGame(BeginGame *);
  void setOpcode(std::string const & op);
  void setVal();

  Click * getClick();
  std::list<CaseContent> & getCaseContent();
  BeginGame * getBeginGame();
  std::string & getOpcode();
  void setSend(const char * const data);
  const char * getSend() const;    
  bool getSendingState() const;
  void setSendingState(bool boule);
};

#endif
