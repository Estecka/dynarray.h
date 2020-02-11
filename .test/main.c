/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:13:54 by abaur             #+#    #+#             */
/*   Updated: 2020/02/11 15:38:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../dynarray.h"

int	main()
{
	t_dynarray array;
	int**	content = (int**)&array.content;
	short	b;

	b = dynarrayinit(&array, sizeof(int), 32);
	if (!b){
		printf("Malloc failed\n");
		exit(-1);
	}
	if (array.capacity != 32)
		printf("[FAILURE][capacity]: %lu\n", array.capacity);
	
	for (int i=0; i<32; i++)
		(*content)[i] = i;


	for (int i=0; i<32; i++)
		if ((*content)[i] != i)
			printf("[FAILURE][%i]: %d\n", i, **content);

	array.length = 32;
	arrayexpand(&array, 128 - 32);
	if (!b){
		printf("Malloc failed\n");
		exit(-1);
	}
	if (array.capacity != 128)
		printf("[FAILURE][capacity]: %lu\n", array.capacity);

	for (int i=0; i<32; i++){
		printf("[%i]\n", i);
		if ((*content)[i] != i)
			printf("[FAILURE][%i]: %d\n", i, **content);
	}

	for (int i=32; i<128; i++)
		(*content)[i] = i;
}
