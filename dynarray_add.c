/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:42:05 by abaur             #+#    #+#             */
/*   Updated: 2020/02/12 15:15:34 by abaur            ###   ########.fr       */
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
** @return void* The updated pointer to the array, or NULL if an error occured.
*/

extern void		*dynappend(t_dynarray *this, const void *value)
{
	if (!dynexpand(this, 1))
		return (NULL);
	dynset(this, this->length, value);
	this->length++;
	return (this->content);
}

/*
** Inserts an element in the middle of an array.
** @param t_dynarray* this	The array where to insert.
** @param size_t index	The position where to insert the element.
** @param const void* value	A pointer to the value to copy into the array.
** @return void* The updated pointer to the array, or NULL if an error occured.
*/

/*
** @var size_t i	The original adress of the byte being moved.
** 	Each bytes are moved `type` bytes to the left.
**	The starting position is the last byte of the last item of the array.
** 	Because `length` must be greater than 0, i can never start at 0,
** 	the smallest possible starting position is `type - 1`.
** @var size_t min The position of the first byte of the first item to be moved
** 	It can be as small as 0, in which case `i <= min` would fail. Thus `i != 0`
** 	 must also be checked at the end of each loop.
*/

extern void		*dyninsert(t_dynarray *this, size_t index, const void *value)
{
	size_t	i;
	size_t	min;
	char	*content;

	if (this->length < index)
		return (NULL);
	if (index == this->length)
		return (dynappend(this, value));
	if (!dynexpand(this, 1))
		return (NULL);
	content = (char*)this->content;
	i = (this->length * this->type) - 1;
	min = index * this->type;
	while (i >= min)
	{
		content[i + this->type] = content[i];
		if (!i--)
			break ;
	}
	this->length++;
	dynset(this, index, value);
	return (this->content);
}
