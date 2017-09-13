/*
** fill_buffer.c for fill_buffer.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Fri Jun  3 18:51:10 2011 eugene-valentin ngontang-tchiadjie
** Last update Tue Jul  5 19:29:27 2011 adrien barrau
*/

#include <string.h>
#include "socket.h"

void		fill_buffer(buffer * b, char * buf, int n)
{
  int		rest;
  int		remind;

  rest = MAX_BUF_SIZE - b->end;
  if ((rest - n) >= 0)
    {
      memcpy(b->data + b->end, buf, n);
      b->end += n;
    }
  else
    {
      memcpy(b->data + b->end, buf, rest);
      remind = ((n - rest) >= (b->begin - 1) ? (b->begin -1) : (n - rest));
      if (remind >= 0)
	{
	  memcpy(b->data, buf + rest, remind);
	  b->end = remind;
	}
    }
}
