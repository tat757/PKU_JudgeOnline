/*PKU Judge Online 1001	*/
/*From: 	Yinsong Xu	*/
/*Begin: 	Oct 15,2014	*/
/*End:		Oct 26,2014	*/
/*Version:	1.0			*/
/*This version will use the most stupid way to make the goal as fast as I can*/

/*This program is used to be calculate some large number which could be larger than 2^32*/
/*Input:	six base numbers and the six power numbers of the base numbers*/
/*Output:	six results of them*/

#include <stdio.h>		//basic I/O head file. To use scanf() printf()
#include <stdlib.h>		//To use exit()
#include <string.h>		//To use strlen() memset()
//#define NUM_INPUT 6		//Set the total input number to 6
#define MAX_DIGIT 200	//Set the max digits of the array which store the input numbers
#define MAX_RESULT_DIGIT 200*2+10 		//Set the max digit of result


/*Main function*/
int main(){
	/*Set the variables*/
	char baseStr[MAX_DIGIT];			//To save the base numbers array while user input
	int power;						//To save the power numbers of the base numbers
	unsigned baseNum[MAX_DIGIT];			//To save the integers of the base number
	unsigned result[MAX_RESULT_DIGIT];			//To save the results
	unsigned resultTmp[MAX_RESULT_DIGIT];		//To save the tmp when doing the calculation
	int point;						//To save the point of each numbers
	int digitBase;					//To save the digits of base numbers
	int digitResult;					//To save the digits of result
	int j,k,l,m;							//To use for the loops
	int check;
	int pointCheck;
	int zeroCheck;
	/*To get the inputs*/
	while(scanf("%s%d",baseStr,&power)==2){
		//printf("%s\n",baseStr);
		digitBase=strlen(baseStr);			//To save the total digits of each base numbers
		memset(baseNum,0,sizeof(baseNum));	//Set all initial digit to 0
		memset(result,0,sizeof(result));
		memset(resultTmp,0,sizeof(resultTmp));		
		//printf("\npass inputs\n");
		/*Transfer the base numbers from string to integer */
		k=0;
		point=0;
		pointCheck=0;									
		for( j=digitBase-1; j>=0; j--){					//Loop untill hit the end of the string
			//printf("%c\n",baseStr[j]);
			if( (baseStr[j]<48) || (baseStr[j]>57)){//If the character is not a number, exit
				if( (baseStr[j]=='.')){				//If the character is the point
					point=j;						//remeber the point position
					digitBase--;
					j--;
					//printf("point[%d]=%d\n",i,point);
					pointCheck=1;					//To find out if the input is start from a point or a number
				}
				else{
					exit(0);					//else will exit
				}
			}
			baseNum[k]=baseStr[j]-'0';	//record the number
			//printf("baseNum[%d][%d]=%d",i,k,baseNum[k]);
			k++;
		}
		//printf("\npass transfer\n");
		/*Calculation*/
		resultTmp[0]=1;
		digitResult=1;											//set the tmp of result initial digit to 0
		//check=0;
		for( j=0; j<power; j++){
			memset(result,0,sizeof(result));					//Reset all of the numbers in the array of result 
			for( k=0; k<digitBase; k++){
				for( l=0; l<digitResult; l++){					
					result[k+l]+=resultTmp[l]*baseNum[k];	
					if(result[k+l]>=10){						//Set less than 10 to avoid the number too large than the computer could store 
						result[k+l+1]+=result[k+l]/10;
						result[k+l]%=10;
					}
				}
				if(digitResult<MAX_RESULT_DIGIT){					//To avoid the digitResult larger than MAX_RESULT_DIGIT
					digitResult=k+l;
				}
			}
			//printf("\n");
			for(m=digitResult;m>=0;m--){
				//printf("%d ",result[m]);
				resultTmp[m]=result[m];
			}
			//printf("\n");
		}

		if(pointCheck!=0){
			//printf("point=%d\n",point);
			point=(digitBase-point);
			//printf("point=%d\n",point);
		}
		//printf("\npass calculations\n");
		
		zeroCheck=0;
		for(j=point-1; j>=0;j--){						//To remove the zero after the point if there are only zeros after the point
			if(baseNum[j]!=0){
				zeroCheck=1;
				break;
			}
		}
		
		if(pointCheck!=0){
			point*=power;
		}

		check=0;
		m=0;
		if((baseNum[0]==0)&&(digitBase==1)){		
			printf("0");
		}
		else if(power==0){
			printf("1");
		}
		else{													
			for( j=MAX_RESULT_DIGIT-1;j>=0;j--){
				if(check==1){
					if((result[j]==0)&&(j<point)){							//To remove the zero at the end of result numbers
						m++;
					}
					else{
						for(k=0;k<m;k++){
							printf("0");
						}
						printf("%d",result[j]);
						if((j==point) && (point!=0)){
							if(zeroCheck==0){
								break;
							}
							printf(".");
						}
						m=0;
					}
				}
				else if(result[j]!=0){							//print the result start with a non-zero number
					printf("%d",result[j]);
					if((j==point) && (point!=0)){
						if(zeroCheck==0){
							break;
						}
						printf(".");
					}
					check=1;
				}
				else if((j==point) && (point!=0)){							//This one is for the number less than one
					if(zeroCheck==0){
						break;
					}
					printf(".");
					check=1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}