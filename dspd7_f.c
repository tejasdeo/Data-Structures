/*
	Practical no. 7
	Filename	: dspd7_f.c
	Author		: TEJAS DEO
	Date 		: 13/09/2018
	Aim			: To study a tree data structure and demonstrate different 
				  traversals on it Inorder, Pre Order, and Post– Order.

	Problem		: Create a self-referential structure, TreeNode to represent a 
				  node of a binary tree. Implement the routines to – (1) create
				  a tree node, (2) create a rooted binary tree from a list 
				  [an array] representing DATA content of the nodes of the 
				  intended binary tree, (3) perform inorder walk of the tree, 
				  (4) perform preorder walk of the tree, (5) perform postorder 
				  walk of the tree, (6) find height of the tree [assume ROOT at
				  height 0], (7) count and print all parent [internal] nodes in 
				  the tree, and (8) to locate a KEY in the tree.
				  Create a menu-driven program to test these routines.
*/
//Libraries included
#include<stdio.h>
#include<stdlib.h>
#include"treeadt.h"
#define max1 5
#define NDT -1
#define MXVAL 99

int length_list(int *);
int get_left_child(int *,int len,int ndx);
int get_right_child(int *,int len,int ndx);
tree build_bin_tree(int *,int len,int ndx);
int parents_bt(tree root);
int all_nodes_bt(tree root);
int leaves_bt(tree root);
int empty_bt(tree root);


int main()
{
	tree root=NULL;
	int len,ndx=0,height1,parent,count,leave,empty,choice;
	//int list[9]={70,60,30,50,NDT,40,10,NDT,MXVAL};
	int list[MXVAL];
	printf("\nEnter the elements  to create a list:\n ");
	scanf("%d",&list[ndx]);
	while(list[ndx]!=MXVAL)
	{
		ndx++;
		printf("\nEnter the elements:\n ");
		scanf("%d",&list[ndx]);
	}
		len=length_list(list);
	printf("\nLENGTH=%d",len);
	root=build_bin_tree(list,len,0);
	
		do{
		printf("\nenter the choice to be selected:");
		printf("\n1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT");
		printf("\n5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT");
		printf("\n0.EXIT");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("inorder..");
				inorder(root);
				printf("\n");
				break;
			case 2:
				printf("postorder..");
				postorder(root);
				printf("\n");
				break;
			case 3:
				printf("preorder..");
				preorder(root);
				printf("\n");
				break;
			case 4:
				printf("height..");
				height1=height(root);
				printf("\nHEIGHT=%d",height1);
				printf("\n");
				break;
			case 5:
				printf("parents_bt");
				parent=parents_bt(root);
				printf("\nparent=%d",parent);
				printf("\n");
				break;
			case 6:
				printf("all_nodes_bt..");
				count=all_nodes_bt(root);
				printf("\nCOUNT=%d",count);
				printf("\n");
				break;
			case 7:
				printf("leaves_bt..");
				leave=leaves_bt(root);
				printf("\nLEAVES_BT=%d",leave);
				printf("\n");
				break;
			case 8:
				
				empty_bt(root);
				printf("\n");
				break;
			
			case 0:
				break;
	
			}
		}while(choice!=0);
return 0;
}


int length_list(int list[])
{
	int ndx=0;
	while(list[ndx]!=MXVAL)
	{
		ndx++;
	}
	return ndx-1;
}


int get_left_child(int list[],int len,int ndx)
{
	if((2*ndx+1)>len)
	return len;

	return 2*ndx+1;
}


int get_right_child(int list[],int len,int ndx)
{
	if((2*ndx+2) >len)
	return len;

	return 2*ndx+2;
}


tree build_bin_tree(int list[],int len,int ndx)
{
	tree temp=NULL;
	if(list[ndx]!=NDT)
	{
		temp=(tree)malloc(sizeof(tnode));
		temp->lchild=build_bin_tree(list,len,get_left_child(list,len,ndx));
		temp->data=list[ndx];
		temp->rchild=build_bin_tree(list,len,get_right_child(list,len,ndx));
	}	
	return temp;
}


int parents_bt(tree root)
{
	if(root==NULL || ((root->lchild==NULL) && (root->rchild==NULL)))
	return 0;
	
	printf("\n%d",root->data);

	return (parents_bt(root->lchild)+parents_bt(root->rchild)+1);
}


int all_nodes_bt(tree root)
{
int count;
	if(root==NULL)
	return 0;
	
	count=1;
	printf("\n%d",root->data);

	count=(count+all_nodes_bt(root->lchild)+all_nodes_bt(root->rchild));

	return count;
}


int leaves_bt(tree root)
{
	if(root==NULL)
	return 0;

	if(root->lchild==NULL && root->rchild==NULL)
	{
	printf("\n%d",root->data);
	return 1;
	}

	return (leaves_bt(root->lchild)+leaves_bt(root->rchild));	
}



int empty_bt(tree root)
{
	if(root!=NULL){
	empty_bt(root->lchild);
	empty_bt(root->rchild);

	printf("\n released node with key=%d",root->data);
} 
}


/*
OUTPUTS

Enter the elements  to create a list:
 2

Enter the elements:
 3

Enter the elements:
 4

Enter the elements:
 -1

Enter the elements:
 1

Enter the elements:
 6

Enter the elements:
 -1

Enter the elements:
 -1

Enter the elements:
 99

LENGTH=7
enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT1
inorder.. 3  1  2  6  4 

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT2
postorder.. 1 3 6 4 2

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT3
preorder..2 3 1 4 6 

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT4
height..
HEIGHT=2

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT5
parents_bt
2
3
4
parent=3

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT6
all_nodes_bt..
2
3
1
4
6
COUNT=5

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT7
leaves_bt..
1
6
LEAVES_BT=2

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT8

 released node with key=1
 released node with key=3
 released node with key=6
 released node with key=4
 released node with key=2

enter the choice to be selected:
1.INORDER      2.POSTORDER      3.PREORDER     4.HEIGHT
5.PARENTS_BT   6.ALL_NODES_BT   7.LEAVES_BT    8.EMPTY_BT
0.EXIT0

*/
