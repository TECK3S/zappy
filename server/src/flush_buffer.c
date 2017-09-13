/*
** flush_buffer.c for flush_buffer.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Fri Jun  3 19:51:08 2011 eugene-valentin ngontang-tchiadjie
** Last update Fri Jun 24 00:45:03 2011 adrien barrau
*/

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "socket.h"

int		flush_buffer(buffer * b, char * buf, int fd, int size)
{
  int		n;
  int		error = 0;
  int		rest;

  n = write(fd, buf, size);
  if ((n < 0) && ((error = errno) != EINTR))
    return (-1);
  else if (error == EINTR)
    flush_buffer(b, buf, fd, size);
  else
    {
      rest = MAX_BUF_SIZE - b->begin;
      if ((rest - n) >= 0)
	b->begin += n;
      else
	b->begin = n - rest;
    }
  return (n);
}
