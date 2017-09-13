//
// Gui.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 15:41:47 2011 abd-el-moxine soumanou
//

#include	"Gui.hh"
#include	"enum.hh"
#include	"bucketsingleton.hpp"

Gui::Gui(int width, int height, int time, std::list<std::string> const & teamName) : QWidget()
{
  std::list<std::string>::const_iterator it;
  QPalette palette(Qt::black);
  QFont font;

  font.setFamily(tr("Utopia"));
  font.setItalic(true);
  font.setWeight(50);
  this->setFixedSize(1038, 707);
  this->setWindowTitle(tr("Zappy"));
  this->move((QApplication::desktop()->width() - this->width()) / 2,
             (QApplication::desktop()->height() - this->height()) /2);
  for (int i = 0; i <= LAB_FOOD; i++)
    this->label[i] = new QLabel(this);
  for (int i = 0; i <= LCD_FOOD; i++)
  this->lcdNumber[i]= new QLCDNumber(this);

  this->label[LAB_BACKGROUND]->setGeometry(QRect(-380, -10, 1481, 861));
  this->label[LAB_MAPSIZE]->setGeometry(QRect(30, 610, 291, 16));
  this->label[LAB_TEAMNAME]->setGeometry(QRect(860, 120, 101, 16));
  this->label[LAB_INFORMATION]->setGeometry(QRect(30, 630, 961, 16));
  this->label[LAB_CURRTIME]->setGeometry(QRect(700, 650, 291, 16));
  this->label[LAB_PLAYERPOS]->setGeometry(QRect(700, 610, 291, 16));
  this->label[LAB_LEVEL]->setGeometry(QRect(30, 650, 291, 16));
  this->label[LAB_REQUEST]->setGeometry(QRect(30, 670, 961, 16));
  this->label[LAB_INVENTORY]->setGeometry(QRect(870, 210, 111, 16));
  this->label[LAB_LINEMATE]->setGeometry(QRect(920, 240, 21, 21));
  this->label[LAB_DERAUMERE]->setGeometry(QRect(930, 270, 16, 18));
  this->label[LAB_SIBUR]->setGeometry(QRect(920, 300, 21, 18));
  this->label[LAB_MENDIANE]->setGeometry(QRect(920, 330, 21, 18));
  this->label[LAB_PHIRAS]->setGeometry(QRect(920, 360, 21, 18));
  this->label[LAB_THYSTAME]->setGeometry(QRect(930, 390, 16, 21));
  this->label[LAB_TIME]->setGeometry(QRect(980, 40, 41, 18));
  this->label[LAB_FOOD]->setGeometry(QRect(930, 420, 21, 18));

  this->lcdNumber[LCD_LINEMATE]->setGeometry(QRect(950, 240, 31, 21));
  this->lcdNumber[LCD_DERAUMERE]->setGeometry(QRect(950, 270, 31, 21));
  this->lcdNumber[LCD_SIBUR]->setGeometry(QRect(950, 300, 31, 21));
  this->lcdNumber[LCD_MENDIANE]->setGeometry(QRect(950, 330, 31, 21));
  this->lcdNumber[LCD_PHIRAS]->setGeometry(QRect(950, 360, 31, 21));
  this->lcdNumber[LCD_THYSTAME]->setGeometry(QRect(950, 390, 31, 21));
  this->lcdNumber[LCD_FOOD]->setGeometry(QRect(950, 420, 31, 21));

  this->label[LAB_LINEMATE]->setPixmap(QPixmap(tr("pictures/diamond.png")));
  this->label[LAB_DERAUMERE]->setPixmap(QPixmap(tr("pictures/bleu (copy).png")));
  this->label[LAB_SIBUR]->setPixmap(QPixmap(tr("pictures/green_diamond.png")));
  this->label[LAB_MENDIANE]->setPixmap(QPixmap(tr("pictures/pink2.png")));
  this->label[LAB_PHIRAS]->setPixmap(QPixmap(tr("pictures/diamond_violet.png")));
  this->label[LAB_THYSTAME]->setPixmap(QPixmap(tr("pictures/emeraude2.png")));
  this->label[LAB_FOOD]->setPixmap(QPixmap(tr("pictures/stone.png")));

  this->label[LAB_MAPSIZE]->setText(tr("Map Size: Width = ") + QString::number(width) + tr(", Height = ") +
				    QString::number(height));
  this->label[LAB_TEAMNAME]->setText(tr("Teams Name"));
  this->label[LAB_INFORMATION]->setText(tr("Information -> ?"));
  this->label[LAB_CURRTIME]->setText(tr("Current Time -> ?"));
  this->label[LAB_PLAYERPOS]->setText(tr("Player position X = ? , Y = ?"));
  this->label[LAB_LEVEL]->setText(tr("Player Level -> ?"));
  this->label[LAB_REQUEST]->setText(tr("Request -> ?"));
  this->label[LAB_INVENTORY]->setText(tr("Player Inventory"));
  this->label[LAB_TIME]->setText(tr("Time"));

  this->label[LAB_BACKGROUND]->setFont(font);
  this->label[LAB_BACKGROUND]->setPixmap(QPixmap(tr("pictures/CiruiorFire.png")));
  this->label[LAB_BACKGROUND]->setScaledContents(true);

  this->mdiArea = new QMdiArea(this);
  this->mdiArea->setFixedSize(821, 571);
  this->mdiArea->move(30,30);
  this->mdiArea->setBackground(QBrush(QColor()));
  this->mdiArea->setFrameShape(QFrame::WinPanel);
  this->mdiArea->setFrameShadow(QFrame::Raised);
  this->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  this->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  this->mdiArea->setViewMode(QMdiArea::SubWindowView);

  QMdiSubWindow *subWin = this->mdiArea->addSubWindow(this->lgui = new SFML::LGui(this->mdiArea));
  subWin->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowMinimizeButtonHint);
  subWin->setCursor(QCursor(Qt::OpenHandCursor));
  subWin->setFixedSize(width, height);
  subWin->move((this->mdiArea->width() - subWin->width()) / 2,
	       (this->mdiArea->height() - subWin->height()) /2);

  this->lab_network = new Label(this);
  this->label[LAB_MAPSIZE]->setPalette(palette);
  QFont font1;
  font1.setFamily(tr("Utopia"));
  font1.setItalic(true);
  font1.setWeight(75);
  this->label[LAB_TEAMNAME]->setFont(font1);
  this->label[LAB_TEAMNAME]->setPalette(palette);
  this->label[LAB_TEAMNAME]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_MAPSIZE]->setFont(font1);
  this->label[LAB_MAPSIZE]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_INFORMATION]->setPalette(palette);
  this->label[LAB_INFORMATION]->setFont(font1);
  this->label[LAB_INFORMATION]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_CURRTIME]->setPalette(palette);
  this->label[LAB_CURRTIME]->setFont(font1);
  this->label[LAB_CURRTIME]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_PLAYERPOS]->setPalette(palette);
  this->label[LAB_PLAYERPOS]->setFont(font1);
  this->label[LAB_PLAYERPOS]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_LEVEL]->setPalette(palette);
  this->label[LAB_LEVEL]->setFont(font1);
  this->label[LAB_LEVEL]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_REQUEST]->setPalette(palette);
  this->label[LAB_REQUEST]->setFont(font1);
  this->label[LAB_REQUEST]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_INVENTORY]->setPalette(palette);
  this->label[LAB_INVENTORY]->setFont(font1);
  this->label[LAB_INVENTORY]->setFrameShape(QFrame::StyledPanel);
  this->label[LAB_TIME]->setPalette(palette);
  this->label[LAB_TIME]->setFont(font1);
  this->label[LAB_TIME]->setFrameShape(QFrame::StyledPanel);

  this->cbx_team_name = new QComboBox(this);
  this->cbx_team_name->setGeometry(QRect(870, 150, 91, 21));

  for (it = teamName.begin(); it != teamName.end(); ++it)
    this->cbx_team_name->addItem(QString((*it).c_str()));

  this->spinBox = new QSpinBox(this);
  this->spinBox->setGeometry(QRect(980, 60, 51, 16));
  this->spinBox->setRange(1, 2000000000);
  this->spinBox->setValue(time);

  this->timer.setInterval(50);
  this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(beginGame()));
  this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(evt_click()));
  this->connect(&this->timer, SIGNAL(timeout()), this, SLOT(opcode_seq()));

  this->ptr_func[0] = &Gui::pnw;
  this->ptr_func[1] = &Gui::ppo;
  this->ptr_func[2] = &Gui::pex;
  this->ptr_func[3] = &Gui::pbc;
  this->ptr_func[4] = &Gui::pic;
  this->ptr_func[5] = &Gui::pie;
  this->ptr_func[6] = &Gui::pfk;
  this->ptr_func[7] = &Gui::pdr;
  this->ptr_func[8] = &Gui::pgt;
  this->ptr_func[9] = &Gui::pdi;
  this->ptr_func[10] = &Gui::enw;
  this->ptr_func[11] = &Gui::eht;
  this->ptr_func[12] = &Gui::ebo;
  this->ptr_func[13] = &Gui::edi;
  this->ptr_func[14] = &Gui::sgt;
  this->ptr_func[15] = &Gui::sst;
  this->ptr_func[16] = &Gui::seg;
  this->ptr_func[17] = &Gui::smg;
  this->ptr_func[18] = &Gui::suc;
  this->ptr_func[19] = &Gui::sbp;

  this->v_opcode.push_back("pnw");
  this->v_opcode.push_back("ppo");
  this->v_opcode.push_back("pex");
  this->v_opcode.push_back("pbc");
  this->v_opcode.push_back("pic");
  this->v_opcode.push_back("pie");
  this->v_opcode.push_back("pfk");
  this->v_opcode.push_back("pdr");
  this->v_opcode.push_back("pgt");
  this->v_opcode.push_back("pdi");
  this->v_opcode.push_back("enw");
  this->v_opcode.push_back("eht");
  this->v_opcode.push_back("ebo");
  this->v_opcode.push_back("edi");
  this->v_opcode.push_back("sgt");
  this->v_opcode.push_back("sst");
  this->v_opcode.push_back("seg");
  this->v_opcode.push_back("smg");
  this->v_opcode.push_back("suc");
  this->v_opcode.push_back("sbp");
  this->timer.start();
  this->show();
}

