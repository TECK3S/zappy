/*
** generate.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:39:08 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:40:41 2011 rahman-serdar aysan
*/

#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "zappy.h"

void		generate_linemate(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * LINEMATE_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[LINEMATE] += 1;
      ++i;
    }
}

void		generate_deraumere(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * DERAUMERE_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[DERAUMERE] += 1;
      ++i;
    }
}

void		generate_sibur(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * SIBUR_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[SIBUR] += 1;
      ++i;
    }
}

void		generate_mendiane(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * MENDIANE_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[MENDIANE] += 1;
      ++i;
    }
}

void		generate_phiras(zappy * zap)
{
  int		i = 0, max = ((zap->trantor_height
			       * zap->trantor_width)
			      / 100) * PHIRAS_RATE;
  int		x, y;

  while (i < max)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[PHIRAS] += 1;
      ++i;
    }
}
