/*
** zappy.h for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun  1 10:39:21 2011 adrien barrau
** Last update Sun Jul 10 22:54:47 2011 rahman-serdar aysan
*/

#ifndef ZAPPY_H__
# define ZAPPY_H__

#include <sys/epoll.h>
#include <sys/types.h>
#include "list.h"
#include "errors.h"
#include "client.h"

# define	ZAPPY_USAGE		("Usage: ./zappy -p PORT -x WIDTH -y HEIGHT -n TEAM [TEAM...] -c SLOTS -t TIME")

# define	MOTD			("Welcome to our zappy server, We did it for the porn !")

# define	DEFAULT_PORT		(1024)
# define	DEFAULT_WIDTH		(50)
# define	DEFAULT_HEIGHT		(50)
# define	DEFAULT_TEAM1		("Toupoutou")
# define	DEFAULT_TEAM2		("Babylone")
# define	DEFAULT_TEAM3		("PornSexHard")
# define	DEFAULT_TEAM4		("W33d")
# define	DEFAULT_TEAM5		("DarkSalutation")
# define	DEFAULT_SLOT_PER_TEAM	(5)
# define	DEFAULT_TIME_DELAY	(100)

# define	MAX_TRANTOR_WIDTH	(1000)
# define	MAX_TRANTOR_HEIGHT	(1000)
# define	MAX_SLOT_PER_TEAM	(10)
# define	MAX_SIMULTANEOUS_CON	(256)

# define	UNUSED_OBJ		("")
# define	PLAYER_OBJ		("joueur")
# define	FOOD_OBJ		("nourriture")
# define	LINEMATE_OBJ		("linemate")
# define	DERAUMERE_OBJ		("deraumere")
# define	SIBUR_OBJ		("sibur")
# define	MENDIANE_OBJ		("mendiane")
# define	PHIRAS_OBJ		("phiras")
# define	THYSTAME_OBJ		("thystame")
# define	EGGS_OBJ		("oeuf")

# define	WIN_MSG			("[System] Team %s win the game ! The game is over, everybody should deconnect\n")
# define	PURGE_MSG		("[System] A player just leaved, the drone is going onto the purgatory\n")
# define	JOIN_PURGE_MSG		("[System] A new player is now controlling an inactive drone of team %s\n")

# define	LINEMATE_RATE		(18)
# define	DERAUMERE_RATE		(16)
# define	SIBUR_RATE		(20)
# define	MENDIANE_RATE		(10)
# define	PHIRAS_RATE		(12)
# define	THYSTAME_RATE		(2)
# define	FOOD_RATE		(30)

# define	false		(0)
# define	true		(!false)

typedef		int		bool;

enum eObjectType
  {
    PLAYER = 0,
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    EGGS
  };

typedef struct
{
  int	obj[9];
}	objects;

typedef struct
{
  int		socket;
  t_list	client_list;
  objects *	trantor;
  size_t	trantor_width;
  size_t	trantor_height;
  size_t	slot_per_team;
  unsigned int	time_delay;
  t_list	team_name;
  int		max_clients;
  int		current_clients;
  int		player_numerotation;
  t_list	eggs;
  int		egg_numerotation;
  t_list	purgatory;
}		zappy;

typedef struct
{
  double	t;
  zappy *	zap;
}		pack_time_t;

/*		parse_connected_cmd.c		*/
t_action *	parse_connected_cmd(char * cmd);

/*		parse_playing_cmd.c		*/
t_action *	parse_playing_cmd(char * cmd, zappy * zap);
int		exec_action_playing(t_action * action, client * host, zappy * zap);

/*		parse_graphic_cmd.c		*/
t_pos *		get_pos(char * str);
t_action *	parse_graphic_cmd(char * cmd);

/*		action_playing.c		*/
int		action_playing(zappy * zap, client * cli);

/*		action_cmd.c			*/
t_action *	cmd_avance(char * cmd, zappy * zap);
t_action *	cmd_droite(char * cmd, zappy * zap);
t_action *	cmd_gauche(char * cmd, zappy * zap);
t_action *	cmd_voir(char * cmd, zappy * zap);
t_action *	cmd_inventaire(char * cmd, zappy * zap);

/*		action_cmd_suite.c		*/
t_action *	cmd_prend(char * cmd, zappy * zap);
t_action *	cmd_pose(char * cmd, zappy * zap);
t_action *	cmd_incantation(char * cmd, zappy * zap);
t_action *	cmd_fork(char * cmd, zappy * zap);

/*		cmd_protocol.c		*/
t_action *	cmd_msz(char * cmd);
t_action *	cmd_bct(char * cmd);
t_action *	cmd_mct(char * cmd);
t_action *	cmd_tna(char * cmd);
t_action *	cmd_ppo(char * cmd);

/*		cmd_protocol_suite.c		*/
t_action *	cmd_plv(char * cmd);
t_action *	cmd_pin(char * cmd);
t_action *	cmd_sgt(char * cmd);
t_action *	cmd_sst(char * cmd);

