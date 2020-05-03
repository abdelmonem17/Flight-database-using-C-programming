/*
 * economy.c
 *
 *  Created on: Apr 3, 2020
 *      Author: Eng Abdo
 */

#include "../inc/economy.h"
#include "../inc/passengerMember.h"
#include "../inc/passenger.h"
#include <stdlib.h>



passengerMember_type * create_passeger_economy(char const * name,uint32_t seatNo,char category)
{
	/*allocte memory for passenger*/
	passengerMember_type  *passenger	 = create_passenger(name,seatNo);

	if(passenger != NULL)
	{

		passenger->membership_union.economyMember.category = category;
		passenger->currentMembership_enm =	economy;
	}

	return passenger;
}

char getCategory_economy(passengerMember_type * passenger)
{
	char category;

  if( (passenger != NULL) && (passenger->currentMembership_enm == economy) )
  {
	  category = passenger->membership_union.economyMember.category;
  }
  else if(passenger == NULL)
  {
	  /*null reference error*/
	  category = -1;
  }
  else
  {
	  /*error this member is not a economy	*/
	  category = -2;
  }

  return category;

}
