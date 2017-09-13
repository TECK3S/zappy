/*
** find_team.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:42:54 2011 rahman-serdar aysan
** Last update Sun Jul 10 20:43:23 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

bool_t	find_team(const content_t ref, const content_t cont)
{
  if (strcmp((char *)ref, (char *)cont) == 0)
    return (TRUE);
  return (FALSE);
}
