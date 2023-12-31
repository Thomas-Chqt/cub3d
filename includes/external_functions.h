/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:14:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_FUNCTIONS_H
# define EXTERNAL_FUNCTIONS_H

# include <stddef.h>
# include <math.h>

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

# define O_RDONLY 0x0000

# define INT_MAX 2147483647

# ifdef DEBUG

int		system(const char *command);

# endif // DEBUG

void	perror(const char *s);
int		open(const char *path, int oflag, ...);
int		close(int fildes);
void	*malloc(size_t size);
void	free(void *ptr);
int		printf(const char *format, ...);
void	exit(int status);

#endif // EXTERNAL_FUNCTIONS_H