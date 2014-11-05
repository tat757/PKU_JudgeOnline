/*		POJ problem 1007		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 04 2014		*/
/*End Date:   Nov, 04 2014		*/
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
		//printf("results->inversions=%d\n",results->inversions);

	}
}

void getInputs(struct Data *results, int *nums, int *digits){			//Get the string data of inputs
	int i;
	struct Data *temp=results;
	for(i=0;i<*nums;i++){
		scanf("%s",temp->string);
		//printf("temp->string=%s\n",temp->string);
		calcuInver(temp,digits);
		if(*nums!=(i+1)){
			temp->next=newData(digits);
			temp=temp->next;
		}
	}
}

void sort(struct Data *results, int *nums, int *digits){				//to arrange the sequence	
	char* stringTemp=(char*)malloc(sizeof(char)*(*digits));
	int i, j, inverTemp;
	struct Data *temp;
	for(i=0;i<*nums;i++){
		temp=results;
		for(j=i;j<*nums;j++){
			if(temp->inversions>results->inversions){
				strcpy(stringTemp,results->string);
				strcpy(results->string,temp->string);
				strcpy(temp->string,stringTemp);
				inverTemp=results->inversions;
				results->inversions=temp->inversions;
				temp->inversions=inverTemp;
			}
			if(!results->next){
				break;
			}
			results=results->next;
		}
		results=temp->next;
	}
}

void printOutputs(struct Data *results, int *nums){						//To print the results
	int i;
	for(i=0; i<*nums; i++){
		printf("%s\n",results->string);
		results=results->next;
	}
}

int main(){
	int *digits, *nums;
	struct Data *results;
	digits=malloc(sizeof(int));
	nums=malloc(sizeof(int));
	getInputsInfor(digits,nums);
	results=newData(digits);
	getInputs(results,nums,digits);
	sort(results,nums,digits);
	printOutputs(results,nums);
	return 0;
}