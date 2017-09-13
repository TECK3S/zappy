/*
** get_client_dir.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 20:55:49 2011 rahman-serdar aysan
** Last update Thu Jun 23 19:25:26 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

char *	get_client_dir(enum eDirection dir)
{
  if (dir == UP)
    return ("N");
  if (dir == RIGHT)
    return ("E");
  if (dir == DOWN)
    return ("S");
  if (dir == LEFT)
    return ("O");
  return ("N");
}
