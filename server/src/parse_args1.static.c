/*
** parse_args1.static.c for <Zappy-Static> in /home/barrau_a//c/zappy_delamort/server/src
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Jun  2 14:10:55 2011 adrien barrau
** Last update Fri Jun 24 00:44:25 2011 adrien barrau
*/

static inline int	do_p_opt(int * port)
{
  *port = (unsigned int)atoi(optarg);
  return (NO_ERR_CODE);
}

static inline int	do_x_opt(zappy * zap)
{
  zap->trantor_width = (size_t)atoi(optarg);
  if (zap->trantor_width > MAX_TRANTOR_WIDTH)
    return (TOO_LARGE_ERR_CODE);
  return (NO_ERR_CODE);
}

static inline int	do_y_opt(zappy * zap)
{
  zap->trantor_height = (size_t)atoi(optarg);
  if (zap->trantor_height > MAX_TRANTOR_HEIGHT)
    return (TOO_HEIGHT_ERR_CODE);
  return (NO_ERR_CODE);
}

static inline int	do_n_opt(int ac, char ** av, zappy * zap)
{
  list_push_back(&zap->team_name, strdup(optarg));
  while (optind < ac && av[optind][0] != '-')
    {
      list_push_back(&zap->team_name, strdup(av[optind]));
      ++optind;
    }
  return (NO_ERR_CODE);
}

static inline int	do_c_opt(zappy * zap)
{
  zap->slot_per_team = (size_t)atoi(optarg);
  if (zap->slot_per_team > MAX_SLOT_PER_TEAM)
    return (TOO_MANY_SLOTS_ERR_CODE);
  return (NO_ERR_CODE);
}
