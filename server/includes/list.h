/*
** list.h for <LIST> in /home/barrau_a//c/list
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Apr 19 14:12:03 2011 adrien barrau
** Last update Sun Jul 10 16:59:39 2011 adrien barrau
*/

#ifndef LIST_H_
# define LIST_H_

#include <sys/types.h>

# define	EMPTY		(NULL)

typedef		void *		content_t;
typedef		unsigned int	pos_t;
typedef		void *		param_t;

typedef			struct s_node
{
  content_t		cont;
  struct s_node *	next;
}			t_node;

typedef		t_node *	t_list;

# define	TRUE		(42)
# define	FALSE		(!TRUE)
typedef		int		bool_t;

/*	Capacity functions	*/
size_t		list_size(const t_list list);
bool_t		list_empty(const t_list list);

/*	Access functions	*/
content_t	list_front(const t_list list);
content_t	list_back(const t_list list);
content_t	list_at(const t_list list, pos_t position);
content_t	list_find(const t_list list, const content_t ref, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2));
content_t	list_find2(const t_list list, const content_t ref, param_t p, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2, param_t p));

/*	Push functions		*/
bool_t		list_push_front(t_list * list, const content_t cont);
bool_t		list_push_back(t_list * list, const content_t cont);
bool_t		list_push_at(t_list * list, const content_t cont, pos_t position);

/*	Pop functions		*/
/*	The content is freed	*/
bool_t		list_pop_front(t_list * list);
bool_t		list_pop_back(t_list * list);
bool_t		list_pop_at(t_list * list, pos_t position);
bool_t		list_remove(t_list * list, const content_t ref, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2));
bool_t		list_remove2(t_list * list, const content_t ref, param_t p, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2, param_t p));
void		list_clear(t_list * list);

/*	Pop functions		*/
/*    No free is performed	*/
bool_t		list_pop_nofree_front(t_list * list);
bool_t		list_pop_nofree_back(t_list * list);
bool_t		list_pop_nofree_at(t_list * list, pos_t position);
bool_t		list_remove_nofree(t_list * list, const content_t ref, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2));
bool_t		list_remove_nofree2(t_list * list, const content_t ref, param_t p, bool_t (*cmp_cont)(const content_t cont1, const content_t cont2, param_t p));
void		list_clear_nofree(t_list * list);

/*	Misc functions		*/
void		list_dump(const t_list list, void (*dump_fct)(const content_t cont));
void		list_iter(t_list * list, param_t p, void (*iter_fct)(content_t * cont, param_t param));
void		list_iter2(t_list * list, param_t p1, param_t p2, void (*iter_fct)(content_t * cont, param_t param1, param_t param2));

#endif
