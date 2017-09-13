/*
** get_client.c for get_client.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Fri Jun  3 19:37:54 2011 eugene-valentin ngontang-tchiadjie
** Last update Thu Jun 23 20:34:15 2011 adrien barrau
*/

#include "zappy.h"
#include "socket.h"

bool_t	get_client_by_socket(const content_t ref, const content_t cur)
{
  if (((client *)ref)->socket == ((client *)cur)->socket)
    return (TRUE);
  return (FALSE);
}

bool_t	get_client_by_num(const content_t ref, const content_t cur)
{
  if (((client *)ref)->num == ((client *)cur)->num)
    return (TRUE);
  return (FALSE);
}
