/*
** win_condition.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Jun 19 17:05:02 2011 adrien barrau
** Last update Tue Jul  5 21:36:10 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "zappy.h"
#include "client.h"

static inline void	count_lvl8(content_t * cont, param_t p)
{
  int		i = 0;
  win_count_t**	count = (win_count_t **)p;
  client *	cli = (client *)*cont;

  if (cli->state == PLAYING
      && cli->level == 8)
    {
      while ((*count)[i].name)
	{
	  if (strcmp((*count)[i].name, cli->team_name) == 0)
	    {
	      (*count)[i].count += 1;
	      break;
	    }
	  ++i;
	}
    }
}

static inline void	init_counter(content_t * cont, param_t p)
{
  win_count_t**	count = (win_count_t **)p;
  char *	name = (char *)*cont;
  int		i = 0;

  while ((*count)[i].name)
    ++i;
  (*count)[i].name = name;
}

static inline char *	is_team_win(zappy * zap)
{
  win_count_t *	win_count = NULL;
  size_t	size = list_size(zap->team_name) + 1, i = 0;
  char *	winner = NULL;

  win_count = malloc(size * sizeof(*win_count));
  while (i < size)
    {
      win_count[i].name = NULL;
      win_count[i].count = 0;
      ++i;
    }
  list_iter(&zap->team_name, &win_count, &init_counter);
  list_iter(&zap->client_list, &win_count, &count_lvl8);
  i = 0;
  while (i < size)
    {
      if (win_count[i].count >= 6)
	winner = win_count[i].name;
      ++i;
    }
  free(win_count);
  return (winner);
}

static inline void	contact_players(zappy * zap, char * winner)
{
  void	send_win(content_t * cont, param_t p)
  {
    client *	cli = (client *)*cont;

    answer(response_gagner((char *)p), cli);
    cli->state = OVER;
  }

  list_iter(&zap->client_list, winner, &send_win);
  printf(WIN_MSG, winner);
}

void		win_condition(zappy * zap)
{
  char *	winner = NULL;

  if ((winner = is_team_win(zap)) != NULL)
    contact_players(zap, winner);
}
