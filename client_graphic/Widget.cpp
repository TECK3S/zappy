//
// Widget.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
//
//

#include	"Widget.hh"
#include        "bucketsingleton.hpp"

SFML::LGui::LGui(QWidget *parent) : QWidget(parent), Observable(), initialized(false)
{
  this->setAttribute(Qt::WA_PaintOnScreen);
  this->setAttribute(Qt::WA_NoSystemBackground);
}

SFML::LGui::~LGui()
{

}

void SFML::LGui::showEvent(QShowEvent *)
{
  if (!this->initialized)
    {
#ifdef Q_WS_X11
      XFlush(QX11Info::display());
#endif
      this->Create(this->winId());
      this->init();
      this->timer.setInterval(10);
      this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(caseContent()));
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
  this->UseVerticalSync(true);
  this->food[0].LoadFromFile("pictures/goo1.png");
  this->food[1].LoadFromFile("pictures/diamond.png");
  this->food[2].LoadFromFile("pictures/bleu (copy).png");
  this->food[3].LoadFromFile("pictures/green_diamond.png");
  this->food[4].LoadFromFile("pictures/pink2.png");
  this->food[5].LoadFromFile("pictures/diamond_violet.png");
  this->food[6].LoadFromFile("pictures/emeraude2.png");
  this->food[7].LoadFromFile("pictures/stone.png");
  this->food[8].LoadFromFile("pictures/egg.png");

  this->v_meal.append("joueur");
  this->v_meal.append("linemate");
  this->v_meal.append("deraumere");
  this->v_meal.append("sibur");
  this->v_meal.append("mendiane");
  this->v_meal.append("phiras");
  this->v_meal.append("thystame");
  this->v_meal.append("nourriture");
  this->v_meal.append("oeuf");
}

void    SFML::LGui::launch()
{
}

void SFML::LGui::traceLine()
{
  int i,x,y;

  i = x = y = 0;
  while (i * PCASE < this->width())
    {
      this->Draw(sf::Shape::Line(x, y, x, this->height(), 1, sf::Color::Red));
      x += PCASE;
      i++;
    }
  i = x = 0;
  while (i * PCASE < this->height())
    {
      this->Draw(sf::Shape::Line(x, y, this->width(), y, 1, sf::Color::Red));
      y += PCASE;
      i++;
    }
}

void	SFML::LGui::caseContent()
{
  int	i = 0;
  std::list<CaseContent>::const_iterator it;
  std::list<int>::const_iterator it2;
  SingletonBucket *sgleBck = SingletonBucket::getInstance();
  std::list<CaseContent> &content = sgleBck->getCaseContent();

  if (content.empty())
    return;
  this->Clear(sf::Color());
  for (it = content.begin(); it != content.end(); ++it)
    {
      std::list<int> object = it->object;
      i = 0;
      for (it2 = object.begin(); it2 != object.end(); ++it2)
	{
	  if (*it2)
	    {
	      this->sFood.SetImage(this->food[i]);
	      this->sFood.SetX(it->x * PCASE);
	      this->sFood.SetY(it->y * PCASE);
	      this->Draw(this->sFood);
	    }
	  i++;
	}
    }
  content.clear();
  this->traceLine();
}

void	SFML::LGui::mousePressEvent(QMouseEvent *e)
{
  this->notify_msg.clear();
  this->caseX = e->x() / PCASE;
  this->caseY = e->y() / PCASE;
  this->notify_msg.append(tr("clk ") + QString::number(this->caseX) + tr(" ") + QString::number(this->caseY));
  this->notify(this->notify_msg.toStdString().c_str());
}
