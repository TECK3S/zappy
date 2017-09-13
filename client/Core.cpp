
// Core.cpp for  in /home/benlou_d//proj/zappy/zappy_delamort/client
// 
// Made by damien benloukil
// Login   <benlou_d@epitech.net>
// 
// Started on  Thu Jun  2 12:13:29 2011 damien benloukil
//
//

#include "qtextstream.h"
#include "Core.hh"
#include "Gui.hh"
#include "TcpSocket.hh"
#include "bucketsingleton.hpp"
#include "iaclientsingleton.hpp"

Core::Core(std::string const & name) :
  keyWord(), objs(), queueToParse(), listToParse(), obje(), code(), opCode(), dropobj(""), takeobj(""), s(SingletonBucket::getInstance()), sIa(SingletonIa::getInstance()), o(new op), sd(new SendResponse), sndIa(false), teamName(name), sock(NULL), _opcode(0)
{
  this->keyWord.push_back(KeyWords::ok);
  this->keyWord.push_back(KeyWords::ko);
  this->keyWord.push_back(KeyWords::vision);
  this->keyWord.push_back(KeyWords::objet);
  this->keyWord.push_back(KeyWords::deplacement);
  this->keyWord.push_back(KeyWords::message);
  this->keyWord.push_back(KeyWords::elevation);
  this->keyWord.push_back(KeyWords::slot);
  this->keyWord.push_back(KeyWords::gagner);
  this->keyWord.push_back(KeyWords::mort);
  this->keyWord.push_back(KeyWords::bienvenue);

  this->objs.push_back(objects::nourriture);
  this->objs.push_back(objects::linemate);
  this->objs.push_back(objects::deraumere);
  this->objs.push_back(objects::sibur);
  this->objs.push_back(objects::mendiane);
  this->objs.push_back(objects::phiras);
  this->objs.push_back(objects::thystame);
  this->objs.push_back(objects::joueur);
  this->objs.push_back(objects::oeuf);

  this->_cmdQueue["avance"] = opcode::avance;
  this->_cmdQueue["droite"] = opcode::droite;
  this->_cmdQueue["gauche"] = opcode::gauche;
  this->_cmdQueue["voir"] = opcode::voir;
  this->_cmdQueue["inventaire"] = opcode::inventaire;
  this->_cmdQueue["prend"] = opcode::prend;
  this->_cmdQueue["pose"] = opcode::pose;
  this->_cmdQueue["expulse"] = opcode::expulse;
  this->_cmdQueue["broadcast"] = opcode::broadcast;
  this->_cmdQueue["incantation"] = opcode::incantation;
  this->_cmdQueue["fork"] = opcode::fork;
  this->_cmdQueue["connect_nbr"] = opcode::connect_nbr;
  this->_cmdQueue["equipe"] = opcode::equipe;
}

Core::~Core()
{
  delete this->o;
  delete this->sd;
}

void Core::ex(lua_State *L)
{
  MGui::MGui	gui;
  //  TCP::Socket   sock(NULL);
  ia  = luabind::object_cast<IARessources*>(luabind::globals(L)["WestCostIA"]);

  this->sock.addObserver(this);
  this->ia->addObserver(this);
  while(gui.isOpen())
    {
      if (QCoreApplication::hasPendingEvents())
	QCoreApplication::processEvents();

      if (this->sndIa == true)
	{
	  this->ia->checkRessources();
	  this->sndIa = false;
	}
     }
}

void Core::checkobjs()
{
  bool ok = false;

      for (std::vector<std::string>::iterator it = this->objs.begin(); it != this->objs.end(); ++it)
	{
	  if (this->queueToParse.front().substr(0, this->queueToParse.front().find(Token::space)) == *it)
	    {
	      ok = true;
	      break;
	    }
	}
      if (ok == false)
	std::cerr << "err parsing" << std::endl;
}

void Core::parser(int opcode)
{
  vis ob;  
  int i = 0;
  int ttmp = 0, tmbegin = 0;
  

  while (!this->queueToParse.empty())
    {
      //check si lobjet existe en base
      this->checkobjs();
      //parsing de la queue
      if (!this->queueToParse.empty())
	{
	  std::string tmp = this->queueToParse.front().append(" ");
	  for (unsigned int j = 0; j < tmp.length(); ++j)
	    {
	      if (tmp.at(j) == Token::space)
		{
		  ob.ob = tmp.substr(tmbegin, ttmp);
		  ob.cas = i;
		  this->listToParse.push_back(ob);
		  tmbegin = ttmp + 1;
		}
	      ttmp += 1;
	    }
	  ttmp = 0;
	  tmbegin = 0;
	  this->queueToParse.pop();
	  i++;
	}
    }  
  o->opcode = opcode;
  o->data = reinterpret_cast<char *>(&this->listToParse);
  s->setInterpretation(*o);

}

