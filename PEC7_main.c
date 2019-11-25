#include <stdio.h>
#include "hotel.h"

int main(int argc, char **argv)
{
	tHotel h1,h2,h3;
	float distance;
	float price;
	
	printf("INTRODUCE DATA FOR HOTEL 1 \n");
	hotelRead(&h1);
	printf("INTRODUCE DATA FOR HOTEL 2 \n");
	hotelRead(&h2);

	hotelCmpPoints(&h3,h1,h2,distance,price);
	
	printf("THE BEST CHOICE IS >> \n");
	hotelWrite(h3);
	
	return 0;
}
