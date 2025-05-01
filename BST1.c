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
struct BinaryTree *FindMin(struct BinaryTree *root){
    if(root->left == NULL){
        return root;
    }
    return FindMin(root->left);
}
struct BinaryTree* Delete(struct BinaryTree *root, int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = Delete(root->left, val);
    }
    else if(val > root->data){
        root->right = Delete(root->right,val);
    }
    else{
        //3 conditions 
        //1) no childrens 
        if(root->left == NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //one child
        else if(root->left == NULL or root->right == NULL){
            struct BinaryTree *temp;
            if(root->right == NULL){
                temp = root->left;
            }
            else{
                temp = root->right;
            }
            free(root);
            return temp;
        }
        //has 2 childs 
        else{
            struct BinaryTree *temp = FindMin(root->right);
            root->val = temp->val;
            root->right = Delete(root->right,temp->val);
            
        }
    }
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
	    Insert(val,root);
	    
	}
	//printf("%d ",root->data);
	Inorder(root);
	scanf("%d",&val);
	Delete(root,val);

}









