/*
** act_graphic.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:39:13 2011 rahman-serdar aysan
** Last update Sun Jul 10 20:43:30 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void	act_graphic(action_param param __attribute__((unused)),
		    client * cli,
		    zappy * zap __attribute__((unused)))
{
  cli->state = GRAPHIC;
  answer(response_ok(), cli);
}
