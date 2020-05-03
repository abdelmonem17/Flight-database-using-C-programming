/*
 ============================================================================
 Name        : passengerData.c
 Author      : abdo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "../inc/flight.h"
#include "../inc/passenger.h"
#include "../inc/economy.h"
#include "../inc/business.h"
#include "../inc/passengerMember.h"

#define WRITE 1
#define READ  2

#define OPERATION 2
int main(void) {


  flight_type 		*flight = create_flight(123,"Minia","Cairo");


 passengerMember_type  *passenger1 = create_passeger_business("abdo",123,70);
 baggage_type * baggage1 =   create_baggage(23,51);
 passenger_add_baggage(passenger1,baggage1);

 passengerMember_type  *passenger2 = create_passeger_business("mohamed",174,90);
 baggage_type * baggage2 =   create_baggage(13,22);
 passenger_add_baggage(passenger2,baggage2);


 passengerMember_type  *passenger3 = create_passeger_business("ahmed",177,9);
 baggage_type * baggage3 =   create_baggage(15,12);
 passenger_add_baggage(passenger3,baggage3);


 passengerMember_type  *passenger4 = create_passeger_economy("ali",355,'B');
 baggage_type * baggage4 =   create_baggage(13,10);
 passenger_add_baggage(passenger4,baggage4);

  add_passengerToFlight(flight,passenger1);
  add_passengerToFlight(flight,passenger2);
  add_passengerToFlight(flight,passenger3);
  add_passengerToFlight(flight,passenger4);

 save_to_file(flight,"data.txt");
 flight_type 		*flight2 = create_flight(76,"Alex","Aswan");
 read_from_file(flight2,"data.txt");
 save_to_file(flight2,"data1.txt");
 printf("\nsuccess");
	return EXIT_SUCCESS;
}
