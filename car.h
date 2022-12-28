#ifndef CAR_STRUCT_H_
#define CAR_STRUCT_H_

#include <stdio.h>
#include <stdlib.h>

// Enumeration som inneh�ller vilken v�xell�da som finns i bilen.
enum car_transmission
{
	CAR_TRANSMISSION_MANUAL,
	CAR_TRANSMISSION_AUTOMATIC,
	CAR_TRANSMISSION_NULL
};

// struct som inneh�ller alla bilarna.
struct car
{
	const char* brand;
	const char* model;
	const char* color;
	int year_of_launch;
	enum car_transmission transmission;

	// Funktionspekare
	void (*change_color)(struct car* self, char* new_color);
	void (*change_transmission)(struct car* self);
	void (*print)(struct car* self, FILE* ostream);
};

// Deklarerar funktioner som har med bilarna att g�ra.
void car_init(struct car* self,
	          char* brand,
	          char* model,
	          char* color,
	          int year_of_launch,
	          enum car_transmission transmission);
void car_clear(struct car* self);
struct car* car_new(char* brand,
	                char* model,
	                char* color,
	                int year_of_launch,
	                enum car_transmission transmission);
void car_delete(struct car** self);

#endif /* CAR_STRUCT_H_ */