void Core::lexing(std::string const & data, int opcode)
{
  int tmp = 0;

  for (unsigned int i = 0; i < data.length(); ++i)
    {
      if (data.at(i) == Token::virg || data.at(i) == Token::closeAc)
	{
	  if (tmp == 0)
	    this->queueToParse.push(data.substr(tmp, i - tmp));
	  else
	    this->queueToParse.push(data.substr(tmp + 1, i - tmp - 1));
	  tmp = i + 1;
	}
    }
  this->parser(opcode);
}

void Core::vision(std::string const & data)
{
  this->sd->data =  data.substr(8, data.size() - 10);
  if (!this->opCode.empty())
    {
      this->sd->opcode = this->opCode.front();;
      this->opCode.pop();
    }
  this->sIa->setResponse(*(this->sd));
}

void Core::objet(std::string const & data)
{
  std::string obj;
  int tmp = 0;

  if (data.find(Token::openAc) == 5 && data.find(Token::closeAc) == data.size() - 1)
    obj = data.substr(6, data.size() - 6);
  if (std::count(data.begin(), data.end(), Token::virg) != 6)
    std::cerr << "err obj" << std::endl;  
  for (unsigned int i = 0; i < obj.length(); ++i)
    {
      if (obj.at(i) == Token::virg || obj.at(i) == Token::closeAc)
	{
	  int tm = obj.substr(tmp, i - tmp).size();
	   this->obje[obj.substr(tmp, i - tmp - 2)]
	     = obj.substr(tmp + tm - 1, 1);
	   //changer pour les nombres + de 9
	   tmp = i + 2;
	}
    }
  
  o->data = reinterpret_cast<char *>(&this->obje);  
  s->setInterpretation(*o);

  QString oj(data.c_str());  
  this->sd->data =  data.substr(8, data.size() - 10);
  if (!this->opCode.empty())
    {
      this->_opcode =this->opCode.front();
      this->opCode.pop();
    }
  this->sd->opcode = this->_opcode;
  o->opcode = this->_opcode;
  this->_opcode = 0;
  this->sIa->setResponse(*(this->sd));
}

/********************** recv ********************************/

void Core::ok(std::string const & data)
{
  (void)data;

  if (this->takeobj != "")
    {
      std::string tmp = this->takeobj + "|ok";
      o->data = tmp.c_str();
      this->takeobj= "";
    }
  else if (this->dropobj != "")
    {
      std::string tmp = this->dropobj + "|ok";
      o->data = tmp.c_str();
      this->dropobj = "";
    }
  else 
    o->data = "ok";    
  
  this->sd->data = "ok";
  if (!this->opCode.empty())
    {
      this->_opcode = this->opCode.front();
      this->opCode.pop();
    }
   if (this->_opcode == opcode::equipe)
     {
       std::cout << "Going to start" << std::endl;
       this->ia->setTeamName(this->teamName);
       this->ia->start();
     }
  o->opcode = this->_opcode;
  this->sd->opcode = this->_opcode;
  this->_opcode = 0;
  this->sIa->setResponse(*(this->sd));
  s->setInterpretation(*o);  
}

void Core::distrib(QString oj, int opcode)
{
  o->opcode = opcode;
  o->data = oj.toAscii();
  s->setInterpretation(*o);  


  sd->opcode = opcode;
  sd->data = oj.toStdString();  
  sIa->setResponse(*sd);
  }

void Core::ko(std::string const & data)
{  
   
  (void)data;
  this->sd->data =  "ko";
  if (!this->opCode.empty())
    {
      this->_opcode = this->opCode.front();
      if (this->_opcode ==  opcode::equipe)
	std::cout << "unable to join team" << std::endl;
      this->opCode.pop();
    }
  o->opcode = this->_opcode;
  this->sd->opcode = this->_opcode;
  this->sIa->setResponse(*(this->sd));
  o->data = "ko";
  this->_opcode = 0;
  s->setInterpretation(*o);  
  this->sIa->setResponse(*(this->sd));
}

void Core::slot(std::string const & data)
{
  std::string obj;

  (void)data;
  obj = data.substr(5, data.size() - 6);
  QString oj(obj.c_str());

  this->sd->data =  data.substr(5, data.size() - 6);
  if (!this->opCode.empty())
    {
      this->_opcode =this->opCode.front();
      this->opCode.pop();
    }
  this->sd->opcode = this->_opcode;
  o->opcode = this->_opcode;
  this->_opcode = 0;
  this->sIa->setResponse(*(this->sd));
  this->distrib(oj, o->opcode);
}

void Core::message(std::string const & data)
{
  std::string obj;

  obj = data.substr(8, data.size() - 9);
  obj.replace(obj.find(Token::virg), 1, "|");

  QString oj(obj.c_str());

  this->sd->data =  data.substr(8, data.size() - 9);
  this->sd->opcode = opcode::broadcast;
  o->opcode = opcode::broadcast;
  this->sIa->setResponse(*(this->sd));
  this->distrib(oj, o->opcode);
}

