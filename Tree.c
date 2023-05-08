#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    
};
struct Node *Creat_A_node(int val){
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
void Inorder(struct Node *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
int main(){
    struct Node *root = Creat_A_node(10);
    struct Node *f1 = Creat_A_node(20);
    struct Node *s1 = Creat_A_node(30);
    struct Node *lf2 = Creat_A_node(40);
    struct Node *ls2 = Creat_A_node(50);
    struct Node *rf2 = Creat_A_node(60);
    struct Node *rs2 = Creat_A_node(70);
    root->left = f1;
    root->right =s1;
    f1->left = lf2;
    f1->right = ls2;
    s1->left = rf2;
    s1->right =rs2;
    Inorder(root);
    
}
