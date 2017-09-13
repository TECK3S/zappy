/*
** actions.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun  3 15:52:03 2011 adrien barrau
** Last update Sun Jul 10 21:23:37 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static void	increment_box(t_pos * box,
			      enum eDirection dir,
			      zappy * zap)
{
  switch (dir)
    {
    case UP:
      box->x = (box->x + 1) % zap->trantor_width;
      break;
    case LEFT:
      box->y -= 1;
      if (box->y < 0)
	box->y = zap->trantor_height - 1;
      break;
    case DOWN:
      box->x -= 1;
      if (box->x < 0)
	box->x = zap->trantor_width - 1;
      break;
    case RIGHT:
      box->y = (box->y + 1) % zap->trantor_height;
      break;
    default: break;
    }
}

static void	init_box(t_pos * cur_box,
			 int lvl,
			 client * cli,
			 zappy * zap)
{
  int		i = 0;
  t_pos		axis;

  axis.x = 1;
  axis.y = 1;
  if (cli->dir == UP || cli->dir == LEFT)
    axis.x = -1;
  if (cli->dir == UP || cli->dir == RIGHT)
    axis.y = -1;
  while (i < lvl)
    {
      cur_box->x = (cli->pos.x + axis.x) % zap ->trantor_width;
      if (cur_box->x < 0)
	cur_box->x = zap->trantor_width - 1;
      ++i;
    }
  i = 0;
  while (i < lvl)
    {
      cur_box->y = (cli->pos.y + axis.y) % zap->trantor_height;
      if (cur_box->y < 0)
	cur_box->y = zap->trantor_height - 1;
      ++i;
    }
}

static objects *	make_box_cpy(objects * proto)
{
  objects *	copy = NULL;
  int		i = 0;

  if ((copy = malloc(sizeof(*copy))) == NULL)
    return (NULL);
  while (i < 9)
    {
      copy->obj[i] = proto->obj[i];
      ++i;
    }
  return (copy);
}

void		act_voir(action_param param __attribute__((unused)),
			 client * cli,
			 zappy * zap)
{
  t_list	vision_obj = EMPTY;
  int		lvl = 1, i = 0;
  t_pos		cur_box;

  list_push_back(&vision_obj,
		 make_box_cpy(&(zap->trantor[(cli->pos.y
					     * zap->trantor_width) + cli->pos.x])));
  while (lvl <= cli->level)
    {
      init_box(&cur_box, lvl, cli, zap);
      i = 0;
      while (i < (2 * lvl + 1))
	{
	  list_push_back(&vision_obj,
			 make_box_cpy(&(zap->trantor[(cur_box.y
						      * zap->trantor_width) + cur_box.x])));
	  increment_box(&cur_box, cli->dir, zap);
	  ++i;
	}
      ++lvl;
    }
  answer(response_vision(&vision_obj), cli);
  list_clear(&vision_obj);
}
