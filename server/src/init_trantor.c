/*
** init_trantor.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 21 13:33:10 2011 adrien barrau
** Last update Sun Jul 10 21:42:06 2011 rahman-serdar aysan
*/

#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "zappy.h"

static inline void	generate_thystame(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * THYSTAME_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[THYSTAME] += 1;
      ++i;
    }
}

static inline void	generate_food(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * FOOD_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[FOOD] += 1;
      ++i;
    }
}

static void (*generate_res[])(zappy *)=
{
  &generate_linemate,
  &generate_deraumere,
  &generate_sibur,
  &generate_mendiane,
  &generate_phiras,
  &generate_thystame,
  &generate_food,
  NULL
};

int	init_trantor(zappy * zap)
{
  int	errcode = NO_ERR_CODE, i = 0;

  if ((zap->trantor =
       malloc(zap->trantor_width
	      * zap->trantor_height
	      * sizeof(*zap->trantor))) == NULL)
    errcode = MEMORY_ERR_CODE;
  memset(zap->trantor, 0, zap->trantor_width * zap->trantor_height
	 * sizeof(*zap->trantor));
  if (!errcode)
    {
      while (generate_res[i])
	{
	  generate_res[i](zap);
	  ++i;
	}
    }
  return (errcode);
}
