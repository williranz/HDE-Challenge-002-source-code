#include <stdio.h>
#include <conio.h>

/* Author : William Cahyadi
student_id : 110706576 */

void repeat(int i, int N, int X, int Y[], int result[]);
void repeat2(int i, int X, int *temp, int Y[], int N);
void repeat3(int i, int N, int result[]);
int power(int a, int b); 


int main() 
{
	int N;
	int X;
	int Y[100];	
	int result[100];

label1 :	
	
	printf("\nEnter N cases [1-100] : "); scanf("%d",&N);  fflush(stdin);
	if(N<1||N>100)
	{
		printf("\nPlease enter N with value only 1 to 100....");
		goto label1;
	}
	
	repeat(0,N,X,Y,result);
	
	printf("\n\nOUTPUT\n");
	
	repeat3(0,N,result);
	
	return 0;
}



void repeat(int i, int N, int X, int Y[], int result[])
{
	int temp;
	
	if(i<N)
	{
		printf("\n Case %d\n",i+1);
		temp=0;
label2 :
		printf("\n Enter number of X [1 to 100] : "); scanf("%d",&X); fflush(stdin);
		if(X<1||X>100)
		{
			printf("\n Please enter number of X with value only 1 to 100....");
			goto label2;
		}
		
		repeat2(0, X, &temp, Y, N);
		result[i]=temp;	
		i++;
		repeat(i,N,X,Y,result);
	}
}


void repeat2(int i, int X, int *temp, int Y[], int N)
{
	if(i<X)
	{

label3 : 

		printf("\n  Enter value for X integer %d [-100 to 100] : ",i+1); scanf("%d",&Y[i]); fflush(stdin);
		
		if(Y[i] < -100 || Y[i] > 100)
		{
			printf("\n  Please enter X integer %d with value only -100 to 100....",i+1);
			goto label3;
		}
		
		else if(Y[i] >= -100 && Y[i] < 0)
			goto label4;
		
		else
			*temp = *temp + power(Y[i],N);

label4 :
		
		i++;
		repeat2(i, X, &(*temp), Y, N);
	}
}


void repeat3(int i, int N, int result[])
{
	if(i<N)
	{
		printf("\nResult of Case %d : %d\n",i+1,result[i]);
		i++;
		repeat3(i,N,result);
	}
}


int power(int a, int b)
{ 
	int output;
	
	if(b==0)  
		output=1; 

	else 	
		output = a*power(a,b-1);
		
	return output;
} 
