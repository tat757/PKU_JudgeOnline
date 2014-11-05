/*		POJ problem 1007		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 04 2014		*/
/*End Date: 					*/
/*Version: 		1.0 			*/

/*To sort the numbers from the most sorted to the least sorted*/

/*Inputs: A size of the numbers of data, A number of the numbers of data, data*/
/*Outputs: The sequence from the most sorted to the least sorted*/

#include <stdio.h>			//To use printf() scanf()
#include <string.h>			//To use strcpy()
#include <stdlib.h>			//To use malloc()

struct Data {
	char* string;
	int inversions;
	struct Data* next;
};

void initData(struct Data *results, int *digits){
	results->string=(char*)malloc(sizeof(char)*(*digits));
	results->inversions=0;
	results->next=0;
}

struct Data *newData(int *digits){
	struct Data *results=malloc(sizeof(struct Data));
	initData(results,digits);
	return results;
}

void getInputsInfor(int *digits, int *nums){		//Get the information of inputs
	scanf("%d%d",digits,nums);
}

void calcuInver(struct Data *results, int *digits){
	int i,j;
	char temp;
	for(i=0;i<*digits;i++){
		temp=results->string[i];
		for(j=i;j<*digits;j++){
			if(temp>results->string[j]){
				results->inversions++;
			}
		}
	}
}

void getInputs(struct Data *results, int *nums, int *digits){			//Get the string data of inputs
	int i;
	for(i=0;i<*nums;i++){
		results=newData(digits);
		scanf("%s",results->string);
		calcuInver(results,digits);
		if(*nums!=(i+1)){
			results=results->next;
		}
	}
}

void sort(struct Data *results, int *nums, int *digits){
	char* stringTemp=(char*)malloc(sizeof(char)*(*digits));
	int i, j, inverTemp;
	for(i=0;i<*nums;i++){
		for(j=i;j<*nums;j++){
			if(results->next==0){
				break;
			}
			else if(results->inversions>results->next->inversions){
				strcpy(stringTemp,results->string);
				strcpy(results->string,results->next->string);
				strcpy(results->next->string,stringTemp);
				inverTemp=results->inversions;
				results->inversions=results->next->inversions;
				results->next->inversions=inverTemp;
			}
		}
	}
}

void printOutputs(struct Data *results, int *nums){
	int i;
	for(i=0; i<*nums; i++){
		printf("%s\n",results->string);
	}
}

int main(){
	int *digits, *nums;
	struct Data *results;
	digits=malloc(sizeof(int));
	nums=malloc(sizeof(int));
	getInputsInfor(digits,nums);
	getInputs(results,nums,digits);
	sort(results,nums,digits);
	printOutputs(results,nums);
	return 0;
}