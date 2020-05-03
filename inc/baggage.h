#ifndef 	__BAGGAGE_H__
#define		__BAGGAGE_H__

#include <stdint.h>

typedef struct {
	uint32_t id;
	double weight;
}baggage_type;


baggage_type *create_baggage(uint32_t id , double weight);
uint32_t baggage_get_id(baggage_type *baggage);
double baggage_get_weight(baggage_type *baggage);


#endif

