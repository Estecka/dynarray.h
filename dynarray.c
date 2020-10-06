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
** In case of error, all members of the dynarray will still be initialized, but
**  its content will be NULL, its capacity 0, and nullterm FALSE.
** @param t_dynarray* this The array to initialize.
** @param size_t type	The size of a single element of the stored type.
** @param size_t capacity	The initial size of the array. This does not includ
** e the automatic NULL-terminator.
** @return void* The updated pointer to the array, or NULL if an error occured.
*/

extern void		*dyninit(t_dynarray *this, size_t type, size_t capacity,
short nullterm)
{
	capacity += (nullterm != 0);
	this->content = malloc(type * capacity);
	this->type = type;
	this->capacity = this->content ? capacity : 0;
	this->length = 0;
	this->nullterm = nullterm && this->content;
	if (this->nullterm)
		dynsetnull(this, 0);
	return (this->content);
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
** The optional NULL-terminator is automatically accounted for.
** If the array evern needs to be expanded, its capacity will be doubled.
** This only expands the array's CAPACITY, not its LENGTH.
** @param t_dynarray* this	The array to expand.
** @param unsigned int amount	The amount of extra elements needed.
** @return void* The updated pointer to the array, or NULL if an error occured.
*/

extern void		*dynexpand(t_dynarray *this, unsigned int amount)
{
	size_t			ncap;
	unsigned char	*ncontent;

	if (this->capacity >= this->length + this->nullterm + amount)
		return (this->content);
	ncap = this->capacity * 2;
	while (ncap < this->length + this->nullterm + amount)
		ncap *= 2;
	ncontent = malloc(ncap * this->type);
	if (!ncontent)
		return (NULL);
	arraycpy((unsigned char*)this->content, (unsigned char*)ncontent,
		(this->length + this->nullterm) * this->type);
	free(this->content);
	this->content = ncontent;
	this->capacity = ncap;
	return (this->content);
}

/*
** Gets a pointer to the nth element of an array.
** @param t_dynarray *this	The array to search.
** @param size_t i	The index of the element to fetch.
** @return void*	A pointer to the element in the array.
*/

extern void		*dynget(t_dynarray *this, size_t i)
{
	return (this->content + (this->type * i));
}

/*
** Sets the value of an existing element of the array.
** Index overflow and underflow are not checked for.
** @param t_dynarray this	The array to edit.
** @param size_t i	The index of the element to overwrite.
** @param const void*	A pointer to the value to be copied.
*/

extern void		dynset(t_dynarray *this, size_t i, const void *value)
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
