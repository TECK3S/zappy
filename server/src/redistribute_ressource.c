/*
** redistribute_ressource.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 21 16:37:51 2011 adrien barrau
** Last update Sun Jul 10 22:23:12 2011 rahman-serdar aysan
*/

#include <stdlib.h>
#include "zappy.h"

static inline void	redistribute_food(zappy * zap)
{
  int		i = 0, x = 0, y = 0;
  int		max = (rand() % FOOD_RATE) / (FOOD_RATE / 4);

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[FOOD] += 1;
      ++i;
    }
}

static inline void	redistribute_thystame(zappy * zap)
{
  int		x, y;

  if (rand() % THYSTAME_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[THYSTAME] += 1;
    }
}

static void	(*redistribute[])(zappy *)=
{
  &redistribute_food,
  &redistribute_linemate,
  &redistribute_deraumere,
  &redistribute_sibur,
  &redistribute_mendiane,
  &redistribute_phiras,
  &redistribute_thystame
};

void	redistribute_ressource(zappy * zap, int ressource)
{
  if (ressource >= 0
      && ressource < THYSTAME)
    redistribute[ressource](zap);
}
