//
// Widget.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 17:40:37 2011 abd-el-moxine soumanou
// Last update Sun Jul 10 07:13:23 2011 eugene-valentin ngontang-tchiadjie
//

#include	<fstream>
#include	"Gui.hh"
#include	"Widget.hh"
#include        "bucketsingleton.hpp"

SFML::LGui::LGui(QWidget *parent) : QWidget(parent, Qt::Tool | Qt::CustomizeWindowHint), initialized(false)
{
  srand(time(NULL));
  this->setAttribute(Qt::WA_PaintOnScreen);
  this->setAttribute(Qt::WA_NoSystemBackground);
  this->setFixedSize(950, 720);
  this->hide_bck = true;

  this->ptr[0] = &LGui::move_forward;
  this->ptr[1] = &LGui::move_right;
  this->ptr[2] = &LGui::move_left;
  this->ptr[3] = &LGui::see;
  this->ptr[4] = &LGui::inventory;
  this->ptr[5] = &LGui::take_object;
  this->ptr[6] = &LGui::drop_object;
  this->ptr[7] = &LGui::expluse;
  this->ptr[8] = &LGui::broadcast;
  this->ptr[9] = &LGui::incantation;
  this->ptr[10] = &LGui::fork;
  this->ptr[11] = &LGui::connect_nbr;
  this->ptr[12] = &LGui::dead;
  this->ptr[13] = &LGui::welcome;
  this->ptr[14] = &LGui::join_team;
  this->ptr[15] = &LGui::win;
}

SFML::LGui::~LGui()
{

}

void SFML::LGui::InitSFML()
{
  this->Clear(sf::Color(255, 255, 255));
  this->init();
  this->UseVerticalSync(true);
  this->v_meal.append("nourriture");
  this->v_meal.append("linemate");
  this->v_meal.append("deraumere");
  this->v_meal.append("sibur");
  this->v_meal.append("mendiane");
  this->v_meal.append("phiras");
  this->v_meal.append("thystame");
  this->v_meal.append("joueur");
  this->v_meal.append("oeuf");
  /*
  if (this->Image.LoadFromFile("pictures/network.png"))
    {
      this->MSprite.SetImage(this->Image);
      this->MSprite.SetPosition(50.f, 0.f);
      }*/
}

void SFML::LGui::showEvent(QShowEvent *)
{
  if (!this->initialized)
    {
#ifdef Q_WS_X11
      XFlush(QX11Info::display());
#endif
      this->Create(this->winId());
      this->InitSFML();
      this->timer.setInterval(50);
      this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(repaint()));
      this->timer.start();
      this->initialized = true;
    }
}

void SFML::LGui::paintEvent(QPaintEvent *)
{
  this->launch();
  this->Display();
}

void SFML::LGui::closeEvent(QCloseEvent *)
{

}

void  SFML::LGui::init()
{
  if (!this->back.LoadFromFile("img/background.png"))
    exit(EXIT_FAILURE);
  if (!this->Img_level.LoadFromFile("img/niveau1.png"))
    exit(EXIT_FAILURE);
  for (int i = 1; i < 33; ++i)
    {
      std::ostringstream oss;
      oss << i;
      this->path = "img/stand" + oss.str() + ".png";
      if (!this->perso[i].LoadFromFile(this->path))
        exit(EXIT_FAILURE);
    }

  for (int i = 1; i < 27; ++i)
    {
      std::ostringstream oss;
      oss << i;
      this->path = "img/goo" + oss.str() + ".png";
      if (!this->joueur[i].LoadFromFile(this->path))
        exit(EXIT_FAILURE);
    }

  this->food[0].LoadFromFile("img/nourriture.png");
  this->food[1].LoadFromFile("img/linemate.png");
  this->food[2].LoadFromFile("img/deraumere.png");
  this->food[3].LoadFromFile("img/sibur.png");
  this->food[4].LoadFromFile("img/mendiane.png");
  this->food[5].LoadFromFile("img/phiras.png");
  this->food[6].LoadFromFile("img/thystame.png");
  this->food[7] = this->joueur[1];
  this->food[8].LoadFromFile("img/egg.png");

  this->hide_background.SetImage(this->Img_level);
  this->background.SetImage(this->back);
  this->personage.SetPosition(24.f, 20.f);
  this->hide_background.SetPosition(35.f, 10.f);
  this->save_objPos();
}

