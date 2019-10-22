#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 10
#define START_ALPHA 97
#define START_NUMBERS 48
#define ALPHA 26
#define NUMBERS 10
#define KEY 3

typedef enum {FALSE, TRUE} boolean;

int main(int argc, char **argv)
{
	char password[MAX_CHARACTERS];
	int numRepetitions;
	int i;
	int j;
	int iteration;
	int digits;
	int letters;
	
	//Pide el numero de repeticiones que hará el bucle de cifrado
	printf("HOW MANY REPETITIONS DO YOU WANT TO PERFORM (1 TO 100)? >> \n");
	scanf("%d",&numRepetitions);
	//Mientras el numero no sea válido, se repite...
	while(numRepetitions<=0 || numRepetitions>100)
	{
		printf("INCORRECT NUMBER, PLEASE ENTER IT AGAIN.\n");
		printf("HOW MANY REPETITIONS DO YOU WANT TO PERFORM (1 TO 100)? >> \n");
		scanf("%d",&numRepetitions);
	}
	iteration=0;
	
	//Inicio Bucle repeticiones
	for (i=numRepetitions;i>0;i--)
	{
		printf("ENTER A 10 CHARACTERS PASSWORD CHARACTER BY CHARACTER – ONLY LOWER CASE LETTERS OR DIGITS >> \n");
		scanf("%s",password);
		digits=0; 
		letters=0;
		
		//Inicio Bucle leer caracteres en vector
		for (j=0;j<strlen(password);j++)
		{
			//If es numero... if es letra...
			if (password[j] >='0' && password[j] <='9') 
			{
				password[j]= (((((int)(password[j]-START_NUMBERS)*9) + 1)%NUMBERS) + START_NUMBERS);
				digits++;
				
			}
			else if (password[j]>='a'&& password[j]<='z')
			{
				password[j]=((((password[j]-START_ALPHA) + KEY)%ALPHA) + START_ALPHA);
				letters++;
			}
		}
		iteration++;
		
		printf("[ITERATION %d]THE ENCRYPTED PASSWORD IS: %s \n",iteration,password);
		printf("IT HAS %d DIGITS AND %d LETTERS \n",digits,letters);
	}
	printf("DONE! \n");
	return 0;
}
