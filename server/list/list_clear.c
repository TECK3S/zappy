/*
** list_clear.c for <List> in /home/barrau_a//c/zappy_delamort/server/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun 23 21:09:11 2011 adrien barrau
** Last update Thu Jun 23 21:09:24 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

void		list_clear(t_list * list)
{
  t_node *	to_pop = *list;
  t_node *	prev = to_pop;

  while (to_pop != NULL)
    {
      to_pop = to_pop->next;
      free(prev->cont);
      free(prev);
      prev = to_pop;
    }
  *list = NULL;
}
