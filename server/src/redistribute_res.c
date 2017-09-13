/*
** redistribute_res.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 22:21:07 2011 rahman-serdar aysan
** Last update Sun Jul 10 22:22:53 2011 rahman-serdar aysan
*/

#include <stdlib.h>
#include "zappy.h"

void		redistribute_linemate(zappy * zap)
{
  int		x, y;

  if (rand() % LINEMATE_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[LINEMATE] += 1;
    }
}

void		redistribute_deraumere(zappy * zap)
{
  int		x, y;

  if (rand() % DERAUMERE_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[DERAUMERE] += 1;
    }
}

void		redistribute_sibur(zappy * zap)
{
  int		x, y;

  if (rand() % SIBUR_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[SIBUR] += 1;
    }
}

void		redistribute_mendiane(zappy * zap)
{
  int		x, y;

  if (rand() % MENDIANE_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[MENDIANE] += 1;
    }
}

void		redistribute_phiras(zappy * zap)
{
  int		x, y;

  if (rand() % PHIRAS_RATE == 0)
    {
      x = rand() % zap->trantor_width;
      y = rand() % zap->trantor_height;
      zap->trantor[(y * zap->trantor_width) + x].obj[PHIRAS] += 1;
    }
}
