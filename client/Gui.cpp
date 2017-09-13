//
// Gui.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 15:41:47 2011 abd-el-moxine soumanou
// Last update Sat Jul  9 19:44:11 2011 eugene-valentin ngontang-tchiadjie
//

#include	"Gui.hh"
#include	"bucketsingleton.hpp"

MGui::MGui::MGui() : QMainWindow()
{
  QFont font, font1, font2, font3;

  this->setAutoFillBackground(true);
  this->setPalette(QPalette(Qt::black));
  this->setFixedSize(1280, 780);
  this->setWindowTitle(tr("Zappy qui suce des gros zizi"));
  this->move((QApplication::desktop()->width() - this->width()) / 2,
             (QApplication::desktop()->height() - this->height()) /2);

  this->openState = true;
  this->zoneSFML = new QMdiArea;
  this->zoneSFML->setFrameShape(QFrame::Box);
  this->zoneSFML->setBackground(QBrush(QColor()));
  this->sfml_gui = new SFML::LGui(this);
  this->subMdi = this->zoneSFML->addSubWindow(this->sfml_gui);
  this->subMdi->setWindowFlags(Qt::FramelessWindowHint);
  this->subMdi->move(220,0);
  this->subMdi->setFixedSize(950, 720);
  this->setCentralWidget(this->zoneSFML);

  font.setFamily(tr("Utopia"));
  font.setBold(false);
  font.setWeight(50);
  font1.setFamily(tr("Utopia"));
  font1.setPointSize(11);
  font1.setBold(true);
  font1.setWeight(75);
  font2.setFamily(tr("Utopia"));
  font2.setBold(false);
  font2.setUnderline(true);
  font2.setWeight(50);
  font3.setUnderline(true);

  this->setFont(font);
  this->picture_lab = new QLabel(this);
  this->picture_lab->setGeometry(QRect(10, 20, 121, 121));
  this->picture_lab->setPixmap(QPixmap(tr("pictures/Point_d'interrogation.png")));
  this->statut_lab = new QLabel(this);
  this->statut_lab->setGeometry(QRect(10, 150, 51, 18));
  this->statut_lab->setFont(font1);
  this->statut_lab->setFrameShape(QFrame::StyledPanel);
  this->statut_lab->setFrameShadow(QFrame::Plain);
  this->level_nb = new QLabel(this);
  this->level_nb->setGeometry(QRect(30, 220, 62, 18));
  this->level_nb->setFont(font2);
  this->player_nb = new QLabel(this);
  this->player_nb->setGeometry(QRect(30, 200, 62, 18));
  this->player_nb->setFont(font3);
  this->inventary_lab = new QLabel(this);
  this->inventary_lab->setGeometry(QRect(10, 250, 71, 18));
  this->inventary_lab->setFrameShape(QFrame::StyledPanel);
  this->linemate_lab = new QLabel(this);
  this->linemate_lab->setGeometry(QRect(40, 280, 111, 18));
  this->linemate_lab->setFrameShape(QFrame::Box);
  this->linemate_lab->setFrameShadow(QFrame::Plain);
  this->deraumere_lab = new QLabel(this);
  this->deraumere_lab->setGeometry(QRect(40, 310, 111, 18));
  this->deraumere_lab->setFrameShape(QFrame::Box);
  this->sibur_lab = new QLabel(this);
  this->sibur_lab->setGeometry(QRect(40, 340, 111, 18));
  this->sibur_lab->setFrameShape(QFrame::Box);
  this->mendiane_lab = new QLabel(this);
  this->mendiane_lab->setGeometry(QRect(40, 370, 111, 18));
  this->mendiane_lab->setFrameShape(QFrame::Box);
  this->phiras_lab = new QLabel(this);
  this->phiras_lab->setGeometry(QRect(40, 400, 111, 18));
  this->phiras_lab->setFrameShape(QFrame::Box);
  this->thystame_lab = new QLabel(this);
  this->thystame_lab->setGeometry(QRect(40, 430, 111, 18));
  this->thystame_lab->setFrameShape(QFrame::Box);
  this->food_lab = new QLabel(this);
  this->food_lab->setGeometry(QRect(40, 460, 111, 18));
  this->food_lab->setFrameShape(QFrame::Box);
  this->team_name = new QLabel(this);
  this->team_name->setGeometry(QRect(30, 180, 171, 18));
  this->team_name->setFont(font3);
  this->menubar = new QMenuBar(this);
  this->menubar->setGeometry(QRect(0, 0, 1024, 24));
  this->setMenuBar(this->menubar);
  this->menu = this->menuBar()->addMenu(tr("Actions"));
  this->a_connect = new QAction(tr("Connect"), this);
  this->a_quit = new QAction(tr("Exit"), this);
  this->settings_box = new SettingsBox(this);

  this->statut_lab->setText(tr("Statut"));
  this->level_nb->setText(tr("Level 1"));
  this->player_nb->setText(tr("Player 1"));
  this->inventary_lab->setText(tr("Inventory"));
  this->linemate_lab->setText(tr("Linemate = 0"));
  this->deraumere_lab->setText(tr("Deraumere = 0"));
  this->sibur_lab->setText(tr("Sibur = 0"));
  this->mendiane_lab->setText(tr("Mendiane = 0"));
  this->phiras_lab->setText(tr("Phiras = 0"));
  this->thystame_lab->setText(tr("Thystame = 0"));
  this->food_lab->setText(tr("Food = 0"));
  this->team_name->setText(tr("Team Name = Deseptican"));

  this->v_label.append(this->food_lab);
  this->v_label.append(this->linemate_lab);
  this->v_label.append(this->deraumere_lab);
  this->v_label.append(this->sibur_lab);
  this->v_label.append(this->mendiane_lab);
  this->v_label.append(this->phiras_lab);
  this->v_label.append(this->thystame_lab);
  this->v_label.append(this->level_nb);
  this->v_label.append(this->team_name);

  this->sfml_gui->setVlabel(&this->v_label);

  this->menu->addAction(this->a_connect);
  this->menu->addAction(menuBar()->addSeparator());
  this->menu->addAction(this->a_quit);
  this->connect(this->a_connect, SIGNAL(triggered()), this, SLOT(ConnectSettingBox()));
  this->connect(this->a_quit, SIGNAL(triggered()), this, SLOT(close()));
  this->show();
}