Gui::~Gui()
{

}

SFML::LGui    *Gui::getIncustredGui() const
{
  return (this->lgui);
}

void        Gui::opcode_seq()
{
  size_t		i;
  SingletonBucket *sgleBck = SingletonBucket::getInstance();
  if (!sgleBck)
    return;

  std::vector<std::string>::iterator it;
  std::string &opcode = sgleBck->getOpcode();

  if (opcode.empty())
    return;
  for (i = 0; i < this->v_opcode.size(); i++)
    {
      if (!opcode.compare(this->v_opcode.at(i)))
	{
	  (this->*ptr_func[i])(opcode);
	  break;
	}
    }
  opcode.clear();
}

void        Gui::closeEvent(QCloseEvent *)
{

}

void	    Gui::beginGame()
{
  SingletonBucket *sgleBck = SingletonBucket::getInstance();

  if (!sgleBck)
    return;

  BeginGame       *begingame = sgleBck->getBeginGame();

  if (!begingame)
    return;
  this->label[LAB_CURRTIME]->setText(tr("Current Time -> ") +
				     QString::number(begingame->time));
  begingame = NULL;
}

void	   Gui::evt_click()
{
  int i;
  SingletonBucket *sgleBck = SingletonBucket::getInstance();

  if (!sgleBck)
    return;

  Click		  *click = sgleBck->getClick();
  std::list<int>::const_iterator it;

  if (!click)
    return;
  i = 0;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Updating player level and his inventory"));
  this->label[LAB_LEVEL]->setText(tr("Player Level -> ") + QString::number(click->level));
  for (it = click->inventory.begin(); it != click->inventory.end(); ++it)
    {
      this->lcdNumber[i]->display(*it);
      i++;
    }
  click = NULL;
}

