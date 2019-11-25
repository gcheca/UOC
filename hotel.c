#include <stdio.h>
#include <string.h>
#include "hotel.h"

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

void hotelCopy(tHotel *dest, tHotel src)
{
	dest->id = src.id;
	strcpy(dest->brand,src.brand);
	strcpy(dest->name,src.name);
	strcpy(dest->city,src.city);
	dest->category = src.category;
	dest->typeHotel = src.typeHotel;
	dest->priceDouble = src.priceDouble;
	dest->distanceFromCityCenter = src.distanceFromCityCenter;
	dest->closeToSubway = src.closeToSubway;
	dest->hasPool = src.hasPool;
	dest->hasGym = src.hasGym;
	dest->percentOccupation = src.percentOccupation;
}

int hotelComputePoints (tHotel h, float price, float distance)
{
	int i;i = 0;
	
	if (h.hasPool == TRUE || h.hasGym == TRUE)
	{i=i+5;}
	else 
	{i=0;}
	
	if(h.closeToSubway == TRUE)
	{i=i+5;}
	else
	{i=i;}
	
	i=i+(100*((price - h.priceDouble)/price))+(100*((distance - h.distanceFromCityCenter)/distance));

	printf("PUNCTUATION FOR HOTEL %s: %d \n",h.name,i);
	return i;
}

void hotelCmpPoints(tHotel *h3, tHotel h1, tHotel h2, float price, float distance)
{
	int hot1,hot2;
	
	printf("WHAT'S THE OPTIMAL DISTANCE? >> \n");
	scanf("%f",&distance);
	printf("WHAT'S THE OPTIMAL PRICE? >> \n");
	scanf("%f",&price);
	
	hot1 = hotelComputePoints(h1,price,distance);
	hot2 = hotelComputePoints(h2,price,distance);
	
	if (hot1 >= hot2)
	{hotelCopy(h3,h1);}
	else if (hot1 < hot2)
	{hotelCopy(h3,h2);}
}