#include <stdio.h>
#include<stdlib.h>

struct BinaryTree{
    int data;
    struct BinaryTree *left , *right;
};
struct BinaryTree *Creat_A_Node(int val){
    struct BinaryTree *temp = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
    
}
struct BinaryTree *Insert(int val ,struct BinaryTree *root){
    //Base case 
    if(root==NULL){
        return Creat_A_Node(val);
    
    }
    //1.if root->data > val go to left
    if(val < root->data){
        root->left = Insert(val,root->left);
    }
    //2.if root-> data < val go to right;
    else if(val > root->data){
        root->right = Insert(val,root->right);
    }
    return root;
    
}
struct BinaryTree* Search(struct BinaryTree *root, target){
    if(root==NULL || root->data == target){
        return root;
    }
    if(target < root->data){
        //go to left 
        return Search(root->left,target);
    }
    else{
        return Search(root->right,target);
    }
}
void Inorder(struct BinaryTree *root){
    if(root==NULL)return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
int main() {
	//BST -> BT
	//Online 
	int n;
	scanf("%d",&n);
	struct BinaryTree *root = NULL;
	int val;
	scanf("%d",&val);
	root = Insert(val,root);
	for(int i = 1 ; i < n ; i++){
	   
	    
	    scanf("%d",&val);
	    //printf("%d ",val);
	    Insert(val,root);
	    
	}
	//printf("%d ",root->data);
	Inorder(root);

}