void Gui::pnw(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n ,X ,Y ,O ,L ,N;
  QString msg;

  str >> opcode;
  str >> n;
  str >> X;
  str >> Y;
  str >> O;
  str >> L;
  str >> N;

  msg.append(tr("Information -> Player ") + tr(n.c_str()) + tr(" from team ") +
	     tr(N.c_str()) + tr(" oriented at ") + tr(O.c_str()) + tr (" is connected."));
  this->label[LAB_PLAYERPOS]->setText(tr("Player position X = ") + tr(X.c_str()) + tr(" , Y = ") + tr(Y.c_str()));
  this->label[LAB_LEVEL]->setText(tr("Player Level -> ") + tr(L.c_str()));
  this->label[LAB_INFORMATION]->setText(msg);
}

void Gui::ppo(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n, X, Y, O;
  QString msg;

  str >> opcode;
  str >> n;
  str >> X;
  str >> Y;
  str >> O;

  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") +
					tr(n.c_str()) + tr(" at orientation ") +
					tr(O.c_str()) + tr(" position set."));
  this->label[LAB_PLAYERPOS]->setText(tr("Player position X = ") + tr(X.c_str()) + tr(" , Y = ") + tr(Y.c_str()));
}

void Gui::pex(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n;

  str >> opcode;
  str >> n;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") + tr(n.c_str()) + tr(" expulse."));
}

