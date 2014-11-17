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

void getInputs(int *numInputs, int *pixel, int *pixelNum, int *total, int *totalPix){
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
		totalPix[i]=iSec;
		i++;
	}
}

void calculation(int *numInputs, int *pixel, int *pixelNum, int *total, int *totalPix){
	int *pixelTemp=malloc(sizeof(int)*MAX_PIXEL);
	int *pixelNumTemp=malloc(sizeof(int)*MAX_PIXEL);
	int i, iTemp, iSec, max, pointer, pointerTemp, secI, totalTemp;
	i=0;
	secI=0;
	iSec=0;
	while(1){
		iTemp=0;
		pointer=0;
		if(i==0){
			totalTemp=0;
		}
		else{
			totalTemp=totalPix[i-1];	
		}
		totalPix[i]=0;
		while(1){
			max=0;
			if(pointer>numInputs[i]){
				if(pointer%numInputs[i]!=1){
					pointerTemp=pointer-numInputs[i]-1;
					iTemp=totalTemp;
					while(pointerTemp>pixelNum[iTemp]){
						pointerTemp-=pixelNum[iTemp];
						iTemp++;
					}
					if(abs(pixel[secI]-pixel[iTemp])>max){
						max=abs(pixel[secI]-pixel[iTemp]);
					}
				}
				if(pointer>numInputs[i]){
					pointerTemp=pointer-numInputs[i];
					iTemp=totalTemp;
					while(pointerTemp>pixelNum[iTemp]){
						pointerTemp-=pixelNum[iTemp];
						iTemp++;
					}
					if(abs(pixel[secI]-pixel[iTemp])>max){
						max=abs(pixel[secI]-pixel[iTemp]);
					}
				}
				if(pointer%numInputs[i]!=0){
					pointerTemp=pointer-numInputs[i]+1;
					iTemp=totalTemp;
					while(pointerTemp>pixelNum[iTemp]){
						pointerTemp-=pixelNum[iTemp];
						iTemp++;
					}
					if(abs(pixel[secI]-pixel[iTemp])>max){
						max=abs(pixel[secI]-pixel[iTemp]);
					}
				}
			}
			if(pointer-1>0 && pointer%numInputs[i]!=1){
				pointerTemp=pointer-1;
				iTemp=totalTemp;
				while(pointerTemp>pixelNum[iTemp]){
					pointerTemp-=pixelNum[iTemp];
					iTemp++;
				}
				if(abs(pixel[secI]-pixel[iTemp])>max){
					max=abs(pixel[secI]-pixel[iTemp]);
				}			
			}
			if(pointer+1<total[i] && pointer%numInputs[i]!=0){
				pointerTemp=pointer-numInputs[i]+1;
				iTemp=totalTemp;
				while(pointerTemp>pixelNum[iTemp]){
					pointerTemp-=pixelNum[iTemp];
					iTemp++;
				}
				if(abs(pixel[secI]-pixel[iTemp])>max){
					max=abs(pixel[secI]-pixel[iTemp]);
				}
			}
			if(pointer+numInputs[i]-1<total[i] && pointer%numInputs[i]!=1){
				pointerTemp=pointer-1+numInputs[i];
				iTemp=totalTemp;
				while(pointerTemp>pixelNum[iTemp]){
					pointerTemp-=pixelNum[iTemp];
					iTemp++;
				}
				if(abs(pixel[secI]-pixel[iTemp])>max){
					max=abs(pixel[secI]-pixel[iTemp]);
				}	
			}
			if(pointer+numInputs[i]<total[i]){
				pointerTemp=pointer+numInputs[i];
				iTemp=totalTemp;
				while(pointerTemp>pixelNum[iTemp]){
					pointerTemp-=pixelNum[iTemp];
					iTemp++;
				}
				if(abs(pixel[secI]-pixel[iTemp])>max){
					max=abs(pixel[secI]-pixel[iTemp]);
				}	
			}
			if(pointer+1+numInputs[i]<total[i] && pointer%numInputs[i]!=0){
				pointerTemp=pointer+numInputs[i]+1;
				iTemp=totalTemp;
				while(pointerTemp>pixelNum[iTemp]){
					pointerTemp-=pixelNum[iTemp];
					iTemp++;
				}
				if(abs(pixel[secI]-pixel[iTemp])>max){
					max=abs(pixel[secI]-pixel[iTemp]);
				}
			}
			totalPix[i]=1;
			if(pointer==1){
				pixelTemp[iSec]=max;
				pixelNumTemp[iSec]++;
			}
			else if(pointer!=1){
				if(max!=pixelTemp[iSec]){
					iSec++;
					pixelTemp[iSec]=max;
					pixelNumTemp[iSec]=1;
					totalPix[i]++;
				}
				else{
					pixelNumTemp[iSec]++;
					totalPix[i]++;
				}
			}
			pointer++;
			if(pointer>total[i]){
				break;
			}
			if(i==0){
				iTemp=0;
			}
			else{
				iTemp=totalPix[i-1];	
			}
			pointerTemp=pointer;
			while(pointerTemp>pixelNum[iTemp]){
				pointerTemp-=pixelNum[iTemp];
				iTemp++;
			}
			secI=iTemp;
			if(pointerTemp==numInputs[i]+2 && pointerTemp<(pixelNum[secI]-numInputs[i]-1)){
				pointer+=pixelNum[iTemp]-numInputs[i]-pointerTemp;
				if(pixelTemp[iSec]==0){
					pixelNumTemp[iSec]+=pixelNum[iTemp]-pointerTemp-numInputs[i];
				}
				else{
					iSec++;
					pixelTemp[iSec]=0;
					pixelNumTemp[iSec]=pixelNum[iTemp]-pointerTemp-numInputs[i];
				}		
			}
		}
		i++;
		if(numInputs[i]==0){
			break;
		}
	}
	printf("%p\n",pixel);
	pixel=pixelTemp;
	pixelNum=pixelNumTemp;
	printf("\n\n\n\n");
	for(i=0;i<3;i++){
		printf("%d %d %p\n",pixelTemp[i],pixelNumTemp[i],pixelTemp);
	}
	printf("\n\n\n\n");
	for(i=0;i<3;i++){
		printf("%d %d %p\n",pixel[i],pixelNum[i],pixel);
	}
	free(pixelTemp);
	free(pixelNumTemp);
}

