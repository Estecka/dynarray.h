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

/*
** Add an item at the end of the array.
** @param t_dynarray* this	The array to expand.
** @param void* value	A pointer to the value to copy into the array.
** @return bool
** 	true  OK
** 	false Allocation failed.
*/

short	dynappend(t_dynarray *this, const void *value)
{
	const char *src;
	char		*dst;
	size_t	 	i;

	if (!dynexpand(this, 1))
		return (0);
	src = (const char*)value;
	dst = (char*)(this->content + (this->length * this->type));
	i = 0;
	while (i < this->type)
	{
		dst[i] = src[i];
		i++;
	}
	this->length++;
	return (1);
}

short	dyninsert(t_dynarray *this, size_t index, const void *value)
{
	
}