void Gui::pbc(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n, tmp;
  QString qstr;
  int	lenght;

  str >> opcode;
  str >> n;
  lenght = str.tellg();
  if (lenght < static_cast<int>(str.str().size()))
    this->label[LAB_INFORMATION]->setText(tr("Information -> Broadcast Player ") + tr(n.c_str()) + tr(&data[lenght + 1]));
  else
    this->label[LAB_INFORMATION]->setText(tr("Information -> Broadcast Player ") + tr(n.c_str()) + tr(" No message."));
}

void Gui::pic(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, X, Y, L;
  QString msg;

  str >> opcode;
  str >> X;
  str >> Y;
  str >> L;

  msg.append("Information -> Incantation for ");
  this->label[LAB_PLAYERPOS]->setText(tr("Player position X = ") + tr(X.c_str()) + tr(" , Y = ") + tr(Y.c_str()));
  this->label[LAB_LEVEL]->setText(tr("Player Level -> ") + tr(L.c_str()));
  while (!str.eof())
    {
      str >> opcode;
      opcode += " ";
      msg.append(opcode.c_str());
    }
  this->label[LAB_INFORMATION]->setText(msg);
}

void Gui::pie(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, X, Y, R;
  QString msg;

  str >> opcode;
  str >> X;
  str >> Y;
  str >> R;

  this->label[LAB_PLAYERPOS]->setText(tr("Player position X = ") + tr(X.c_str()) + tr(" , Y = ") + tr(Y.c_str()));
  this->label[LAB_INFORMATION]->setText(tr("Information -> End of incantation with result ") + tr(R.c_str()));
}

void Gui::pfk(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n;

  str >> opcode;
  str >> n;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") + tr(n.c_str()) + tr(" makes an egg."));
}

void Gui::pdr(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n, i;

  str >> opcode;
  str >> n;
  str >> i;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") + tr(n.c_str()) + tr(" drops resource ") + tr(i.c_str()));
}

void Gui::pgt(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n, i;

  str >> opcode;
  str >> n;
  str >> i;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") + tr(n.c_str()) + tr(" takes resource ") + tr(i.c_str()));
}

void Gui::pdi(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, n;

  str >> opcode;
  str >> n;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Player ") + tr(n.c_str()) + tr(" is starved."));
}

void Gui::enw(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, e, n, X, Y;

  str >> opcode;
  str >> e;
  str >> n;
  str >> X;
  str >> Y;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Egg ") + tr(e.c_str()) +
					tr(" is created by Player ") +
					tr(n.c_str()) + tr(" at posX ") + tr(X.c_str()) +
					tr(" and posY ") + tr(Y.c_str()));
}

void Gui::eht(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, e;

  str >> opcode;
  str >> e;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Egg ") + tr(e.c_str()) + tr(" hatches."));
}

void Gui::ebo(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, e;

  str >> opcode;
  str >> e;
  this->label[LAB_INFORMATION]->setText(tr("Information -> A Player has connected for egg ") + tr(e.c_str()));
}

void Gui::edi(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, e;

  str >> opcode;
  str >> e;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Egg ") + tr(e.c_str()) + tr("newly created is starved."));
}

void Gui::sgt(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, T;

  str >> opcode;
  str >> T;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Current time is ") + tr(T.c_str()));
}

void Gui::sst(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, T;

  str >> opcode;
  str >> T;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Current time is modified and is now ") + tr(T.c_str()));
}

void Gui::seg(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode, N;

  str >> opcode;
  str >> N;
  this->label[LAB_INFORMATION]->setText(tr("Information -> Team ") + tr(N.c_str()) + tr(" lose the game. You are a Coward."));
}

void Gui::smg(std::string const &data)
{
  std::istringstream str(data);
  std::string opcode;
  QString	msg;

  str >> opcode;
  msg.append("Information -> Message from server % ");
  while (!str.eof())
    {
      str >> opcode;
      opcode += " ";
      msg.append(opcode.c_str());
    }
  msg.append("%");
  this->label[LAB_INFORMATION]->setText(msg);
}

void Gui::suc(std::string const &)
{
  this->label[LAB_INFORMATION]->setText(tr("Information -> Unknow command."));
}

void Gui::sbp(std::string const &)
{
  this->label[LAB_INFORMATION]->setText(tr("Information -> Bad Parameter for command."));
}
