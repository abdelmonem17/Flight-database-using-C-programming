#ifndef 	__FLIGHT_H__
#define 	__FLIGHT_H__

#include "linkedlist.h"
#include <stdint.h>
#include "common.h"
#include "passengerMember.h"
#include "passenger.h"


typedef passengerMember_type filghtPassengers	;

typedef struct
{
	uint32_t flightNumber;
	char from[30];
	char to[30];
	list_type passengersList;
}flight_type;


void *create_flight(uint32_t flightNumber,char const *from,char const *to);

bool add_passengerToFlight(flight_type * ptr_flight,filghtPassengers *ptr_passenger);
void save_to_file(flight_type * ptr_flight, const char * fileName);
void read_from_file(flight_type * flight, const char * fileName);
filghtPassengers * get_passenger(flight_type * ptr_flight ,passengerType_enm type ,uint32_t *pSize);


#endif
