/*
	Practical no. 6
	Filename	: lldt.c
	Author		: TEJAS DEO
	Date 		: 06/09/2018
	Aim			: To study singly linked linear lists and implement various operations on it
                  Insert, Delete, Reverse, Order, Locate Merge, Linked Stack and Linked Queue.

	Problem		: Create a self-referential structure, NodeLL to represent a node of a singly
    Statement     linked linear list. Implement the routines to (1) find length of the list,
                  (2) create a list, (3) insert an element at the beginning, at the end and at
                  a specified position in the list, (4) delete an element fromthe front,
                  rear, or a specified position at the list, (5) reverse the list, (6) search
                  the list. Create a menu-driven C program to test these routines. Use the singly
                  linked linear list routines to implement a linked stack and a linked queue.
*/
//Libraries included
#include<stdio.h>
#include<stdlib.h>

#define ULI unsigned long int
//Making the link list
struct node {
    int data;
    struct node *link;
};
typedef struct node nodell;
typedef nodell *list;
int main() {
    list llist, lstack, lqueue, llistcopy;
    int choice, len, value, sans, select;
    list create(list, int );
    list insert_at_beg(list, int );
    list insert_at_end(list, int );
    list insert_at_pos(list, int, int );
    list insert_ordered(list, int );
    list delete_at_beg(list );
    list delete_at_end(list );
    list delete_at_pos(list, int );
    list deleteordered(list, int );
    list sort(list );
    list reverse(list, int );
    list copy(list );
    void display(list );
    int search(list, int );
    int length(list );
    void displayLS(list );
    int topvalLS(list );
    void displayLQ(list );
    int frontvalLQ(list );
    int rearvalLQ(list );
    do {
        llist = lstack = lqueue = NULL;
        printf("\nEnter the data structure you would like to use : \n1. Linked List ADT\t2. Linked Stack\t\t3. Linked Queue\nYour choice : ");
        scanf("%d",&select);
        switch(select) {
            //Linked List
            case 1: do {
                    printf("\n\nLinked list ADT Funtions are : \n1. InsertAtBeg\t2. InsertAtEnd\t3. InsertAtPos\t4. InsertOrdered");
                    printf("\n5. DeleteAtBeg\t6. DeleteAtEnd\t7. DeleteAtPos\t8. DeleteOrdered");
                    printf("\n9. Display\t10.Sort\t\t11.Create\t12.Destroy");
                    printf("\n13.Reverse\t14.Search\t15.Length\t16.Copy\n0. Exit\nYour choice : ");
                    scanf("%d",&choice);
                    switch(choice) {
                        case 0: printf("\nExiting...");
                            break;
                        case 1: printf("\nEnter the value to be inserted : ");
                            scanf("%d",&value);
                            llist = insert_at_beg(llist, value);
                            printf("\nInserted : %d",value);
                            break;
                        case 2: printf("\nEnter the value to be inserted : ");
                            scanf("%d",&value);
                            llist = insert_at_end(llist, value);
                            printf("\nInserted : %d",value);
                            break;
                        case 3: printf("\nEnter the value to be inserted : ");
                            scanf("%d",&value);
                            llist = insert_at_pos(llist, value, length(llist));
                            printf("\nInserted : %d",value);
                            break;
                        case 4: printf("\nEnter the value to be inserted : ");
                            scanf("%d",&value);
                            llist = insert_ordered(llist, value);
                            printf("\nInserted : %d",value);
                            break;
                        case 5: llist = delete_at_beg(llist);
                            break;
                        case 6: llist = delete_at_end(llist);
                            break;
                        case 7: llist = delete_at_pos(llist, length(llist));
                            break;
                        case 8: printf("\nEnter the value to be deleted : ");
                            scanf("%d",&value);
                            llist = deleteordered(llist, value);
                            break;
                        case 9: display(llist);
                            break;
                        case 10: llist = sort(llist);
                            printf("\nSort Succesful");
                            break;
                        case 11: printf("\nEnter the number of nodes to be created : ");
                            scanf("%d",&value);
                            llist = create(llist, value);
                            break;
                        case 12: llist = NULL;
                            printf("\nThe Linked List has been Destroyed");
                            break;
                        case 13: llist = reverse(llist, length(llist));
                            printf("\nReversal Succesful");
                            break;
                        case 14: printf("\nEnter the value to be searched : ");
                            scanf("%d",&value);
                            sans = search(llist, value);
                            if(sans == -1)
                                printf("\nNo matching value");
                            else
                                printf("\nThe Entered value matches the value '%d' index",sans);
                            break;
                        case 15: len = length(llist);
                            printf("\nThe length of the linked list is %d",len);
                            break;
                        case 16: llistcopy = copy(llist);
                            break;
                        default: printf("\nEnter a valid option from the menu");
                    }
                }while(choice != 0);
                break;
            //Linked Stack
            case 2: do {
                    printf("\n\nLinked Stack Functions are : \n1. PushLS\t2. PopLS\t3. isEmptyLS\n4. DisplayLS\t5. TopValLS\n0. Exit\nYour choice : ");
                    scanf("%d",&choice);
                    switch(choice) {
                        case 1: printf("\nEnter the value to Push : ");
                            scanf("%d",&value);
                            lstack = insert_at_beg(lstack, value);
                            break;
                        case 2: lstack = delete_at_beg(lstack);
                            break;
                        case 3: if(lstack == NULL)
                                printf("\nThe Linked Stack is Empty");
                            else
                                printf("\nThe Linked Stack is not Empty");
                            break;
                        case 4: displayLS(lstack);
                            break;
                        case 5: value = topvalLS(lstack);
                            if(value == -1)
                                printf("\nThe Linked Stack is empty, TopVal not present");
                            else
                                printf("\nThe top value is %d",value);
                            break;
                        case 0: printf("\nExiting...");
                            break;
                        default: printf("\nEnter a valid option from the menu");
                    }
                }while(choice != 0);
                break;
            //Linked Queue
            case 3: do {
                    printf("\n\nLinked Queue functions are : \n1. InsertLQ\t2. DeleteLQ\t3. isEmptyLQ\n4. DisplayLQ\t5.FrontValueLQ\t6. RearValueLQ\n0. Exit\nYour choice : ");
                    scanf("%d",&choice);
                    switch(choice) {
                        case 1: printf("\nEnter the value you would like to insert : ");
                            scanf("%d",&value);
                            lqueue = insert_at_end(lqueue, value);
                            break;
                        case 2: lqueue = delete_at_beg(lqueue);
                            break;
                        case 3: if(lqueue == NULL)
                                printf("\nThe Linked Queue is empty");
                            else
                                printf("\nThe linked Queue is not empty");
                            break;
                        case 4: displayLQ(lqueue);
                            break;
                        case 5: value = frontvalLQ(lqueue);
                            if(value == -1)
                                printf("\nThe Linked Stack is empty, FrontVal not present");
                            else
                                printf("\nThe Front value is %d",value);
                            break;
                        case 6: value = rearvalLQ(lqueue);
                            if(value == -1)
                                printf("\nThe Linked Stack is empty, RearVal not present");
                            else
                                printf("\nThe Rear value is %d",value);
                            break;
                        case 0: printf("\nExiting...");
                            break;
                        default: printf("\nEnter a valid option from the menu");
                    }
                }while(choice != 0);
                break;
            default: printf("\nEnter a valid option from the menu");
                select = 0;
        }
        if(select != 0) {
			printf("\nWould you like to continue the program?\n0 -> Continue\t\tAnyOtherNumber -> Exit\nYour choice : ");
			scanf("%d",&select);
		}
    }while(select == 0);
    return 0;
}
//Function to Make a node
list makenode(list llist) {
    list temp;
    temp = (list) malloc(sizeof(nodell));
    if(temp == NULL)
        printf("\nMemory Underflow");
    return temp;
}
//Function to InsertAtBeg
list insert_at_beg(list llist, int value) {
    list temp;
    temp = makenode(NULL);
    if(temp == NULL)
        return llist;
    temp->data = value;
    temp->link = llist;
    return temp;
}
//Function to InsertAtEnd
list insert_at_end(list llist, int value) {
    list temp, ph = llist;
    temp = makenode(NULL);
    if(temp == NULL)
        return llist;
    temp->data = value;
    temp->link = NULL;
    if(llist == NULL)
        return temp;
    while(ph->link != NULL)
        ph = ph->link;
    ph->link = temp;
    return llist;
}
//Function to InsertAtPos
list insert_at_pos(list llist, int value, int len) {
    list temp, ph;
    int tndx=0, index;
    printf("\nEnter the index at which you would like to insert the element [0 - %d] : ",len);
    do {
        scanf("%d",&index);
        if(index < 0 || index > len)
            printf("Enter a valid value as stated above : ");
    }while(index < 0 || index > len);
    if(index == 0) {
        llist = insert_at_beg(llist, value);
        return llist;
    }
    temp = makenode(NULL);
    if(temp == NULL)
        return llist;
    temp->data = value;
    temp->link = NULL;
    if(llist == NULL)
        return temp;
    ph = llist;
    while(tndx < (index-1)) {
        tndx++;
        ph = ph->link;
    }
    temp->link = ph->link;
    ph->link = temp;
    return llist;
}
//Fuction to InsertOrdered
list insert_ordered(list llist, int value) {
    list temp, ph = llist;
    list sort(list );
    printf("\nTo insert in an ordered linked list, it will be sorted");
    llist = sort(llist);
    if(value < llist->data || llist == NULL) {
        llist = insert_at_beg(llist, value);
        return llist;
    }
    temp = makenode(NULL);
    temp->data = value;
    temp->link = NULL;
    while(temp->data > ph->link->data && ph->link != NULL)
        ph = ph->link;
    temp->link = ph->link;
    ph->link = temp;
    return llist;
}
//Function to DeleteAtBeg
list delete_at_beg(list llist) {
    if(llist == NULL) {
        printf("\nLinked list is Already Empty, Deletion not possible");
        return llist;
    }
    printf("\nDeleted : %d[%lu]", llist->data, (ULI) llist);
    llist = llist->link;
    return llist;
}
//Function to DeleteAtEnd
list delete_at_end(list llist) {
    list temp = llist, ptr;
    if(llist == NULL) {
        printf("\nLinked list is Already Empty, Deletion not possible");
        return llist;
    }
    if(llist->link == NULL) {
        printf("\nDeleted : %d[%lu]",llist->data ,llist);
        free(llist);
        return NULL;
    }
    while(temp->link->link != NULL)
        temp = temp->link;
    printf("\nDeleted : %d[%lu]",temp->link->data, (ULI) temp->link);
    free(temp->link);
    temp->link = NULL;
    return llist;
}
//Function to DeleteAtPos
list delete_at_pos(list llist, int len) {
    list ph = llist, ptr;
    int index, tndx=0;
    if(llist == NULL) {
        printf("\nLinked list is Already Empty, Deletion not possible");
        return llist;
    }
    printf("\nEnter the index at which you would like to delete the element [0 - %d] : ",len-1);
    do {
        scanf("%d",&index);
        if(index<0 || index > (len-1))
            printf("Enter a valid value as stated above : ");
    }while(index<0 || index > (len-1));
    if(index == 0) {
        printf("\nDeleted : %d[%lu]",ph->data, (ULI) ph);
        llist = llist->link;
        free(ph);
        return llist;
    }
    while(tndx < (index-1)) {
        tndx++;
        ph = ph->link;
    }
    ptr = ph->link;
    printf("\nDeleted : %d[%lu]",ph->link->data, (ULI) ph->link);
    ph->link = ptr->link;
    free(ptr);
    return llist;
}
//Function to DeleteOrdered
list deleteordered(list llist, int value) {
    list temp, ph = llist;
    list sort(list );
    if(llist == NULL) {
        printf("\nLinked list is Already Empty, Deletion not possible");
        return llist;
    }
    printf("\nTo delete in an ordered linked list, it will be sorted");
    llist = sort(llist);
    if(value < llist->data) {
        printf("\nNo element matches the entered value");
        return llist;
    }
    if(value == llist->data) {
        temp = llist;
        printf("\nDeleted : %d[%lu]",llist->data, (ULI) llist);
        llist = llist->link;
        free(temp);
    }
    while(ph->link->data < value) {
        ph = ph->link;
        if(ph->link == NULL) {
            printf("\nNo element matches the entered value");
            return llist;
        }
        if(ph->link->data == value) {
            temp = ph->link;
            printf("\nDeleted : %d[%lu]",ph->link->data, (ULI) ph->link);
            ph->link = temp->link;
            free(temp);
            return llist;
        }
    }
    printf("\nNo element matches the entered value");
    return llist;
}
//Function to Display
void display(list llist) {
    if(llist == NULL) {
        printf("\nThe Linked List is empty");
        return;
    }
    printf("\nThe contents of the linked list are : \n");
    while(llist != NULL) {
        printf("%d[%lu] --> ",llist->data, (ULI) llist);
        llist = llist->link;
    }
    printf("NULL");
    return;
}
//Function to Sort
list sort(list llist) {
    list iptr, jptr;
    int length(list );
    int temp, len;
    len = length(llist);
    if(len==0 || len==1) {
        printf("\nThe list is too small to be sorted");
        return llist;
    }
    for(iptr = llist; iptr->link != NULL; iptr = iptr->link) {
        for(jptr = iptr->link; jptr != NULL; jptr = jptr->link) {
            if(iptr->data > jptr->data) {
                temp = iptr->data;
                iptr->data = jptr->data;
                jptr->data = temp;
            }
        }
    }
    return llist;
}
//Function to Create
list create(list llist, int nodesno) {
    list temp;
    while(nodesno) {
        temp = makenode(llist);
        printf("\nEnter the data value : ");
        scanf("%d",&temp->data);
        temp -> link = NULL;
        if(llist == NULL)
            llist = temp;
        else {
            temp->link = llist;
            llist = temp;
        }
        nodesno--;
    }
    temp = llist;
    return llist;
}
//Function to Reverse
list reverse(list llist, int len) {
    list revf = llist, ph2, ph1;
    if(len == 0 || len == 1) {
        printf("\nThe list is too small to be reversed");
        return llist;
    }
    ph1 = llist->link;
    ph2 = ph1->link;
    revf->link = NULL;
    ph1->link = revf;
    while(ph2 != NULL) {
        revf = ph1;
        ph1 = ph2;
        ph2 = ph2->link;
        ph1->link = revf;
    }
    return ph1;
}
//Function to Search
int search(list llist, int value) {
    list ph = llist;
    int ndx = 0;
    while(ph != NULL) {
        if(value == ph->data)
            return ndx;
        else {
            ndx++;
            ph = ph->link;
        }
    }
    return -1;
}
//Function for Length
int length(list llist) {
    int len=0;
    while(llist!=NULL) {
        len++;
        llist = llist->link;
    }
    return len;
}
//Function to Copy
list copy(list llist1)  {
    list llistcopy = NULL, previous = NULL, temp;
    if(llist1 == NULL) {
        printf("\nThe linked list is empty, Copy failed");
        return NULL;
    }
    while(llist1!=NULL) {
        temp = (list) malloc (sizeof(nodell));
        temp->data = llist1->data;
        temp->link = NULL;
        if(llistcopy == NULL) {
            llistcopy = temp;
            previous = temp;
        }
        else {
            previous->link = temp;
            previous = temp;
        }
        llist1 = llist1->link;
    }
    printf("\nThe copied list is :\n");
    while(llistcopy != NULL) {
        printf("%d[%lu] --> ",llistcopy->data, (ULI) llistcopy);
        llistcopy = llistcopy->link;
    }
    printf("NULL");
    return llistcopy;
}
//Fuction to DisplayLinkedStack
void displayLS(list lstack) {
    if(lstack == NULL) {
        printf("\nThe Linked Stack is empty");
        return;
    }
    printf("\nThe contents of the Linked Stack are : \nTOP");
    while(lstack != NULL) {
        printf(" --> %d[%lu]",lstack->data, (ULI) lstack);
        lstack = lstack->link;
    }
    return;
}
//Function for topvalLS
int topvalLS(list lstack) {
    int ans;
    if(lstack == NULL)
        return -1;
    ans = lstack->data;
    return ans;
}
//Function to DisplayLinkedQueue
void displayLQ(list lqueue) {
    if(lqueue == NULL) {
        printf("\nThe Linked Queue is empty");
        return;
    }
    printf("\nThe contents of the Linked Queue are : \nFRONT --> ");
    while(lqueue != NULL) {
        printf("%d[%lu] --> ",lqueue->data, (ULI) lqueue);
        lqueue = lqueue->link;
    }
    printf("REAR");
    return;
}
//Function for FrontValLQ
int frontvalLQ(list lqueue) {
    int ans;
    if(lqueue == NULL)
        return -1;
    ans = lqueue->data;
    return ans;
}
//Function for RearValLQ
int rearvalLQ(list lqueue) {
    int ans;
    if(lqueue == NULL)
        return -1;
    while(lqueue->link != NULL)
        lqueue = lqueue->link;
    ans = lqueue->data;
    return ans;
}
/*
    OUTPUT
    
    
    Enter the data structure you would like to use : 
1. Linked List ADT	2. Linked Stack		3. Linked Queue
Your choice : 1


Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 1

Enter the value to be inserted : 1

Inserted : 1

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 1

Enter the value to be inserted : 2

Inserted : 2

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The contents of the linked list are : 
2[94155426904736] --> 1[94155426904704] --> NULL

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 3

Enter the value to be inserted : 2

Enter the index at which you would like to insert the element [0 - 2] : 1

Inserted : 2

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 2

Enter the value to be inserted : 45

Inserted : 45

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The contents of the linked list are : 
2[94155426904736] --> 2[94155426904768] --> 1[94155426904704] --> 45[94155426904800] --> NULL

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 4

Enter the value to be inserted : 3

To insert in an ordered linked list, it will be sorted
Inserted : 3

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The contents of the linked list are : 
1[94155426904736] --> 2[94155426904768] --> 2[94155426904704] --> 3[94155426904832] --> 45[94155426904800] --> NULL

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 5

Deleted : 1[94155426904736]

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 6

Deleted : 45[94155426904800]

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 7

Enter the index at which you would like to delete the element [0 - 2] : 0

Deleted : 2[94155426904768]

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The contents of the linked list are : 
2[94155426904704] --> 3[94155426904832] --> NULL

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 8

Enter the value to be deleted : 2

To delete in an ordered linked list, it will be sorted
Deleted : 2[94155426904704]
No element matches the entered value

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The contents of the linked list are : 
3[94155426904832] --> NULL

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 12

The Linked List has been Destroyed

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 9

The Linked List is empty

Linked list ADT Funtions are : 
1. InsertAtBeg	2. InsertAtEnd	3. InsertAtPos	4. InsertOrdered
5. DeleteAtBeg	6. DeleteAtEnd	7. DeleteAtPos	8. DeleteOrdered
9. Display	10.Sort		11.Create	12.Destroy
13.Reverse	14.Search	15.Length	16.Copy
0. Exit
Your choice : 0

Exiting...
Would you like to continue the program?
0 -> Continue		AnyOtherNumber -> Exit
Your choice : 0

Enter the data structure you would like to use : 
1. Linked List ADT	2. Linked Stack		3. Linked Queue
Your choice : 2


Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 1

Enter the value to Push : 1


Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 1

Enter the value to Push : 2


Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 1

Enter the value to Push : 3


Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 4

The contents of the Linked Stack are : 
TOP --> 3[94155426904800] --> 2[94155426904768] --> 1[94155426904704]

Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 2

Deleted : 3[94155426904800]

Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 5

The top value is 2

Linked Stack Functions are : 
1. PushLS	2. PopLS	3. isEmptyLS
4. DisplayLS	5. TopValLS
0. Exit
Your choice : 0

Exiting...
Would you like to continue the program?
0 -> Continue		AnyOtherNumber -> Exit
Your choice : 0

Enter the data structure you would like to use : 
1. Linked List ADT	2. Linked Stack		3. Linked Queue
Your choice : 3


Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 1

Enter the value you would like to insert : 1


Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 1

Enter the value you would like to insert : 2


Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 1

Enter the value you would like to insert : 3


Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 4

The contents of the Linked Queue are : 
FRONT --> 1[94155426904864] --> 2[94155426904896] --> 3[94155426904928] --> REAR

Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 5

The Front value is 1

Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 6

The Rear value is 3

Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 2

Deleted : 1[94155426904864]

Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 4

The contents of the Linked Queue are : 
FRONT --> 2[94155426904896] --> 3[94155426904928] --> REAR

Linked Queue functions are : 
1. InsertLQ	2. DeleteLQ	3. isEmptyLQ
4. DisplayLQ	5.FrontValueLQ	6. RearValueLQ
0. Exit
Your choice : 0

Exiting...
Would you like to continue the program?
0 -> Continue		AnyOtherNumber -> Exit
Your choice : 1





*/
