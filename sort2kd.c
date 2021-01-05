/*
    FILE NAME : sort2kd.c
    AUTHOR : KAWAKIB DARAIN
    DATE : 16/08/18 
    AIM : To study and implement the divide– and– conquer sorting methods
		  Merge, Quick, and Heap.
          
         
    PROBLEM    :   Using the utility functions created in Experiment-2, 
    			   write a menu driven program to order a list in ascending 
    			   order using following “ divide-and-conquer” approaches – 
    			   the Quick Sort, the Heap Sort, and the Merge Sort.
				   You should compare the running time for ordering lists 
				   different input sizes in respect of traditional comaprison 
				   sorts and divide-and-conquer sorts.
*/

//Header file inclusions
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define INF 999999999

void quick_sort(int *,int,int);
int partition(int *,int,int);

void merge_sort(int *,int,int);
void merge(int *,int,int,int);
void heap_sort(int *,int);
int parent(int);
int left(int);
int right(int);
int build_heap(int *,int,int);
int heapify(int *,int,int);
void display(int *,int);
                    
int main()
{
    int choice1,choice2,flag[2]={0,0},i,arrlen;
    clock_t start,end;
    double timetaken;
    int *arr,*cpy,const1=100000,const2=999999;
    do
    {
    	printf("Enter number of elements of the list[multiples of 10]:- ");
    	printf("\n");
    	scanf("%d",&arrlen);
    	if(arrlen>1000000 ||arrlen%10!=0)
    	{
    		flag[0]=1;
    		printf("Entered value is invalid, enter a valid number\n");
    	}
    	else
    		flag[0]=0;
    }while(flag[0]==1);
    
    arr=(int*)malloc(arrlen*sizeof(int));
    cpy=(int*)malloc(arrlen*sizeof(int));	
    
    srand(time(0));	
    
    do
    {
    printf("What type of list do you want to create?");
    printf("\n1.Random List  2.Ascending List  3.Descending List");
    printf("  4.Nearly Sorted List  0.Exit\n");
    scanf("%d",&choice1);
    switch (choice1)
    {
    	case 1:		
    		//random list
    		for(i=0;i<arrlen;i++)
    		{
    			*(arr+i)=rand()%1000000;    //random elements
    			*(cpy+i)=*(arr+i);   //copy array
    		}
    		if(arrlen<20)
    		{
    			for(i=0;i<arrlen;i++)
    			{
    				printf("%d\t",*(arr+i));
    			}
    		}
    		break;
    		
    	case 2:		//ascending list
    		for(i=0;i<arrlen;i++)
    		{
    			*(arr+i)=const1;
    			*(cpy+i)=*(arr+i);
    			const1+=10;
    		}
    		if(arrlen<20)
    		{
    			for(i=0;i<arrlen;i++)
    			{
    				printf("%d\t",*(arr+i));
    			}
    		}
    		break;
    		
    	case 3:		//descending list
    		for(i=0;i<arrlen;i++)
    		{
    			*(arr+i)=const2;
    			*(cpy+i)=*(arr+i);
    			const2-=10;
    		}
    		if(arrlen<20)
    		{
    			for(i=0;i<arrlen;i++)
    			{
    				printf("%d\t",*(arr+i));
    			}
    		}
    		break;
    		
    	case 4:		//nearly sorted list
    		for(i=0;i<arrlen;i++)
    		{
    			if((i+5)%8==0)
    				*(arr+i)=const1-75;
    			else
    				*(arr+i)=const1;
    			*(cpy+i)=*(arr+i);
    			const1+=50;
    		}
    		if(arrlen<20)
    		{
    			for(i=0;i<arrlen;i++)
    			{
    				printf("%d\t",*(arr+i));
    			}
    		}    		
    		
    		break;
    		
    	case 0:
    		exit(1);
    		break;
    	default:
    		printf("wrong choice");
    }
    
    do
    {
    	printf("Select type of sort\n1.Quick Sort\t2.Merge Sort\t3.Heap Sor\t");
    	printf("0.Back\n");
    	scanf("%d",&choice2);
    	switch (choice2)
    	{
        	case 1:
        		for(i=0;i<arrlen;i++)
        			*(arr+i)=*(cpy+i);
        		start=clock();
        		quick_sort(arr,0,arrlen-1);
        		end=clock();
        		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
        		printf("Time taken to sort = %lf\n",timetaken);
        		if(arrlen<20)
            	{
            		display(arr,arrlen);
            	}
            	flag[1]=0;
            	break;
        	case 2:
            	for(i=0;i<arrlen;i++)
        			*(arr+i)=*(cpy+i);
            	start=clock();
            	merge_sort(arr,0,arrlen-1);
            	end=clock();
        		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
        		printf("Time taken to sort = %lf\n",timetaken);
        		if(arrlen<20)
        		{
            		display(arr,arrlen);
            	}
            	flag[1]=0;
           	 	break;
        	case 3:
            	for(i=0;i<arrlen;i++)
        			*(arr+i)=*(cpy+i);
            	start=clock();
            	heap_sort(arr,arrlen);
            	end=clock();
        		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
        		printf("Time taken to sort = %lf\n",timetaken);
        		if(arrlen<20)
        		{
            		display(arr,arrlen);
            	}
            	flag[1]=0;
            	break;
       	 	case 0:
        		flag[1]=1;
        		break;
        	default:
                printf("Invalid Choice\n");
                flag[1]=0;
    	}
    }while(flag[1]==0);
    
    }while(1);
    return 0;
}


