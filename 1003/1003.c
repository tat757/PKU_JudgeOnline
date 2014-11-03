/* 	 PKU_OJ Problem 1003	*/
/*		Yinsong Xu			*/
/*Start Date: Nov, 02 2014	*/
/*End Date:   Nov, 02 2014	*/
/*Version: 		1.0 		*/

/*To put cards as a stack on a table, each time a card over the next card half less than the last card*/
/*the n cards will over 1/(n+1) space than next card*/

/*Input, some three digits numbers which are larger than 0.00 less than 5.20*/
/*Output, how many cards are needed to reach the goal*/

#include <stdio.h>		//To use printf() scanf()
#include <stdlib.h>		//To use exit()
#include <string.h> 	//To use strlen() strcmp()
#define MAX_SIZE_INPUTS 4

void getStrInput(char* inputStr){		//To get a input as string
	int size;
	scanf("%s",inputStr);
	size=strlen(inputStr);
	if(size!=MAX_SIZE_INPUTS){
		exit(0);
	}
}

double strToDoub(char* inputStr){		//transfer the string input to a double
	double a,b,c,inputNum;
	a=inputStr[0]-'0';
	b=(inputStr[2]-'0')*0.1;
	c=(inputStr[3]-'0')*0.01;
	inputNum=a+b+c;
	return inputNum;
}

int calculation(double inputNum){		//Calculate how many cards are needed
	int numCards=1;
	int check=1;
	double totalDistance=0;
	while(check){
		totalDistance+=1/((double)(numCards+1));
		if(totalDistance>=inputNum){
			break;
		}
		numCards++;
	}
	return numCards;
}

int main(){
	char* inputStr;
	double inputNum;
	char end[5]="0.00";
	int check;
	int numCards;

	check=0;
	while(check==0){
		inputStr=(char*)malloc(sizeof(char)*MAX_SIZE_INPUTS);	
		getStrInput(inputStr);									//get input
		if(strcmp(inputStr,end)==0){							//if input is 0.00, exit
			exit(0);
		}
		inputNum=strToDoub(inputStr);
		if(inputNum>5.20 || inputNum<0.00){						//if out of range, exit
			exit(0);
		}
		else{
			numCards=calculation(inputNum);						//Calculate how many cards are needed
			printf("%d card(s)\n",numCards);					//print number of cards
		}
		free(inputStr);
	}
	return 0;
}