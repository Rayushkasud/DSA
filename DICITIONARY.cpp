/* RAYUSHKA SUD CSE # 2193191
   Assignment 1
   Dictionary */
#include <iostream>
using namespace std;

template<class T>
class BSTNode{
    public:
T data;
T value;
BSTNode<T>* parent;
BSTNode<T>* left;
BSTNode<T>* right;
public:
BSTNode(T newdata=T(),T newvalue=T(),BSTNode<T>* newparent = nullptr, BSTNode<T>* newleft = nullptr, BSTNode<T>* newright = nullptr):
data(newdata),value(newvalue),parent(newparent),left(newleft),right(newright) {}

};

template<class T>
class Dict{
    BSTNode<T>* root;
    public:
    Dict(){
        root=nullptr;
    }
    public:
    BSTNode<T>* insert(T,T);
    void Inorderdisplay(BSTNode<T>*);
    BSTNode<T>* Delete(BSTNode<T>* ,T);
    BSTNode<T>* search(BSTNode<T>*,T);
    void DescendingOrderDisplay(BSTNode<T>*);
    BSTNode<T>* UpdateDict(BSTNode<T>*, T,T);
    friend class BSTNode<T>;
   
    
   
};

template<class T>
BSTNode<T>* Dict<T>::insert(T key,T value){
    if(root==nullptr)
{
    root= new BSTNode<T>(key,value);
    return root;
}
else{
BSTNode<T>* temp=root;
BSTNode<T>* previous=root;
while(temp !=nullptr)
{
    previous=temp;
    if(key<temp->data){
        temp=temp->left;
    }
    else 
    temp=temp->right;
} //end of while
if(previous->data>key){
    previous->left= new BSTNode<T>(key,value,previous);
    return root;
}
    else if(previous->data<key){
        previous->right= new BSTNode<T>(key,value,previous);
        return root;
    }
    
}
}

template<class T>
BSTNode<T>* Dict<T>:: Delete(BSTNode<T>* root,T del){
    BSTNode<T> *delNode, *temp = new BSTNode<T>;
    // delNode=search(root,del);
    // temp=delNode;
    BSTNode<T> *parent;//,*delNode,*temp;
    // delNode=search(root,del);
    // temp=delNode;
    temp=root;
    //delNode->data=del;
    while(temp!=nullptr && temp->data!=del){
        parent=temp;
        if(del>temp->data){
            temp=temp->right;
        }
        else
        temp=temp->left;
   }
   cout<<"\n"<<temp->data;
   delNode=temp;
    if(temp->left ==nullptr && temp->right==nullptr){
        if(delNode==root){
        root=nullptr;
        return root;
    }
    else if(parent->left==temp)
    {
        parent->left=nullptr;
        free(temp);
        return root;
    }
    else if(parent->right==temp){
        parent->right= nullptr;
        free(temp);
        return root;
    }
    
    }
    else if(temp->right == nullptr && temp->left !=nullptr){    //does not have right child
            if(parent==nullptr){
                root=temp->left;
                return root;
            }
            
            else if(parent->left==temp){
               parent->left=temp->left;
               free(temp);
               return root;
            }
            else if(parent->right==temp){
                parent->right=temp->left;
                free(temp);
                return root;
                  }
        }

    else if(temp->left == nullptr && temp->right != nullptr){ 
         if(parent==nullptr){
                root=temp->right;
                return root;
            }
           else  if(parent->left==temp){ //node to del is left child of its parent
                parent->left=temp->right;
                free(temp);
                return root;
            }
            else if(parent->right==temp) {//node to del is right child of it parent
                   parent->right=temp->right;
                   free(temp);
                   return root;
            }                           
    }
    else{
        BSTNode<T> *minOfRight=temp->right;
        BSTNode<T> *Parent=nullptr;
        while(minOfRight->left != nullptr){
            Parent=minOfRight;
            minOfRight=minOfRight->left;
        }
        temp->data=minOfRight->data;
        temp->value=minOfRight->value;
        if(Parent==nullptr)
        {
            Parent=temp;
            Parent->right=nullptr;
            
        }
        else Parent->left=nullptr;
        //temp->right=minOfRight->right;
        if(temp==root){
            delete(minOfRight);
            return temp;
        }
        return root;
        }
}

