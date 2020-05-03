
#include "../inc/linkedlist.h"
#include <string.h>


/****************************************************************************
*
*   @brief function create a node an list
*   this function  takes list pointer and data pointer and return pointer to this node
*   @params  list_type * : list
*			 void * :	   data
*   @return void *
****************************************************************************/
static void * create_node(list_type *list , void *data);





/****************************************************************************
*
*   @brief function create list
*   this function  takes list pointer and data size in every node and return status of creation
*   @params  list_type * : list
*			 uint32_t :	   dataSize
*   @return uint8_t
****************************************************************************/
uint8_t createList(list_type *list,uint32_t dataSize)
{

	/*allocate memory for list head*/
 list->head=(node_type *) malloc(sizeof(node_type));
 if(list->head != NULL)
 {
	 list->head->next_node=NULL;
	 list->elementsCount=0;
	 /*asign sign of data in every node node */
	 list->DataSize = dataSize;
	 return 1;
 }
 else
	 return 0;

}


/****************************************************************************
*
*   @brief function create a node an list
*   this function  takes list pointer and data pointer and return pointer to this node
*   @params  list_type * : list
*			 void * :	   data
*   @return void *
****************************************************************************/
static void * create_node(list_type *list , void *data)
{

	node_type *node=(node_type *)malloc( sizeof(node_type) );

	if( node != NULL)
	{
		node->data = (void *)malloc( list->DataSize );

		/*copy data to the node*/
		memcpy(  node->data , data , list->DataSize );

	}
	return node;

}


/****************************************************************************
*
*   @brief function create a node an list
*   this function  takes list pointer and data pointer and return pointer to this node
*   @params  list_type * : list
*			 void * :	   data
*   @return void *
****************************************************************************/
uint8_t addToListEnd(list_type *list,void *data)
{

	node_type *current;
	node_type *node = create_node(list,data);
	if(node != NULL)
	{
		current=list->head;
		/* fine end of the list */
		while(current->next_node != NULL)
		{
			current=current->next_node;

		}

		/* insert in last position*/
		current->next_node=node;
		node->next_node=NULL;
		list->elementsCount++;
		return 1;
	}
	else
	{

		return 0;
	}
}



/****************************************************************************
*
*   @brief function get data from a list from a spacfic position
*   this function  takes list pointer and data pointer and the position and return pointer to 0 if the position not found
*   @params  list_type * : list
*   		 uint8_t  :	   position
*			 void * :	   data
*   @return uint_t
****************************************************************************/

uint8_t getDataInList(list_type *list, uint8_t position, void *pData)
{
			node_type *current;
			current=list->head;

			/*find the node in this postion */
			for(int i=0;i<position+1;i++)
			{
				if(current->next_node==NULL)
				{
					/* this position exceeds the list bound  */
					return 0;
				}
				else
				{
					/*step to next node*/
					current=current->next_node;
				}
			}

			/*	copy data	*/
			memcpy( pData, (current->data) , list->DataSize );

			return 1;
}
