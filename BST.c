#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node* left;
   struct Node* right;
}BST;
struct Node* newNodeCreate(int value)
{
    struct Node* temp;
    temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
 
struct Node* insert(struct Node* root,int value){
     if (root==NULL) {
        return newNodeCreate(value);
    }
    if (value<root->data) {
        root->left= insert(root->left, value);
    }
    else if (value >root->data) {
        root->right=insert(root->right, value);
    }
    return root;
}
void ino(struct Node* root){
    if(root==NULL){
      return;
   }
   ino(root->left);
   printf("%d",root->data);
   ino(root->right);
}

int main(){
    int a;
    struct Node* root;
    scanf("%d",&a);
   for(int i=0;i<8;i++)
    {
    printf("Enter an element to insert in bst: ");
    insert(root,i);
    }
    ino(root);
}