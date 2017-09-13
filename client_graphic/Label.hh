//
// Label.hh for  in /home/souman_a//Desktop/my_project/zappy_delamort/zappy_delamort/client_graphic
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Mon Jun 13 19:20:12 2011 abd-el-moxine soumanou
// Last update Tue Jun 14 11:32:46 2011 abd-el-moxine soumanou
//

#ifndef	LABEL_HH
#define LABEL_HH

#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

class	Label : public QLabel
{
public:
  Label(QWidget *);
  ~Label();
  void	enterEvent( QEvent *);
};

#endif
