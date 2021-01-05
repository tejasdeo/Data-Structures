/*
    FILE NAME : stkqcq.c
    AUTHOR : KAWAKIB DARAIN
    DATE : 30/08/18 
    AIM : To study and implement different linear data structures using
    	  arrays- Stack ADT, Queue ADT, and Circular Queue ADT.
          
         
    PROBLEM : Use array based allocation to initialize a Stack, a Queue, 
    		  and a Circular Queue and implement the permissible operations
    		  on them. Write a menu-driven program in C to test these
    		  data structures.
    		  The solution involving use of structure(s) to realize the 
    		  mentioned data structures will be preferred (but not essential).     
*/
//Header file inclusions
#include<stdio.h>
#define MAXSTK 5
#define MAXQ 5
#define MAXCQ 5
//STACK
typedef struct
{
	int Top;
	int items[MAXSTK];
}stack;
//QUEUE
typedef struct
{
	int front,rear;
	int items[MAXQ];
}queue;
//CQUEUE
typedef struct
{
	int front,rear;
	int items [MAXCQ];
}cqueue;
//STACK
void Push(stack *,int);
int Pop(stack *,int);
void Displays(stack *);
int Tops(stack *, int);
//QUEUE
void Insertq(queue *,int);
int Deleteq(queue *);
void Displayq(queue *);
//CQUEUE
int Insertcq(cqueue *, int);
int Deletecq(cqueue *, int);
void Displaycq(cqueue *);
int main()
{
	stack s;
	queue q;
	cqueue cq;
	int x,ch,choice,c;

	do
	{
		printf("Choose from the following:-\n");
		printf("1.Stack\t\t2.Queue\t\t3.Circular Queue\t0.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
					s.Top=-1;
					do	
					{
						printf("\nChoose from the following:-\n");
						printf("1.Push(s,i)\t2.Pop(s)\t3.Top(s)\t4.IsEmpty\n");
						printf("5.IsFull\t6.Display\t0.Exit\n");
						scanf("%d",&ch);
						switch(ch)	
						{
							case 1 :				
									Push(&s,x);
									break;
							case 2 :
									x=Pop(&s,x);				
									break;
							case 3 :
									x=Tops(&s,x);					
									break;
							case 4 :
									if(s.Top==-1)
										printf("\nStack is empty.\n");
									else
										printf("\nStack s not empty.\n");
									break;
							case 5 :
									if(s.Top == MAXSTK-1)
										printf("\nStack is full.\n");
									else
										printf("\nStack is not full.\n");
									break;
							case 6 :
									Displays(&s);
									break;
							case 7 :
									break;
						}
					}while(ch!=0);	
					break;
			case 2 :
					q.front=0;
					q.rear=-1;
					do
					{
						printf("\n\nEnter choice:-\n");
						printf("1.Insert(Q,ELE)\t\t");
						printf("2.Delete(Q,ELE)\t\t3.QEmpty(Q)\t4.QFull(Q)");
						printf("\n5.Display(Q)\t\t6.Front(Q)\t");
						printf("\t7.Rear(Q)\t0.Exit\n");
						scanf("%d",&c);
						switch(c)
						{
							case 1 :
									printf("\nEnter element to be inserted:-");
									printf("\n");
									scanf("%d",&x);
									Insertq(&q,x);
									break;
							case 2 :
									x=Deleteq(&q);
									printf("\nDeleted element is %d.\n",x);
									break;
							case 3 :
									if(q.rear < q.front)
									{
										printf("\nQueue is empty.\n");
									}
									else
									{
										printf("\nQueue is not empty.\n");
									}
									break;
							case 4 :
									if(q.rear==MAXQ-1)
									{
										printf("\nQueue is full.\n");
									}
									else
									{
										printf("Queue is not full.\n");
									}
									break;
							case 5 :
									Displayq(&q);
									break;
							case 6 :
									if(q.rear < q.front)
									{
										printf("\nQueue is empty.\n");
										break;
									}
									printf("\nThe value at front is");
									printf(" %d.\n",q.front+1);
									break;
							case 7 :
									if(q.rear < q.front)
									{
										printf("\nQueue is empty.\n");
										break;
									}
									printf("\nThe value at rear is");
									printf(" %d.\n",q.rear+1);
									break;
							case 0 :
									break;
						}
					}while(c!=0);
					break;	
				case 3 :
						cq.front=-1;
						cq.rear=-1;
						do
						{
							printf("\n\nEnter choice:-\n");
							printf("1.Insert(CQ,ELE)\t");
							printf("2.Delete(CQ,ELE)\t3.CQEmpty(CQ)\t");
							printf("4.CQFull(CQ)\n5.Display(CQ)");
							printf("\t\t6.Front(CQ)\t\t7.Rear(CQ)");
							printf("\t0.Exit\n");
							scanf("%d",&c);
							switch(c)
							{
								case 1 :
										Insertcq(&cq,x);
										break;
								case 2 : 
										x=Deletecq(&cq,x);
										printf("Deleted element is %d.",x);
										break;
								case 3 :
										if(cq.front==-1)
											printf("Circular queue is empty.");
										else
											printf("Circ. queue is not empty.");
										break;
								case 4 :
										if(cq.front==(cq.rear+1)%MAXCQ)
											printf("Circular queue is full.");
										else
											printf("Circ. queue is not full.");
										break;
								case 5 :
										Displaycq(&cq);
										break;
								case 6 :
										if(cq.front==-1)
										{
											printf("Circular queue is empty.");
											break;
										}
										printf("The value at front is");
										printf(" %d.",cq.front+1);
										break;
								case 7 :
										if(cq.front==-1)
										{
											printf("Circular queue is empty.");
											break;
										}
										printf("The value at rear is");
										printf(" %d.",cq.rear+1);
										break;
								case 0 :
										break;
							}
						}while(c!=0);
						break;
				case 0 :
						printf("Program Ended!!!\n");
						break;
			}
		}while(choice!=0);
}		
//STACK					
void Push(stack *s,int x)
{
	if(s->Top == MAXSTK-1)
	{
		printf("\nStack is full, element cannot be pushed.\n");
		return;
	}
	else
	{
		printf("\nEnter the element to be pushed:- ");
		scanf("%d",&x);	
		s->Top++;
		s->items[s->Top]=x;
	}
}
int Pop(stack *s, int x)
{
	if(s->Top==-1)
	{
		printf("\nStack is empty, element cannot be poped.\n");
		return 0;
	}
	else
		{
			x=s->items[s->Top];
			s->Top--;
			printf("\nPoped element is %d.\n",x);
			return 0;
		}
}
int Tops(stack *s, int x)
{
	if(s->Top==-1)
	{
		printf("\nStack is empty.\n");
	}
	else
	{
		printf("\nTop value is %d.\n",s->items[s->Top]);
		return 0;
	}
}
void Displays(stack *s)
{
	int i;
	if(s->Top==-1)
	{
		printf("\nStack is empty.\n");
		return;
	}
	else
	{
		printf("\nElements in stack are:-\n");
		for(i=s->Top;i>=0;i--)
		{
			printf("%d\n",s->items[i]);
		}
	}
}
//QUEUE
void Insertq(queue *q,int x)
{
	if(q->rear==MAXQ-1)
	{
		printf("\nQueue is full, element cannot be inserted.\n");
		return;
	}
	q->rear++;
	q->items[q->rear]=x;
}
int Deleteq(queue *q)
{
	int x;
	if(q->rear < q->front)
	{	
		printf("\nQueue is empty.\n");
		return 0;
	}
	x=q->items[q->front];
	q->front++;
	return x;
}
void Displayq(queue *q)
{
	int i;
	if(q->rear < q->front)
	{	
		printf("\nQueue is empty.\n");
		return;
	}
	printf("\nElements in queue are:-\n");
	for(i=q->front;i<=q->rear;i++)
	{
		printf("%d\t",q->items[i]);
	}
}
//CQUEUE
int Insertcq(cqueue *cq,int x)
{
	printf("\nEnter the element to be inserted:-\n");
	scanf("%d",&x);
	if(cq->front==(cq->rear+1) % MAXCQ)
	{
		printf("\nCircular queue is full.\n\n");
		return 0;
	}
	if(cq->front==-1)
	{
		cq->front=0;
		cq->rear=0;
	}
	else
	{
		cq->rear=(cq->rear+1) % MAXCQ;
	}
	cq->items[cq->rear]=x;
	return x;
}
int Deletecq(cqueue *cq,int x)
{
	if(cq->front==-1)
	{
		printf("\nCircular queue is empty.\n\n");
		return 0;
	}
	x=cq->items[cq->front];
	if(cq->front==cq->rear)
	{
		cq->front=-1;
		cq->rear=-1;
	}
	else
	{
		cq->front=(cq->front+1) % MAXCQ;
	}
	return x;
}
void Displaycq(cqueue *cq)
{
	int i;
	if(cq->front==-1)
	{
		printf("Circular queue is empty.");
		return;
	}
	printf("Elements in the circular queue are:-\n");
	if(cq->front<=cq->rear)
	{
		for(i=cq->front;i<=cq->rear;i++)
		{
			printf("%d\t",cq->items[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=cq->front;i<=MAXCQ-1;i++)
		{
			printf("%d\t",cq->items[i]);
		}
		for(i=0;i<=cq->rear;i++)
		{
			printf("%d\t",cq->items[i]);
		}
		printf("\n");
	}
}	



//OUTPUTS

/*

Choose from the following:-
1.Stack		2.Queue		3.Circular Queue	0.Exit
1

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Enter the element to be pushed:- 1

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Enter the element to be pushed:- 2

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Enter the element to be pushed:- 3

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Enter the element to be pushed:- 4

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Enter the element to be pushed:- 5

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
1

Stack is full, element cannot be pushed.

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
6

Elements in stack are:-
5
4
3
2
1

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
2

Poped element is 5.

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
2

Poped element is 4.

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
6

Elements in stack are:-
3
2
1

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
3

Top value is 3.

Choose from the following:-
1.Push(s,i)	2.Pop(s)	3.Top(s)	4.IsEmpty
5.IsFull	6.Display	0.Exit
0

Choose from the following:-
1.Stack		2.Queue		3.Circular Queue	0.Exit
2


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
1


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
2


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
3


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
4


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
5


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
6

Queue is full, element cannot be inserted.


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
5

Elements in queue are:-
1	2	3	4	5	

Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
6

The value at front is 1.


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
7

The value at rear is 5.


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
2

Deleted element is 1.


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
1

Enter element to be inserted:-
6

Queue is full, element cannot be inserted.


Enter choice:-
1.Insert(Q,ELE)		2.Delete(Q,ELE)		3.QEmpty(Q)	4.QFull(Q)
5.Display(Q)		6.Front(Q)		7.Rear(Q)	0.Exit
0
Choose from the following:-
1.Stack		2.Queue		3.Circular Queue	0.Exit
3


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
1


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
2


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
3


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
4


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
5


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
6

Circular queue is full.



Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
5
Elements in the circular queue are:-
1	2	3	4	5	


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
6
The value at front is 1.

Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
7
The value at rear is 5.

Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
2
Deleted element is 1.

Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
1

Enter the element to be inserted:-
6


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
5
Elements in the circular queue are:-
2	3	4	5	6	


Enter choice:-
1.Insert(CQ,ELE)	2.Delete(CQ,ELE)	3.CQEmpty(CQ)	4.CQFull(CQ)
5.Display(CQ)		6.Front(CQ)		7.Rear(CQ)	0.Exit
0
Choose from the following:-
1.Stack		2.Queue		3.Circular Queue	0.Exit
0
Program Ended!!!

*/
