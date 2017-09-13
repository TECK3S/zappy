//
// Core.cpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client_graphic
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Tue Jun 14 20:22:50 2011 damien benloukil
//

#include <pthread.h>
#include "Observable.hh"
#include "Core.hh"

Core::Core(QString const & ip, quint16 port) : ip(ip), port(port), connected(false), s(SingletonBucket::getInstance()), waitingClick(false)
{
  this->cmd.push_back(cmd::msz);
  this->cmd.push_back(cmd::bct);
  this->cmd.push_back(cmd::tna);
  this->cmd.push_back(cmd::pnw);
  this->cmd.push_back(cmd::ppo);
  this->cmd.push_back(cmd::plv);
  this->cmd.push_back(cmd::pin);
  this->cmd.push_back(cmd::pex);
  this->cmd.push_back(cmd::pbc);
  this->cmd.push_back(cmd::pic);
  this->cmd.push_back(cmd::pie);
  this->cmd.push_back(cmd::pfk);
  this->cmd.push_back(cmd::pdr);
  this->cmd.push_back(cmd::pgt);
  this->cmd.push_back(cmd::pdi);
  this->cmd.push_back(cmd::enw);
  this->cmd.push_back(cmd::eht);
  this->cmd.push_back(cmd::ebo);
  this->cmd.push_back(cmd::edi);
  this->cmd.push_back(cmd::sgt);
  this->cmd.push_back(cmd::seg);
  this->cmd.push_back(cmd::smg);
  this->cmd.push_back(cmd::suc);
  this->cmd.push_back(cmd::sbp);  
  this->cmd.push_back(cmd::okc);
  this->cmd.push_back(cmd::koc);  
  this->cmd.push_back(cmd::clk);  
  this->s->setVal();
}

Core::~Core()
{
  if (this->gui)
    delete this->gui;
}

void Core::ex()
{
  TCP::Socket   sock(NULL, this->ip, this->port);
  this->b = this->s->getBeginGame();
  sock.addObserver(this);

  while (1)
    {
      if (QCoreApplication::hasPendingEvents())
	QCoreApplication::processEvents();
      if (this->connected)
	{
	  this->settings();
	  if (this->b->width != 0
	      && this->b->height != 0
	      && this->b->time != 0
	      && !this->b->teamName.empty())
	    {
	      std::cout << "all request are done ! creating GUI..." << std::endl;
	      this->gui =  new Gui(this->b->width, this->b->height, this->b->time, this->b->teamName);
	      this->gui->getIncustredGui()->addObserver(this);
	      std::cout << "GUI created, enjoy !" << std::endl;
	      break;
 	    }
	  sleep(1);
	}
    }

  int i = 0;
  while (1)
    {    
      if (i == 0)
	{
	  this->s->setSendingState(true);
	  this->s->setSend("mct\n");
	}
      if (QCoreApplication::hasPendingEvents())
	QCoreApplication::processEvents();
      i++;
    }
}

void Core::settings()
{
  static int i = 0;
 
  if (i <= 0)
    {
      this->s->setSendingState(true);
      this->s->setSend(request::graphic);
      std::cout << "sending information 'graphic' to the server..." << std::endl;
    }
  if (i == 1)
    {
      this->s->setSendingState(true);
      this->s->setSend(request::msz);
      std::cout << "sending size request..." << std::endl;
    }
  if (i == 2)
    {
      this->s->setSendingState(true);
      this->s->setSend(request::tna);
      std::cout << "sending team request..." << std::endl;
    }
  if (i == 3)
    {
      this->s->setSendingState(true);
      this->s->setSend(request::sgt); 
      std::cout << "sending time request..." << std::endl;
    }
  
  if (this->s->getBeginGame()->width != 0)
    this->b->width = this->s->getBeginGame()->width;
  if (this->s->getBeginGame()->height != 0)
    this->b->height = this->s->getBeginGame()->height;
  if (this->s->getBeginGame()->time != 0)
    this->b->time = this->s->getBeginGame()->time;
  if (!this->s->getBeginGame()->teamName.empty())
    this->b->teamName = this->s->getBeginGame()->teamName;  
  i++;
}

void Core::msz(std::string const & data)
{
  BeginGame *b = this->s->getBeginGame();
  std::string tmp = data.substr(4, data.size());
  int w, h;
  std::stringstream ss, ss2;

  ss << tmp.substr(0, tmp.find(" "));
  ss >> w;
  ss2 << tmp.substr(tmp.find(" "), tmp.size());
  ss2 >> h;

  b->width = w * 25;
  b->height = h * 25;
  this->s->setBeginGame(b);
}

void Core::wList(std::string const & str)
{
 std::string st, final;
 int q = 0;
 this->click = this->s->getClick();
 for (unsigned int i = 0; i < str.size(); ++i)
   {
     if (str[i] == ' ')
       q++;
     if (q == 2)
       st = str.substr(i, str.find(" "));
   }
 this->click->nb_player = atoi(st.c_str());
 this->waitingClick = false;
 final = "plv " + st + "\n";
 this->s->setSendingState(true);
 this->s->setSend(final.c_str());
}

