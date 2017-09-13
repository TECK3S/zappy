/*
** socket.h<2> for socket.h in /home/ngonta_e//my_home/rendu/c/zappy/zappy_delamort/server/doc/includes
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Jun  2 12:11:20 2011 eugene-valentin ngontang-tchiadjie
** Last update Fri Jun  3 22:52:58 2011 eugene-valentin ngontang-tchiadjie
*/


#ifndef SOCKET_H__
#define SOCKET_H__


#include <netdb.h>
#include "client.h"

#define SRV_BIND_TIMEOUT (60)
#define MAX_BUF_SIZE	(1024)

struct buffer;

/* socket.c */

int	socket_read(buffer * b, int fd);

int	socket_write(buffer * b, int fd);

int	socket_create_connServer(int port);

int	socket_create_connClient(const int serverfd, const struct sockaddr_in * new_client);

int	socket_close(int fd);

int	my_accept(int s, struct sockaddr *addr,
			  socklen_t *addrlen);

/* fill_buffer.c */

void		fill_buffer(buffer * b, char * buf, int n);

/* flush_buffer */

int		flush_buffer(buffer * b, char * buf, int fd, int size);

#endif /* !SOCKET_H__ */
