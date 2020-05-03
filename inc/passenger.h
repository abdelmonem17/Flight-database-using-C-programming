#ifndef 	__PASSENGER_H__
#define 	__PASSENGER_H__

#include <stdint.h>
#include "common.h"
#include "passengerMember.h"




passengerMember_type *create_passenger(char const * name , uint32_t seat);
const char *passenger_get_name(const passengerMember_type * ptr_passenger );
seatNo_type passenger_get_seat(const passengerMember_type * ptr_passenger );
passengerType_enm get_type(passengerMember_type *passenger);
bool passenger_add_baggage(passengerMember_type * ptr_passenger,baggage_type *baggage);
double get_total_weight(passengerMember_type * ptr_passenger);

double get_total_weight(passengerMember_type * ptr_passenger);
double get_heavest_weight(passengerMember_type * ptr_passenger);

#endif
