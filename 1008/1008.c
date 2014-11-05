/*		POJ problem 1008		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 04 2014		*/
/*End Date:   Nov, 04 2014		*/
/*Version:  	1.0 			*/

/*Convert the dates from the Haab calendar to the Tzolkin calendar*/

/*Inputs: The date in Haad*/
/*Outputs: The date in Tzolkin*/

#include <stdio.h>				//To use printf() scanf()
#include <stdlib.h>				//To use malloc()
#include <string.h>				//To use strcmp()

void getNumInputs(int *numInputs){				//Get the number of inputs
	scanf("%d",numInputs);
}

int monthToNum(char *month){					//convert the month to the day
	
		if(strcmp(month,"pop")==0) return 0;
		if(strcmp(month,"no")==0)  return 20;
		if(strcmp(month,"zip")==0)  return 20*2;
		if(strcmp(month,"zotz")==0)  return 20*3;
		if(strcmp(month,"tzec")==0)  return 20*4;
		if(strcmp(month,"xul")==0)  return 20*5;
		if(strcmp(month,"yoxkin")==0)  return 20*6;
		if(strcmp(month,"mol")==0)  return 20*7;
		if(strcmp(month,"chen")==0)  return 20*8;
		if(strcmp(month,"yax")==0)  return 20*9;
		if(strcmp(month,"zac")==0)  return 20*10;
		if(strcmp(month,"ceh")==0)  return 20*11;
		if(strcmp(month,"mac")==0)  return 20*12;
		if(strcmp(month,"kankin")==0)  return 20*13;
		if(strcmp(month,"muan")==0)  return 20*14;
		if(strcmp(month,"pax")==0)  return 20*15;
		if(strcmp(month,"koyab")==0)  return 20*16;
		if(strcmp(month,"cumhu")==0)  return 20*17;
		if(strcmp(month,"uayet")==0)  return 20*18;

		return 1;
}

void getInputs(int *numInputs, int *days){		//Get Haab dates
	int i;
	int day, monthNum, year;
	char *month;
	for(i=0;i<*numInputs;i++){
		month=(char*)malloc(sizeof(char)*20);
		scanf("%d. %s %d",&day,month,&year);
		if(monthToNum(month)!=1){
			monthNum=monthToNum(month);
		}
		else{
			exit(0);
		}
		days[i]=day+monthNum+365*year;
	}
}

void printOutput(int *numInputs, int *days){
	int i;
	int day,month,year;
	const char *monthStr[]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	printf("%d\n",*numInputs);
	for(i=0;i<*numInputs;i++){
		day=days[i]%13;
		month=days[i]%20;
		year=days[i]/(13*20);
		printf("%d %s %d\n",day+1,monthStr[month],year);
	}
}

int main(){
	int *numInputs=malloc(sizeof(int));
	int *days;
	getNumInputs(numInputs);
	days=malloc(sizeof(int)*(*numInputs));
	getInputs(numInputs,days);
	printOutput(numInputs,days);
	return 0;
}