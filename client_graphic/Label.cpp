//
// Label.cpp for  in /home/souman_a//Desktop/my_project/zappy_delamort/zappy_delamort/client_graphic
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Mon Jun 13 19:21:54 2011 abd-el-moxine soumanou
// Last update Tue Jun 14 12:36:33 2011 abd-el-moxine soumanou
//

#include "Label.hh"

Label::Label(QWidget *parent) : QLabel(parent)
{
  this->setMouseTracking(true);
  this->setFrameShape(QFrame::StyledPanel);
  this->setCursor(QCursor(Qt::OpenHandCursor));
  this->setPixmap(QPixmap(tr("pictures/netpc.png")));
  this->setGeometry(QRect(860, 40, 61, 61));
}

Label::~Label()
{
}

void	Label::enterEvent( QEvent *)
{


}
