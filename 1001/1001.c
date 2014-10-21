/*PKU Judge Online 1001	*/
/*From: 	Yinsong Xu	*/
/*Begin: 	Oct 15,2014	*/
/*End:					*/
/*Version:	1.0			*/
/*This version will use the most stupid way to make the goal as fast as I can*/

/*This program is used to be calculate some large number which could be larger than 2^32*/
/*Input:	six base numbers and the six power numbers of the base numbers*/
/*Output:	six results of them*/

#include <stdio.h>		//basic I/O head file. To use scanf() printf()
#include <stdlib.h>		//To use exit()
#include <string.h>		//To use strlen()
#define NUM_INPUT 6		//Set the total input number to 6
#define MAX_DIGIT 200	//Set the max digits of the array which store the input numbers

/*Main function*/
int main(){
	/*Set the variables*/
	char* baseStr[NUM_INPUT];			//To save the base numbers array while user input
	int power[NUM_INPUT];				//To save the power numbers of the base numbers
	int baseNum[NUM_INPUT][MAX_DIGIT];	//To save the integers of the base number
	int result[NUM_INPUT][MAX_DIGIT];	//To save the results
	int point[NUM_INPUT];				//To save the point of each numbers
	int digitBase[NUM_INPUT];			//To save the digits of base numbers
	int digitResult[NUM_INPUT];			//To save the digits of result
	int i,j,k;							//To use for the loops

	/*To get the inputs*/
	for( i=0; i<6; i++){
		scanf("%s %d", baseStr[i], power[i]);	//To get inputs
		digitBase[i]=strlen(baseStr[i]);			//To save the total digits of each base numbers
	}

	/*Transfer the base numbers from string to integer */
	for( i=0; i<6; i++){
		k=0;										//Use to store the integer
		for( j=digitBase[i]; j=0, j--){					//Loop untill hit the end of the string
			if( (baseStr[j]<48) || (baseStr[j]>57)){//If the character is not a number, exit
				if( (baseStr[j]=='.')){				//If the character is the point
					point[i]=j;						//remeber the point position
					digitBase[i]--;
				}
				else{
					exit(0);					//else will exit
				}
			}
			baseNum[i][k]=baseStr[i][j]-'0';
			k++;
		}
	}

	/*Calculation*/
	for( i=0; i<6; i++){
		result[i][0]=1;
	}
}