template<class T>
BSTNode<T>* Dict<T>::UpdateDict(BSTNode<T>* root,T entryToBeUpdated, T updatedVal){
    BSTNode<T>* temporaryNode;
    temporaryNode=search(root,entryToBeUpdated);
    if(temporaryNode==nullptr) 
    {
        temporaryNode=root;
        temporaryNode->value=updatedVal;
        return temporaryNode;
    }
    else if(temporaryNode->right->data == entryToBeUpdated)
    {
         temporaryNode=temporaryNode->right;
         temporaryNode->value=updatedVal;
         return root;
    }
    else if(temporaryNode->left->data == entryToBeUpdated){
        temporaryNode=temporaryNode->left;
        temporaryNode->value=updatedVal;
        return root;
    }
    

} 
template<class T>
void Dict<T>::Inorderdisplay(BSTNode<T>* root){
    BSTNode<T>* temp =root;
    if(temp == nullptr) return; 
    Inorderdisplay(temp->left);
    cout<<temp->data<<" : "<<temp->value<<"\n";
    Inorderdisplay(temp->right);
    
}

template<class T>
void Dict<T>::DescendingOrderDisplay(BSTNode<T>* root){
    BSTNode<T>* node=root;
    if(node==nullptr) return;
    DescendingOrderDisplay(node->right);
    cout<<node->data<<" : "<<node->value<<"\n";
    DescendingOrderDisplay(node->left);

}
template<class T>
BSTNode<T>* Dict<T>::search(BSTNode<T>* root,T searchNode){
    BSTNode<T> *temp1,*prev=new BSTNode<T>;
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
    
    Dict<string> dict;
    BSTNode<string> *root;
    int choice;
    cout<<"Enter key Value pair in Dictionary: "<<"\n";
    int ch=1;
    while(ch){
        string key, value;
        cin>>key>>value;
        root=dict.insert(key,value);
        cout<<"Would you like to continue? (0/1)"<<"\n";
        cin>>ch;
    
    }
    do{
    
    cout<<"Enter 1 to delete key Value pair from Dictionary: "<<"\n";
    cout<<"Enter 2 to display inorder traversal(ascending order) of key Value pairs in Dictionary: "<<"\n";
    cout<<"Enter 3 to display key Value pairs of Dictionary in descending Order: "<<"\n";
    cout<<"Enter 4 to update key Value pairs of Dictionary : "<<"\n";
    cout<<"Enter choice"<<"\n";
    cin>>choice;
    switch(choice){
        case 1:{
        string del;
        cout<<"Enter key to delete"<<"\n";
        cin>>del;
        root=dict.Delete(root,del);
        break;
        }

        case 2:{
        dict.Inorderdisplay(root);
        break;
        }

        case 3:{
        dict.DescendingOrderDisplay(root);
        break;
        }

        case 4:{
        string updateKey,updateVal;
        cout<<"Enter key to update and its updated value"<<"\n";
        cin>>updateKey>>updateVal;
        root=dict.UpdateDict(root,updateKey,updateVal);
        break;}

        default:{
        cout<<"Invalid input";
        break;
        }
    }
       
    }
    while(choice<5);
    // root=dict.insert("ruchika","mom");
    // dict.insert("rashmika","sis");
    // dict.insert("vikas","dad");
    // dict.insert("rayushka","me");
    // dict.insert("vaastav","friend");
    // dict.insert("sushi","baby");
    // dict.insert("fifi","baby");
    //  cout<<"DICIONARY:"<<"\n";
    //  cout<<"Root "<<root->data<<"\n";
    //  dict.Inorderdisplay(root);
    // // //dict.search(root,2);
    //   root=dict.Delete(root,"vikas");
    //   cout<<"Displaying post deletion"<<"\n";
    //   dict.Inorderdisplay(root);
    // cout<<"\n"<<"Displaying in decending order:"<<"\n";
    // dict.DescendingOrderDisplay(root);
    //  cout<<"\n"<<"Updated Dictionary"<<"\n";
    //  root=dict.UpdateDict(root,"vikas","siss");
    //  dict.Inorderdisplay(root);

    //dict.Delete(root,10);
    //dict.display(root);

}
