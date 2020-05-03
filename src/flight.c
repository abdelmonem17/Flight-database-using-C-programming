
#include "../inc/flight.h"
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "../inc/linkedlist.h"
#include "../inc/common.h"
#include <strings.h>
#include "../inc/business.h"
#include "../inc/economy.h"





#define ALLOCATED_SIZE			                     	    30
#define ALIGN_OFFSET			                     	    20
//#define SPACE_SIZE(str1,str2)                      		(strlen(str1)-strlen(str2) + ALIGN_OFFSET)
#define SPACE(x,y)				                     		(x-y+20)
#define GET_SPACE_LENGTH(x)		                     		(x+ALIGN_OFFSET)


/*allignment spaces for every column in file*/
#define SEAT_ID_ALLIGN()									createSpace(ALLOCATED_SIZE - (int32_t)strlen(temp_passenger.passengerInfo->name)  )
#define FRACTIONS_LENGTH									7

#define ALLIGN_SEAT_NUMBER()								createSpace(ALLOCATED_SIZE - (int32_t)strlen(temp_passenger.passengerInfo.name) )
#define ALLIGN_BAGGAGE_ID()									createSpace(ALLOCATED_SIZE - (int32_t)digitsCount(temp_passenger.passengerInfo.seatNo)  )
#define ALLIGN_BAGGAGE_WEIGHT()								createSpace(ALLOCATED_SIZE - (int32_t)digitsCount(baggageId)  )
#define ALLIGN_TYPE()								        createSpace(ALLOCATED_SIZE - (int32_t)digitsCount(baggageWeight) - FRACTIONS_LENGTH  )
#define ALLIGN_CAT()								        createSpace(ALLOCATED_SIZE - strlen(membership)  )
#define ALLIGN_REWARD()								        createSpace(ALLOCATED_SIZE - strlen(membership)  )
#define ALLIGN_SEAT_NUMBER_HEAD										(ALLOCATED_SIZE - (int32_t)strlen("passengerName"))
#define ALLIGN_BAGGAGE_ID_HEAD									(ALLOCATED_SIZE - (int32_t)strlen("SeatNumber"))
#define ALLIGN_BAGGAGE_WEIGHT_HEAD								(ALLOCATED_SIZE - (int32_t)strlen("BaggageId"))
#define ALLIGN_TYPE_HEAD										(ALLOCATED_SIZE - (int32_t)strlen("BaggageWeight"))
#define ALLIGN_CAT_REWARD										(ALLOCATED_SIZE - (int32_t)strlen("Type"))




void *create_flight(uint32_t flightNumber,char const *from,char const *to)
{

	/*create a flight pointer*/
	flight_type * ptr_Flight = (flight_type *)malloc(sizeof(flight_type));

	if(ptr_Flight != NULL)
	{

		ptr_Flight->flightNumber = flightNumber;
		strcpy(ptr_Flight->from , from);
		strcpy(ptr_Flight->to , to);

		/* create list of passengers in this flight */
		createList( &(ptr_Flight->passengersList) , sizeof(filghtPassengers) );
	}
	else
	{
		/*fail to allocate memory to this flight*/
	}
	return ptr_Flight;

}

bool add_passengerToFlight(flight_type * ptr_flight,filghtPassengers *ptr_passenger)
{


	bool status;

	/*check for not null pointer*/
	if( ptr_flight != NULL )
	{
		/*add passenger to this flight*/
		status = (bool)addToListEnd( &(ptr_flight->passengersList) , ptr_passenger);
	}
	else
	{
		/*null pointer*/
		status = 0;
	}
	return status;
}

