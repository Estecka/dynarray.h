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
** @var size_t length	The current amount of items in the array.
** @var void* content	The actual content of the array.
*/

typedef struct s_dynarray	t_dynarray;
struct	s_dynarray
{
	size_t	type;
	size_t	capacity;
	size_t	length;
	void	*content;
};

void	*dyninit(t_dynarray *this, size_t type, size_t capacity);
void	*dynexpand(t_dynarray *this, unsigned int amount);

void	*dynappend(t_dynarray *this, const void *value);
void	*dyninsert(t_dynarray *this, size_t index, const void *value);

#endif
