#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

void getCustomerStr(tCustomer customer, int maxSize, char *str) 
{
	int length= 0;
    /* Uncomment to test */
	length = snprintf(str,maxSize-1,"%d %s %s %s %d %d %d %s %d %d %d %d %.2f", 
        customer.id, customer.name, customer.surname, customer.docNumber, 
        customer.birthDate.year, customer.birthDate.month, customer.birthDate.day, 
        customer.birthCity, (int)customer.status, (int)customer.profile, customer.bookingsCounter,
        customer.points, customer.satisfaction);
    /**/
	if (length>0) 
		str[length]='\0';
}

void getCustomerObject(const char *str, tCustomer *customer) 
{	
    int id= 0;
    /* Uncomment to test*/
	int status, profile;
	sscanf(str, "%d %s %s %s %d %d %d %s %d %d %d %d %f", &(id), customer->name, customer->surname, 
        customer->docNumber, &(customer->birthDate.year), &(customer->birthDate.month), &(customer->birthDate.day),
        customer->birthCity, &status, &profile, &customer->bookingsCounter, 
        &customer->points, &customer->satisfaction);
	customer->status = (tCivilState)(status);
	customer->profile = (tProfile)(profile);
    /**/
	customer->id = (tCustomerId)(id);
}

int date_cmp( tDate d1, tDate d2 ) {
    
    int result;
    
    result= 0;

    if (d1.year > d2.year)
        result= 1;
    else if (d1.year < d2.year)
        result= -1;
    else {
        if (d1.month > d2.month)
            result= 1;
        else if (d1.month < d2.month)
            result= -1;
        else {
            if (d1.day > d2.day)
                result= 1;
            else if (d1.day < d2.day)
                result= -1;
        }
    }
    
    return result;
}

void customerTable_init(tCustomerTable *customerTable) {
	
	customerTable->nCustomers=0;
}

void convertToUpper( char *string )
{
    int i, len;
    char originalChar;
    
    len= strlen(string);
    for (i= 0; i < len; i++) {
        originalChar= string[i];
        if (originalChar >= 'a' && originalChar <= 'z') 
            string[i]= originalChar + 'A' - 'a';
    }
}

int strcmpUpper( char *s1, char *s2 )
{
    int result= 0;
/*************** PR1 EX3A *****************/
	char s1Up[MAX_NAME];
	char s2Up[MAX_NAME];
	
	strcpy(s1Up,s1);
	strcpy(s2Up,s2);
	
	convertToUpper(s1Up);
	convertToUpper(s2Up);
	
	result= (strcmp(s1Up,s2Up));

/******************************************/
    return result;
}

int customer_cmp(tCustomer d1, tCustomer d2) 
{	
	int result = 0;
/*************** PR1 EX3B *****************/
	result = strcmpUpper(d1.name,d2.name);
	if(result==0)
	{
		result = strcmpUpper(d1.surname,d2.surname);
		if(result==0)
		{
			result = strcmpUpper(d1.docNumber,d2.docNumber);
			if(result==0)
			{
				result = date_cmp(d1.birthDate,d2.birthDate);
				if(result==0)
				{
					result = strcmpUpper(d1.birthCity,d2.birthCity);
					if(result==0)
					{
						if(d1.status > d2.status)
							result = 1;
						else if(d1.status < d2.status)
							result = -1;
						else
						{
							if(d1.profile > d2.profile)
								result = 1;
							else if(d1.profile > d2.profile)
								result = -1;
							else
							{
								if(result==0)
								{
									if(d1.bookingsCounter > d2.bookingsCounter)
										result = 1;
									else if(d1.bookingsCounter < d2.bookingsCounter)
										result = -1;
									else
									{
										if(d1.points > d2.points)
											result = 1;
										else if(d1.points < d2.points)
											result = -1;
										else
										{
											if(d1.satisfaction > d2.satisfaction)
												result = 1;
											else if(d1.satisfaction < d2.satisfaction)
												result = -1;
										}
									}		
								}
							}	
						}
					}
				}
			}
		}
	}
/******************************************/
    return result;
}

void customer_cpy(tCustomer *dst, tCustomer src) 
{    
    dst->id = src.id; 
    /* Uncomment to test*/
    strcpy(dst->name,src.name);
    strcpy(dst->surname,src.surname);
    strcpy(dst->docNumber,src.docNumber);
    dst->birthDate.year = src.birthDate.year;
    dst->birthDate.month = src.birthDate.month;
    dst->birthDate.day = src.birthDate.day;
    strcpy(dst->birthCity,src.birthCity);
    dst->status = src.status;
    dst->profile = src.profile;    
    dst->bookingsCounter = src.bookingsCounter;
    dst->points= src.points;
    dst->satisfaction= src.satisfaction;
    /**/
}

void customerTable_add(tCustomerTable *tabCustomer, tCustomer customer, tError *retVal) {

	*retVal = OK;

	/* Check if there enough space for the new customer */
	if(tabCustomer->nCustomers>=MAX_CUSTOMERS)
		*retVal = ERR_MEMORY;

	if (*retVal == OK) {
		/* Add the new customer to the end of the table */
		customer_cpy(&tabCustomer->table[tabCustomer->nCustomers],customer);
		tabCustomer->nCustomers++;
	}

}

int customerTable_find(tCustomerTable tabCustomer, tCustomerId id) {

	int idx = NO_CUSTOMER;
	
	int i=0;
	while(i< tabCustomer.nCustomers && idx==NO_CUSTOMER) {
		/* Check if the id is the same */
		if(tabCustomer.table[i].id==id) {
			idx = i;
		}
		i++;
	}
	
	return idx;
}

