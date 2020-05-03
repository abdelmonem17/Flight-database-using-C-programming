#ifndef 	__BUSNESS_H__
#define 	__BUSNESS_H__
#include <stdint.h>
#include "passengerMember.h"




passengerMember_type * create_passeger_business(char const * name,uint32_t seatNo,uint32_t reword_points);
int32_t getReward_business(passengerMember_type * passenger);

#endif
