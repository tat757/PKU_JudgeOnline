/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Oct, 30	2014	*/
/*End Date:    					*/
/*Version:	   2.0				*/
/*For the version 1.0, I used structs to store the number which is reorded form users, but it take too many time to do that*/
/*this version, I will try the ninary tree to try this agian*/

/*487-3279*/
/*Currently, companies like to use some letters to replace numbers.*/
/* This program is to check the letter+numbers combination and find out how many combination are represent same numbers.*/
/*A,B,C = 2*/
/*D,E,F = 3*/
/*G,H,I = 4*/
/*J,K,L = 5*/
/*M,N,O = 6*/
/*P,R,S = 7*/
/*T,U,V = 8*/
/*W,X,Y = 9*/

/*Inputs: number of combinations, combinations of "-"+UppercaseLetters+numbers*/
/*Outputs: numbers that 3digits+4digits separate by "-", and how many times it repeats*/

#include <stdio.h> //To use printf() scanf()
#include <stdlib.h> //To use malloc() free()
#include <string.h> //To use memset()
#define MAX_SIZE_INPUTS 20

struct Data {							//the struct of the data store in the BT
	struct Data *left;
	struct Data *right;
	struct Data *father;
	int phoneNum;
	int num;
	int leftWeight;
	int rightWeight;
};

struct Tree {
	struct Data *root;
	int count;
};

void initTree(struct Tree *a){
	a->root=0;
	a->count=0;
}

struct Tree* newTree(){
	struct Tree *a=(struct Tree*)malloc(sizeof(struct Tree*));
	initTree(a);
	return a;
}

void initData(struct Data *a){			//To initialize the new struct
	a->left=0;
	a->right=0;
	a->father=0;
	a->phoneNum=0;
	a->num=0;
	a->leftWeight=0;
	a->rightWeight=0;
}

struct Data* newData(){					//a function to save the space in the main
	struct Data *a=(struct Data*)malloc(sizeof(struct Data*));
	initData(a);
	return a;
}

void createTree(int inputNum, struct Tree *a){
	struct Data *first=newData();
	first->phoneNum=inputNum;
	first->num=1;
	a->root=first;
	a->count=1;
}

int compare(int num, int inputNum){ 		//To compare two things.
	if(num>inputNum){
		return 1;
	}
	else if(num==inputNum){
		return 0;
	}
	else if(num<inputNum){
		return -1;
	}
	return 0;
}

int getNumInputs(){
	int numInputs;
	scanf("%d",&numInputs);
	printf("numInputs=%d\n",numInputs);
	return numInputs;
}

char* getStrInputs(){
	char* strInputs=(char*)malloc((sizeof(char))*MAX_SIZE_INPUTS);
	scanf("%s",strInputs);
	return strInputs;
}

int strToNum(char* inputStr){
	int inputNum=0;
	int digit=1000000;
	int j;
	int check;
	for( j=0; j<MAX_SIZE_INPUTS; j++){
		if(inputStr[j]=='\0'){
			break;
		}
		check=0;
		if((inputStr[j]>='A')&&(inputStr[j]<'Z')){
			if(inputStr[j]<'Q'){	
				inputNum+=((inputStr[j]-'A')/3+2)*digit;
			}
			else if(inputStr[j]>'Q'){
				inputNum+=((inputStr[j]-'A'-1)/3+2)*digit;
			}
			check++;
		}
		else if((inputStr[j]>='0')&&(inputStr[j]<='9')){
			inputNum+=(inputStr[j]-'0')*digit;
			check++;				
		}
		if(check!=0){
			digit/=10;
		} 
	}
	return inputNum;
}

void addData(int inputNum, struct Tree *a){
	struct Data *tmp;
	struct Data *newLeaf;
	int numTemp;
	int changingTemp;
	int phoneNumTemp;
	int check;
	check=0;
	tmp=a->root;
	numTemp=1;
	changingTemp=0;
	phoneNumTemp=0;
	while(tmp!=0){
		if(compare(tmp->phoneNum,inputNum)==0){
			tmp->num++;
			check=1;
			break;
		}
		else if(compare(tmp->phoneNum,inputNum)==1){
			tmp->leftWeight++;
			if(tmp->left==0){
				check=2;
				break;
			}
			tmp=tmp->left;
		}
		else if(compare(tmp->phoneNum,inputNum)==-1){
			if(compare(tmp->leftWeight,tmp->rightWeight)==0){
				phoneNumTemp=tmp->phoneNum;
				tmp->phoneNum=inputNum;
				inputNum=phoneNumTemp;
				changingTemp=tmp->num;
				tmp->num=numTemp;
				numTemp=changingTemp;
			}
			else if(compare(tmp->leftWeight,tmp->rightWeight)==1){
				tmp->rightWeight++;
				if(tmp->right==0){
					check=3;
					break;
				}
				tmp=tmp->right;
			}
		}
	}
	if(check!=1){
		newLeaf=newData();
		newLeaf->phoneNum=inputNum;
		newLeaf->num=numTemp;
		if(check==2){
			tmp->left=newLeaf;
		}
		else if(check==3){
			tmp->right=newLeaf;
		}
		newLeaf->father=tmp;
		a->count++;
	}
}

void printOutput(struct Tree *a){
	int total;
	struct Data *tmp=newData();
	total=a->count;
	tmp=a->root;
	while(tmp->left!=0){
		tmp=tmp->left;
	}
	while(total!=0){
		if(tmp->num!=0){
			printf("%d-%d %d\n",tmp->phoneNum/10000,tmp->phoneNum%10000,tmp->num);
		}
		if(tmp->num==0){
			total--;
		}
		tmp->num=0;
		if(tmp->left){
			tmp=tmp->left;
		}
		else if(tmp->right){
			tmp=tmp->right;
		}
		else if(tmp->father){
			tmp=tmp->father;
		}
	}
}

int main(){
	int numInputs;
	int inputNum;
	int i;
	char *strInputs;
	struct Tree *results=newTree();

	numInputs=getNumInputs();
	for(i=0;i<numInputs;i++){
		strInputs=getStrInputs();
		inputNum=strToNum(strInputs);
		if(i==0){
			createTree(inputNum,results);
			printf("results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		}
		else{
			printf("results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
			addData(inputNum,results);
		}
	}
	printOutput(results);
	return 0;
}