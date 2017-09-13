//
// Widget.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 17:32:53 2011 abd-el-moxine soumanou
// Last update Thu Jun 23 16:22:45 2011 abd-el-moxine soumanou
//

#ifndef		SFMLGUI_HH
#define		SFMLGUI_HH

#include <list>
#include <QtGui/QWidget>
#include <QCloseEvent>
#include <QTimer>
#include <QLabel>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <QMessageBox>
#include "Observable.hh"

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif

namespace	SFML
{
  const int PCASE = 25;
  class	LGui : public QWidget, public sf::RenderWindow, public Observable
  {
    Q_OBJECT
  public:
    LGui(QWidget *);
    ~LGui();
    void traceLine();

  private :
    void init();
    void launch();
    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *);

  private slots:
    void caseContent();

  private:
    QTimer timer;
    bool   initialized;
    sf::Image food[9];
    sf::Sprite sFood;
    QString	notify_msg;
    QList<std::string>  v_meal;
    int caseX, caseY;
  };
}

#endif