void display(int *a,int arrlen)
 {
    int i;
    
    printf("Sorted List:-\n");
    for(i=0;i<arrlen;i++)
        printf("%d\t",a[i]);
    printf("\n");
    
}

void quick_sort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		 q=partition(a,p,r);
		 quick_sort(a,p,q-1);
		 quick_sort(a,q+1,r);
	}
}

int partition(int *a,int p,int r)
{
	int pivot,i,j,t;
	
	pivot=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<pivot)
		{
				i++;
				SWAP(a[i],a[j],t);
		}
	}
	SWAP(a[i+1],a[r],t);
	
	return i+1;
}


void merge_sort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

void merge(int *a,int p,int q,int r)
{
	int n1,n2,i,j,k,*L,*R;
	n1=q-p+1;
	n2=r-q;
	
	L=(int*)malloc((n1+1)*sizeof(int));
	R=(int*)malloc((n2+1)*sizeof(int));
	for(i=0;i<n1;i++)
		L[i]=a[p+i];
	for(j=0;j<n2;j++)
		R[j]=a[q+j+1];
	L[n1]=INF;
	R[n2]=INF;
	i=0;j=0;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{	
			a[k]=L[i];
			i=i+1;
		}
		else
		{
			a[k]=R[j];
			j=j+1;
		}
	}
}
			
void heap_sort(int *a,int arrlen)
{
	int i,heap_size,temp;
	heap_size=arrlen-1;
	heap_size=build_heap(a,arrlen,heap_size);
	for(i=arrlen-1;i>=1;i--)
	{
		SWAP(a[0],a[i],temp);
		heap_size-=1;
		heap_size=heapify(a,0,heap_size);
	}
}

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}

int build_heap(int *a, int arrlen, int heap_size)
{
	int i;
	for(i=(arrlen-1)/2;i>=0;i--)
		heap_size=heapify(a,i,heap_size);
	return heap_size;
}

int heapify(int *a,int i,int heap_size)
{
	int l,r,largest,temp;
	l=left(i);
	r=right(i);
	if(l<=heap_size && a[l]>a[i])
		largest=l;
	else
		largest=i;
	
	if(r<=heap_size && a[r]>a[largest])
		largest=r;
	
	if( largest != i)
	{
		SWAP(a[i],a[largest],temp);
		heap_size=heapify(a,largest,heap_size);
	}
	return heap_size;
}
	
