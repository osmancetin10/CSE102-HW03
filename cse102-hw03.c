						/***************************/
						/*                         */
						/*      Osman Çetin        */
						/*       161044069         */
						/*         HW-03           */
						/*                         */
						/***************************/

#include <stdio.h>
#include <stdlib.h>/*because of these librarys(time.h and stdlib.h), we can generate random numbers*/  
#include <time.h>
#include <math.h>/*because of this library, we can use pow function*/

void menu();
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
/*this program does
	Horse Racing Game
	Occurrence Counter
	Triangle of Sequences*/

int main(){
		srand(time(NULL));
	menu();

}	

void menu(){/*this menu function displays options to users*/
	
	int k=1,selection;
	
	do{
		printf("\n1. Horse Racing Game");
		printf("\n2. Occurrence Counter");
		printf("\n3. Triangle of Sequences");
		printf("\n0. Exit");
		printf("\n				Make Selection:");			
		scanf("%d",&selection);
		
		switch(selection){
			case 1: horseRacingGame();  break;
			case 2: countOccurrence();  break;
			case 3: triangleOfSequences(); break;
			case 0: k++; break;
			default : printf("\nThis choise is not defined!! Again Enter:");  break;/*if user select false selection he or she should select any option again*/
		}
	}while(k==1);
} 

int getInt(int mini, int maxi){/*this funciton gets number from user between in range*/
	int k=0,number;
	while(k==0){
		scanf("%d",&number);
		if(number>=mini && number<=maxi) k++;
		else printf("\nThis number is not in range!! Again Enter:");/*if number which is user entered is not in range, user enters number again*/ 
	}	
	return number;
}

int numberGeneratorBetweenRange(int min,int max){/*this function generates numbers between min and max range with using rand function*/

	int number;
		number=rand()%(max-min+1)+min;	
	return number;
}
			

void horseRacingGame(){/*this function going to implement a virtual horse race. firstly user selects horse number between in range. after than race will start race. finally program says who is the winner */
	int	i,j,horse_count,users_horse,now_horse,first=1000,first_index,second=0,second_index,mini=1,maxi;
	horse_count=numberGeneratorBetweenRange(3,5);
	maxi=horse_count;
	printf("\nNumber of Horse:%d",horse_count);
	printf("\nHorse Number:");
	
	users_horse=getInt(mini,maxi);
	printf("\nRacing starts...");
	for(i=1;i<=horse_count;i++){
		now_horse=numberGeneratorBetweenRange(10,20);
		printf("\nNow horse:%d",now_horse);
		printf("\nHorse %d:",i);
		for(j=0;j<now_horse;j++){
			printf("-");
		}
		if(now_horse<=first){ 
			second=first;
			second_index=first_index;
			first=now_horse;
			first_index=i;
		}
	}	
	if(first_index==users_horse) printf("\nYou win! Winner is Horse %d.",first_index);/*this comparison compares is the first horse equals your selection*/
	else{
		if(first==second) printf("\nYou lose! Winner is Horse %d (or %d. It does not matter.).",first_index,second_index);
		else printf("\nYou lose! Winner is Horse %d",first_index);
	}
	printf("\n*********************************************************");	
}
		

void countOccurrence(){/*This sub-program asks for two positive integer values from the user. These two values are bigNumber and searchNumber. This sub-program computes number of occurrences ofsearchNumber in bigNumber.*/
	
	int i,k=0,big,search,digit,counter=0,digit_count=0,mode;
	int temp,bigtemp;
	printf("\nBig Number:");
	scanf("%d",&big);
	printf("\nSearch Number:");
	scanf("%d",&search);
	temp=search;
	bigtemp=big;
	
	while(temp>0){/*this is digit counter of search number*/
		digit_count++;  
  		temp/=10;         
	}

	
	if(digit_count==1){/*if search number's digit is 1 program does this*/
		while(k==0){
			digit=big%10;
			if(digit==search) counter++;
			big=(big-digit)/10;
			if(big<1) k++;
		}
	}
	else{/*if search number's digit is bigger than 1 program does this*/
		mode=pow(10,digit_count);
		while(k==0){
			digit=big%mode;
			if(digit==search) counter++;
			big=(big-digit)/pow(10,digit_count);
			if(big<1) k++;
		}
		k=0;
		bigtemp=(bigtemp-bigtemp%10)/10;
		while(k==0){
			digit=bigtemp%mode;
			if(digit==search) counter++;
			bigtemp=(bigtemp-digit)/pow(10,digit_count);
			if(bigtemp<1) k++;
		}
	}		
	
	printf("\nOccurrence:%d",counter);
	printf("\n*********************************************************");	
}

void triangleOfSequences(){/*This sub-program generates a random integer value between 2 and 10. It then generates a triangle of sequences as illustrated below.*/
	int i, j,temp;
	int number=numberGeneratorBetweenRange(2,10);
	
	for(i=1;i<=number;i++){
		temp=i;
		for(j=1;j<=i;j++){
			printf("%d ",temp);
			temp=temp+i;
		}
		printf("\n");
	}
	printf("\n*********************************************************");	
}				
