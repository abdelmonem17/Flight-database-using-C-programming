
#include "../inc/baggage.h"
#include <stdlib.h>
#include "../inc/passenger.h"

baggage_type *create_baggage(uint32_t id , double weight)
{
	/*allocate memory for a baggage */

	baggage_type *baggage  = (baggage_type *)malloc( sizeof(baggage_type) );

	if(baggage != NULL)
	{
		baggage->id = id;
		baggage->weight = weight;
	}
	return baggage;
}

uint32_t baggage_get_id(baggage_type *baggage)
{
	if(baggage != NULL)
		return baggage->id;
	else
		return 0;
}
double baggage_get_weight(baggage_type *baggage)
{
	if(baggage != NULL)
		return baggage->weight;
	else
		return 0;
}
