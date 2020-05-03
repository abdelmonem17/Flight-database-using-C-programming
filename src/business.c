/*
 * business.c
 *
 *  Created on: Apr 3, 2020
 *      Author: Eng Abdo
 */
#include "../inc/business.h"
#include "../inc/passenger.h"
#include <stdlib.h>

passengerMember_type * create_passeger_business(char const * name,uint32_t seatNo,uint32_t reword_points)
{
	passengerMember_type *passenger = create_passenger(name,seatNo);

	if(passenger != NULL)
	{
		/*set passengers data*/
		passenger->membership_union.businessMemeber.reword_points = reword_points;
		passenger->currentMembership_enm =business;
	}

	return passenger;
}
int32_t getReward_business(passengerMember_type * passenger)
{
	int32_t reword_points;
  if( (passenger != NULL) && (passenger->currentMembership_enm == business) )
  {
	  reword_points = passenger->membership_union.businessMemeber.reword_points;
  }
  else if(passenger == NULL)
  {
	  /*null reference*/
	  reword_points = -1;
  }
  else
  {
	  /*	this member is not a business	*/
	  reword_points = -2;
  }

  return reword_points;

}
