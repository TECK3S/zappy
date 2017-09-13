/*
** errors.h for <Zappy> in /home/barrau_a//c/zappy_delamort/server
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Jun  1 15:45:22 2011 adrien barrau
** Last update Sat Jun  4 17:44:20 2011 adrien barrau
*/

#ifndef ERRORS_H_
# define ERRORS_H_

# define	NO_ERR_CODE		(0)
# define	TOO_LARGE_ERR_CODE	(-1)
# define	TOO_HEIGHT_ERR_CODE	(-2)
# define	TOO_MANY_SLOTS_ERR_CODE	(-3)
# define	PARSE_OPT_ERR_CODE	(-4)
# define	SOCK_ERR_CODE		(-5)
# define	LISTEN_ERR_CODE		(-6)
# define	FDS_ERR_CODE		(-7)
# define	MEMORY_ERR_CODE		(-8)
# define	EPOLL_CREATE_ERR_CODE	(-9)
# define	ACCEPT_ERR_CODE		(-10)
# define	POLL_ERR_CODE		(-11)
# define	LIST_ADD_ERR_CODE	(-12)
# define	LIST_DEL_ERR_CODE	(-13)
# define	SIGFILLLSET_ERR_CODE	(-14)
# define	EXEC_ERR_CODE		(-15)

# define	NO_ERR_MSG		("")
# define	TOO_LARGE_ERR_MSG	("The world is too large")
# define	TOO_HEIGHT_ERR_MSG	("The world is too high")
# define	TOO_MANY_SLOTS_ERR_MSG	("There is too many slots per team")
# define	PARSE_OPT_ERR_MSG	("Arguments error")
# define	SOCK_ERR_MSG		("Socket creation error")
# define	LISTEN_ERR_MSG		("Listen error")
# define	FDS_ERR_MSG		("Cannot initialize the fds")
# define	MEMORY_ERR_MSG		("Cannot allocate memory")
# define	EPOLL_CREATE_ERR_MSG	("epoll_create() error")
# define	ACCEPT_ERR_MSG		("Cannot accept connection")
# define	POLL_ERR_MSG		("epoll() error")
# define	LIST_ADD_ERR_MSG	("Cannot add to list")
# define	LIST_DEL_ERR_MSG	("Cannot remove from list")
# define	SIGFILLLSET_ERR_MSG	("Cannot set the signal set")
# define	EXEC_ERR_MSG		("Unable to execute client command")

#endif /* !ERRORS_H_ */
