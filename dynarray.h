/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:16:38 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 14:32:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNARRAY_H
# define DYNARRAY_H

# include "stdlib.h"

/*
** @var size_t size	The total size of the array object.
** @var size_t type	The size of each element.
** @var size_t capacity	The maximum capacity of the array object.
** @var size_t length	The current amount of items in the array.
** @var void* content	The actual content of the array.
*/

typedef struct s_dynarray	t_dynarray;
struct	s_dynarray
{
	size_t	size;
	size_t	type;
	size_t	capacity;
	size_t	length;
	void	*content;
}

short	dynarrayinit(t_dynarray *this, size_t type, size_t capacity);
short	arrayexpand(t_dynarray *this,  unsigned int amount);

#endif
