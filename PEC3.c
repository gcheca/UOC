#include <stdio.h>
#include <float.h>

#define NAME_HOTEL1 "SUN"
#define NAME_HOTEL2 "MOON"
#define NAME_HOTEL3 "EARTH"
#define MAX_HOTELS 3;
#define MAX_DISCOUNT 50;
#define HOTEL1 1;
#define HOTEL2 2;
#define HOTEL3 3;
#define MIN_DISCOUNT 0;

typedef enum {FALSE, TRUE} boolean;
typedef enum {BUDGET, INN, RESORT, CONDO, LUXURY, COUNTRY} tTypeHotel;

int main(int argc, char **argv)
{
	//int HOTELS [3];
	int DISCOUNT_HOTELS [3];
	int PRICE_HOTELS [3];
	float DISPRICE_HOTELS [3];
	float SINGLE_HOTELS [3];	
	int numGuests;
	
	printf("PRICE DOUBLE ROOM HOTEL SUN >> \n");
	scanf("%d",&PRICE_HOTELS[0]);
	printf("PRICE DOUBLE ROOM HOTEL MOON >> \n");
	scanf("%d",&PRICE_HOTELS[1]);
	printf("PRICE DOUBLE ROOM HOTEL EARTH >> \n");
	scanf("%d",&PRICE_HOTELS[2]);
	
	printf("DISCOUNT FOR GROUPS BIGGER THAN 10. HOTEL SUN >>  \n");
	scanf("%d",&DISCOUNT_HOTELS[0]);
	
	printf("DISCOUNT FOR GROUPS BIGGER THAN 10. HOTEL MOON >> \n");
	scanf("%d",&DISCOUNT_HOTELS[1]);
	
	printf("DISCOUNT FOR GROUPS BIGGER THAN 10. HOTEL EARTH >> \n");
	scanf("%d",&DISCOUNT_HOTELS[2]);
	
	
	printf("NUM CLIENTS >> \n");
	scanf("%d",&numGuests);
	
		
	if ((DISCOUNT_HOTELS[0] < 0) || (DISCOUNT_HOTELS[0] > 50))
		{
			printf("INCORRECT INPUT DATA. START AGAIN \n");
			return 0;
		}else if ((DISCOUNT_HOTELS[1] < 0) || (DISCOUNT_HOTELS[1] > 50))
		{
			printf("INCORRECT INPUT DATA. START AGAIN \n");
			return 0;
		}else if ((DISCOUNT_HOTELS[2] < 0) || (DISCOUNT_HOTELS[2] > 50))
		{
			printf("INCORRECT INPUT DATA. START AGAIN \n");
			return 0;
		}
	
	//Operaciones si NO es grupo
	if(numGuests<=10)
		{
			SINGLE_HOTELS[0] = ( (float)(numGuests/2) * PRICE_HOTELS[0] + (numGuests%2) * (float)PRICE_HOTELS[0] );
			SINGLE_HOTELS[1] = ( (float)(numGuests/2) * PRICE_HOTELS[1] + (numGuests%2) * (float)PRICE_HOTELS[1] );
			SINGLE_HOTELS[2] = ( (float)(numGuests/2) * PRICE_HOTELS[2] + (numGuests%2) * (float)PRICE_HOTELS[2] );
			/*
			SINGLE_HOTELS[0] = ( PRICE_HOTELS[0] / (numGuests) );
			SINGLE_HOTELS[1] = ( PRICE_HOTELS[1] / (numGuests) );
			SINGLE_HOTELS[2] = ( PRICE_HOTELS[2] / (numGuests) );*/
			
			if(SINGLE_HOTELS[0] <= SINGLE_HOTELS[1] && SINGLE_HOTELS[0] <= SINGLE_HOTELS[2])
				{
					printf("THE MOST ECONOMIC HOTEL IS SUN \n");
					printf("THE TOTAL COST IS %.2f \n",SINGLE_HOTELS[0]);
				}
				else if (SINGLE_HOTELS[0] > SINGLE_HOTELS[1] && SINGLE_HOTELS[1] <= SINGLE_HOTELS[2])
					{
						printf("THE MOST ECONOMIC HOTEL IS MOON \n");	
						printf("THE TOTAL COST IS %.2f \n",SINGLE_HOTELS[1]);
					}
					else if (SINGLE_HOTELS[2] < SINGLE_HOTELS[1] && SINGLE_HOTELS[2] < SINGLE_HOTELS[0])
					{
						printf("THE MOST ECONOMIC HOTEL IS EARTH \n");
						printf("THE TOTAL COST IS %.2f \n",SINGLE_HOTELS[2]);
					}
			return 0;
		}
	
	//precio CON descuento
	
	if (numGuests>10)  
	{
		DISPRICE_HOTELS[0] = ( (float) (numGuests/2) * PRICE_HOTELS[0] + (numGuests%2) * PRICE_HOTELS[0] ) * ( (float) (100-DISCOUNT_HOTELS[0])/100);
		DISPRICE_HOTELS[1] = ( (float) (numGuests/2) * PRICE_HOTELS[1] + (numGuests%2) * PRICE_HOTELS[1] ) * ( (float) (100-DISCOUNT_HOTELS[1])/100);
		DISPRICE_HOTELS[2] = ( (float) (numGuests/2) * PRICE_HOTELS[2] + (numGuests%2) * PRICE_HOTELS[2] ) * ( (float) (100-DISCOUNT_HOTELS[2])/100);

	
	if (DISPRICE_HOTELS[0] <= DISPRICE_HOTELS[1] && DISPRICE_HOTELS[0] <= DISPRICE_HOTELS[2])
		{
			printf("THE MOST ECONOMIC HOTEL IS SUN \n");
			printf("THE TOTAL COST IS %.2f \n",DISPRICE_HOTELS[0]);
			
		}
		else if (DISPRICE_HOTELS[0] > DISPRICE_HOTELS[1] && DISPRICE_HOTELS[1] <= DISPRICE_HOTELS[2])
			{
				printf("THE MOST ECONOMIC HOTEL IS MOON \n");	
				printf("THE TOTAL COST IS %.2f \n",DISPRICE_HOTELS[1]);			
			}
			else if (DISPRICE_HOTELS[2] < DISPRICE_HOTELS[1] && DISPRICE_HOTELS[2] < DISPRICE_HOTELS[0])
			{
				printf("THE MOST ECONOMIC HOTEL IS EARTH \n");
				printf("THE TOTAL COST IS %.2f \n",DISPRICE_HOTELS[2]);
			}

	
	return 0;
	}
}
