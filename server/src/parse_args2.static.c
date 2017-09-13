/*
** parse_args2.static.c for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Mon Jun 13 13:38:05 2011 adrien barrau
** Last update Fri Jun 24 02:48:21 2011 adrien barrau
*/

static inline void	default_param(zappy * zap, int * port)
{
  if (*port == 0)
    *port = DEFAULT_PORT;
  if (zap->trantor_width == 0)
    zap->trantor_width = DEFAULT_WIDTH;
  if (zap->trantor_height == 0)
    zap->trantor_height = DEFAULT_HEIGHT;
  if (zap->team_name == EMPTY)
    {
      list_push_back(&zap->team_name, DEFAULT_TEAM1);
      list_push_back(&zap->team_name, DEFAULT_TEAM2);
      list_push_back(&zap->team_name, DEFAULT_TEAM3);
      list_push_back(&zap->team_name, DEFAULT_TEAM4);
      list_push_back(&zap->team_name, DEFAULT_TEAM5);
    }
  if (zap->slot_per_team == 0)
    zap->slot_per_team = DEFAULT_SLOT_PER_TEAM;
  if (zap->time_delay == 0)
    zap->time_delay = DEFAULT_TIME_DELAY;
}