void SFML::LGui::setVlabel(QVector<QLabel *> *v_lab)
{
  this->v_lab = v_lab;
}

void    SFML::LGui::launch()
{
  static int i = 1;
  static int j = 1;

  this->Draw(this->background);
  if (this->hide_bck)
    this->Draw(this->hide_background);
  if (!this->food_to_see.isEmpty())
    for (int i = 0; i < this->food_to_see.size(); ++i)
      {
        this->sFood.SetImage(this->food[this->food_to_see.at(i)]);
        this->sFood.SetPosition(this->v_pos.at(this->food_to_see_pos.at(i)));
        this->Draw(this->sFood);
      }
  if (this->clock.GetElapsedTime() > 0.05f)
    {
      if (i == 33)
	i = 1;
      if (j == 27)
	j = 1;
      this->personage.SetImage(this->perso[i]);
      this->food[7] = this->joueur[j];
      this->clock.Reset();
      i++;
      j++;
    }
  this->Draw(this->personage);
  this->check_actions();
}

void        SFML::LGui::check_actions()
{
  SingletonBucket *sgleBck = SingletonBucket::getInstance();
  op		  &s_op    = sgleBck->getInterpretation();
  int		  i;


  if (s_op.opcode < 0)
    return;
  for (i = 0; i < 16; i++)
    if (i + 1 == s_op.opcode)
      {
	std::cout << i << std::endl;
	(this->*ptr[i])(s_op.data);
	s_op.opcode = -1;
	break;
      }
}

void SFML::LGui::move_forward(char const *)
{
  std::cout << "MOVE FORWARD COWARD" << std::endl;
}

void SFML::LGui::move_right(char const *)
{
  std::cout << "MOVE RIGHT COWARD" << std::endl;
}

void SFML::LGui::move_left(char const *)
{
  std::cout << "MOVE LEFT COWARD" << std::endl;
}

void SFML::LGui::see(char const *data)
{
  std::list<vis> *l_vis = reinterpret_cast<std::list<vis> *> (const_cast<char *>(data));
  std::list<vis>::const_iterator it;

  if (!this->food_to_see.empty())
    this->food_to_see.clear();
  if (!this->food_to_see_pos.empty())
    this->food_to_see_pos.clear();
  for (it = l_vis->begin(); it != l_vis->end(); ++it)
    {
      vis     tmp_vis = (*it);
      QString base;
      int     case_val, i;

      if (tmp_vis.ob.empty())
	continue;
      case_val = tmp_vis.cas;
      for (i = 0; i < this->v_meal.size(); i++)
	if (!tmp_vis.ob.compare(this->v_meal.at(i)))
	  {
	    this->food_to_see.append(i);
	    this->food_to_see_pos.append(case_val);
	    break;
	  }
    }
  l_vis->clear();
}

void SFML::LGui::inventory(char const *data)
{
  std::map<std::string, std::string> const *map = reinterpret_cast<std::map<std::string, std::string> const *> (data);
  std::map<std::string, std::string>::const_iterator it;
  bool		ok;

  std::cout << map->size()<< std::endl;
  for (it = map->begin(); it != map->end(); ++it)
    {
      std::string food_name = (*it).first;
      int	  qty = QString((*it).second.c_str()).toInt(&ok), i;

      for (i = 0; i < this->v_meal.size(); i++)
	if (!food_name.compare(this->v_meal.at(i)))
	  {
	    QString	name;
	    QStringList list = this->v_lab->at(i)->text().split('=');
	    name = list.first();
	    name += tr(" = ") + QString::number(qty);
	    this->v_lab->at(i)->setText(name);
	    break;
	  }
    }
}

void SFML::LGui::take_object(char const *data)
{
  QString	str(data);
  std::string	obj;
  QStringList   list;
  int		i;

  if (str.contains("ko"))
    {
      std::cout << "Object unaivalable to be taken" << std::endl;
      return;
    }
  list = str.split('|');
  obj = list.first().toStdString();
  for (i = 0; i < this->food_to_see.size(); i++)
    if (!obj.compare(this->v_meal.at(this->food_to_see.at(i))))
      {
	this->food_to_see.remove(i);
	this->food_to_see_pos.remove(i);
	break;
      }
}

