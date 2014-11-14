/*		POJ problem 1009		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 05 2014		*/
/*End Date:	Nov, 13 2014		*/
/*Version: 1.0 					*/

/*for one table, change the number in the table to the largest cap near the point*/

/*Inputs: numbers in the chart by the RLE pairs*/

/*Output: the numbers after the convert*/

#include <stdio.h>			//To use printf() scanf()
#include <stdlib.h>			//To use malloc()
#include <math.h>			//To use abs()
#include <string.h>			//To use memset()
#define MAX_PIXEL 1000

struct Data{												//To store the information of inputs
	int numInputs;
	int *pixel;
	int *pixelNum;
	int total;
	struct Data* next;
};

void initData(struct Data *newD){							//To initialize the struct
	newD->numInputs=0;
	newD->pixel=malloc(sizeof(int)*MAX_PIXEL);
	newD->pixelNum=malloc(sizeof(int)*MAX_PIXEL);
	newD->next=0;
	newD->total=0;
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
		scanf("%d%d",&temp->pixel[i],&temp->pixelNum[i]);
		while(temp->pixelNum[i]!=0){
			temp->total+=temp->pixelNum[i];
			i++;
			scanf("%d%d",&temp->pixel[i],&temp->pixelNum[i]);
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
	int *pixelTemp=malloc(sizeof(int)*MAX_PIXEL);
	int *pixelNumTemp=malloc(sizeof(int)*MAX_PIXEL);
	int i,iTemp,iSec;
	int pointer;
	int pointerTemp;
	int max;
	temp=first;
	while(1){												//This loop use for all image
		i=0;
		iSec=0;
		pixelTemp=malloc(sizeof(int)*MAX_PIXEL);
		pixelNumTemp=malloc(sizeof(int)*MAX_PIXEL);
		pixelTemp[0]=0;
		pixelNumTemp[0]=0;
		pointer=1;
		while(1){											//This loop use for one image
			max=0;
			if(pointer>temp->numInputs && (pointer%temp->numInputs!=1)){						//If the pointer has up-left number, check it
				pointerTemp=pointer-temp->numInputs-1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				//printf("pointerTemp=%d\n i=%d iTemp=%d\n",pointerTemp, i, iTemp);
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if(pointer>temp->numInputs){														//If the pointer has up number, check it
				pointerTemp=pointer-temp->numInputs;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if(pointer>temp->numInputs && (pointer%temp->numInputs!=0)){						//If the pointer has up-right number, check it
				pointerTemp=pointer-temp->numInputs+1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if(pointer-1>0 && (pointer%temp->numInputs!=1)){										//If the pointer has left number, check it
				pointerTemp=pointer-1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if((pointer+1)<=temp->total && (pointer%temp->numInputs!=0)){						//If the pointer has right number , check it
				pointerTemp=pointer+1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if((pointer+temp->numInputs-1)<=temp->total && (pointer%temp->numInputs!=1)){		//If the pointer has down-left number, check it
				pointerTemp=pointer+temp->numInputs-1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if((pointer+temp->numInputs)<=temp->total){											//If the pointer has down number, check it
				pointerTemp=pointer+temp->numInputs;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if((pointer+temp->numInputs+1)<=temp->total && (pointer%temp->numInputs!=0)){		//If the pointer has down-right number, check it
				pointerTemp=pointer+temp->numInputs+1;
				iTemp=0;
				while(pointerTemp>temp->pixelNum[iTemp]){
					pointerTemp-=temp->pixelNum[iTemp];
					iTemp++;
				}
				if(abs(temp->pixel[i]-temp->pixel[iTemp])>max){
					max=abs(temp->pixel[i]-temp->pixel[iTemp]);
				}
			}
			if(pointer==1){
				pixelTemp[iSec]=max;
				pixelNumTemp[iSec]++;
			}
			else if(pointer!=1){
				if(max!=pixelTemp[iSec]){
					iSec++;
					pixelTemp[iSec]=max;
					pixelNumTemp[iSec]=1;
				}
				else{
					pixelNumTemp[iSec]++;
				}
			}
			//printf("pointer==%d i=%d iSec=%d\n",pointer,i,iSec);
			pointer++;
			if(pointer>temp->total){
				break;
			}
			iTemp=0;
			pointerTemp=pointer;
			while(pointerTemp>temp->pixelNum[iTemp]){
				pointerTemp-=temp->pixelNum[iTemp];
				iTemp++;
			}
			i=iTemp;
			if(pointerTemp==temp->numInputs+2 && pointerTemp<(temp->pixelNum[i]-temp->numInputs-1)){
				pointer+=temp->pixelNum[iTemp]-temp->numInputs-pointerTemp;
				if(pixelTemp[iSec]==0){
					pixelNumTemp[iSec]+=temp->pixelNum[iTemp]-pointerTemp-temp->numInputs;
				}
				else{
					iSec++;
					pixelTemp[iSec]=0;
					pixelNumTemp[iSec]=temp->pixelNum[iTemp]-pointerTemp-temp->numInputs;
				}
			}
			//printf("pointer==%d i=%d iSec=%d\n",pointer,i,iSec);
		}
		temp->pixel=pixelTemp;
		temp->pixelNum=pixelNumTemp;
		if(temp->next){
			temp=temp->next;
		}
		else{
			break;
		}
	}
}

void printOutput(struct Data *first){
	struct Data *temp;
	int i;
	temp=first;
	while(1){
		i=0;
		printf("%d\n",temp->numInputs);
		while(1){
			printf("%d %d\n",temp->pixel[i],temp->pixelNum[i]);
			temp->total-=temp->pixelNum[i];
			if(temp->total==0){
				break;
			}
			else{
				i++;
			}
		}
		printf("0 0\n");
		if(temp->next){
			temp=temp->next;	
		}
		else{
			break;
		}
	}
}

int main(){
	struct Data *first;
	first=newData();
	getInputs(first);
	calculation(first);
	printOutput(first);
	printf("0\n");
	return 0;
}