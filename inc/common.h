#ifndef 	__COMMON_H__
#define		__COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef	uint8_t bool;


char* createSpace(uint8_t size);
void memory_copy(void *to ,const void *from,uint32_t size);
uint8_t digitsCount(uint32_t number);
void file_goNewLineRead(FILE *file);
void scapeLinesRead(FILE *file,int32_t counts);
int32_t strLength(char* str);



#endif
