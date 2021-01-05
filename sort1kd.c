/*
    FILE NAME : sort1kd.c
    AUTHOR : KAWAKIB DARAIN
    DATE : 02/08/18 
    AIM : To study and implement basic comparative sorting methods
		  Selection, Insertion, Bubble, and Shell.
         
    PROBLEM    :   Write a generalized function that takes a parameter to
     			   indicate the mode (say 1 for decreasing order, 2 for 
     			   increasing order, 3 for increasing order with the Nth 
     			   element out of order, 4 for a randomly generated element 
     			   values), to create a list of elements. The parameter 
     			   indicating the number of elements in a statically allocated 
     			   array (the maximum size is large enough to run possible 
     			   iterarations to test the time complexity, say 1000000)
				   will be a multiple of 10. Also write appropriate functions 
				   to create a copy of the list and to display the list 
				   contents.
				   Using above functions, write a menu-driven C program to 
				   order the list in ascending sequence using - the 
				   Bubble Sort, the Insertion Sort, the Selection Sort, 
				   the Shell Sort.
*/

//Header file inclusions
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MX_SIZE 10000000
void bubble_sort(int *,int len);
void insertion_sort(int *,int len);
void selection_sort(int *,int len);
void shell_sort(int *,int len);
void display(int *,int len);
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t));
int main()
{
	int op,temp,a,k,i,t;
        int len;
	double elapsed_time;
	double clock_t,beg,end;
	int* arr;
	int* arr1;
	char c;
	printf("Enter the number of digits you want to sort(multiples of 10):");
	scanf("%d",&len);
	arr=(int*)malloc(len*sizeof(int));
	arr1=(int*)malloc(len*sizeof(int));
	
	
	if(len>=MX_SIZE)
	printf("Maximum limit exceeded");
	a=len;

	do
	{
	
	
		printf(" \n Choose of the following :");
		printf(" \n 1.Ascending \t 2.Descending \t 3.Random \t");
		printf("4.Partially sorted\n 5.Display \t 6.Exit \n ");
		printf("Enter your choice :");	
		scanf("%d",&op);
	
		switch(op)
	{	
		//ASCENDING ORDER	
		case 1 : 
					 for(i=0;i<len;i++)
            			 	{
             		 			arr1[i] = 1000000 +i+1;
             		 	        }


			do
		{
			printf("\n Choose of the following to check for ");
			printf("ascending ordered list:-");
			printf("\n a.Insertion sort \t b.Bubble sort \t c.Selection Sort"); 
			printf("\n d.Shell Sort \n e.Display \t f.Exit \n");
			printf("\n Enter your choice:");
			scanf(" %c",&c);
			switch(c)
		{


			case 'a' :	
					//Insertion Sort
					beg=clock();
					insertion_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is  %f ",elapsed_time);
					break;
			case 'b' :	
					//Bubble Sort
					beg=clock();
					bubble_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			
			case 'c' :	
					//Selection Sort
					beg=clock();
					selection_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;		

			case 'd':	
					//Shell Sort
					beg=clock();
					shell_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;	

			case 'e' :      display(arr1,len);
					break;	

		}	
		}while(c!='f');
		break;
	
			



		//DESCENDING ORDER
		case 2 : 		
					for(i=0;i<len;i++)
            				{
             					arr1[i] = 1000000+a;
             					a = a-1;
					}
		
			do
		{
			printf("\n Choose of the following to check for descending ");
			printf("ordered list:-");
			printf("\n a.Insertion sort \t b.Bubble sort \t c.Selection Sort"); 
			printf("\n d.Shell Sort \n e.Display \t f.Exit \n");
			printf("\n Enter your choice:");
			scanf(" %c",&c);
			switch(c)
		{	


			case 'a' :	//Insertion Sort
					beg=clock();
					insertion_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			case 'b' :	
					//Bubble Sort
					beg=clock();
					bubble_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			
			case 'c' :	
					//Selection Sort
					beg=clock();
					selection_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;		

			case 'd':	
					//Shell Sort
					beg=clock();
					shell_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;	

			case 'e' :      display(arr1,len);
					break;	

		
		}
		}while(c!='f');
		break;	


		//RANDOM ORDER
		case 3 : 
	    			
				if (len>0)
  				 {
   					for(i=0;i<len;i++)
					{
   						arr1[i]=rand()/10;
					}		  
	   	        
			         }


			do
		{
			printf("\n Choose of the following to check for randomly"); 
			printf("ordered list :-");
			printf("\n a.Insertion sort \t b.Bubble sort \t c.Selection Sort"); 
			printf("\n d.Shell Sort \n e.Display \t f.Exit \n");
			printf("\n Enter your choice:");
			scanf(" %c",&c);
			switch(c)
		{


			case 'a' :	//Insertion Sort
					beg=clock();
					insertion_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			case 'b' :	
					//Bubble Sort
					beg=clock();
					bubble_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			
			case 'c' :	//Selection Sort
					beg=clock();
					selection_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;		

			case 'd':	
					//Shell Sort
					beg=clock();
					shell_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;	

			case 'e' :      display(arr1,len);
					break;	

		
		}
		}while(c!='f');
		break;		






		//PARTIALLY ORDERED
		case 4 :  	
				for(i=0;i<len;i++)
            		
             			arr1[i] = 1000000 + i;
				
            				
	   					for(k=len/5;k<len;k++)
						{
	     					arr1[k] = 1000000 +8*k-10;
						swap(arr1[i],arr1[k],t);
						}
					
			do
		{
			printf("\n Choose of the following for partially ordered list:-");
			printf("\n a.Insertion sort \t b.Bubble sort \t c.Selection Sort"); 
			printf("\n d.Shell Sort \n e.Display \t f.Exit \n");
			printf("\n Enter your choice:");
			scanf(" %c",&c);
			switch(c)
		{


			case 'a' :	//Insertion Sort
					beg=clock();
					insertion_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			case 'b' :	
					//Bubble Sort
					beg=clock();
					bubble_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;
			
			case 'c' :	
					//Selection Sort
					beg=clock();
					selection_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;		

			case 'd':	
					//Shell Sort
					beg=clock();
					shell_sort(arr1,len);
					end=clock();
					elapsed_time=((double)(end-beg))/CLOCKS_PER_SEC;
					printf(" Time taken is %f ",elapsed_time);
					break;	

			case 'e' :      display(arr1,len);
					break;	

		
		}
		}while(c!='f');
		break;
	


			case 5 : display(arr1,len);
		 	 	 break;
	}
	}while(op!=6);
}

