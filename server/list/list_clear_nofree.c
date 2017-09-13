/*
** list_clear_nofree.c for <List> in /home/barrau_a//c/zappy_delamort/server/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun 23 21:09:53 2011 adrien barrau
** Last update Thu Jun 23 21:10:05 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

void		list_clear_nofree(t_list * list)
{
  t_node *	to_pop = *list;
  t_node *	prev = to_pop;

  while (to_pop != NULL)
    {
      to_pop = to_pop->next;
      free(prev);
      prev = to_pop;
    }
  *list = NULL;
}
