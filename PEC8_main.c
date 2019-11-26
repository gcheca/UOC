#include <stdio.h>
#include "hotel.h"

int main(int argc, char **argv)
{
	tHotelTable hotelsTable;
	tHotelTable selectHotelsTable;
	const char city[MAX_CITY];
	int points;
	float price, distance;
	const char filename[MAX_LINE];
	
	hotelsTableInitialize(&hotelsTable);
	
	printf("LOAD DATA FROM FILENAME? >> \n");
	scanf("%s",filename);
	hotelsTableLoadDataFromFile(&hotelsTable,filename);
	
	printf("HOTELS SUCCESSFULLY LOADED! \n");
	
	printf("CITY NAME? >> \n");
	scanf("%s",city);
	
	printf("WHAT'S THE OPTIMAL PRICE? >> \n");
	scanf("%f",&price);
	
	printf("WHAT'S THE OPTIMAL DISTANCE? >> \n");
	scanf("%f",&distance);
	
	printf("NUMBER OF NEEDED POINTS? >> \n");
	scanf("%d",&points);
	
	hotelsTableSelect(hotelsTable,city,price,distance,points,&selectHotelsTable);
	
	if(selectHotelsTable.nHotels>0)
	{
		printf("WE FOUND %d HOTELS \n",selectHotelsTable.nHotels);
		printf("LIST OF SELECTED HOTELS >> \n");
		int i;
		for (i=0;i<selectHotelsTable.nHotels;i++)
		{
			hotelWrite(selectHotelsTable.hotels[i]);
		}
	}
	else
	{
		printf("THERE ARE NO AVAILABLE HOTELS WITH THIS CRITERION \n");
	}
	
	printf("THE MEAN PERCENTAGE OCCUPATION FOR THE CITY OF %s IS %.2f \n",city,hotelsComputeAverageOccupation(hotelsTable,city));
	
	
	
	return 0;
}
