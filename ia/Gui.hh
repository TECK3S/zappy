//
// Gui.hh for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 13:01:10 2011 abd-el-moxine soumanou
// Last update Tue Jul  5 21:18:06 2011 abd-el-moxine soumanou
//

#ifndef		GUI_HH
#define		GUI_HH

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <QtGui/QMenu>
#include <QtGui/QApplication>
#include <QCoreApplication>
#include <QDesktopWidget>
#include <QtGui/QMdiSubWindow>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QMdiArea>
#include "Widget.hh"
#include "Observable.hh"

namespace	MGui
{
  class SettingsBox : public QDialog, public Observable
  {
    Q_OBJECT
    public:
    SettingsBox(QWidget *parent);
    ~SettingsBox();

  private slots:
    void        button(QAbstractButton *button);

  private:
    QDialogButtonBox    *buttonBox;
    QLineEdit           *lineEdit;
    QLabel              *label;
    QLabel              *label_2;
    QSpinBox            *spinBox;
    QString             ip;
    int                 port_value;
  };

  class	MGui : public QMainWindow
  {
    Q_OBJECT
  public:
    MGui();
    ~MGui();

    void	closeEvent(QCloseEvent *);
    bool	isOpen() const;
  private slots:
    void	ConnectSettingBox();

  private:
    QLabel		*picture_lab,   *statut_lab,
			*level_nb,      *player_nb,
			*inventary_lab, *linemate_lab,
			*deraumere_lab, *sibur_lab,
			*mendiane_lab,  *phiras_lab,
			*thystame_lab,  *team_name,
			*statusBarLabel, *food_lab;
    QVector<QLabel *>	v_label;
    QMenuBar		*menubar;
    QMenu		*menu;
    QAction		*a_connect,     *a_quit;
    SFML::LGui		*sfml_gui;
    QMdiArea		*zoneSFML;
    SettingsBox		*settings_box;
    QMdiSubWindow	*subMdi;
    bool		openState;
  };
}

#endif