void Core::elevation(std::string const & data)
{
  std::string obj;
  obj = data.substr(10, data.size() - 11);

  QString oj(obj.c_str());

  this->sd->data =  data.substr(10, data.size() - 11);
  this->sd->opcode = opcode::incantation;
  o->opcode = opcode::incantation;
  this->sIa->setResponse(*(this->sd));
  this->distrib(oj, o->opcode);
}

void Core::deplacement(std::string const & data)
{
  std::string obj;

  obj = data.substr(12, data.size() - 13);
  QString oj(obj.c_str());

  this->sd->data =  data.substr(12, data.size() - 13);
  this->sd->opcode = opcode::expulse;
  o->opcode = opcode::expulse;
  this->sIa->setResponse(*(this->sd));
  this->distrib(oj, o->opcode);
}

void Core::mort(std::string const & data)
{
  std::string obj;

  obj = data.substr(5, data.size() - 6);
  
  QString oj(obj.c_str());

  this->sd->data =  data.substr(5, data.size() - 6);
  this->sd->opcode = opcode::mort;
  o->opcode = opcode::mort;
  o->data = NULL;
  s->setInterpretation(*o);
  this->sIa->setResponse(*(this->sd));
  this->distrib(oj, o->opcode);
}

void Core::bienvenue(std::string const & data)
{
  std::string obj;
  obj = data.substr(10, data.size() - 11);

  QString oj(obj.c_str());

  o->opcode = opcode::bienvenue;
  o->data = oj.toAscii();
  this->sd->data =  data.substr(10, data.size() - 11);
  this->sd->opcode = opcode::bienvenue;
  o->opcode = opcode::bienvenue;
  s->setInterpretation(*o);
  this->sIa->setResponse(*(this->sd));
  std::string tmp = "equipe " + this->teamName + "\n";
  this->updateIa(tmp);
  this->distrib(oj, o->opcode);
}

void Core::gagner(std::string const & data)
{
  std::string obj;
  
  obj = data.substr(6, data.size() - 7);
  QString oj(obj.c_str());
  
  this->sd->data =  data.substr(6, data.size() - 7);
  this->sd->opcode = opcode::gagner;
  o->opcode = opcode::gagner;
  o->data = oj.toAscii();
  this->distrib(oj, o->opcode);
  this->sIa->setResponse(*(this->sd));
  s->setInterpretation(*o);
}

void Core::equipe(std::string const & data)
{
  std::string obj;

  obj = data.substr(7, data.size() - 8);
  QString oj(obj.c_str());
  o->opcode = 0x0F;
  o->data = oj.toAscii();
  s->setInterpretation(*o);
}

static void (Core::*ptr[])(std::string const &) =
{
  &Core::ok,
  &Core::ko,
  &Core::vision,
  &Core::objet,
  &Core::deplacement,
  &Core::message,
  &Core::elevation,
  &Core::slot,
  &Core::gagner,
  &Core::mort,
  &Core::bienvenue,
  NULL
};

void Core::update(std::string const & data)
{
  int i = 0;

  for (std::vector<std::string>::const_iterator it = this->keyWord.begin(); it != this->keyWord.end(); ++it)
    {
      if (data.compare(0, it->size(), *it) == 0)
	{
	  (this->*ptr[i])(data);
	  if ((*it).compare("bienvenue") != 0)
	    {
	      this->sndIa = true;
	      std::cout << *it << std::endl;
	    }
	  return;
	 }	    
      i++;
    }
}

static int	getOp(std::string const & s, std::map<std::string, int> const & myMap)
{
  std::map<std::string, int>::const_iterator it = myMap.find(s);

  if (it != myMap.end())
    return (it->second);
  return (0);
}

void Core::updateIa(std::string const & data)
{
  std::string  cmd;
  char *tmp = const_cast<char *>(data.c_str());
  size_t find = data.find(' ');
  
  if (find == std::string::npos)
    cmd = (data[data.size() - 1] == '\n' ? data.substr(0, data.size() - 1) : data);
  else
    cmd = data.substr(0, data.find(' '));
  this->opCode.push(getOp(cmd, this->_cmdQueue));
  this->s->setSend(tmp);
  this->sock.hasDataToSend();
 }

void  Core::update(Command const &data)
{
  int i = 0;
  for (std::list<int>::iterator it = this->code.begin();
       it != this->code.end();++it)
    {
      if (*it == data.opcode)
	{
	  this->opCode.push(data.opcode);
	  if (data.opcode == opcode::prend)
	    this->takeobj = &data.msg[5];
	  if (data.opcode == opcode::pose)
	    this->dropobj = &data.msg[4];
	  s->setSend(data.msg);
	}
      i++;
    }
}
