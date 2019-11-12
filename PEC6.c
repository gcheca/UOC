#include <stdio.h>
#include <string.h>

#define MAX_STRING 15
//Declaro tipos enum
typedef enum {FALSE, TRUE} boolean;
typedef enum {BUDGET, INN, RESORT, CONDO, LUXURY, COUNTRY} tHotelType;

typedef struct
	{
		int id;
		char brand[MAX_STRING];
		char name[MAX_STRING];
		tHotelType typeHotel;
		char city[MAX_STRING];
		int category;
		float priceDouble;
		float distanceFromCityCenter;
		boolean hasPool;
		boolean hasGym;
		boolean closeToSubway;
		float percentOccupation;
	}tHotel;

//headers
void hotelRead(tHotel *h);
void hotelWrite(tHotel h);
int hotelCmp(tHotel h1, tHotel h2);
boolean hotelAcceptable(tHotel h, float maxDistance, float maxPrice);

int main(int argc, char **argv)
{
	tHotel h1;
	tHotel h2;
	float maxDistance;
	float maxPrice;
	//Pide Datos de h1 h2 y máximos
	printf("ENTER DATA FOR HOTEL 1 \n");
	hotelRead(&h1);
	printf("ENTER DATA FOR HOTEL 2 \n");
	hotelRead(&h2);
	
	printf("WHAT'S THE MAXIMUM ACCEPTABLE PRICE? >> \n");
	scanf("%f",&maxPrice);
	printf("WHAT'S THE MAXIMUM ACCEPTABLE DISTANCE FROM CITY CENTER? >> \n");
	scanf("%f",&maxDistance);
	//En base a lo que salga de la función hotelAcceptable... compara o no
	if ( (hotelAcceptable(h1,maxDistance,maxPrice) == TRUE) && ((hotelAcceptable(h2,maxDistance,maxPrice) == TRUE)) )
	{
		if(strcmp(h1.city,h2.city) == 0)
		{
			if(hotelCmp(h1,h2) < 1)
			{
				printf("THE HOTEL 1 SUITS YOU BETTER, AND THE DATA ARE \n");
				hotelWrite(h1);
				printf("THE SECOND BEST HOTEL IS HOTEL 2 AND THE DATA ARE \n");
				hotelWrite(h2);
			}
			else
			{
				printf("THE HOTEL 2 SUITS YOU BETTER, AND THE DATA ARE \n");
				hotelWrite(h2);
				printf("THE SECOND BEST HOTEL IS HOTEL 1 AND THE DATA ARE \n");
				hotelWrite(h1);
			}
		}
		else
		{
			printf("THE HOTELS CAN'T BE COMPARED \n");
		}
		
	}
	else
		{
			printf("THE HOTELS CAN'T BE COMPARED \n");
		}
		
	return 0;
}

void hotelRead(tHotel *h)
{
	printf("ID >> \n");
	scanf("%d",&h->id);
	printf("BRAND >> \n");
	scanf("%s",h->brand);
	printf("NAME >> \n");
	scanf("%s",h->name);
	printf("CITY >> \n");
	scanf("%s",h->city);
	printf("CATEGORY (AN INTEGER) >> \n");
	scanf("%d",&h->category);
	printf("TYPE (0-BUDGET, 1-INN, 2-RESORT, 3-CONDO, 4-LUXURY, 5-COUNTRY) >> \n");
	scanf("%u",&h->typeHotel);
	printf("PRICE FOR A DOUBLE ROOM >> \n");
	scanf("%f",&h->priceDouble);
	printf("DISTANCE TO CITY CENTER? (IN KM) >> \n");
	scanf("%f",&h->distanceFromCityCenter);
	printf("IS IT CLOSE TO A SUBWAY STATION? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&h->closeToSubway);
	printf("HAS SWIMMING POOL? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&h->hasPool);
	printf("HAS GYM? (0-FALSE, 1-TRUE) >> \n");
	scanf("%u",&h->hasGym);
	printf("PERCENT OCCUPATION >> \n");
	scanf("%f",&h->percentOccupation);
}

void hotelWrite(tHotel h)
{
	printf("HOTEL'S DATA: \n");
	printf("ID: %d\n", h.id);
	printf("BRAND: %s\n", h.brand);
	printf("NAME: %s\n", h.name);
	printf("CITY: %s\n", h.city);
	printf("CATEGORY: %d\n", h.category);
	printf("TYPE: %u\n", h.typeHotel);
	printf("PRICE FOR A DOUBLE ROOM: %.2f\n", h.priceDouble);
	printf("DISTANCE TO CITY CENTER: %.2f\n", h.distanceFromCityCenter);
	printf("CLOSE TO A SUBWAY STATION: ");
	if (h.closeToSubway) printf ("YES\n");
	else printf("NO\n");
	printf("HAS SWIMMING POOL: ");
	if (h.hasPool) printf ("YES\n");
	else printf("NO\n");
	printf("HAS A GYM: ");
	if (h.hasGym) printf ("YES\n");
	else printf("NO\n");
	printf("PERCENT OCCUPATION: %.2f\n", h.percentOccupation);
}
//Funcion Compara hotel segun especificaciones
int hotelCmp(tHotel h1, tHotel h2)
{
	int result=0;

	if(strcmp(h1.brand, h2.brand) > 0)
	{
		result = 1;
	}
	else if (strcmp(h1.brand, h2.brand) < 0)
	{
		result = -1;
	}
	else
	{
		if(h1.category > h2.category)
		{
			result = 1;
		}
		else if (h1.category < h2.category)
		{
			result = -1;
		}
		else
		{
			if(h1.priceDouble > h2.priceDouble)
			{
				result = 1;
			}
			else if(h1.priceDouble < h2.priceDouble)
			{
				result = -1;
			}
			else
			{
				if(h1.distanceFromCityCenter > h2.distanceFromCityCenter)
				{
					result = 1;
				}
				else if(h1.distanceFromCityCenter < h2.distanceFromCityCenter)
				{
					result = -1;
				}
				else
				{
					if(h1.percentOccupation > h2.percentOccupation)
					{
						result = 1;
					}
					else if(h1.percentOccupation < h2.percentOccupation)
					{
						result = -1;
					}
					else
					{
						if(h1.closeToSubway > h2.closeToSubway)
						{
							result = 1;
						}
						else if(h1.closeToSubway < h2.closeToSubway)
						{
							result = -1;
						}
						else
						{
							if(h1.hasPool > h2.hasPool)
							{
								result = 1;
							}
							else if(h1.hasPool < h2.hasPool)
							{
								result = -1;
							}
							else
							{
								if(h1.hasGym > h2.hasGym)
								{
									result = 1;
								}
								else if(h1.hasGym < h2.hasGym)
								{
									result = -1;
								}
							}
						}
					}
				}
			}
		}
	}	
	return result;
}	
//Funcion Booleana, si el hotel es aceptable TRUE
boolean hotelAcceptable (tHotel h, float maxDistance, float maxPrice)
{
	boolean isAcceptable = FALSE;
	boolean hasPoolGym = FALSE;
	boolean isNear = FALSE;
	boolean isPrice = FALSE;
	
	hasPoolGym = (h.hasPool || h.hasGym);
	isNear = ((h.distanceFromCityCenter <= maxDistance) || (h.closeToSubway == TRUE)); 
	isPrice = (h.priceDouble <= maxPrice);
	
	isAcceptable = hasPoolGym && isNear;
	isAcceptable = isAcceptable && isPrice;
	
	return isAcceptable;
}