void Core::bct(std::string const & data)
{
  std::string str = data.substr(4, data.size());  
  std::list<int> ob;
  int tmp = 0;
  int beg = 0;
  CaseContent caseC;
  std::stringstream ss1, ss2, ss3;
  int x,y,z;
  
  if (this->waitingClick)
    {
      this->wList(str);
      return;
    }
  if (str.compare("end") == 0)
    this->s->setCaseContent(this->caseList);
  else
    {
    for (unsigned int i = 0; i < str.size(); ++i)
      {
	if (str[i] == ' ')
	  {
	    if (beg == 0)
	      {
		ss1 << str.substr(tmp, i);
		ss1 >> x;
		caseC.x = x;
	      }
	    else if (beg == 1)
	      {
		ss2 << str.substr(tmp, i);
		ss2 >> y;
		caseC.y = y;
	      }
	    else
	      {
		ss3 << str.substr(tmp, i);
		ss3 >> z;
		ob.push_back(z);
	      }
	    tmp = i + 1;
	    beg++;
	  }      
      }
    caseC.object = ob;  
    this->caseList.push_back(caseC);
  }
}

void Core::tna(std::string const & data)
{
  BeginGame *b = this->s->getBeginGame();
  std::string str = data.substr(4, data.size());
  std::list<std::string> teamList;
  int tmp = 0;

  for (unsigned int i = 0; i < str.size(); ++i)
    {
      if (str[i] == ' ' || str[i+1] == '\0')
	{
	  teamList.push_back(str.substr(tmp, i - tmp));
	  tmp = i + 1;
	}
    }
  b->teamName = teamList;
  this->s->setBeginGame(b);
}

void Core::pnw(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::ppo(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::plv(std::string const & data)
{
  std::string str = data.substr(4, data.size());
  int tmp;
  std::string final;
  std::stringstream ss, ss2;
  int lev, nb;

  tmp = str.find(" ", 0);
  ss << str.substr(0, str.find(" ", 0));
  ss >> lev;
  this->click->level = lev;
  ss2 << str.substr(tmp + 1, str.size());
  ss2 >> nb;
  this->click->level = lev;
  final = "pin " + ss2.str() + "\n";
  this->s->setSendingState(true);
  this->s->setSend(final.c_str());  
}

void Core::pin(std::string const & data)
{
  std::string str = data.substr(6, data.size());
  int tmp = 0;
  int tm = 0;
  int ok = 0;
  std::list<int> inv;
  std::stringstream ss;
  
  while(tm != 2)
    {
      ok = tmp;
      tmp = str.find(" ", tmp + 1);
      if (tmp != ok)
	tm ++;
    }
  str = str.substr(str.find(" ", tmp));
  tmp = 1;
  for (unsigned int i = 1; i < str.size(); ++i)
    {
      if (str[i] == ' ' || str[i] == '\n')
	{
	  ss << str.substr(tmp, i);
	  ss >> tm;
	  inv.push_back(tm);
	  tmp = i + 1;
	  ss.str("");
	}
    }  
   usleep(1000);
  this->click->inventory = inv;
  this->s->setClick(this->click);
}

void Core::pex(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pbc(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pic(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pie(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pfk(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pdr(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pgt(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::pdi(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::enw(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::eht(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::ebo(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::edi(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::sgt(std::string const & data)
{
  std::string tmp =  data.substr(4, data.size());
  BeginGame *b = this->s->getBeginGame(); 
  int t;
  std::stringstream ss;

  ss << tmp;
  ss >> t;
  b->time = t;
  this->s->setBeginGame(b);  
}

void Core::seg(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::smg(std::string const & data)
{
  this->s->setOpcode(data);
}

void Core::suc(std::string const & data)
{
  std::cout << data << ": unknown command" << std::endl;
}

void Core::sbp(std::string const & data)
{
  std::cout << data << ": wrong parameters" << std::endl;
}

void Core::okc(std::string const &)
{
    this->connected = true;
}

void Core::koc(std::string const &)
{
  std::cout << "Connection terminated" << std::endl;
  exit (EXIT_SUCCESS);
}

void	Core::clk(std::string const & data)
{
  std::string str =  data.substr(4, data.size());
  std::string final = "bct ";

  final.append(str + "\n");
  this->waitingClick = true;
  this->s->setSendingState(true);
  this->s->setSend(final.c_str());
}

static void (Core::*ptr[])(std::string const &) =
{
  &Core::msz,
  &Core::bct,
  &Core::tna,
  &Core::pnw,
  &Core::ppo,
  &Core::plv,
  &Core::pin,
  &Core::pex,
  &Core::pbc,
  &Core::pic,
  &Core::pie,
  &Core::pfk,
  &Core::pdr,
  &Core::pgt,
  &Core::pdi,
  &Core::enw,
  &Core::eht,
  &Core::ebo,
  &Core::edi,
  &Core::sgt,
  &Core::seg,
  &Core::smg,
  &Core::suc,
  &Core::sbp,
  &Core::okc,
  &Core::koc,
  &Core::clk,
  NULL
};

void Core::update(std::string const & data)
{
  int i = 0;
  std::string d =  data.substr(0, 3);
  if (d.compare("snd") == 0)
    this->sndCmd(data.substr(4, data.size()));
  for (std::vector<std::string>::const_iterator it = this->cmd.begin(); it != this->cmd.end(); ++it)
    {
      if (d.compare(0, it->size(), *it) == 0)
	  (this->*ptr[i])(data);
      i++;
    }
}

void Core::sndCmd(std::string const & data)
{
  this->s->setSendingState(true);
  this->s->setSend(data.c_str());
}
