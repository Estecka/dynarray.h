/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:23:00 by abaur             #+#    #+#             */
/*   Updated: 2020/10/19 12:23:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynarray.h"

/*
** Removes an element from the array.
** This will never reallocate the array, and thus never fail.
** @param t_dynarray* this	The array to edit.
** @param size_t index	The index of the element to remove.
*/

extern void	dynremove(t_dynarray *this, size_t index)
{
	while (index < (this->length + this->nullterm))
	{
		dynset(this, index, dynget(this, index + 1));
		index++;
	}
	this->length--;
	dynsetnull(this, this->length);
}
