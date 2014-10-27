/*The solution of problem 1000 of pku online judge*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int a=0,b=0;
	scanf("%d %d",&a,&b);
	if(a<0||b>10){
		exit(0);
	}
	printf("%d",a+b);
	return 0;
}