/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:29:36 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 14:45:03 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "dynarray.h"

/*
** Initializes a new dynarray.
** @param t_dynarray* this The array to initialize.
** @param size_t type	The size of a single element of the stored type.
** @param size_t capacity	The initial size of the array.
** @return bool
** 	true  OK
**	false Allocation failed.
*/

extern short	dynarrayinit(t_dynarray *this, size_t type, size_t capacity)
{
}

/*
** Makes sure the array can contain more elements.
** @param t_dynarray* this	The array to expand.
** @param unsigned int amount	The amount of extra elements needed.
** @return bool
** 	true  OK
** 	false allocation failed.
*/

extern short	arrayexpand(t_dynarray *this, unsigned int amount)
{
}
