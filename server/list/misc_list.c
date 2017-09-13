/*
** misc_list.c for <Misc list> in /home/barrau_a//c/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Apr 20 15:46:43 2011 adrien barrau
** Last update Thu Jun 23 21:11:49 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

void		list_dump(const t_list list,
			  void (*dump_fct)(const content_t cont))
{
  t_node *	cur = list;

  while (cur != NULL)
    {
      dump_fct(cur->cont);
      cur = cur->next;
    }
}

void		list_iter(t_list * list,
			  param_t p,
			  void (*iter_fct)(content_t * cont,
					   param_t param))
{
  t_node *	cur = *list;

  while (cur != NULL)
    {
      iter_fct(&(cur->cont), p);
      cur = cur->next;
    }
}

void		list_iter2(t_list * list,
			   param_t p1,
			   param_t p2,
			   void (*iter_fct)(content_t * cont,
					    param_t param1,
					    param_t param2))
{
  t_node *	cur = *list;

  while (cur != NULL)
    {
      iter_fct(&(cur->cont), p1, p2);
      cur = cur->next;
    }
}
