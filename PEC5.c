#include <stdio.h>
#include <string.h>

#define MAX_STRING 15

typedef enum {FALSE, TRUE} boolean;
typedef enum {BUDGET, INN, RESORT, CONDO, LUXURY, COUNTRY} tHotelType;

typedef struct
	{
		int num;
		int id;
		char brand[MAX_STRING];
		char name[MAX_STRING];
		tHotelType hotelType;
		char city[MAX_STRING];
		int category;
		float priceDouble;
		float distanceFromCityCenter;
		boolean hasPool;
		boolean hasGym;
		boolean closeToSubway;
		float percentOccupation;
	}tHotel;

int main(int argc, char **argv)
{

	tHotel hotel1;
	tHotel hotel2;
	tHotel hotel3;
	char cityVisited[MAX_STRING];
	float maxPrice;
	tHotel bestHotel;
		
	//input hoteles 
	printf("ENTER DATA FOR HOTEL 1 \n");
	hotel1.num = 1;
	printf("ID >> \n");
	scanf(" %d",&hotel1.id);
	printf("BRAND >> \n");
	scanf("%s",hotel1.brand);
	printf("NAME >> \n");
	scanf("%s",hotel1.name);
	printf("CITY >> \n");
	scanf("%s",hotel1.city);
	printf("CATEGORY (AN INTEGER) >> \n");
	scanf("%d",&hotel1.category);
	printf("TYPE (0-BUDGET, 1-INN, 2-RESORT, 3-CONDO, 4-LUXURY, 5-COUNTRY) >> \n");
	scanf("%u",&hotel1.hotelType);
	printf("PRICE FOR A DOUBLE ROOM >> \n");
	scanf("%f",&hotel1.priceDouble);
	printf("DISTANCE TO CITY CENTER (IN KM) >> \n");
	scanf("%f",&hotel1.distanceFromCityCenter);
	printf("IS IT CLOSE TO A SUBWAY STATION? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel1.closeToSubway);
	printf("HAS SWIMMING POOL? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel1.hasPool);
	printf("HAS GYM? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel1.hasGym);
	printf("PERCENT OCCUPATION >> \n");
	scanf("%f",&hotel1.percentOccupation);
	
	printf("ENTER DATA FOR HOTEL 2 \n");
	hotel2.num = 2;
	printf("ID >> \n");
	scanf(" %d",&hotel2.id);
	printf("BRAND >> \n");
	scanf("%s",hotel2.brand);
	printf("NAME >> \n");
	scanf("%s",hotel2.name);
	printf("CITY >> \n");
	scanf("%s",hotel2.city);
	printf("CATEGORY (AN INTEGER) >> \n");
	scanf("%d",&hotel2.category);
	printf("TYPE (0-BUDGET, 1-INN, 2-RESORT, 3-CONDO, 4-LUXURY, 5-COUNTRY) >> \n");
	scanf("%u",&hotel2.hotelType);
	printf("PRICE FOR A DOUBLE ROOM >> \n");
	scanf("%f",&hotel2.priceDouble);
	printf("DISTANCE TO CITY CENTER (IN KM) >> \n");
	scanf("%f",&hotel2.distanceFromCityCenter);
	printf("IS IT CLOSE TO A SUBWAY STATION? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel2.closeToSubway);
	printf("HAS SWIMMING POOL? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel2.hasPool);
	printf("HAS GYM? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel2.hasGym);
	printf("PERCENT OCCUPATION >> \n");
	scanf("%f",&hotel2.percentOccupation);
	
	printf("ENTER DATA FOR HOTEL 3\n");
	hotel3.num = 3;
	printf("ID >> \n");
	scanf(" %d",&hotel3.id);
	printf("BRAND >> \n");
	scanf("%s",hotel3.brand);
	printf("NAME >> \n");
	scanf("%s",hotel3.name);
	printf("CITY >> \n");
	scanf("%s",hotel3.city);
	printf("CATEGORY (AN INTEGER) >> \n");
	scanf("%d",&hotel3.category);
	printf("TYPE (0-BUDGET, 1-INN, 2-RESORT, 3-CONDO, 4-LUXURY, 5-COUNTRY) >> \n");
	scanf("%u",&hotel3.hotelType);
	printf("PRICE FOR A DOUBLE ROOM >> \n");
	scanf("%f",&hotel3.priceDouble);
	printf("DISTANCE TO CITY CENTER? (IN KM) >> \n");
	scanf("%f",&hotel3.distanceFromCityCenter);
	printf("IS IT CLOSE TO A SUBWAY STATION? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel3.closeToSubway);
	printf("HAS SWIMMING POOL? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel3.hasPool);
	printf("HAS GYM? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&hotel3.hasGym);
	printf("PERCENT OCCUPATION >> \n");
	scanf("%f",&hotel3.percentOccupation);
	
	printf("TYPE THE MAXIMUM PRICE FOR THE HOTEL >> \n");
	scanf("%f",&maxPrice);
	printf("TYPE THE CITY WHERE YOU WANT THE HOTEL >> \n");
	scanf("%s",cityVisited);
	//Evalua Si coincide con la ciudad Y Cual es el precio... 
	if ( (strcmp(hotel1.city,cityVisited) == 0) && (strcmp(hotel2.city,cityVisited) == 0) && (strcmp(hotel3.city,cityVisited) == 0) )
	{
		if( (hotel1.priceDouble <= hotel2.priceDouble) && (hotel1.priceDouble <= hotel3.priceDouble) && (hotel1.priceDouble <= maxPrice) )
		{
			bestHotel = hotel1;
		}
		else if( (hotel2.priceDouble <= hotel3.priceDouble) && (hotel2.priceDouble < hotel1.priceDouble) && (hotel2.priceDouble <= maxPrice) )
		{
			bestHotel = hotel2;
		}
		else if ( (hotel3.priceDouble < hotel1.priceDouble) && (hotel3.priceDouble < hotel2.priceDouble) && (hotel3.priceDouble <= maxPrice) )
		{
			bestHotel = hotel3;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if ( (strcmp(hotel1.city,cityVisited) == 0) && (strcmp(hotel2.city,cityVisited) == 0) && (strcmp(hotel3.city,cityVisited) != 0) )
	{
		if( (hotel1.priceDouble <= hotel2.priceDouble) && (hotel1.priceDouble <= maxPrice) )
		{
			bestHotel = hotel1;
		}
		else if( (hotel2.priceDouble < hotel1.priceDouble) && (hotel2.priceDouble <= maxPrice) )
		{
			bestHotel = hotel2;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if ( (strcmp(hotel1.city,cityVisited) == 0) && (strcmp(hotel3.city,cityVisited) == 0) && (strcmp(hotel2.city,cityVisited) != 0) )
	{
		if( (hotel1.priceDouble <= hotel3.priceDouble) && (hotel1.priceDouble <= maxPrice) )
		{
			bestHotel = hotel1;
		}
		else if( (hotel3.priceDouble < hotel1.priceDouble) && (hotel3.priceDouble <= maxPrice) )
		{
			bestHotel = hotel3;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if ( (strcmp(hotel2.city,cityVisited) == 0) && (strcmp(hotel3.city,cityVisited) == 0) && (strcmp(hotel1.city,cityVisited) != 0) )
	{
		if( (hotel2.priceDouble <= hotel3.priceDouble) && (hotel2.priceDouble <= maxPrice) )
		{
			bestHotel = hotel2;
		}
		else if( (hotel3.priceDouble < hotel2.priceDouble) && (hotel3.priceDouble <= maxPrice) )
		{
			bestHotel = hotel3;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if ( (strcmp(hotel1.city,cityVisited) == 0) && (strcmp(hotel2.city,cityVisited) != 0) && (strcmp(hotel3.city,cityVisited) != 0) )
	{
		if( (hotel1.priceDouble <= maxPrice) )
		{
			bestHotel = hotel1;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if ((strcmp(hotel1.city,cityVisited) != 0) && (strcmp(hotel2.city,cityVisited) == 0) && (strcmp(hotel3.city,cityVisited) != 0))
	{
		if( (hotel2.priceDouble <= maxPrice) )
		{
			bestHotel = hotel2;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else if( (strcmp(hotel1.city,cityVisited) != 0) && (strcmp(hotel2.city,cityVisited) != 0) && (strcmp(hotel3.city,cityVisited) == 0) )
	{
		if( (hotel2.priceDouble <= maxPrice) )
		{
			bestHotel = hotel3;
		}
		else
		{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
		}
	}
	else
	{
			printf("THERE IS NO HOTEL WITH THE DESIRED CONDITIONS \n");
			return 0;
	}
//Output Final		
	printf("THE BEST HOTEL IS NUMBER %d \n",bestHotel.num);
	printf("NAME: %s \n",bestHotel.name);
	printf("CITY: %s \n",bestHotel.city);
	printf("CATEGORY: %d \n",bestHotel.category);
	printf("TYPE: %u \n", bestHotel.hotelType);
	printf("PRICE FOR A DOUBLE ROOM: %.2f \n",bestHotel.priceDouble);
	
	return 0;

}
