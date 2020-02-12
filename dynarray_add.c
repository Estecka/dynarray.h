/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:42:05 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 16:10:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynarray.h"

static void		dynset(t_dynarray *this, size_t i, const void *value)
{
	const char	*src;
	char		*dst;

	src = (const char*)value;
	dst = ((char*)this->content) + (i * this->type);
	i = 0;
	while (i < this->type)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
** Add an item at the end of the array.
** @param t_dynarray* this	The array to expand.
** @param void* value	A pointer to the value to copy into the array.
** @return bool
** 	true  OK
** 	false Allocation failed.
*/

extern short	dynappend(t_dynarray *this, const void *value)
{
	if (!dynexpand(this, 1))
		return (0);
	dynset(this, this->length, value);
	this->length++;
	return (1);
}

/*
** Inserts an element in the middle of an array.
** @param t_dynarray* this	The array where to insert.
** @param size_t index	The position where to insert the element.
** @param const void* value	A pointer to the value to copy into the array.
** @return bool
** 	true  OK
** 	false Allocation failed / Index out of range.
*/

/*
** @var size_t i	The original adress of the byte being moved.
** 	Each bytes are moved `type` bytes to the left.
**	The starting position is the last byte of the last item of the array.
** 	Because `length` must be greater than 0, i can never start at 0,
** 	the smallest possible starting position is `type - 1`.
** @var size_t min The position of the first byte of the first item to be moved
** 	It can never be smaller than 0.
*/

extern short	dyninsert(t_dynarray *this, size_t index, const void *value)
{
	size_t	i;
	size_t	min;
	char 	*content;

	if (index < 0 || this->length < index)
		return (0);
	if (index == this->length)
		return (dynappend(this, value));
	if (!dynexpand(this, 1))
		return (0);
	content = (char*)this->content;
	i = (this->length * this->type) - 1;
	min = index * this->type;
	while (i >= min)
	{
		content[i + this->type] = content[i];
		i--;
	}
	this->length++;
	dynset(this, index, value);
	return (1);
}
