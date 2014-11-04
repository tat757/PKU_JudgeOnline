/*		POJ problem 1006		*/
/*		Yinsong Xu				*/
/*Start Date: Nov, 03 2014		*/
/*End Date:	  Nov, 03 2014		*/
/*Version: 1.0 					*/

/*There are three different periods, we want to find out when will the three periods will be happened at a same day*/

/*Inputs: the start day of three periods, and the start day*/
/*Output: the day that three events are happened together*/

#include <stdio.h>				//To use printf() scanf()
#include <stdlib.h>				//To use exit()

int main(){
	int a, b, c, d;
	int results;
	int i, check, j;
	check=1;
	j=1;
	while(check){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a==-1 && b==-1 && c==-1 && d==-1){
			break;
		}
		if(a<0 || b<0 || c<0 || d<0 || a>365 || b>365 || c>365 || d>365){
			exit(0);
		}
		for(i=1;;i++){
			if(((a+23*i-b)%28==0) && ((23*i+a-c)%33==0)){
				break;
			}
		}
		results=a+23*i-d;
		while(results>21252){
			results-=21252;
		}
		while(results<0){
			results+=21252;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",j++,results);
	}
	return 0;
}