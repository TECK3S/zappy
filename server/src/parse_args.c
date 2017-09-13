/*
** parse_args.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun  1 10:41:30 2011 adrien barrau
** Last update Fri Jun 24 00:44:07 2011 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "zappy.h"

#include "parse_args1.static.c"
#include "parse_args2.static.c"

static inline int	do_t_opt(zappy * zap)
{
  zap->time_delay = atoi(optarg);
  return (NO_ERR_CODE);
}

static inline int	do_default_opt()
{
  fprintf(stderr, "%s\n", ZAPPY_USAGE);
  return (PARSE_OPT_ERR_CODE);
}

static inline void	print_params(zappy * zap, int * port)
{
  printf("[Listening port] = %i\n", *port);
  printf("[Trantor size] = %ux%u\n", zap->trantor_width, zap->trantor_height);
  printf("[Teams] = \n");

  void dump_team(void * name)
  {
    printf("          > %s\n", (char *)name);
  }

  list_dump(zap->team_name, &dump_team);
  printf("[Slot per team] = %u\n", zap->slot_per_team);
  printf("[Time modifier] = %u\n", zap->time_delay);
}

static inline int	check_param_number(zappy * zap, int * port)
{
  if (*port == 0
      || zap->trantor_width == 0
      || zap->trantor_height == 0
      || zap->team_name == EMPTY
      || zap->slot_per_team == 0
      || zap->time_delay == 0)
    {
      fprintf(stderr, "%s\nDefault Settings\n", ZAPPY_USAGE);
      default_param(zap, port);
    }
  print_params(zap, port);
  return (NO_ERR_CODE);
}

int	parse_args(int ac,
		   char ** av,
		   zappy * zap,
		   int * port)
{
  int	errcode = 0;
  int	opt;

  while ((opt = getopt(ac, av, "+p:x:y:n:c:t:")) != -1)
    {
      switch (opt)
	{
	case 'p': errcode = do_p_opt(port);           break;
	case 'x': errcode = do_x_opt(zap);            break;
	case 'y': errcode = do_y_opt(zap);            break;
	case 'n': errcode = do_n_opt(ac, av, zap);    break;
	case 'c': errcode = do_c_opt(zap);            break;
	case 't': errcode = do_t_opt(zap);            break;
	default : errcode = do_default_opt();         break;
	}
      if (errcode)
	break;
    }
  if (!errcode)
    errcode = check_param_number(zap, port);
  return (errcode);
}