void customerTable_del(tCustomerTable *tabCustomer, tCustomer customer) 
{	
/*************** PR1 EX7 *****************/
	int i;
	int pos;
	
	pos = customerTable_find(*tabCustomer,customer.id);
	if(pos!=NO_CUSTOMER)
	{
		for(i=pos; i < tabCustomer->nCustomers-1;i++)
		{
			customer_cpy(&tabCustomer->table[i],tabCustomer->table[i+1]);
		}
		tabCustomer->nCustomers=tabCustomer->nCustomers-1;
	}
				
/******************************************/
}

void customerTable_save(tCustomerTable tabCustomer, const char* filename, tError *retVal) {

	*retVal = OK;
	
	FILE *fout=0;
	int i;
	char str[MAX_LINE];
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))==0) {
		*retVal = ERR_CANNOT_WRITE;
	} else {
	
        /* Save all customers to the file */
        for(i=0;i<tabCustomer.nCustomers;i++) {
            getCustomerStr(tabCustomer.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);
        }
            
        /* Close the file */
        fclose(fout);
	}
}

void customerTable_load(tCustomerTable *tabCustomer, const char* filename, tError *retVal) {
	
	*retVal = OK;
	
	FILE *fin=0;
	char line[MAX_LINE];
	tCustomer newCustomer;
	
	/* Initialize the output table */
	customerTable_init(tabCustomer);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))!=NULL) {

		/* Read all the lines */
		while(!feof(fin) && tabCustomer->nCustomers<MAX_CUSTOMERS) {
			/* Remove any content from the line */
			line[0] = '\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE-1, fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getCustomerObject(line, &newCustomer);
				/* Add the new customer to the output table */
				customerTable_add(tabCustomer, newCustomer, retVal);		
			}
		}
		/* Close the file */
		fclose(fin);
		
	}else {
		*retVal = ERR_CANNOT_READ;
	}
}

int calculateAge( tDate birthDate )
{
   return 2019 - birthDate.year;
}

void customerTable_selectCustomers(tCustomerTable customers, char *city, tCustomerTable *result) 
{
/*************** PR1 EX4A *****************/
	int i;
	tError retVal;
	
	customerTable_init(result);
	
	for(i=0;i<customers.nCustomers;i++)
	{
		if(strcmpUpper(city,customers.table[i].birthCity) != 0) //IF DIFERENT CITY
		{
			if( ((calculateAge(customers.table[i].birthDate))>=25 && (calculateAge(customers.table[i].birthDate))<=35) ) //IF aGE
			{
				if(customers.table[i].status == 0) //IF STATUS
				{
					if( (customers.table[i].profile == 3) || (customers.table[i].profile == 4) || (customers.table[i].profile == 5) ) // IF PROFILE
					{
						customerTable_add(result,customers.table[i],&retVal);
					}
				}
			}
 		}
	}
/******************************************/
}

void customerTable_selectSatisfiedCustomers(tCustomerTable customers, tCustomerTable *result) {
/*************** PR1 EX4B *****************/
	int i;
	tError retVal;
	
	customerTable_init(result);
	
	for(i=0;i<customers.nCustomers;i++)
	{
		if( (customers.table[i].bookingsCounter>=10) )
		{
			if(customers.table[i].satisfaction>85)
			{
				customerTable_add(result,customers.table[i],&retVal);
			}
		}
	}
/******************************************/
}

float customerTable_getAvgPointsPerBooking(tCustomerTable tabCustomer) 
{
    float avg= 0.0;
/*************** PR1 EX6A *****************/ 
	int i;
	//INITIALIZED VARS FROM 0.0 (REAL NUMBERS)
	float tPoints= 0.0;
	float tBookings= 0.0;
	
	for(i=0;i<tabCustomer.nCustomers;i++)
	{
		if(tabCustomer.table[i].bookingsCounter)
		{
			tPoints = tPoints+tabCustomer.table[i].points;
			tBookings = tBookings+tabCustomer.table[i].bookingsCounter;
		}
	}
	//IF NOT CUSTOMERS. NO DIVISION
	if (tabCustomer.nCustomers>0)
	{
		avg = (tPoints/tBookings);
	}
/******************************************/
    return avg;
}

void customerTable_getMaxSatisfactionPerAgeInterval(tCustomerTable tabCustomer,
     float *upto29, float *between30and44, float *between45and59, float *from60) 
{
/*************** PR1 EX6B *****************/
	int i;
	//INITIALIZED VARS FROM 0.0 (REAL NUMBERS)
	*upto29=0.0;
	*between30and44=0.0;
	*between45and59=0.0;
	*from60=0.0;
	// ITERATIVE INITIAL... THEN SUB29, AND OTHERS...
	for(i=0;i<tabCustomer.nCustomers;i++)
	{
		if((calculateAge(tabCustomer.table[i].birthDate))<=29)
		{
			if(tabCustomer.table[i].satisfaction>*upto29)
			{
				*upto29=tabCustomer.table[i].satisfaction;
			}
		}
		
		if((calculateAge(tabCustomer.table[i].birthDate))>=30 && (calculateAge(tabCustomer.table[i].birthDate))<=44)
		{
			if(tabCustomer.table[i].satisfaction>*between30and44)
			{
				*between30and44=tabCustomer.table[i].satisfaction;
			}
		}
		
		if((calculateAge(tabCustomer.table[i].birthDate))>=45 && (calculateAge(tabCustomer.table[i].birthDate))<=59)
		{
			if(tabCustomer.table[i].satisfaction>*between45and59)
			{
				*between45and59=tabCustomer.table[i].satisfaction;
			}
		}
		
		if((calculateAge(tabCustomer.table[i].birthDate))>=60)
		{
			if(tabCustomer.table[i].satisfaction>*from60)
			{
				*from60=tabCustomer.table[i].satisfaction;
			}
		}
	}
/******************************************/
}

