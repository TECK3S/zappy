/*
** push_list.c for <Push list> in /home/barrau_a//c/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Apr 20 15:45:08 2011 adrien barrau
** Last update Wed Apr 20 15:45:33 2011 adrien barrau
*/

#include <stdlib.h>
#include "list.h"

static t_node *	alloc_node(const content_t cont, t_node * next)
{
  t_node *	new_node = NULL;

  if ((new_node = malloc(sizeof(*new_node))) == NULL)
    return (NULL);
  new_node->cont = cont;
  new_node->next = next;
  return (new_node);
}

bool_t		list_push_front(t_list * list, const content_t cont)
{
  t_node *	new_node = NULL;

  if ((new_node = alloc_node(cont, *list)) == NULL)
    return (FALSE);
  *list = new_node;
  return (TRUE);
}

bool_t		list_push_back(t_list * list, const content_t cont)
{
  t_node *	new_node = NULL;
  t_node *	cur = *list;

  if ((new_node = alloc_node(cont, NULL)) == NULL)
    return (FALSE);
  if (*list == NULL)
    *list = new_node;
  else
    {
      while (cur->next != NULL)
	cur = cur->next;
      cur->next = new_node;
    }
  return (TRUE);
}

static void	insert_into(t_node ** prev,
			    t_node ** next,
			    t_node ** new_node,
			    t_list * li)
{
  if (*prev == NULL)
    *li = *new_node;
  else
    (*prev)->next = *new_node;
  (*new_node)->next = *next;
}

bool_t		list_push_at(t_list * list, const content_t cont, pos_t position)
{
  t_node *	new_node = NULL;
  t_node *	prev = NULL;
  t_node *	cur = *list;
  pos_t		cur_pos = 1;

  if ((new_node = alloc_node(cont, NULL)) == NULL)
    return (FALSE);
  if (*list == NULL)
    *list = new_node;
  else
    {
      while (cur->next != NULL)
	{
	  if (cur_pos++ == position)
	    {
	      insert_into(&prev, &cur, &new_node, list);
	      break;
	    }
	  prev = cur;
	  cur = cur->next;
	}
      if (cur_pos != position)
	cur->next = new_node;
    }
  return (TRUE);
}