filghtPassengers * get_passenger(flight_type * ptr_flight ,passengerType_enm type ,uint32_t *pSize)
{
	int32_t listSize = 10;

	/*allocate memory for return list*/
	filghtPassengers *passengers = (filghtPassengers*)malloc( sizeof(filghtPassengers) * listSize);
	filghtPassengers temp_passenger;
	int32_t index = 0;
	int32_t FlightpassengersSize = 0;


	/*loop over passengers on the list*/
	while( getDataInList(&ptr_flight->passengersList,index,&temp_passenger ) == 1 )
	{

		/*check for current passenger type*/
		if(temp_passenger.currentMembership_enm == type)
		{
			/* allocate more 10 spaces for return array  */
			if(listSize == FlightpassengersSize)
			{
				listSize += 10;
				passengers =(filghtPassengers *) realloc(passengers,sizeof(filghtPassengers) * listSize);
			}
			/*story in result array*/
			passengers[FlightpassengersSize++] = temp_passenger;
		}
	}

	*pSize =  FlightpassengersSize;
	/*reallocte result array to the spacific size*/
	passengers =(filghtPassengers *) realloc(passengers,sizeof(filghtPassengers) *FlightpassengersSize );
	return passengers;
}
void save_to_file(flight_type * ptr_flight, const char * fileName)
{
	int32_t index=0;
	filghtPassengers temp_passenger;
	baggage_type temp_baggage;
	uint32_t baggageId;
	double baggageWeight;
	char *membership = NULL;
	int catecory;
	int reward;


	FILE * writeFile = fopen(fileName,"w");

	/*print table head and flight information in file*/
	fprintf(writeFile,"FlightNumber : %d		From : %s		To : %s\n\n",ptr_flight->flightNumber,ptr_flight->from,ptr_flight->to);
	fprintf(writeFile,"Passengers data:\n\n");
	fprintf(writeFile,"PassengerName %s SeatNumber %s BaggageId %s BaggageWeight %s Type %s Reward || Category \n",
			createSpace(ALLIGN_SEAT_NUMBER_HEAD ),
			createSpace(ALLIGN_BAGGAGE_ID_HEAD ),
			createSpace(ALLIGN_BAGGAGE_WEIGHT_HEAD ),
			createSpace(ALLIGN_TYPE_HEAD),
			createSpace(ALLIGN_CAT_REWARD)
	);

	/* loop over the flight list of passengers and write the information in the file */
	while( getDataInList(&ptr_flight->passengersList,index++,&temp_passenger ) == 1 )
	{
		/*loop over weight for every user and print it*/
		if(getDataInList(&temp_passenger.passengerInfo.baggageList,0,&temp_baggage ) == 1)
		{

			baggageWeight = baggage_get_weight( &temp_baggage );
			baggageId =  baggage_get_id(&temp_baggage);

		}
		else
		{
			baggageId =0;
			baggageWeight =0;
		}


		if(temp_passenger.currentMembership_enm == economy)
		{
			membership = "economy";
			catecory =getCategory_economy( &temp_passenger );

			/* write passenger data in the file in spacic alligment */
					fprintf(writeFile,"%s %s %d %s %d %s %f %s %s %s %d\n",
							passenger_get_name(	&temp_passenger ),
							ALLIGN_SEAT_NUMBER() , passenger_get_seat(& temp_passenger),
							ALLIGN_BAGGAGE_ID() , baggageId,
							ALLIGN_BAGGAGE_WEIGHT() ,baggageWeight,
							ALLIGN_TYPE()        , membership,
							ALLIGN_CAT()       , catecory
					);
		}
		else if(temp_passenger.currentMembership_enm == business)
		{
			membership = "business";
			reward = getReward_business(&temp_passenger);
			/* write passenger data in the file in spacic alligment */
					fprintf(writeFile,"%s %s %d %s %d %s %f %s %s %s %d\n",
							temp_passenger.passengerInfo.name,
							ALLIGN_SEAT_NUMBER() , temp_passenger.passengerInfo.seatNo,
							ALLIGN_BAGGAGE_ID() , baggageId,
							ALLIGN_BAGGAGE_WEIGHT() ,baggageWeight,
							ALLIGN_TYPE()        , membership,
							ALLIGN_REWARD()       , reward
					);
		}
		else
		{
			membership = "N/A";
			reward =0;
			/* write passenger data in the file in spacic alligment */
					fprintf(writeFile,"%s %s %d %s %d %s %f %s %s %s %d\n",
							temp_passenger.passengerInfo.name,
							ALLIGN_SEAT_NUMBER() , temp_passenger.passengerInfo.seatNo,
							ALLIGN_BAGGAGE_ID() , baggageId,
							ALLIGN_BAGGAGE_WEIGHT() ,baggageWeight,
							ALLIGN_TYPE()        , membership,
							ALLIGN_REWARD()       , reward
					);
		}



	}

	fclose(writeFile);
}

void read_from_file(flight_type * flight, const char * fileName)
{
	char pName[30];
	char typeStr[10];

	int32_t seatNo;
	int32_t baggageId;
	int32_t category;
	int reward;
	double baggageWeight;

	passengerMember_type  *passenger1 ;
	baggage_type * baggage1;


	FILE * read= fopen("data.txt","r");

	/*	scape first 5 lines	*/

	scapeLinesRead(read,5);
	/*read passenger name and check if reading fail this main the end of file*/
	while(fscanf(read,"%s",pName) == 1)
	{

		/*read row of data to the current  passenger*/
		fscanf(read,"%d",&seatNo);
		fscanf(read,"%d",&baggageId);
		fscanf(read,"%lf",&baggageWeight);
		fscanf(read,"%s",typeStr);


		/* check the type of passenger and create typw*/
		if (strcmp (typeStr,"business") == 0 )
		{
			fscanf(read,"%d",&reward);
			passenger1 = create_passeger_business(pName,seatNo,reward);

		}
		else
		{
			fscanf(read,"%d",&category);
			passenger1 = create_passeger_economy(pName,seatNo,(char)category);
		}
		/*save passenger data to the flight passenger list*/
		baggage1 =   create_baggage(baggageId,baggageWeight);
		passenger_add_baggage(passenger1,baggage1);
		add_passengerToFlight(flight,passenger1);
	}

}
