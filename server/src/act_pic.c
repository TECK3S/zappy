/*
** act_pic.c for  in /home/aysan_r//zzzzaaaappppyyyy/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Wed Jun 22 21:03:17 2011 rahman-serdar aysan
** Last update Mon Jul  4 22:03:08 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

static inline void	get_player_num(content_t * cont, param_t param)
{
  static  char	tmp[MAX_BUF_SIZE];

  *((int *)param) += sprintf(tmp, " #%i", *((int *) *cont));
}

void		act_pic(client * host, t_list * player_num_list, client * gui)
{
  char *	msg;
  char		tmp[MAX_BUF_SIZE];
  int		len = 0;
  t_node *	cur = *player_num_list;

  len += sprintf(tmp, " %i %i %i", host->pos.x, host->pos.y, host->level);
  list_iter(player_num_list, &len, get_player_num);
  if ((msg = malloc((strlen(PIC_RESPONSE_CMD)
		     + len + 2) * sizeof(*msg))) == NULL)
    return ;
  len = sprintf(msg, "%s %i %i %i", PIC_RESPONSE_CMD,
		host->pos.x, host->pos.y, host->level);
  while (cur != NULL)
    {
      len += sprintf(msg + len, " #%i", *((int *)cur->cont));
      cur = cur->next;
    }
  sprintf(msg + len, "\n");
  answer(msg, gui);
}
