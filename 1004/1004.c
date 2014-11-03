/*	POJ Problem 1004  		*/
/*	Yinsong Xu		  	    */
/*Start Date: Nov, 03 2014  */
/*End Date: Nov, 03 2014	*/
/*Version:  1.0 			*/

/*Give 12 numbers find the ave*/

/*Input: 12 numbers*/
/*Output: the ave with a dollar sign*/

#include <stdio.h>	//To use scanf() printf()

#define MAX_NUM_NUMS 12

int main(){
	float months;
	float total=0;
	int i;
	for(i=0;i<MAX_NUM_NUMS;i++){	
		scanf("%f",&months);
		total+=months;	
	}
	printf("$%.2f\n",(total/12.0));
	return 0;
}
