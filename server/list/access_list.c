/*
** access_list.c for <Access list> in /home/barrau_a//c/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Apr 20 15:43:32 2011 adrien barrau
** Last update Thu Jun 23 21:03:58 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

content_t	list_front(const t_list list)
{
  if (list != NULL)
    return (list->cont);
  return (NULL);
}

content_t	list_back(const t_list list)
{
  t_node *	cur = list;

  if (list != NULL)
    {
      while (cur->next != NULL)
	cur = cur->next;
      return (cur->cont);
    }
  return (NULL);
}

content_t	list_at(const t_list list, pos_t position)
{
  t_node *	cur = list;
  pos_t		cur_pos = 1;

  if (list != NULL)
    {
      while (cur != NULL)
	{
	  if (cur_pos == position)
	    return (cur->cont);
	  cur = cur->next;
	  ++cur_pos;
	}
    }
  return (NULL);
}

content_t	list_find(const t_list list,
			  const content_t ref,
			  bool_t (*cmp_cont)(const content_t cont1,
					     const content_t cont2))
{
  t_node *	cur = list;

  if (list != NULL)
    {
      while (cur != NULL)
	{
	  if (cmp_cont(ref, cur->cont) == TRUE)
	    return (cur->cont);
	  cur = cur->next;
	}
    }
  return (NULL);
}

content_t	list_find2(const t_list list,
			   const content_t ref,
			   param_t p,
			   bool_t (*cmp_cont)(const content_t cont1,
					      const content_t cont2,
					      param_t p))
{
  t_node *	cur = list;

  if (list != NULL)
    {
      while (cur != NULL)
	{
	  if (cmp_cont(ref, cur->cont, p) == TRUE)
	    return (cur->cont);
	  cur = cur->next;
	}
    }
  return (NULL);
}
