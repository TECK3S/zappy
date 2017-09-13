//
// Widget.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 17:32:53 2011 abd-el-moxine soumanou
// Last update Tue Jun 14 19:59:30 2011 damien benloukil
//

#ifndef		SFMLGUI_HH
#define		SFMLGUI_HH

#include <QtGui/QWidget>
#include <QCloseEvent>
#include <QTimer>
#include <QLabel>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <QMessageBox>

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif

namespace	SFML
{
  class	LGui : public QWidget, public sf::RenderWindow
  {
    Q_OBJECT
  public:
    LGui(QWidget *);
    ~LGui();
    void init();
    void launch();
    void save_objPos();
    void setVlabel(QVector<QLabel *> *v_lab);

  private slots:
    void	check_actions();

  private :
    void InitSFML();

    void move_forward(char const *);
    void move_right(char const *);
    void move_left(char const *);
    void see(char const *);
    void inventory(char const *);
    void take_object(char const *);
    void drop_object(char const *);
    void expluse(char const *);
    void broadcast(char const *);
    void incantation(char const *);
    void fork(char const *);
    void connect_nbr(char const *);
    void dead(char const *);
    void welcome(char const *);
    void join_team(char const *);
    void win(char const *);

    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);

    QTimer timer;
    bool   initialized, hide_bck;
    sf::Image Image, Img_level, back, perso[33], food[9], joueur[27];
    std::string path;
    sf::Sprite personage, background, hide_background, MSprite, sFood, sJoueur;
    sf::Clock  clock;
    QList<sf::Vector2f> v_pos, vhide_bground;
    QList<std::string>	v_meal;
    QVector<QLabel *>   *v_lab;
    QVector<int >	food_to_see, food_to_see_pos;
    void (LGui::*ptr[16])(char const *);
  };
}

#endif
