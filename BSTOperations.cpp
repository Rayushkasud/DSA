/* RAYUSHKA SUD CSE 3 2193191
   Assignment 2 
   Binary Search Tree Oprations  */


#include <iostream>
#include<queue>
using namespace std;


class BSTNode{
    public:
int data;
BSTNode* parent;
BSTNode* left;
BSTNode* right;
public:
BSTNode(int newdata=int(),BSTNode* newparent = nullptr, BSTNode* newleft = nullptr, BSTNode* newright = nullptr):
data(newdata),parent(newparent),left(newleft),right(newright) {}

};


class BST{
    BSTNode* root;
    public:
    BST(){
        root=nullptr;
    }
    public:
    BSTNode* insert(int);
    void display(BSTNode*);
    BSTNode* Delete(BSTNode* ,int);
    BSTNode* search(BSTNode*,int);
    void BFSTraversal(BSTNode*);
    int heightOfBTree(BSTNode*);
    void BSTMirror(BSTNode*);
    friend class BSTNode;
   
    
   
};

BSTNode* BST::insert(int key){
    if(root==nullptr)
{
    root= new BSTNode(key);
    return root;
}
else{
BSTNode* temp=root;
BSTNode* previous=root;
while(temp !=nullptr){
    previous=temp;
    if(key<temp->data){
        temp=temp->left;
    }
    else 
    temp=temp->right;
} //end of while
if(previous->data>key){
    previous->left= new BSTNode(key,previous);
    return root;
}
    else if(previous->data<key){
        previous->right= new BSTNode(key,previous);
        return root;
    }
    
}
}

BSTNode* BST:: Delete(BSTNode* root,int del){
    // BSTNode *delNode, *temp=new BSTNode;
    // delNode=search(root,del);
    // temp=delNode;
    BSTNode *parent,*delNode,*temp;
    parent=search(root,del);
    if(parent==nullptr) temp=root;
    else if(parent->right->data==del)delNode=parent->right;
    else if(parent->left->data == del) delNode=parent->left;
    temp=delNode;
    
    // while(root->data != delNode->data){
    //     parent=root;
    //     if(delNode->data>root->data){
    //         root=root->right;
    //     }
    //     else
    //     root=root->left;
   // }
    if(temp->left ==nullptr && temp->right==nullptr){
        if(parent==nullptr){
        root=nullptr;
        return root;
    }
    else if(parent->left==temp)
    {
        parent->left=nullptr;
        free(delNode);
        return root;
    }
    else if(parent->right==temp){
        parent->right= nullptr;
        free(delNode);
        return root;
    }
    }
    else if(temp->right == nullptr && temp->left !=nullptr){    //does not have right child
            if(parent->left==temp){
               parent->left=temp->left;
               free(delNode);
               return root;
            }
            else if(parent->right==temp){
                parent->right=temp->left;
                free(delNode);
                return root;
                  }
        }

    else if(temp->left == nullptr && parent->right != nullptr){ 
            if(parent->left==temp){ //node to del is left child of its parent
                parent->left=temp->right;
                free(delNode);
                return root;
            }
            else if(parent->right==temp) {//node to del is right child of it parent
                   parent->right=temp->right;
                   free(delNode);
                   return root;
            }                           
    }
    else{
        BSTNode *minOfRight=temp->right;
        while(minOfRight->left != nullptr){
            minOfRight=minOfRight->left;
        }
        temp->data=minOfRight->data;
        temp->right=minOfRight->right;
        if(temp==root){
            free(minOfRight);
            return temp;
        }
        else
        return root;
        }
}
    

void BST::display(BSTNode* root){
    BSTNode* temp =root;
    if(temp == nullptr) return; 
    display(temp->left);
    cout<<temp->data<<", ";
    display(temp->right);
    
}
void BST::BFSTraversal(BSTNode* root){
    queue<BSTNode*>q;
    BSTNode* temp=root;
    q.push(root);
    while(!q.empty()){
    temp=q.front();
    cout<<temp->data<<" ";
    q.pop();
    if(temp->left != nullptr){
        q.push(temp->left);
    }
    if(temp->right != nullptr){
        q.push(temp->right);
    }
    }
}

int BST::heightOfBTree(BSTNode* root){
    BSTNode* node=root;
    int l,r;
    if(node==nullptr){
        return -1;
    }
    else{
       l=heightOfBTree(node->left);
       r=heightOfBTree(node->right);
       return max(l,r)+1;
    }
}

void BST::BSTMirror(BSTNode* root){
    BSTNode* node;
    if(root==nullptr){
        return;
    }
    else{
        BSTMirror(root->left);
        BSTMirror(root->right);
        node=root->left;
        root->left=root->right;
        root->right=node;
    }
}
BSTNode* BST::search(BSTNode* root,int searchNode){
    BSTNode *temp1,*prev=new BSTNode;
    temp1=root;
    prev=nullptr;
    while(temp1->data != searchNode){
        prev=temp1;
        if(searchNode>temp1->data){
            temp1=temp1->right;
        }
        else 
        temp1=temp1->left;
    }
    if(temp1->data==searchNode){
    cout<<"Node found"<<"\n";
    return prev;
    }  
    else {
        cout<<"Node not found"<<"\n";
        return root;
    }
}
int main(){
    BST bst;
    BSTNode *root;
    root=bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(15);
    bst.insert(2);
    bst.insert(40);
    bst.insert(39);
    cout<<"DICIONARY:"<<"\n";
    cout<<"Root "<<root->data<<"\n";
    bst.display(root);
    //dict.search(root,2);
    root=bst.Delete(root,40);
    cout<<"Displaying post deletion"<<"\n";
    bst.display(root);
    cout<<"\n"<<"BFS TRaversal of tree:"<<"\n";
    bst.BFSTraversal(root);
    int result=bst.heightOfBTree(root);
    cout<<"\n"<<"Height of tree is: "<<result<<"\n";
    bst.BSTMirror(root);
    cout<<"\n"<<"BST Mirror:"<<"\n";
    bst.display(root);
    // dict.Delete(root,10);
    // dict.display(root);

}