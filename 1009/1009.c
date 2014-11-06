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

struct Data{
	int numInputs;
	int *pixel;
	int *pixelNum;
	struct Data* next;
};

void initData(struct Data *newD){
	newD->numInputs=0;
	newD->pixel=malloc(sizeof(int)*MAX_PIXEL);
	newD->pixelNum=malloc(sizeof(int)*MAX_PIXEL);
	newD->next=0;
}

struct Data *newData(){
	struct Data *new=malloc(sizeof(struct Data));
	initData(new);
	return new;
}

void getInputs(struct Data *first){
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
		if(num!=0){
			newImage=newData();
			temp->next=newImage;
			temp=temp->next;
		}
		else if(num==0){
			break;
		}
	}
}