/*PKU Judge Online problem 1002 */
/*			Yinsong Xu			*/
/*Start Date:  Oct, 30	2014	*/
/*End Date:    Nov, 02  2014	*/
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
	struct Data *a=(struct Data*)malloc(sizeof(struct Data));
	initData(a);
	return a;
}

void createTree(int inputNum, struct Tree *a){
	struct Data *first=newData();
	a->root=first;
	a->root->phoneNum=inputNum;
	a->root->num=1;
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
	//printf("numInputs=%d\n",numInputs);
	return numInputs;				//to get the number of inputs
}

void getStrInputs(char* strInputs){		//to get the number
	scanf("%s",strInputs);
}

int strToNum(char* inputStr){			//transfer the string to integer
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

void addData(int inputNum, struct Tree *a){			//add new data to the tree
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
	//printf("1a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
	while(tmp!=0){
		if(compare(tmp->phoneNum,inputNum)==0){
			tmp->num++;
			check=1;
			break;
		}
		else if(compare(tmp->phoneNum,inputNum)==1){
			tmp=tmp->left;
		}
		else if(compare(tmp->phoneNum,inputNum)==-1){
			tmp=tmp->right;
		}
	}
	tmp=a->root;
	while(check==0){
		if(compare(tmp->phoneNum,inputNum)==1){
			if(compare(tmp->leftWeight,tmp->rightWeight)==0){
				tmp->leftWeight++;
				if(tmp->left==0){
					check=2;
					break;
				}
				tmp=tmp->left;
			}
			else if(compare(tmp->leftWeight,tmp->rightWeight)==1){
				phoneNumTemp=tmp->phoneNum;
				tmp->phoneNum=inputNum;
				inputNum=phoneNumTemp;
				changingTemp=tmp->num;
				tmp->num=numTemp;
				numTemp=changingTemp;
			}
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
		//printf("4.5a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		newLeaf=newData();
		//printf("4.7a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		newLeaf->phoneNum=inputNum;
		//printf("4.6a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		newLeaf->num=numTemp;
		if(check==2){
			//printf("4.4a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
			tmp->left=newLeaf;
			//printf("4a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		}
		else if(check==3){
			tmp->right=newLeaf;
			//printf("5a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		}
		newLeaf->father=tmp;
		//printf("6a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
		a->count++;
		//printf("count=%d\n",a->count);
	}
	//printf("3a->root->phoneNum=%d\na=%p\n",a->root->phoneNum,a->root);
}

void printOutput(struct Tree *a){		//print the output
	int total;
	struct Data *tmp=newData();
	total=a->count;
	tmp=a->root;
	while(total!=0){
		while(tmp->left){
			if(tmp->left->num==0){
				break;
			}
			tmp=tmp->left;
		}
		if(tmp->num!=0){
			if(tmp->num>1){
				printf("%d-%d %d\n",tmp->phoneNum/10000,tmp->phoneNum%10000,tmp->num);
			}
			tmp->num=0;
			total--;
		}
		else if(tmp->right){
			if(tmp->right->num!=0){
				tmp=tmp->right;
			}
			else{
				tmp=tmp->father;
			}
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
		//if(i>0)
			//printf("1results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		strInputs=(char*)malloc(sizeof(char)*MAX_SIZE_INPUTS);
		//if(i>0)
			//printf("2results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		getStrInputs(strInputs);
		//if(i>0)
			//printf("3results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		//printf("strInputs=%s\n",strInputs);
		//printf("sizeof=%d\n",(int)sizeof(strInputs));
		inputNum=strToNum(strInputs);
		//if(i>0)
			//printf("4results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		//printf("inputNum=%d\n",inputNum);
		if(i==0){
			createTree(inputNum,results);
			//printf("5results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		}
		else{
			//printf("6results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
			addData(inputNum,results);
			//printf("7results->root->phoneNum=%d\na=%p\n",results->root->phoneNum,results->root);
		}
		free(strInputs);
	}
	printOutput(results);
	return 0;
}