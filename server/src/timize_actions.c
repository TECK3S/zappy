/*
** timize_actions.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 17 15:30:54 2011 adrien barrau
** Last update Sun Jul 10 18:31:36 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "zappy.h"
#include "client.h"

static inline double		get_sec_time()
{
  struct timeval	t;
  double		sec = 0;

  if (gettimeofday(&t, NULL) != -1)
    {
      sec = t.tv_sec;
      sec += t.tv_usec / 1000000.0;
    }
  return (sec);
}

static inline int	life_management(client * cli, pack_time_t * pack_time)
{
  cli->life -= pack_time->t;
  if (cli->life <= 0)
    {
      printf("[System] A player from team %s is dead\n", cli->team_name);
      answer(response_mort(), cli);
      cli->state = OVER;
      destroy_full_egg(pack_time->zap, cli->team_name);
      return (0);
    }
  cli->inventory[0] = (cli->life / (126 / pack_time->zap->time_delay)) + 1;
  return (1);
}

static inline void	do_timization(content_t * cont, param_t p)
{
  client *	cli = (client *)*cont;
  pack_time_t *	pack_time = (pack_time_t *)p;

  if (cli->state == PLAYING)
    {
      if (!life_management(cli, pack_time))
	return;
      if (cli->current_act != cli->last_act)
	{
	  cli->action[cli->current_act]->time -= pack_time->t;
	  if (cli->action[cli->current_act]->time <= 0.0)
	    {
	      exec_action_playing(cli->action[cli->current_act],
				  cli, pack_time->zap);
	      cli->current_act = (cli->current_act + 1) % 11;
	    }
	}
    }
}

static inline void	hatch_egg(content_t * cont, param_t p)
{
  egg *		the_egg = (egg *)*cont;
  pack_time_t *	pack_time = (pack_time_t *)p;

  if (the_egg->state == LAID)
    {
      the_egg->time -= pack_time->t;
      if (the_egg->time <= 0)
	{
	  printf("[System] An egg has just hatched for the team %s\n",
		 the_egg->team_name);
	  the_egg->state = HATCHED;
	}
    }
}

void		timize_actions(zappy * zap)
{
  static double	old_time = 0;
  double	now_time = get_sec_time();
  pack_time_t	pack_time;

  if (old_time == 0)
    old_time = now_time;
  pack_time.t = now_time - old_time;
  pack_time.zap = zap;
  list_iter(&zap->client_list, &pack_time, &do_timization);
  list_iter(&zap->eggs, &pack_time, &hatch_egg);
  old_time = now_time;
}
