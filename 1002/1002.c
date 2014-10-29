/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Oct, 27	2014	*/
/*End Date:    					*/
/*Version:	   1.0				*/

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

#include <stdio.h>					//Base I/O headfile, to use scanf() printf()
#include <stdlib.h>					//to use malloc() free()
#include <string.h>					//To use memset()
#define MAX_SIZE_INPUTS 20  		//Set the max size of inputs

struct Data {				//To store the Data;
	int phoneNum;		
	int num;
	struct Data *next;
};



void initData(struct Data *results){	//initial a struct
	results->phoneNum=0;
	results->num=0;
	results->next=0;
}

struct Data* newData(){		//Create a new struct
	struct Data *results=(struct Data *)malloc(sizeof(struct Data));
	initData(results);
	return results; 
}

int main(){
	int numInputs;
	char* inputs;
	int inputNum;
	int digit;
	int phoneNumTmp;
	int numTmp;
	struct Data *results=newData();
	struct Data *tmp;
	struct Data *newNext;
	int i,j;
	int check;

	scanf("%d",&numInputs);										//get number of inputs
	for( i=0; i<numInputs; i++){
		inputs=(char*)malloc((sizeof(char))*MAX_SIZE_INPUTS);	//give memory
		scanf("%s",inputs);										//get input string
		inputNum=0;
		digit=1000000;
		for( j=0; j<MAX_SIZE_INPUTS; j++){
			if(inputs[j]=='\0'){
				break;
			}
			check=0;
			if((inputs[j]>='A')&&(inputs[j]<'Z')){
				if(inputs[j]<'Q'){
					inputNum+=((inputs[j]-'A')/3+2)*digit;
				}
				else if(inputs[j]>'Q'){
					inputNum+=((inputs[j]-'A'-1)/3+2)*digit;
				}
				check++;
			}
			else if((inputs[j]>='0')&&(inputs[j]<='9')){
				inputNum+=(inputs[j]-'0')*digit;
				check++;				
			}
			if(check!=0){
				digit/=10;
			}
		}
		//printf("inputNum=%d\n",inputNum);
		if(results->phoneNum==0){
			results->phoneNum=inputNum;
			results->num=1;
		}
		else if(results->phoneNum==inputNum){
			results->num++;
			printf("\n1results->num=%d\n",results->num);
			printf("results->phoneNum=%d\n\n",results->phoneNum);
		}
		else if(results->phoneNum>inputNum){
			phoneNumTmp=results->phoneNum;
			results->phoneNum=inputNum;
			inputNum=phoneNumTmp;
			numTmp=results->num;
			results->num=1;
		}
		else{
			check=0;
			tmp=malloc(sizeof(struct Data));
			tmp=results;
			if(tmp->phoneNum>inputNum){
				phoneNumTmp=tmp->phoneNum;
				tmp->phoneNum=inputNum;
				inputNum=phoneNumTmp;
				numTmp=tmp->num;
				tmp->num=1;
			}
			while(tmp->next!=0){
				tmp=tmp->next;
				if(tmp->phoneNum==inputNum){				//if the phone num is in the database, record it
					tmp->num++;
					check=1;
					printf("\n2tmp->num=%d\n",tmp->num);
					printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
					break;
				}
				else if(tmp->phoneNum>inputNum){
					phoneNumTmp=tmp->phoneNum;
					tmp->phoneNum=inputNum;
					inputNum=phoneNumTmp;
					numTmp=tmp->num;
					tmp->num=1;
					check=2;
				}
				printf("\n3tmp->num=%d\n",tmp->num);
				printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
			}
			if(check==0){									//if it is not in the database, create a new one
				newNext=newData();
				newNext->phoneNum=inputNum;
				newNext->num=1;
				tmp->next=newNext;
			}
			else if(check==2){
				newNext=newData();
				newNext->phoneNum=inputNum;
				newNext->num=numTmp;
				tmp->next=newNext;
				printf("\n4tmp->num=%d\n",tmp->num);
				printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
			}
		}
		free(inputs);
	}
	/*print part*/
	if(results->num>1){
		printf("%d-%d %d\n",results->phoneNum/10000,results->phoneNum%10000,results->num);
	}
	if(results->next!=0){
		check=0;
		tmp=results;
		while(tmp->next!=0){
			tmp=tmp->next;
			if(tmp->num>1){
				printf("%d-%d %d\n",tmp->phoneNum/10000,tmp->phoneNum%10000,tmp->num);
			}
		}
	}
	return 0;
}