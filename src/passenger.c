#include "../inc/passenger.h"
#include <stdlib.h>
#include <string.h>

passengerMember_type *create_passenger(char const * name , uint32_t seat)
{
    /*	allocate memory for passenger	*/
	passengerMember_type *ptr_Passenger = (passengerMember_type *)malloc( sizeof(passengerMember_type) );
 if(ptr_Passenger != NULL)
 {


	/*seat passenger data */
  ptr_Passenger->passengerInfo.seatNo = seat;
  strcpy(ptr_Passenger->passengerInfo.name,name);

  /*create list to this passenger*/
  createList( &(ptr_Passenger->passengerInfo.baggageList) , sizeof(baggage_type) );
 }
 else
 {
	 /*fail to allocate memory */
 }
  return ptr_Passenger;

}
const char *passenger_get_name(const passengerMember_type * ptr_passenger )
{
	return ptr_passenger->passengerInfo.name;
}

seatNo_type passenger_get_seat(const passengerMember_type * ptr_passenger )
{
	return ptr_passenger->passengerInfo.seatNo;
}
bool passenger_add_baggage(passengerMember_type * ptr_passenger,baggage_type *baggage)
{


	/* add baggage to this passenger list */
	return addToListEnd(&ptr_passenger->passengerInfo.baggageList,baggage);

}
double get_total_weight(passengerMember_type * ptr_passenger)
{
	double totalWeight=0;
	baggage_type baggage;
	int32_t i =0;
	/*  loop over list of weights and get total weight */
	while( getDataInList(&ptr_passenger->passengerInfo.baggageList,i++,&baggage) )
	{
		totalWeight += baggage.weight;
	}

	return totalWeight;
}
double get_heavest_weight(passengerMember_type * ptr_passenger)
{
	    double maxWeight=0;
		baggage_type baggage;
		int32_t i =0;
		/*  loop over list of weights and get max weight */
		while( getDataInList(&ptr_passenger->passengerInfo.baggageList,i++,&baggage) )
		{
			/*compare current weight to max weight*/
			maxWeight = maxWeight > baggage.weight ?  maxWeight : baggage.weight;
		}
  return maxWeight;
}
