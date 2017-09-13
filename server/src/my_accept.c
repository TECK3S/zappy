/*
** my_accept.c for my_accept.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/doc/includes
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Jun  2 13:36:07 2011 eugene-valentin ngontang-tchiadjie
** Last update Tue Jul  5 19:30:18 2011 adrien barrau
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "socket.h"

int		my_accept(int s, struct sockaddr *addr,
			  socklen_t *addrlen)
{
  int		error = 0;
  int		fs;

  if ((fs = accept(s, addr, addrlen)) == -1
      && (error = errno) != ECONNABORTED
      && errno != EINTR)
    {
      fprintf (stderr, "[System] Failed in accept\n");
      return (-1);
    }
  if (error == ECONNABORTED)
    {
      fprintf(stderr,
	      "[System] A connection closed while waiting on the listen queue\n");
      return (-1);
    }
  else
    if (error == EINTR)
      fs = my_accept(s, addr, addrlen);
  return (fs);
}
