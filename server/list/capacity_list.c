/*
** capacity_list.c for <Capacity list> in /home/barrau_a//c/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Apr 20 15:44:30 2011 adrien barrau
** Last update Wed Apr 20 15:44:50 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

size_t	list_size(const t_list list)
{
  size_t	s = 0;
  t_node *	cur = list;

  while (cur != NULL)
    {
      cur = cur->next;
      ++s;
    }
  return (s);
}

bool_t	list_empty(const t_list list)
{
  if (list == NULL)
    return (TRUE);
  return (FALSE);
}
