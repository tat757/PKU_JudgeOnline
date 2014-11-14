/*		POJ problem 1009		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 13 2014		*/
/*End Date:						*/
/*Version: 2.0 					*/
/*For this version, I will not use struct to see if this way could reduce the time.*/
/*for one table, change the number in the table to the largest cap near the point*/

/*Inputs: numbers in the chart by the RLE pairs*/

/*Output: the numbers after the convert*/

#include <stdio.h>			//To use printf() scanf()
#include <stdlib.h>			//To use malloc()
#include <math.h>			//To use abs()
#include <string.h>			//To use memset()
#define MAX_PIXEL 100000000

void getInputs(int *numInputs, int *pixel, int *pixelNum, int *total){
	int i, iSec;
	i=0;
	iSec=0;
	while(1){
		scanf("%d", &numInputs[i]);
		if(numInputs[i]==0){
			break;
		}
		scanf("%d%d", &pixel[iSec], &pixelNum[iSec]);
		while(pixelNum[iSec]!=0){
			total[i]+=pixelNum[iSec];
			iSec++;
			scanf("%d%d", &pixel[iSec], &pixelNum[iSec]);
		}
	}
}

void calculation(int *numInputs, int *pixel, int *pixelNum, int *total){
	int *pixelTemp=malloc(sizeof(int)*MAX_PIXEL);
	int *pixelNumTemp=malloc(sizeof(int)*MAX_PIXEL);
	int i, iTemp, iSec, max, pointer, pointer, pointerTemp, check;
	i=0;
	while(1){
		iTemp=0;
		iSec=0;
		pointer=0;
		while(1){
			max=0;
			if(pointer>numInputs[i]){
				if(pointer%numInputs[i]!=1){
					pointerTemp=pointer-numInputs[i]-1;
					iTemp=totalTemp;
					while(pointerTemp>pixelNum[iTemp])
				}
			}
			totalTemp=
		}
	}
}