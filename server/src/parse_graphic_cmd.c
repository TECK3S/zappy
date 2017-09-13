/*
** parse_graphic_cmd.c for parse_graphic_cmd.c in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/src
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Jun 13 19:34:02 2011 eugene-valentin ngontang-tchiadjie
** Last update Sun Jul 10 22:16:32 2011 rahman-serdar aysan
*/

#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

static inline int	get_coord(char * s, size_t * i)
{
  int		j = 0;
  char		buf[MAX_BUF_SIZE];

  while (s && s[j] != ' ' && s[j])
    {
      buf[j] = s[j];
      ++j;
      *i += 1;
    }
  buf[j] = '\0';

  return (atoi(buf));
}

t_pos *		get_pos(char * str)
{
  size_t		i = 0;
  t_pos	*	pos;

  if ((pos = malloc(sizeof(*pos))) == NULL)
    return (NULL);
  pos->x = 0;
  pos->y = 0;
  if (str)
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (i < strlen(str))
	{
	  pos->x = get_coord(&str[i], &i);
	  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	    ++i;
	  if (i < strlen(str))
	    pos->y = get_coord(&str[i], &i);
	  printf("%i %i\n", pos->x, pos->y);
	}
    }
  return (pos);
}

static t_action * (*cmds[])(char *)=
 {
  &cmd_msz,
  &cmd_bct,
  &cmd_mct,
  &cmd_tna,
  &cmd_ppo,
  &cmd_plv,
  &cmd_pin,
  &cmd_sgt,
  &cmd_sst,
  0
 };

t_action *	parse_graphic_cmd(char * cmd)
{
  int		i = 0, j = 0;
  t_action *	act = NULL;

  if (!cmd)
    return (NULL);
  while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
    ++i;
  while (cmds[j])
    {
      if ((act = cmds[j](&(cmd[i]))) != NULL)
	break;
      ++j;
    }
  return (act);
}
