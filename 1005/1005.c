/*		POJ problem 1005	*/
/*		Yinsong Xu			*/
/*Start Date: Nov, 03 2014	*/
/*End Date:   Nov, 03 2014	*/
/*Version:		1.0 		*/

/*The land will be shrinked, the area is shrinking 50 square each year, the area is a semicircle*/

/*give a coordinates for X and Y, to find out how many years are needed to be shrinked*/

/*Input: a number of data, numbers of X, Y*/
/*Output: how many years are needed*/

#include <stdio.h>		//To use printf() scanf()
#include <stdlib.h>		//To use malloc()
#include <math.h>		//To use sqrt()
#define PI 3.14159265358979323846	//Set the value of pi

int getNumInputs(){					//To get how many inputs
	int numInputs;
	scanf("%d",&numInputs);
	return numInputs;
}

int getInputNums(float r){				//To get the inputs
	float x,y,z;
	int i;
	scanf("%f %f",&x,&y);
	z=sqrt(x*x+y*y);					//To calculate the range from the center to the edge 
	i=1;
	while(z>sqrt(((float)i)*r)){		//If the range is larger than the edge, return the integer
		i++;
	}
	return i;
}

int main(){
	int numInputs;
	int *results;
	float r=100/PI;
	int i;
	numInputs=getNumInputs();
	results=malloc(sizeof(int)*numInputs);
	for(i=0;i<numInputs;i++){
		results[i]=getInputNums(r);
	}
	for(i=0;i<numInputs;i++){
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,results[i]);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}