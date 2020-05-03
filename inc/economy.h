#ifndef 	__ECONOMY_H__
#define 	__ECONOMY_H__
#include "passengerMember.h"



passengerMember_type * create_passeger_economy(char const * name,uint32_t seatNo,char category);
char getCategory_economy(passengerMember_type * passenger);


#endif
