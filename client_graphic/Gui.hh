//
// Gui.hh for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 13:01:10 2011 abd-el-moxine soumanou
// Last update Thu Jun 23 16:49:45 2011 abd-el-moxine soumanou
//
//

#ifndef		GUI_HH
#define		GUI_HH

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMdiArea>
#include <QtGui/QWidget>
#include <QSpinBox>
#include <QtGui/QMdiSubWindow>
#include <QDesktopWidget>
#include <QTimer>
#include "Widget.hh"
#include "Label.hh"
#include "Observable.hh"

class	Gui : public QWidget
{
  Q_OBJECT
  public:
  Gui(int width, int height, int time, std::list<std::string> const &teamName);
  ~Gui();

  void	closeEvent(QCloseEvent *);
  SFML::LGui    *getIncustredGui() const;

  void pnw(std::string const &);
  void ppo(std::string const &);
  void pex(std::string const &);
  void pbc(std::string const &);
  void pic(std::string const &);
  void pie(std::string const &);
  void pfk(std::string const &);
  void pdr(std::string const &);
  void pgt(std::string const &);
  void pdi(std::string const &);
  void enw(std::string const &);
  void eht(std::string const &);
  void ebo(std::string const &);
  void edi(std::string const &);
  void sgt(std::string const &);
  void sst(std::string const &);
  void seg(std::string const &);
  void smg(std::string const &);
  void suc(std::string const &);
  void sbp(std::string const &);


private slots:
  void	beginGame();
  void  evt_click();
  void	opcode_seq();

private:
  QLabel	*label[17];
  Label		*lab_network;
  QMdiArea	*mdiArea;
  QWidget	*subwindow;
  QComboBox	*cbx_team_name;
  QLCDNumber	*lcdNumber[7];
  QSpinBox	*spinBox;
  SFML::LGui	*lgui;
  QTimer	timer;
  void (Gui::*ptr_func[20])(std::string const &);
  std::vector<std::string> v_opcode;
};

#endif
