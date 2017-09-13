//
// Core.hh for  in /home/benlou_d//proj/zappy/zappy_delamort/client_graphic
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Tue Jun 14 20:19:11 2011 damien benloukil
// Last update Thu Jun 23 17:48:40 2011 damien benloukil
//

#ifndef CORE__
#define CORE__

#include <QString>
#include <sstream>
#include <list>
#include <iostream>
#include "TcpSocket.hh"
#include "Gui.hh"
#include "Widget.hh"
#include "IObserver.hh"
#include "bucketsingleton.hpp"

class Core : public IObserver
{
private:
  TCP::Socket *sock;
  std::vector<std::string> cmd;
  std::list<CaseContent> caseList;
  QString ip;
  quint16 port;
  bool connected;
  Gui    *gui;
  SingletonBucket * s;
  bool waitingClick;
  Click *click;
  BeginGame *b;
  Core & operator=(Core const &);
  Core(Core const &);

public:

  Core(QString const &, quint16);
  void update(std::string const &);
  void sndCmd(std::string const &);
  void ex();
  void settings();
  void wList(std::string const &);
  ~Core();

  /* ptr sur fct membre*/
  void msz(std::string const & );
  void bct(std::string const & );
  void tna(std::string const & );
  void pnw(std::string const & );
  void ppo(std::string const & );
  void plv(std::string const & );
  void pin(std::string const & );
  void pex(std::string const & );
  void pbc(std::string const & );
  void pic(std::string const & );
  void pie(std::string const & );
  void pfk(std::string const & );
  void pdr(std::string const & );
  void pgt(std::string const & );
  void pdi(std::string const & );
  void enw(std::string const & );
  void eht(std::string const & );
  void ebo(std::string const & );
  void edi(std::string const & );
  void sgt(std::string const & );
  void seg(std::string const & );
  void smg(std::string const & );
  void suc(std::string const & );
  void sbp(std::string const & );
  void okc(std::string const & );
  void koc(std::string const & );
  void clk(std::string const & );
};

namespace cmd
{
  const std::string msz = "msz";
  const std::string bct = "bct";
  const std::string tna = "tna";
  const std::string pnw = "pnw";
  const std::string ppo = "ppo";
  const std::string plv = "plv";
  const std::string pin = "pin";
  const std::string pex = "pex";
  const std::string pbc = "pbc";
  const std::string pic = "pic";
  const std::string pie = "pie";
  const std::string pfk = "pfk";
  const std::string pdr = "pdr";
  const std::string pgt = "pgt";
  const std::string pdi = "pdi";
  const std::string enw = "enw";
  const std::string eht = "eht";
  const std::string ebo = "ebo";
  const std::string edi = "edi";
  const std::string sgt = "sgt";
  const std::string seg = "seg";
  const std::string smg = "smg";
  const std::string suc = "suc";
  const std::string sbp = "sbp";
  const std::string okc = "okC";
  const std::string koc = "koC";
  const std::string clk = "clk";
}

#endif
