/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:29:36 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 15:46:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynarray.h"

/*
** Initializes a new dynarray.
** @param t_dynarray* this The array to initialize.
** @param size_t type	The size of a single element of the stored type.
** @param size_t capacity	The initial size of the array.
** @return bool
** 	true  OK
**	false Allocation failed.
*/

extern short	dyninit(t_dynarray *this, size_t type, size_t capacity)
{
	this->content = malloc(type * capacity);
	if (!this->content)
		return (0);
	this->type = type;
	this->capacity = capacity;
	this->length = 0;
	return (1);
}

static void		arraycpy(const unsigned char *src, unsigned char *dst,
	size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
** Makes sure the array can contain more elements.
** @param t_dynarray* this	The array to expand.
** @param unsigned int amount	The amount of extra elements needed.
** @return bool
** 	true  OK
** 	false allocation failed.
*/

extern short	dynexpand(t_dynarray *this, unsigned int amount)
{
	size_t			ncap;
	unsigned char	*ncontent;

	if (this->capacity >= this->length + amount)
		return (1);
	ncap = this->capacity * 2;
	while (ncap < this->length + amount)
		ncap *= 2;
	ncontent = malloc(ncap * this->type);
	if (!ncontent)
		return (0);
	arraycpy((unsigned char*)this->content, (unsigned char*)ncontent,
		this->length * this->type);
	free(this->content);
	this->content = ncontent;
	this->capacity = ncap;
	return (1);
}
