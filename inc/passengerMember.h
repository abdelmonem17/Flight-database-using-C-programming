#ifndef 	__PASSENGER_MEMBER_H__
#define		__PASSENGER_MEMBER_H__

#include "linkedlist.h"
#include "baggage.h"


typedef uint32_t seatNo_type;

typedef struct
{
	char name[30];
	seatNo_type seatNo;
	list_type baggageList;
}passengerInfo_type;


typedef struct
{
	int32_t reword_points;

}business_type;

typedef struct
{
	char category;

}economy_type;


typedef enum
{
	economy = 1,
	business =2,

}passengerType_enm;


typedef struct
{
	passengerInfo_type passengerInfo;
	union
	{
		business_type businessMemeber;
		economy_type economyMember;
	}membership_union;
	passengerType_enm currentMembership_enm;



}passengerMember_type;



#endif
