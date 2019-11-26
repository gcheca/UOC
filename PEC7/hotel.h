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
	
void hotelRead(tHotel *h);
void hotelWrite(tHotel h);
int hotelComputePoints (tHotel h, float price, float distance);
void hotelCmpPoints(tHotel *h3, tHotel h1, tHotel h2, float price, float distance);