/*		redistribute_res.c		*/
void		redistribute_linemate(zappy * zap);
void		redistribute_deraumere(zappy * zap);
void		redistribute_sibur(zappy * zap);
void		redistribute_mendiane(zappy * zap);
void		redistribute_phiras(zappy * zap);

/*		get_sound.c			*/
int		get_sound(t_float_pos * sender, t_float_pos * receiver, enum eDirection dir_rec);

/*		generate.c			*/
void		generate_linemate(zappy * zap);
void		generate_deraumere(zappy * zap);
void		generate_sibur(zappy * zap);
void		generate_mendiane(zappy * zap);
void		generate_phiras(zappy * zap);

/*		act_avance.c			*/
void		update_pos(int * pos, int off, int max);

/*		action_connected.c		*/
int		action_connected(zappy * zap, client * cli);

/*		action_graphic.c		*/
int		action_graphic(zappy * zap, client * cli);

/*		parse_args.c			*/
int		parse_args(int ac, char ** av, zappy * zap, int * port);

/*		zappy_server.c			*/
int		zappy_server(zappy * zap, int port);

/*		zappy_manager.c			*/
int		get_events(zappy * zap, struct epoll_event * events, struct epoll_event * ev, int nfds, int epfd);

/*		get_client.c			*/
bool_t		get_client_by_socket(const content_t ref, const content_t cur);
bool_t		get_client_by_num(const content_t ref, const content_t cur);

/*		get_command.c			*/
int		get_command(zappy * zap, int sock);

/*		cmd_response.c			*/
char *		response_ok();
char *		response_ko();
char *		response_vision(t_list * vision_list);

/*		cmd_response_suite.c		*/
char *		response_objets(int * objs);
char *		response_deplacement(int position);
char *		response_message(char * msg, int position);
char *		response_elevation(int level);
char *		response_slot(int slot_dispo, int slot_total);

/*		response_to_str.c		*/
char *		response_mort();
char *		response_bienvenue();
char *		response_gagner(char * team_name);
void		answer(char * msg, client * cli);

/*		act_playing.c			*/
void		act_avance(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_droite(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_gauche(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_voir(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_inventaire(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_prend(action_param param, client * cli, zappy * zap);
void		act_pose(action_param param, client * cli, zappy * zap);
void		act_expulse(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_broadcast(action_param param, client * cli, zappy * zap);
void		act_incantation(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_fork(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_connect_nbr(action_param param __attribute__((unused)), client * cli, zappy * zap);

/*		act_graphic.c			*/
void		act_msz(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_bct(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_mct(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_tna(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_ppo(action_param param __attribute__((unused)), client * cli, zappy * zap __attribute__((unused)));
void		act_plv(action_param param, client * cli, zappy * zap);
void		act_pin(action_param param, client * cli, zappy * zap);
void		act_sgt(action_param param __attribute__((unused)), client * cli, zappy * zap);
void		act_sst(action_param param, client * cli, zappy * zap);
void		act_pnw(client * host, client * gui);
void		act_pex(client * host, client * gui);
void		act_pbc(client * host, client * gui, char * smg);
void		act_pic(client * host, t_list * player_num_list, client * gui);
void		act_pie(t_pos * pos, char R, client * gui);
void		act_pfk(client * host, client * gui);
void		act_pdr(client * host, client * gui, int i);
void		act_pgt(client * host, client * gui, int i);
void		act_pdi(client * host, client * gui);
void		act_enw(egg * e, client * host, client * gui);
void		act_eht(egg * e, client * gui);
void		act_ebo(egg * e, client * gui);
void		act_edi(egg * e, client * gui);
void		act_seg(char * team_name, client * gui);
void		act_smg(char * smg, client * gui);
void		act_sbp(client * gui);

/*		act_connected.c			*/
void		act_equipe(action_param param, client * cli, zappy * zap);
void		act_graphic(action_param param, client * cli, zappy * zap);
bool_t		find_team(const content_t ref, const content_t cont);

/*		timize_actions.c		*/
void		timize_actions(zappy * zap);

/*		win_condition.c			*/
void		win_condition(zappy * zap);

/*		init_trantor.c			*/
int		init_trantor(zappy * zap);

/*		redistribute_ressource.c	*/
void		redistribute_ressource(zappy * zap, int ressource);

/*		init_sigaction.c		*/
int		init_sigaction();

/*		purge_client.c			*/
int		purge_client(zappy * zap,
			     struct epoll_event * event,
			     struct epoll_event * ev,
			     int epfd);
int		join_from_purgatory(client * cli, zappy * zap, char * name);

/*		get_client_dir.c		*/
char *		get_client_dir(enum eDirection dir);

/*		egg.c				*/
int		join_from_egg(client * cli, zappy * zap, char * team_name);
void		destroy_full_egg(zappy * zap, char * team_name);

/*		free_all.c			*/
void		free_all(zappy * zap, struct epoll_event * events);

#endif /* !ZAPPY_H__ */
