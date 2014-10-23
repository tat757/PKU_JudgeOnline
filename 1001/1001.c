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
#include <string.h>		//To use strlen() memset()
#define NUM_INPUT 6		//Set the total input number to 6
#define MAX_DIGIT 200	//Set the max digits of the array which store the input numbers
#define MAX_RESULT_DIGIT 200*2+10 		//Set the max digit of result


/*Main function*/
int main(){
	/*Set the variables*/
	char baseStr[NUM_INPUT][MAX_DIGIT];			//To save the base numbers array while user input
	int power[NUM_INPUT];						//To save the power numbers of the base numbers
	unsigned baseNum[NUM_INPUT][MAX_DIGIT];			//To save the integers of the base number
	unsigned result[NUM_INPUT][MAX_RESULT_DIGIT];			//To save the results
	int point[NUM_INPUT];						//To save the point of each numbers
	int digitBase[NUM_INPUT];					//To save the digits of base numbers
	int digitResult[NUM_INPUT];					//To save the digits of result
	int i,j,k,l;							//To use for the loops
	int check;
	/*To get the inputs*/
	for( i=0; i<NUM_INPUT; i++){
		scanf("%s %d", baseStr[i], &power[i]);	//To get inputs
		//printf("%s\n",baseStr[i]);
		digitBase[i]=strlen(baseStr[i]);			//To save the total digits of each base numbers
		memset(baseNum[i],0,sizeof(baseNum[i]));	//Set all initial digit to 0
		memset(result[i],0,sizeof(result[i]));		
	}
	printf("\npass inputs\n");
	/*Transfer the base numbers from string to integer */
	for( i=0; i<NUM_INPUT; i++){
		k=0;										//Use to store the integer
		for( j=digitBase[i]-1; j>=0; j--){					//Loop untill hit the end of the string
			//printf("%c\n",baseStr[i][j]);
			if( (baseStr[i][j]<48) || (baseStr[i][j]>57)){//If the character is not a number, exit
				if( (baseStr[i][j]=='.')){				//If the character is the point
					point[i]=j;						//remeber the point position
					digitBase[i]--;
					j--;
					//printf("point[%d]=%d\n",i,point[i]);
				}
				else{
					exit(0);					//else will exit
				}
			}
			baseNum[i][k]=baseStr[i][j]-'0';	//record the number
			//printf("baseNum[%d][%d]=%d",i,k,baseNum[i][k]);
			k++;
		}
	}
	printf("\npass transfer\n");
	/*Calculation*/
	for( i=0; i<NUM_INPUT; i++){
		result[i][0]=1;
		digitResult[i]=1;											//set the initial digit to 0
		check=0;
		for( j=0; j<power[i]; j++){
			printf("power=%d ",j);
			for( k=0; k<digitBase[i]; k++){
				for( l=0; l<digitResult[i]; l++){					//use digitResult will save time than use MAX_RESULT_DIGIT
					result[i][k+l]+=result[i][l]*baseNum[i][k];
					if((check)==0){									//remove the origin 1 in the result array
						result[i][k+l]--;
						check++;
					}
					printf("%d")
					if(result[i][k+l]>=10000){						//Set less than 10000 to avoid the number too large than the computer could store 
						result[i][k+l+1]+=result[i][k+l]/10000;
						result[i][k+l]%=10000;
					}
				}
				digitResult[i]=k+l;
			}
		}
		point[i]=point[i]*power[i];
	}

	for(i=0; i<NUM_INPUT; i++){										//make the number less than 10
		for(j=0;j<MAX_RESULT_DIGIT;j++){
			if(result[i][j]>=10){
				result[i][j+1]+=result[i][j]/10;
				result[i][j]%=10;
			}
		}
	}

	printf("\npass calculations\n");
	for( i=0;i<NUM_INPUT;i++){									
		check=0;													
		for( j=MAX_RESULT_DIGIT-1;j>=0;j--){
			if(check==1){
				printf("%d",result[i][j]);
				if(j==point[i]){
					printf(".");
				}
			}
			else if(result[i][j]!=0){							//print the result start with a non-zero number
				printf("%d",result[i][j]);
				if(j==point[i]){
					printf(".");
				}
				check=1;
			}
		}
		printf("\n");
	}
	return 0;
}