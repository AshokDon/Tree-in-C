#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* CreatANode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;  
    return newNode;
}
struct Node *CreatATree(int *arr, int i, int n){
    
    if(i<n){
        struct Node *temp = CreatANode(arr[i]);
        if(arr[2*i+1]!=-1)temp->left = CreatATree(arr, 2*i+1, n);
        if(arr[2*i+2]!=-1) temp->right = CreatATree(arr, 2*i+2, n);
        return temp;

    }
    return NULL;

}
void InOrder(struct Node *root){
    if(root){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
int main(){
    //take an array and creat it into tree
    //-1 is NULL
    int arr[] = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    struct Node *root = CreatATree(arr, 0 , 15);
    InOrder(root);
    return 0;

}
