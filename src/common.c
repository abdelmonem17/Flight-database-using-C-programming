/*
 * common.c
 *
 *  Created on: Apr 3, 2020
 *      Author: Eng Abdo
 */
#include "../inc/common.h"
#include <stdlib.h>

/*this function create space string*/
char* createSpace(uint8_t size)
{
	char *str = (char *)malloc(50);
	volatile uint8_t i;
	for(i=0;i<size;)
	{

		str[i++] = ' ';

	}
	str[size] = 0;
	return str;
}

uint8_t digitsCount(uint32_t number)
{

	uint8_t count=0;
	while(number)
	{
		++count;
		number/=10;
	}

	return count;

}
/*  to go to new line to read in the file*/
void file_goNewLineRead(FILE *file)
{
	char ch;

	if(file != NULL)
	{
		do
		{
			fscanf(file,"%c",&ch);
		}while(ch != '\n');
	}
}

/*scaps lines when reading a file*/
void scapeLinesRead(FILE *file,int32_t counts)
{
	while(counts-- > 0)
		file_goNewLineRead(file);
}

int32_t strLength(char* str)
{
	int32_t size =0;
	while(str[size++] != 0 );
	return (size-1);
}
