/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Nov, 02 2014		*/
/*End Date:    					*/
/*Version:	   3.0				*/
/*For the last version, I tried some hard way to do this, this time, I will try it by a simple way.*/

/*487-3279*/
/*Currently, companies like to use some letters to replace numbers.*/
/* This program is to check the letter+numbers combination and find out how many combination are represent same numbers.*/
/*A,B,C = 2*/
/*D,E,F = 3*/
/*G,H,I = 4*/
/*J,K,L = 5*/
/*M,N,O = 6*/
/*P,R,S = 7*/
/*T,U,V = 8*/
/*W,X,Y = 9*/

/*Inputs: number of combinations, combinations of "-"+UppercaseLetters+numbers*/
/*Outputs: numbers that 3digits+4digits separate by "-", and how many times it repeats*/

#include <stdio.h> 			//to use printf() scanf()
#include <stdlib.h>			//to use malloc()
#include <string.h>			//to use memset()
#define MAX_NUM_INPUTS 10000000
#define MAX_SIZE_INPUTS 500
	
int getNumInputs(){
	int numInputs;
	scanf("%d",&numInputs);
	//printf("numInputs=%d\n",numInputs);
	return numInputs;				//to get the number of inputs
}

void getStrInputs(char* strInputs){		//to get the number
	scanf("%s",strInputs);
}

int strToNum(char* inputStr){			//transfer the string to integer
	int inputNum=0;
	int digit=1000000;
	int j;
	int check;
	for( j=0; j<MAX_SIZE_INPUTS; j++){
		if(inputStr[j]=='\0'){
			break;
		}
		check=0;
		if((inputStr[j]>='A')&&(inputStr[j]<'Z')){
			if(inputStr[j]<'Q'){	
				inputNum+=((inputStr[j]-'A')/3+2)*digit;
				check++;
			}
			else if(inputStr[j]>'Q'){
				inputNum+=((inputStr[j]-'A'-1)/3+2)*digit;
				check++;
			}
		}
		else if((inputStr[j]>='0')&&(inputStr[j]<='9')){
			inputNum+=(inputStr[j]-'0')*digit;
			check++;				
		}
		if(check!=0){
			digit/=10;
		} 
	}
	return inputNum;
}

int main(){
	int *results;
	int numInputs;
	int inputNum;
	char *strInputs;
	int max, min;
	results=(int*)malloc(sizeof(int)*MAX_NUM_INPUTS);
	max=-1;
	min=MAX_NUM_INPUTS;
	numInputs=getNumInputs();
	memset(results,0,sizeof(int)*MAX_NUM_INPUTS);
	while((numInputs--)>0){
		strInputs=(char*)malloc(sizeof(char)*MAX_SIZE_INPUTS);
		getStrInputs(strInputs);
	//	printf("strInputs=%s\n",strInputs);
		inputNum=strToNum(strInputs);
	//	printf("inputNum=%d\n",inputNum);
		results[inputNum]++;
	//	printf("results[%d]=%d\n",inputNum,results[inputNum]);
		if(results[inputNum]>1){
			if(inputNum<min){
				min=inputNum;
			}
			if(inputNum>max){
				max=inputNum;
			}
		}
		free(strInputs);
	}
	if(min==MAX_NUM_INPUTS && max==-1){
		printf("No duplicates.\n");
		exit(0);
	}
	//printf("min=%d\n",min);
	//printf("max=%d\n",max);
	while(min<=max){
		if(results[min]>1){
			printf("%03d-%04d %d\n",min/10000,min%10000,results[min]);
		}
		min++;
	}
	return 0;
}