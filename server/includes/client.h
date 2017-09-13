/*
** client.h for client.h in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/includes
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Wed Jun  1 15:46:51 2011 eugene-valentin ngontang-tchiadjie
** Last update Thu Jun 23 20:02:37 2011 adrien barrau
*/

#ifndef CLIENT_H__
# define CLIENT_H__

#define MAX_BUF_SIZE	(1024)

# define NO_PARAM	(NULL)

# define AVANCE_CMD		("avance")
# define DROITE_CMD		("droite")
# define GAUCHE_CMD		("gauche")
# define VOIR_CMD		("voir")
# define INVENTAIRE_CMD		("inventaire")
# define PREND_CMD		("prend")
# define POSE_CMD		("pose")
# define EXPULSE_CMD		("expulse")
# define BROADCAST_CMD		("broadcast")
# define INCANTATION_CMD	("incantation")
# define FORK_CMD		("fork")
# define CONNECT_NBR_CMD	("connect_nbr")
# define EQUIPE_CMD		("equipe")
# define GRAPHIC_CMD		("graphic")

# define AVANCE_ID		(0x01)
# define DROITE_ID		(0x02)
# define GAUCHE_ID		(0x03)
# define VOIR_ID		(0x04)
# define INVENTAIRE_ID		(0x05)
# define PREND_ID		(0x06)
# define POSE_ID		(0x07)
# define EXPULSE_ID		(0x08)
# define BROADCAST_ID		(0x09)
# define INCANTATION_ID		(0x0A)
# define FORK_ID		(0x0B)
# define CONNECT_NBR_ID		(0x0C)

# define MSZ_ID			(0x01)
# define BCT_ID			(0x02)
# define MCT_ID			(0x03)
# define TNA_ID			(0x04)
# define PPO_ID			(0x05)
# define PLV_ID			(0x06)
# define PIN_ID			(0x07)
# define SGT_ID			(0x08)
# define SST_ID			(0x09)

# define EQUIPE_ID		(0x01)
# define GRAPHIC_ID		(0x02)

# define OK_RESPONSE_CMD		("ok")
# define KO_RESPONSE_CMD		("ko")

# define VISION_RESPONSE_CMD		("vision")
# define OBJETS_RESPONSE_CMD		("objets")
# define DEPLACEMENT_RESPONSE_CMD	("deplacement")
# define MESSAGE_RESPONSE_CMD		("message")
# define ELEVATION_RESPONSE_CMD		("elevation")
# define SLOT_RESPONSE_CMD		("slot")
# define MORT_RESPONSE_CMD		("mort")
# define BIENVENUE_RESPONSE_CMD		("bienvenue")
# define GAGNER_RESPONSE_CMD		("gagner")

# define MSZ_CMD			("msz")
# define BCT_CMD			("bct")
# define MCT_CMD			("mct")
# define TNA_CMD			("tna")
# define PPO_CMD			("ppo")
# define PLV_CMD			("plv")
# define PIN_CMD			("pin")
# define SGT_CMD			("sgt")
# define SST_CMD			("sst")

# define MSZ_RESPONSE_CMD		("msz")
# define BCT_RESPONSE_CMD		("bct")
# define MCT_RESPONSE_CMD		("mct")
# define TNA_RESPONSE_CMD		("tna")
# define PPO_RESPONSE_CMD		("ppo")
# define PLV_RESPONSE_CMD		("plv")
# define PIN_RESPONSE_CMD		("pin")
# define SGT_RESPONSE_CMD		("sgt")
# define SST_RESPONSE_CMD		("sgt")
# define PNW_RESPONSE_CMD		("pnw")
# define PEX_RESPONSE_CMD		("pex")
# define PBC_RESPONSE_CMD		("pbc")
# define PIC_RESPONSE_CMD		("pic")
# define PIE_RESPONSE_CMD		("pie")
# define PFK_RESPONSE_CMD		("pfk")
# define PDR_RESPONSE_CMD		("pdr")
# define PGT_RESPONSE_CMD		("pgt")
# define PDI_RESPONSE_CMD		("pdi")
# define ENW_RESPONSE_CMD		("enw")
# define EHT_RESPONSE_CMD		("eht")
# define EBO_RESPONSE_CMD		("ebo")
# define EDI_RESPONSE_CMD		("edi")
# define SEG_RESPONSE_CMD		("seg")
# define SMG_RESPONSE_CMD		("smg")
# define SBP_RESPONSE_CMD		("sbp")

typedef void *		action_param;

typedef struct
{
  int	x;
  int	y;
}	t_pos;

typedef struct
{
  float	x;
  float	y;
}	t_float_pos;

enum eDirection
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
  };

typedef struct
{
  unsigned int	id;
  action_param	param;
  double	time;
}		t_action;

typedef struct
{
  char		data[MAX_BUF_SIZE];
  int		begin;
  int		end;
}		buffer;

enum eState
  {
    CONNECTED = 0,
    GRAPHIC,
    PLAYING,
    OVER
  };

typedef struct 
{
  int			socket;
  char *		team_name;
  t_pos			pos;
  t_action *		action[11];
  int			current_act;
  int			last_act;
  int			num;
  int			inventory[7];
  enum eState		state;
  enum eDirection	dir;
  int			level;
  buffer		read_buffer;
  buffer		write_buffer;
  double		life;
}			client;

typedef struct
{
  client *	cli;
  char *	msg;
}		pack_msg;

typedef struct
{
  client *	cli;
  int		checker;
}		lvl_checker;

typedef struct
{
  int		player;
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		level_up;

typedef struct
{
  char *	name;
  int		count;
}		win_count_t;

enum eEggState
  {
    LAID = 0,
    HATCHED,
    FULL
  };

typedef struct
{
  int			num;
  char *		team_name;
  double		time;
  t_pos			pos;
  enum eEggState	state;
}			egg;


#endif /* CLIENT_H__ */
