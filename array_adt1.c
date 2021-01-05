/*
    FILE NAME : array_adt.c
    AUTHOR : TEJAS DEO
    DATE : 19/07/18 
    AIM : To study an Array ADT and to implement various operations on an
          Array ADT.
         
    PROBLEM    :   Create an array and implement the operations – 
                   traverse(), insert_element(),delete_element(), sort(),
                   search(), merge(), copy(), create(), isFull(),isEmpty()
                   and length(). Write a C program to demonstrate an array
                   ADT using defined operations appropriately using a 
                   menu-driven approach. Your programshould be able to 
                   print the array contents appropriately at any or all
                   instances (as required may be). You must also ensure 
                   that no input is acquired within the body of functions,
                   nor (preferably) display any prompts/results. 
*/
//Header file inclusions
#include<stdio.h>

//Global declaration
#define min_val -999
#define max_size 5
	
//Start of BODY

int main()
{
	int choice,len = 0,fullcheck,emptycheck;
	void initial(int arr[]);
	int length(int arr[]);
	void create(int arr[]);
	void display(int arr[]);
	void search(int arr[]);
	void deletion(int arr[]);
	void insert(int arr[]);	
	void sort(int arr[]);
	void copy(int arr[] ,int arr2[]);
	void merge(int arr[], int arr2[], int arr3[]);
	void traverse(int arr[]);
	int isfull(int arr[]);
	int isempty(int arr[]);
	
	int arr[5], arr2[5], arr3[10]; 
		
	initial(arr);
	initial(arr2);
	initial(arr3);
		
	do{	
		//Creation of the menu for array ADT
		printf(" \n\nThe Array ADT Functions are... \n 1. Create()\t 
		2. isFull()\t 3. isEmpty()\n 4. Display()\t 5. Length()\t 6. Copy()
		\n 7. Merge()\t8. Search()\t 9. Insert_element()\n 10.Delete() 
		\t 11.Sort()\t12.Traverse()\n 0. Exit()\n Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: printf("\nPROGRAM TERIMINATED!\n\n");
				break;
			case 1: create(arr);
				break;
			case 2: fullcheck = isfull(arr);
					(fullcheck==1)? printf("\n the array is full") : printf("\n 
					the array is not full");
				break;
			case 3: emptycheck = isempty(arr);
					(emptycheck==1)? printf("\n The array is empty"):printf("\n
					 the array is not empty");
				break;
			case 4: display(arr);
				break;
			case 5: len=length(arr);
				printf("\n The length of the array is %d ",len);
				break;
			case 6: copy(arr,arr2);
				break;
			case 7: merge(arr,arr2,arr3);
				break;
			case 8: search(arr);
				break;
			case 9: insert(arr); 
				break;
			case 10: deletion(arr); 
				break;
			case 11: sort(arr);
				break;
			case 12: traverse(arr);
				break;
			default: printf("\nPlease Enter a Valid Value as shown in the
					 above menu");
		}
	}while(choice!=0);
	return 0;
}
//Function for Initialisation
void initial(int arr[])
{
	int cnt;
	for(cnt=0;cnt<max_size;cnt++)
	{
		arr[cnt] = min_val;
	}
    return;
}
//Function for Length
int length(int arr[])
{
	int len=0,cnt;
	for(cnt=0;cnt<max_size;cnt++)
	{
		if(arr[cnt]==min_val)
			return len;
		len++;
	}
	return len;
}
//Function for Creation
void create(int arr[])
{
    int leng, cnt;
    leng=length(arr);
    for(cnt=leng;cnt<max_size;cnt++)
    {
    	do
    	{  	printf("\n Enter the elements at position %d : ",cnt+1);
        	scanf("%d",&arr[cnt]);
        	if(arr[cnt]==min_val)
        	{
        		return;
        	}
        }while(arr[cnt]==min_val);
    }
    return;
}
//Function for display
void display(int arr[])
{
	int cnt, len;
	len = length(arr);
	if(len==0)
	{
		printf("\nThere are no elements present in the array");
		return;
	}
	printf("\nThe elements of your array are: \n");
	for(cnt=0; cnt<len; cnt++)
		printf("%d\t",arr[cnt]);
	return;		
}
//Function for isfull
int isfull(int arr[])
{
	int len;
	len = length(arr);
	if (len == max_size)
		return 1;
	return 0;
}	
//Function for isempty
int isempty(int arr[])
{
	int len;
	len = length(arr);
	if(len==0)
		return 1;
	return 0;
}
//Function for search
void search(int arr[])
{
	int sear,cnt,len;
	len=length(arr);
	if(len==0)
	{
		printf("\nPlease create an array before trying to search");
		return;
	}
	do
	{
		printf("\n Enter the element to be searched :");
		scanf("%d",&sear);
		if(sear==min_val)
			printf("\nPlease enter a value that is different than that of the
			minimum value of the array");
	}while(sear==min_val);
	
	for(cnt=0;cnt<len;cnt++)
	{
		if(sear==arr[cnt])
		{
			printf("\n The entered element is similar to the element
			at %d position",cnt+1);
			return;
		}
	}
	printf("\n There is no element in the array which matches to
	the entered element");
	return;
}
//Function for deletion
void deletion(int arr[])
{
	int len,index,cnt;
	len=length(arr);
	if(len==0)
	{
		printf("\nNo elements can be deleted as the array is already empty");
		return;
	}
	printf("\n Enter the index at which you would like
	to delete the element : ");
	scanf("%d",&index);
	if (index>len-1 || index <0)
	{
		printf("\n The entered index is invalid");
		return;
	}
	if(index==len-1)
	{
		arr[index]=min_val;
		return;
	}
	for(cnt=index;cnt<len;cnt++)
	{
		arr[cnt]=arr[cnt+1];
		arr[len]=min_val;
	}
	
	return;
}
//Function for Insertion
void insert(int arr[])
{
	int len,index,value,cnt;
	len=length(arr);
	if(len==max_size)
	{
		printf("\nNo elements can be inserted, as the array is already full");
		return;
	}
	
	printf("\n Enter the index at which you would like to insert
	the element : ");
	scanf("%d",&index);
	
	if(index>len || index<0)
	{
		printf("\n The entered index is invaild");
		return;
	}
	for(cnt=len;cnt>=index;cnt--)
		arr[cnt+1]=arr[cnt];
	do
	{
		printf("\n Enter the value to be inserted : ");
		scanf("%d",&arr[index]);
		if(arr[index]==min_val)
		{
			printf("\nPlease enter a value that is different than that of
		    the minimum value of the array");
		}
	}while(arr[index]==min_val);
	return;
}
//Function for Sort using old bubble sort
void sort(int arr[])
{
	int cnt,cnt2,order,len,ph;
	len=length(arr);
	if(len==0 || len==1)
		{
			printf("Sorting cannot be done on such a small array");
			return;
		}
		printf("\n Enter the order is which you would like to sort the array \n 
		1. Asending \t 2. Decesnding \n 0. Go Back \n Your Choice :");
		scanf("%d",&order);
		switch(order)
		{
			case 1: for(cnt=0;cnt<len;cnt++)
						{
							for(cnt2=cnt+1;cnt2<len;cnt2++)
							{
								if(arr[cnt]>arr[cnt2])
								{
									//Swapping the elements
									ph=arr[cnt];
									arr[cnt]=arr[cnt2];
									arr[cnt2]=ph;									
								}
							}
						}
				break;
			case 2: for(cnt=0;cnt<len;cnt++)
						{
							for(cnt2=cnt+1;cnt2<len;cnt2++)
							{
								if(arr[cnt] < arr[cnt2])
								{
									//Swapping the elements
									ph=arr[cnt];
									arr[cnt]=arr[cnt2];
									arr[cnt2]=ph;									
								}
							}
						}
				break;	
			case 0:
				break;			
			default: printf("\n Please enter a vaild option from the menu");
		}	
	return;
}
//Function for Copy
void copy(int arr[],int arr2[])
{
	int len,cnt;
	len=length(arr);
	if(len==0)
	{
		printf("\nPlease create an array before trying to copy it");
		return;
	}	
	for(cnt=0;cnt<len;cnt++)
		arr2[cnt]=arr[cnt];
	printf(" \nThe array has been succesfully copied");
	return;
}
//Function for merge
void merge(int arr[],int arr2[],int arr3[])
{
	int len,len2,i=0,j;
	printf("Enter the elements of second array to merge with first array.\n");
	if(i>max_size)
	{
		printf("\nArray length crosses maximum value.");
		return;
	}
	for(i=0;i<max_size;i++)
	{
		printf("\nEnter the element at position %d : ",i+1);
		scanf("%d",&arr2[i]);
		if(arr2[i]==min_val)
		{
			break;
		}
	}
	len=length(arr);
	len2=length(arr2);
	j=0;
	for(i=0;i<len;i++)
	{
		arr3[j]=arr[i];
		j++;	
	}
	for(i=0;i<len2;i++)
	{
		arr3[j]=arr2[i];
		j++;
	}
	printf("\nThe elements of first array are:\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nThe elements of second array are:\n");
	for(i=0;i<len2;i++)
	{
		printf("%d\t",arr2[i]);
	}
	printf("\nThe merged array is:\n");
	for(i=0;i<(len+len2);i++)
	{
		printf("%d\t",arr3[i]);
	}
	return;	
}
//Function for traverse
void traverse(int arr[])
{
    int len,cnt,index,check;
    len=length(arr);
    printf("\nEnter the index in which you need to check if the number 
    is odd or even and add 10 if it is even or subtract 10 if it is odd.\n");
    scanf("%d",&index);
    if(index>len || index<0)
    {
        printf("\nPlease enter valid index.");
        return;
    }
    check=arr[index]%2;
    if(check==0)
    {
        arr[index]=arr[index]+10;
    } 
    else
    {
        arr[index]=arr[index]-10;
    }
    return;   
}

