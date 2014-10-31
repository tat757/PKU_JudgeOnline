/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Oct, 27 2014		*/
/*End Date:    Oct, 29 2014		*/
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
	int changingTmp;
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
		numTmp=1;
		phoneNumTmp=0;
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
			}			//since the 
		}
		//printf("inputNum=%d\n",inputNum);
		if(results->phoneNum==0){
			results->phoneNum=inputNum;
			results->num=1;
		}
		else{
			check=0;
			tmp=malloc(sizeof(struct Data));
			tmp=results;
			if(tmp->phoneNum==inputNum){				//if the phone num is in the database, record it
				tmp->num++;
				check=1;
				//printf("\n2tmp->num=%d\n",tmp->num);
				//printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
			}
			while(tmp->next!=0){
				if((tmp->phoneNum==inputNum)&&check==0){				//if the phone num is in the database, record it
					tmp->num++;
					check=1;
					//printf("\n2tmp->num=%d\n",tmp->num);
					//printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
					break;
				}
				else if(tmp->phoneNum>inputNum){
					//printf("\ntmp->phoneNum(before)=%d\n",tmp->phoneNum);
					phoneNumTmp=tmp->phoneNum;
					tmp->phoneNum=inputNum;
					inputNum=phoneNumTmp;
					//printf("\ntmp->phoneNum(after)=%d\n",tmp->phoneNum);
					changingTmp=tmp->num;
					tmp->num=numTmp;
					numTmp=changingTmp;
				}
				tmp=tmp->next;
				//printf("\n3tmp->num=%d\n",tmp->num);
				//printf("tmp->phoneNum=%d\n\n",tmp->phoneNum);
			}
			if(check==0){									//if it is not in the database, create a new one
				newNext=newData();
				newNext->phoneNum=inputNum;
				newNext->num=numTmp;
				tmp->next=newNext;
				//printf("\ntmp->phoneNum=%d\n",tmp->phoneNum);
				//printf("tmp->num=%d\ntmp->next->phoneNum=%d\ntmp->next->num=%d\n\n",tmp->num,tmp->next->phoneNum,tmp->next->num);
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