//Function for bubble sort
void bubble_sort(int*arr1,int len)
{
	int i,j,t;
        for(i=1;i<len;i++)
		{
		for(j=0;j<len-i;j++)
			{			
				if(arr1[j]>arr1[j+1])
				swap(arr1[j],arr1[j+1],t);
	        	
			}
		}


	
		return; 
}


//Function for insertion sort
void insertion_sort(int*arr1,int len)
{
	int i,j;
	int key;
	for(j=1;j<len;j++)
	{

	key=arr1[j];
	i=j-1;
	while(i>=0 && arr1[i]>key)
		{
			arr1[i+1]=arr1[i];
			i=i-1;
		}
	arr1[i+1]=key;
	
	}
	return;
}		


//Function for selection sort 			
void selection_sort(int*arr1,int len)
{
	int i,j,min_pos,t;
	for(i=0;i<len;i++)
  {
  	min_pos=i;
  		for(j=i+1;j<len;j++)
  			{
  				if(arr1[j]<arr1[min_pos])
  				min_pos=j;
			}
  				if(min_pos!=i)
  				swap(arr1[i],arr1[min_pos],t);
  			
  }
  	return;
}  				


//Function for shell sort
void shell_sort(int*arr1,int len)
{
	int gap,i,j,key;
	for(gap=len/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<len;i++)
			{
				key=arr1[i];
				for(j=i;j>=gap && arr1[j-gap]>key;j=j-gap)
				{
						
						arr1[j]=arr1[j-gap];
				}
					        arr1[j]=key;	
			}
    	}		
		
		return;		
}
					
 
//Function for display 	
void display(int*arr1,int len)
{
		int i;
		printf("\n The elements of your array are: \n");
		for(i=0;i<len;i++)
		{
			printf(" %d\t",arr1[i]);
		}
		return;		
}



