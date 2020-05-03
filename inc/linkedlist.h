/*
 * Linkedlist.h
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef NULL
#define NULL ((void*)0)
#endif


typedef uint32_t linkedlist_size_Type ;


typedef	struct linkedList{

	struct linkedList *next_node;
	void *data ;

}node_type;

typedef	struct{

	node_type *head;
	linkedlist_size_Type elementsCount;
	uint32_t	  DataSize;
}list_type;


/****************************************************************************
*
*   @brief function create list
*   this function  takes list pointer and data size in every node and return status of creation
*   @params  list_type * : list
*			 uint32_t :	   dataSize
*   @return uint8_t
****************************************************************************/
uint8_t createList(list_type *list,uint32_t dataSize);





/****************************************************************************
*
*   @brief function create a node an list
*   this function  takes list pointer and data pointer and return pointer to this node
*   @params  list_type * : list
*			 void * :	   data
*   @return void *
****************************************************************************/
uint8_t addToListEnd(list_type *list,void *data);



/****************************************************************************
*
*   @brief function get data from a list from a spacfic position
*   this function  takes list pointer and data pointer and the position and return pointer to 0 if the position not found
*   @params  list_type * : list
*   		 uint8_t  :	   position
*			 void * :	   data
*   @return uint_t
****************************************************************************/
uint8_t getDataInList(list_type *list, uint8_t position, void *pData);


#endif /* LINKEDLIST_H_ */
