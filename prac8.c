/*
	Practical no: 8
	Filename	: prac8.c
	Author		: Vaishnavi Mandhana
	Date 		: 21/09/2018
	Aim			: To study study binary search tree (BST) and implement various 
				  operations on a BST.

	Problem		: Create a header file, “ treeADT.h " to include the self-
				  referential structure, TreeNode cretaed in Experiment-7 and 
				  the routines to (1) traversal the tree (pre-, post-, and in-
				  order), (2) find the height of a tree, (3) to count and list 
				  all leaf nodes and parent nodes. Using “ treeADT.h” , 
				  implement the routines for a binary search tree [BST] to – 
				  (1) insert a node, (2) delete a node with specified key value,
				  (3) traverse the tree in level-order, and (4) create binary 
				  tree at once using insertNode().
*/
//Libraries included
#include<stdio.h>
#include<stdlib.h>
#include"treeadt1.h"
#define mxval 999
typedef tree bst;
bst create(bst);
bst insert_BST(bst root,int key);
void display(bst root);
bst deleteBST(bst root,int key);
bst FindminNode(bst root);
int main()
{
	bst root,rootx;
    int choice,key;
    do
    {
        printf("\nEnter choice from below you want to perform:-\n");
        printf("\n1.Create\t2.Insert\t3.Display\t4.Delete\t5.Heigth\n");
        printf("6.FindminNode\t7.Parents\t8.Leaves\t9.Search\t0.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:root=create(root);
                    break;
            case 2:printf("\nEnter the value you want o insert\n");
                    scanf("%d",&key);
                    root=insert_BST(root,key);  
                    break;
            case 3:display(root);
					break;  
			case 4:	printf("\nEnter the value you want to delete\n");
					scanf("%d",&key);
					root=deleteBST(root,key);
					break;
			case 5://key=heigth(root);
					printf("\nHeight of BST is:%d",heigth(root));
					break;		
			case 6: rootx=FindminNode(root);
					printf("%d",rootx->data);
					break;
			case 7: key=parents(root);
					printf("\nNumber of parents=%d\n",key);
					break;
			case 8:key=leaves(root);
					printf("\nNumber of leaves=%d\n",key);
					break;
			case 9:printf("\nEnter the value you want to search\n");
					scanf("%d",&key);
					key=search(root,key);
					 
					break;
			case 0:printf("Program Terminated!\n!");	
					break;									            
        }
     }while(choice!=0);
                 
}

bst create(bst root)
{
    int key=1;
    root=NULL;
    printf("\nEnter the value of key :-\n");
        scanf("%d",&key);
    while(key!=mxval)
    {
          
        //if(key!=NDT)
            root=insert_BST(root,key);
        printf("\nEnter the value of key :-\n");
        scanf("%d",&key);
     } 
     return root;
}      
bst insert_BST(bst root,int key)
{
    if(root==NULL)
    {
        root=createNode(key);
        if(root==NULL)
            printf("\nunderflow,insert fail");
        else
        {
            root->data=key;
            root->lchild=root->rchild=NULL;
        }
      return root;
      }
      else if(key<=(root->data))
        root->lchild=insert_BST(root->lchild,key);
      else if(key > (root->data))
        root->rchild=insert_BST(root->rchild,key);
      else
        printf("\nDUplicate key\n");
     return root;
} 
bst FindminNode(bst root)
{
    if(root==NULL)
        return NULL;
    if(root->lchild==NULL)
        return root;
    return FindminNode(root->lchild); 
}

bst deleteBST(bst root,int key)
{
	bst temp;
    if(root==NULL)
    {
        printf("\nEmpty tree\n");
        return NULL;
    }
    if(key< root->data)
    {
    	root->lchild=deleteBST(root->lchild,key);
	}
	else if(key> root->data)
		root->rchild=deleteBST(root->rchild,key);
	else
	{
		if(root->lchild!=NULL && root->rchild!=NULL)
		{
			temp=FindminNode(root->rchild);
			root->data=temp->data;
			root->rchild=deleteBST(root->rchild,root->data);	
		}
		else
		{
			temp=root;
			if(root->lchild==NULL)
				root=root->rchild;
			else if(root->rchild==NULL)
				root=root->lchild;
			free(temp);		
		}
		return root;
	}
}
void display(bst root)
{
	int key;
	do
	{
		printf("\nEnter the type of print you want to do\n ");
		printf("\n1.Postorder\t2.Preorder\t3.Inorder\t0.Back\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1:postorder(root);
					break;
			case 2:preorder(root);
					break;
			case 3:inOrderT(root);
					break;	
			case 0:break;	
		}
	}while(key!=0);
}                        
              
/*

OUTPUTS

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
1

Enter the value of key :-
50

Enter the value of key :-
40

Enter the value of key :-
60

Enter the value of key :-
30

Enter the value of key :-
45

Enter the value of key :-
55

Enter the value of key :-
70

Enter the value of key :-
999

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
3

Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
1
30	45	40	55	70	60	50	
Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
2
50	40	30	45	60	55	70	
Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
3
30	40	45	50	55	60	70	
Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
5

Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
6

Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
0

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
6
30
Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
7

50
40
60
Number of parents=3

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
8

30

45

55

70

Number of leaves=4

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
9

Enter the value you want to search
30
30::key is present at [94254498773728]

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
4

Enter the value you want to delete
40

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
3

Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
1
30	45	55	70	60	50	
Enter the type of print you want to do
 
1.Postorder	2.Preorder	3.Inorder	0.Back
0

Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
5

Height of BST is:2
Enter choice from below you want to perform:-

1.Create	2.Insert	3.Display	4.Delete	5.Heigth
6.FindminNode	7.Parents	8.Leaves	9.Search	0.Exit
0
Program Terminated!

*/                  
