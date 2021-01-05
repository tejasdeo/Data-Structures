#include<stdlib.h>
#include<stdio.h>
struct treenode{
    int data;
    struct treenode *lchild;
    struct treenode *rchild;
};
typedef struct treenode tnode;
typedef tnode * tree;
void inOrderT(tree root);
int heigth(tree root);
void postorder(tree root);
void preorder(tree root);
tree createNode(int key);
int parents(tree root);
int leaves(tree root);
int search(tree root,int key);
void inOrderT(tree root){
        if(root != NULL) {
        inOrderT(root->lchild);
        printf("%d\t", root->data);
        inOrderT(root->rchild);
        }
}
int heigth(tree root)
{
    int lht,rht;
    if(root==NULL)
        return -1;
    if(root->lchild==NULL && root->rchild==NULL)
        return 0;
    lht=heigth(root->lchild);        
    rht=heigth(root->rchild);
    if(lht>rht)
        return lht+1;
    if(rht>=lht)
        return rht+1;
}
void postorder(tree root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
        }
        return;                
}

void preorder(tree root)
{
    if(root!=NULL)
    {
    printf("%d\t",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    }
    return ;
}
tree createNode(int key){
        tree neww;
        neww = (tree) malloc(sizeof(tnode));
        /*Assume that treeNode is ALWAYS returned.. */
        neww->data = key;
        neww->lchild = NULL;
        neww->rchild = NULL;
        return neww; 
}   
int parents(tree root){
    if(root==NULL||(root->lchild==NULL && root->rchild==NULL))return 0;
    printf("\n%d",root->data);
    return (parents(root->lchild)+parents(root->rchild)+1);
    }          
    
int leaves(tree root){
     if(root==NULL)return 0;
     if(root->lchild==NULL && root->rchild==NULL){
        printf("\n%d\n",root->data);
        return 1;
        }
     return (leaves(root->lchild) + leaves(root->rchild));
    }   
int search(tree root,int key)
{
 int n=0;
if(root!=NULL)
{
search(root->lchild,key);
search(root->rchild,key);
if(root->data==key)
{
printf("%d::key is present at [%lu]\n",root->data,root);
n++;
}
return n;
}
}	 
