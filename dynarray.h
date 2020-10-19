/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:16:38 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 16:00:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARRAY_H
# define DYNARRAY_H

# include "stdlib.h"

/*
** @var size_t type	The size of each element.
** @var size_t capacity	The maximum capacity of the array object.
** 	Exceptionally, this DOES include the optional automatic null-terminator.
** @var size_t length	The current amount of items in the array.
** 	This DOES NOT include the optional automatic NULL-terminator.
** @var bool nullterm	Whether the array should have an automatic NULL-termina
** tor.
** @var void* content	The actual content of the array.
*/

typedef struct s_dynarray	t_dynarray;
struct	s_dynarray
{
	size_t	type;
	size_t	capacity;
	size_t	length;
	short	nullterm;
	void	*content;
};

void	*dyninit(t_dynarray *this, size_t type, size_t capacity,
short nullterm);
void	*dynexpand(t_dynarray *this, unsigned int amount);

void	*dynappend(t_dynarray *this, const void *value);
void	*dynappendn(t_dynarray *this, const void *array, unsigned int count);
void	*dynappendnull(t_dynarray *this);
void	*dyninsert(t_dynarray *this, size_t index, const void *value);

void	dynset(t_dynarray *this, size_t i, const void *value);
void	dynsetnull(t_dynarray *this, size_t i);

void	*dynget(t_dynarray *this, size_t index);

void	dynremove(t_dynarray *this, size_t index);

#endif
