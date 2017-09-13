/*
** get_sound.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 21:24:16 2011 rahman-serdar aysan
** Last update Sun Jul 10 21:25:17 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline int	get_sound_from_right(t_float_pos * sender, float ord,
					     t_float_pos * vect, float k)
{
  float y = sender->y + (k * vect->y);

  if (y >= ord && y < ord + 0.25)
    return (8);
  if (y >= ord + 0.25 && y < ord + 0.75)
    return (7);
  if (y >= ord + 0.75 && y <= ord + 1)
    return (6);
  else
    return (-1);
}

static inline int	get_sound_from_left(t_float_pos * sender, float ord,
					    t_float_pos * vect, float k)
{
  float y = sender->y + (k * vect->y);

  if (y >= ord && y < ord + 0.25)
    return (2);
  if (y >= ord + 0.25 && y < ord + 0.75)
    return (3);
  if (y >= ord + 0.75 && y <= ord + 1)
    return (4);
  else
    return (-1);
}

static inline int	get_sound_from_up(t_float_pos * sender, float absc,
					  t_float_pos * vect, float k)
{
  float x = sender->x + (k * vect->x);

  if (x >= absc && x < absc + 0.25)
    return (2);
  if (x >= absc + 0.25 && x < absc + 0.75)
    return (1);
  if (x >= absc + 0.75 && x <= absc + 1)
    return (8);
  else
    return (-1);
}

static inline int	get_sound_from_down(t_float_pos * sender, float absc,
					    t_float_pos * vect, float k)
{
  float x = sender->x + (k * vect->x);

  if (x >= absc && x < absc + 0.25)
    return (4);
  if (x >= absc + 0.25 && x < absc + 0.75)
    return (5);
  if (x >= absc + 0.75 && x <= absc + 1)
    return (6);
  else
    return (-1);
}

int	get_sound(t_float_pos * sender,
				  t_float_pos * receiver,
				  enum eDirection dir_rec)
{
  int		dir_sound = -1;
  t_float_pos	vect;

  vect.x = receiver->x - sender->x;
  vect.y = receiver->y - sender->y;
  if (sender->x == receiver->x && sender->y == receiver->y)
    return (0);
  if (sender->x >= receiver->x)
    dir_sound = get_sound_from_right(sender, receiver->y - 0.5,
				     &vect, ((receiver->x + 0.5 - sender->x) / vect.x));
  else
    dir_sound = get_sound_from_left(sender, receiver->y - 0.5,
				    &vect, ((receiver->x - 0.5 - sender->x) / vect.x));
  if (dir_sound == -1 && sender->y >= receiver->y)
    dir_sound = get_sound_from_down(sender, receiver->x - 0.5,
				    &vect, ((receiver->y + 0.5 - sender->y) / vect.y));
  else if (dir_sound == -1)
    dir_sound = get_sound_from_up(sender, receiver->x - 0.5,
				  &vect, ((receiver->y - 0.5 - sender->y) / vect.y));
  dir_sound = (((dir_sound - 1) + (2 * (int)dir_rec)) % 8) + 1;
  return (dir_sound);
}