void SFML::LGui::drop_object(char const *data)
{
  QString       str(data);
  std::string   obj;
  QStringList   list;
  int           i;


  if (str.contains("ko"))
    {
      std::cout << "Object unaivalable to be dropped" << std::endl;
      return;
    }
  list = str.split('|');
  obj = list.first().toStdString();
  for (i = 0; i < this->v_meal.size(); i++)
    if (!obj.compare(this->v_meal.at(i)))
      {
	this->food_to_see.append(i);
	this->food_to_see_pos.append(0);
      }
}

void SFML::LGui::expluse(char const *data)
{
  QString       str(data);

  if (str.contains("ko"))
    std::cout << "Push player failed." << std::endl;
  else if (str.contains("ok"))
    std::cout << "Push player success." << std::endl;
  else
    {
      std::cout << "Push at position " << data << std::endl;
    }
}

void SFML::LGui::broadcast(char const *data)
{
  QString       str(data);
  std::string   obj;
  QStringList   list;

  if (str.contains("ok"))
    std::cout << "Message player send success." << std::endl;
  else
    {
      list = str.split('|');
      obj = list.first().toStdString();
      std::cout << "Receive message from pos : " << obj << " -> " << list.last().toStdString() << std::endl;
    }
}

void SFML::LGui::incantation(char const *data)
{
  QString       str(data), path;
  int		nv;
  bool		ok;

  if (str.contains("ko"))
    {
      std::cout << "Cannot make the incantation" << std::endl;
      return;
    }
  nv = str.toInt(&ok);
  path = tr("img/niveau") + QString::number(nv) + tr(".png");
  if (this->Img_level.LoadFromFile(path.toStdString().c_str()))
    {
      this->hide_background.SetImage(this->Img_level);
      this->hide_background.SetPosition(this->vhide_bground.at(nv - 1));
    }
  else
    this->hide_bck = false;
}

void SFML::LGui::fork(char const *data)
{
  QString       str(data);

  if (str.contains("ok"))
    std::cout << "Has laid an egg" << std::endl;
}

void SFML::LGui::connect_nbr(char const *data)
{
  QString       str(data);
  std::string   obj;
  QStringList   list;

  list = str.split('/');
  obj = list.first().toStdString();
  std::cout << "There are " << obj << "/" << list.last().toStdString() <<  " slots total" << std::endl;
}

void SFML::LGui::dead(char const *)
{
  QMessageBox::warning(this, tr("Warning"), "You have lost the game because you are dead.....");
  exit(EXIT_SUCCESS);
}

void SFML::LGui::welcome(char const *data)
{
  std::cout << data << std::endl;
}

void SFML::LGui::join_team(char const *data)
{
  QString       str(data);

  if (str.contains("ko"))
    std::cout << "Team doesn't exist" << std::endl;
  else
    std::cout << "I join team " << data << std::endl;
}

void SFML::LGui::win(char const *)
{
  QMessageBox::warning(this, tr("Warning"), "You win the game....");
}

void SFML::LGui::save_objPos()
{
  std::ifstream file("pos.txt", std::ios::in);
  float		x,y;

  if (file.is_open())
    {
      while (!file.eof())
        {
	  file >> x >> y;
	  if (file.eof())
            break;
	  sf::Vector2f v(x,y);
	  this->v_pos.append(v);
	}
      file.close();
      this->vhide_bground.append(sf::Vector2f(35,10));
      this->vhide_bground.append(sf::Vector2f(50, 10));
      this->vhide_bground.append(sf::Vector2f(50, 10));
      this->vhide_bground.append(sf::Vector2f(80, 10));
      this->vhide_bground.append(sf::Vector2f(95, 10));
      this->vhide_bground.append(sf::Vector2f(110, 10));
      this->vhide_bground.append(sf::Vector2f(125, 10));
    }
  else
    {
      std::cerr << "Missing file Pos.txt" << std::endl;
      exit(EXIT_FAILURE);
    }
}
