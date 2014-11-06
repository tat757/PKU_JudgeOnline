/*		POJ problem 1009		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 05 2014		*/
/*End Date:						*/
/*Version: 1.0 					*/

/*for one table, change the number in the table to the largest cap near the point*/

/*Inputs: numbers in the chart by the RLE pairs*/

/*Output: the numbers after the convert*/

#include <stdio.h>			//To use printf() scanf()
#include <stdlib.h>			//To use malloc()
#define MAX_PIXEL 1000

struct Data{												//To store the information of inputs
	int numInputs;
	int *pixel;
	int *pixelNum;
	struct Data* next;
};

void initData(struct Data *newD){							//To initialize the struct
	newD->numInputs=0;
	newD->pixel=malloc(sizeof(int)*MAX_PIXEL);
	newD->pixelNum=malloc(sizeof(int)*MAX_PIXEL);
	newD->next=0;
}

struct Data *newData(){										//To use for creat a new struct
	struct Data *newD=malloc(sizeof(struct Data));
	initData(newD);
	return newD;
}

void getInputs(struct Data *first){							//To get the inputs and store them to struct
	int i,num;
	struct Data *temp;
	struct Data *newImage;
	temp=first;
	scanf("%d",&num);
	while(1){
		i=0;
		temp->numInputs=num;
		scanf("%d%d",temp->pixel[i],temp->pixelNum[i]);
		while(temp->pixel[i]!=0 && temp->pixelNum[i]!=0){
			i++;
			scanf("%d%d",temp->pixel[i],temp->pixelNum[i]);
		}
		scanf("%d",&num);
		if(num!=0){											//For each new image create a new struct
			newImage=newData();
			temp->next=newImage;
			temp=temp->next;
		}
		else{
			break;
		}
	}
}

void calculation(struct Data *first){
	struct Data *temp;
	int *pixelTemp;
	int *pixelNumTemp;
	int i,j;
	int pointer;
	int pointerTemp;
	int min;
	temp=first;
	while(1){
		i=0;
		pointer=1;
		while(1){
			if(pointer-temp->numInputs-1){
				
			}
		}
		if(temp->next){
			temp=temp->next;
		}
		else{
			break;
		}
	}
}

void printOutput(struct Data *first){

}

int main(){
	struct Data *first;
	first=newData();
	getInputs(first);
	calculation(first);
	printOutput(first);
	return 0;
}