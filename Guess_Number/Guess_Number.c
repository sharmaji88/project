 //////////////////////////////////////////////////////
 // Mini Project -1  Guess the Number
 //////////////////////////////////////////////////////
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 
 
 void iGuess();
 int main()
 {
 		iGuess();
		
		return 0;
 }  
 void iGuess()
 {
 	
 	int iNguess = 1 , iNo = 0,iguess=0;
 	srand(time(0));
 	iNo = rand() % 100 + 1; //Generate Random Number Btwn 1 to 100 
 	do
 	{	printf("Guess Beetween 1 to 100 \n");
		scanf("%d",&iguess);
 		if(iguess > iNo )	
 		{
			printf("Lower Number Please\n");
		}
		else if( iguess < iNo)
		{
			printf("Higher Number Please\n");
		}
		else
		{
			printf("Hurreeehh !!!! Number Found\n");
		}
 		iNguess++;	
	}while(iguess != iNo);
	printf("you try this many time %d:",iNguess);
 	
 }
 