MGui::MGui::~MGui()
{}

void        MGui::MGui::closeEvent(QCloseEvent *)
{
  this->openState = false;
}

void        MGui::MGui::ConnectSettingBox()
{
  this->settings_box->exec();
}

MGui::SettingsBox::SettingsBox(QWidget *parent) : QDialog(parent)
{
  this->setFixedSize(334, 143);
  this->setWindowModality(Qt::ApplicationModal);
  this->buttonBox = new QDialogButtonBox(this);
  this->buttonBox->setGeometry(QRect(-70, 100, 341, 32));
  this->buttonBox->setOrientation(Qt::Horizontal);
  this->buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
  this->lineEdit = new QLineEdit(this);
  this->lineEdit->setGeometry(QRect(10, 60, 151, 21));
  this->lineEdit->setMaxLength(15);
  this->label = new QLabel(this);
  this->label->setGeometry(QRect(10, 30, 131, 18));
  this->label->setFrameShape(QFrame::WinPanel);
  this->label_2 = new QLabel(this);
  this->label_2->setGeometry(QRect(230, 30, 81, 18));
  this->label_2->setFrameShape(QFrame::WinPanel);
  this->spinBox = new QSpinBox(this);
  this->spinBox->setMaximum(65536);
  this->spinBox->setGeometry(QRect(250, 60, 61, 21));
  this->ip = "127.0.0.1";
  this->port_value = 1024;
  this->lineEdit->setText(this->ip);
  this->spinBox->setValue(this->port_value);
  this->label->setText(tr("Server IP ADDRESS"));
  this->label_2->setText(tr("Server Port"));
  this->connect(this->buttonBox, SIGNAL(clicked(QAbstractButton *)), this, SLOT(button(QAbstractButton *)));
}

MGui::SettingsBox::~SettingsBox()
{

}

bool MGui::MGui::isOpen() const
{
  return(this->openState);
}

void        MGui::SettingsBox::button(QAbstractButton *button)
{
  QDialogButtonBox::StandardButton but;
  SingletonBucket *sgleBck;

  if (button)
    {
      but = this->buttonBox->standardButton(button);
      if (but == QDialogButtonBox::Ok)
	{
	  this->ip = this->lineEdit->text().trimmed();
	  this->port_value = this->spinBox->value();
	  sgleBck = SingletonBucket::getInstance();
	  sgleBck->setAddress(this->ip.toStdString());
	  sgleBck->setPort(this->port_value);
	}
    }
  this->done(0);
}
