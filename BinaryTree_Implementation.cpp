#include<bits/stdc++.h>
using namespace std;

//tree is consistes of node -> [left pointer, val , right pointer]
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
    
};
class Tree{
    private:
    Node *root;
    void InorderHelp(Node *node){
        if(node==NULL)return;
        InorderHelp(node->left);
        cout << node->data<<" ";
        InorderHelp(node->right);
    }
    void PostOrderHelp(Node *node){
        //left,right ,root 
        if(nood==NULL)return;
        PostOrderHelp(node->left);
        PostOrderHelp(node->right);
        cout << node->data<<" ";
    }
    
    void PreOrderHelp(Node *node){
        //root,left,right
        if(node==NULL)return;
        cout << node->data<<" "; // root 
        PreOrderHelp(node->left); // left 
        PreOrderHelp(node->right);//right
    }
    public:
    Tree(){
        root = NULL;
    }
    void BuildTree(string str){
        if(str.size()==0 || str[0]=='N')return nullptr;
        vector<string>info;
        stringstream ss(str);
        string word;
        while(ss >> word){
            info.push_back(word);
        }
        int val = stoi(info[0]);
        root = new Node(val);
        queue<Node*>Q;
        Q.push(root);
        int i = 1;
        while(!Q.empty() && i < info.size()){
            Node *curr = Q.front();
            Q.pop();
            if(info[i]!="N"){
                val = stoi(info[i]);
                Node *nn = new Node(val);
                curr->left = nn;
                Q.push(nn);
            }
            i++;
            if(info[i]!="N"){
                val = stoi(info[i]);
                Node *nn = new Node(val);
                curr->right = nn;
                Q.push(nn);
            }
            i++;
        }
        return root;
    }
    void Inorder(){
       InorderHelp(root);
    }
    void PostOrder(){
        PostOrderHelp(root);
    }
    void PreOrder(){
        PreOrderHelp(root);
    }
    void BFS(){
        queue<Node*>Q; // 2
        Q.push(root); // 2
        int height = 0;
        while(!Q.empty()){ //
            int len = Q.size(); // 2 
            height++;
            for(int i = 0 ; i < len ; i++){ // 2 time 
               
                Node *curr = Q.front(); // 2
                Q.pop(); // 2 
                cout << curr->data<<" "; // 2
                if(curr->left){ // 2->left
                    Q.push(curr->left); //
                }
                if(curr->right){ // 2->right
                    Q.push(curr->right);
                }
            }
        }
    }
    
    
};
int main(){
    Tree t1;
    string str;
    getline(cin,str); // "10 20 30 "
    t1.BuildTree(str);
    t1.Inorder();
    t1.PostOrder();
    t1.PreOrder();
    t1.BFS();
}

















