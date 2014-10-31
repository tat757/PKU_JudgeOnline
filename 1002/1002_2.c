/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Oct, 30	2014	*/
/*End Date:    					*/
/*Version:	   2.0				*/
/*For the version 1.0, I used structs to store the number which is reorded form users, but it take too many time to do that*/
/*this version, I will try the ninary tree to try this agian*/

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

#include <stdio.h> //To use printf() scanf()
#include <stdlib.h> //To use malloc() free()
#include <string.h> //To use memset()
#define MAX_SIZE_INPUTS 20

struct Data {							//the struct of the data store in the BT
	struct Data *left;
	struct Data *right;
	struct Data *father;
	int phoneNum;
	int num;
	int leftWeight;
	int rightWeight;
}

struct Tree {
	struct Data *root;
}

void initTree(struct Tree *a){
	a->root=0;
}

struct Tree* newTree(){
	struct Tree *a=(struct Tree*)malloc(sizeof(struct Tree*));
	initTree(a);
	return a;
}

void initData(struct Data *a){			//To initialize the new struct
	a->left=0;
	a->right=0;
	a->father=0;
	a->phoneNum=0;
	a->num=0;
	a->leftWeight=0;
	a->rightWeight=0;
}

struct Data* newData(){					//a function to save the space in the main
	struct Data *a=(struct Data*)malloc(sizeof(struct Data*));
	initData(a);
	return a;
}

int compare(struct Data *a, int input){
	if(a->phoneNum>input){
		return 1;
	}
	else if(a->phoneNum==input){
		return 0;
	}
	else if(a->phoneNum<input){
		return -1;
	}
}

int getNumInputs(){
	int numInputs;
	scanf("%d",numInputs);
	return numInputs;
}

char* getStrInputs(){
	char* strInputs=(char*)malloc((sizeof(char))*MAX_SIZE_INPUTS);
	scanf("%s",strInputs);
	return strInputs;
}

int strToNum(char* inputStr){
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
			}
			else if(inputStr[j]>'Q'){
				inputNum+=((inputStr[j]-'A'-1)/3+2)*digit;
			}
			check++;
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
	int numInputs;
	int inputNum;
	int i;
	char *strInputs;
	numInputs=getNumInputs();
	for(i=0;i<numInputs;i++){
		strInputs=getStrInputs();
		inputNum=strToNum(strInputs);
	}
}