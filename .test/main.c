/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:13:54 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 15:47:57 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../dynarray.h"

static void printarr(t_dynarray* this)
{
	int* content = this->content;

	printf("%lu : \n", this->length);
	for (int i=0; i<this->length; i++)
		printf("[%i:%i]", i, content[i]);
	printf("\n\n");
}

static short assertcap(t_dynarray* this, int cap)
{
	if (this->capacity != cap) {
		printf("[FAILURE][capacity]: %lu != %d\n", this->capacity, cap);
		return (0);
	}
	return (1);
}
static short assertlength(t_dynarray* this, int cap)
{
	if (this->length != cap) {
		printf("[FAILURE][length]: %lu != %d\n", this->length, cap);
		return (0);
	}
	return (1);
}

static short	assert(t_dynarray* this)
{
	int* content = this->content;
	short r = 1;

	for (int i=0; i<this->length; i++)
		if (i != content[i])
		{
			printf("[FAILURE][%i]: %d\n", i, content[i]);
			r = 0;
		}
	return (r);
}

int	main()
{
	t_dynarray array;
	int**	content = (int**)&array.content;
	int		value;
	void*	err;

	// Dyninit
	err = dyninit(&array, sizeof(int), 32);
	if (!err){
		printf("Malloc failed\n");
		exit(-1);
	}
	assertcap(&array, 32);
	
	array.length = 32;
	for (int i=0; i<32; i++)
		(*content)[i] = i;

	assert(&array);

	// Dynexpand
	err = dynexpand(&array, 64 - 32);
	if (!err){
		printf("Malloc failed\n");
		exit(-1);
	}

	assertcap(&array, 64);
	assert(&array);

	array.length = 64;
	for (int i=32; i<64; i++)
		(*content)[i] = i;

	// Dynappend
	value = 64;
	dynappend(&array, &value);
	assertlength(&array, 65);
	assert(&array);


	// Dyninsert
	for (int i=32; i<array.length; i++)
		(*content)[i] = i +1;
	value = 32;
	dyninsert(&array, value, &value);
	assert(&array);

	// Dynappendnull
	dynexpand(&array, 4);
	array.length -= 4;
	for (int i=0; i<4; i++)
		(*content)[array.length + i] = -1;
	for (int i=0; i<4; i++)
		dynappendnull(&array);
	for (int i=4; i>0; i--)
		if ((*content)[array.length - i] != 0)
			printf("[FAILURE][Value] %d != 0\n", (*content)[array.length - i]);

	printf("Done\n");
}
