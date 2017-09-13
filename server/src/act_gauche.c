/*
** act_gauche.c for  in /home/aysan_r//zappy_final/zappy_delamort/server/src
** 
** Made by rahman-serdar aysan
** Login   <aysan_r@epitech.net>
** 
** Started on  Sun Jul 10 20:50:37 2011 rahman-serdar aysan
** Last update Sun Jul 10 20:51:06 2011 rahman-serdar aysan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket.h"
#include "zappy.h"

void	act_gauche(action_param param __attribute__((unused)),
		   client * cli,
		   zappy * zap __attribute__((unused)))
{
  if (cli->dir == 0)
    cli->dir = 3;
  else
    cli->dir -= 1;
  answer(response_ok(), cli);
}