void printOutput(int *numInputs, int *pixel, int *pixelNum, int *totalPix){
	int i, secI;
	i=0;
	printf("%p\n",pixel);
	while(1){
		secI=0;
		printf("%d\n",numInputs[i]);
		while(1){
			printf("%d %d\n",pixel[secI],pixelNum[secI]);
			secI++;
			if(secI==totalPix[i]){
				break;
			}
		}
		printf("0 0\n");
		i++;
		if(numInputs[i]==0){
			printf("0\n");
			break;
		}
	}
}

int main(){
	int *pixel=malloc(sizeof(int)*MAX_PIXEL);
	int *pixelNum=malloc(sizeof(int)*MAX_PIXEL);
	int *numInputs=malloc(sizeof(int)*MAX_PIXEL);
	int *total=malloc(sizeof(int)*MAX_PIXEL);
	int *totalPix=malloc(sizeof(int)*MAX_PIXEL);
	int i;
	for(i=0;i<MAX_PIXEL;i++){
		pixel[i]=0;
		pixelNum[i]=0;
		numInputs[i]=0;
		total[i]=0;
		totalPix[i]=0;
	}
	getInputs(numInputs,pixel,pixelNum,total,totalPix);
	printf("%p\n",pixel);
	calculation(numInputs,pixel,pixelNum,total,totalPix);
	printf("%p\n",pixel);
	printOutput(numInputs,pixel,pixelNum,totalPix);
	return 0;
}