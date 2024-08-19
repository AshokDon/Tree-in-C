//binary search tree 
#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

};
struct TreeNode* CreatATreeNode(int key){
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
}
//when the array is in sorted order
struct TreeNode* BSTinsert(int low , int high, int nodes[]){
    if(low > high)return NULL; // if low and high cross each other no data to insert so return null
    if(low == high){ // leaf node
        return CreatAnode(nodes[low]);
    }
    //find the mid and this mid is your root
    int mid = (low + high)/2; // 
    struct TreeNode *root = CreatAnode(nodes[mid]);
    root->left = BSTinsert(low, mid-1,nodes);
    root->right = BSTinsert(mid+1,high,nodes);
    return root;
}

//when the array is not in sorted order
struct TreeNode* insert(struct TreeNode *root, int key){
    if(root == NULL){
        return CreatATreeNode(key);
    }
    if(root->data > key){
        root->left = insert(root->left,key);
    }
    if(root->data < key){
        root->right = insert(root->right,key);
    }
    return root;
}
struct TreeNode *sucess(struct TreeNode *root){
    struct TreeNode *curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}

struct TreeNode *Delete(struct TreeNode *root,int key){
    if(root==NULL)return NULL;
    if(root->data > key){
        root->left = Delete(root->left,key);
    }
    else if(root->data < key){
        root->right = Delete(root->right,key);
    }
    else{
        //no child or one child

        if(root->left==NULL){
            struct TreeNode *node = root->right;
            free(root);
            return node;
        }
        else if(root->right==NULL){
            struct TreeNode *node = root->left;
            free(root);
            return node;
        }

        //two
        struct TreeNode *node = sucess(root->right);
        root->data = node->data;
        root->right = Delete(root->right,node->data);
    }
    return root;
}
int main(){
    struct TreeNode *root = NULL;
    root = insert(root,9);

}
