/* RAYUSHKA SUD CSE 3 2193191
   Assignment 3 
   Expression Tree */

#include <iostream>
#include <stack>
#include<ctype.h>
#include<cstring>
using namespace std;


class treeNode{
    public:
    char data;
    treeNode* left;
    treeNode* right;

    public:
    treeNode(char newdata=char(), treeNode* newleft = nullptr, treeNode* newright = nullptr):
    data(newdata),left(newleft),right(newright) {}
   
};


class expressionTrees{
    public:
    treeNode* root;
    expressionTrees(){
        root=nullptr;
    }
    public:
    //treeNode* createExpressionTree(char[]*);
    void infixExpression(treeNode* );
    void prefixExpression(treeNode*);
    void postfixExpression(treeNode* );
    void infixExpressionWithoutRecursion(treeNode*);
    void prefixExpressionWithoutRecursion(treeNode*);
    void postfixExpressionWithoutRecursion(treeNode*);
    friend class treeNode;


treeNode*  createExpressionTree(string exp){
        stack<treeNode *>s;
        treeNode *newNode, *operand1,*operand2;
    for(int op=0;op<exp.size();op++)
    {
        if(isalnum(exp[op]))
        {
            newNode=new treeNode(exp[op]);
            s.push(newNode);
        }
        else if(!isalnum(exp[op]))
        {
            newNode=new treeNode(exp[op]);
            operand1 = s.top();
            s.pop();
            operand2 = s.top();
            s.pop();
            newNode->left=operand2;
            newNode->right=operand1;
            s.push(newNode);
        }
        else{
            continue;
        }
        
    
    }
        newNode=s.top();
        s.pop();
       return newNode;
        
}
};
void expressionTrees::infixExpression(treeNode* root){
    treeNode* node=root;
    if(node == nullptr) return;
    infixExpression(node->left);
    cout<<node->data<<" ";
    infixExpression(node->right);
}

void expressionTrees::infixExpressionWithoutRecursion(treeNode* root){
    treeNode* node=root;
    stack<treeNode*> st;
    while(1){
        while(node != nullptr){
            st.push(node);
            node=node->left;
        }
        if(st.empty()) return;
        node=st.top() ;
        cout<<node->data<<" ";
        st.pop();
        node=node->right;

    }
}
void expressionTrees::prefixExpressionWithoutRecursion(treeNode* root){
    treeNode* node;
    stack<treeNode*> st;
    // while(1){
    //     while(node != nullptr){
    //         st.push(node);
    //         cout<<node->data<<" ";
    //         node=node->left;
    //     }
    //     if(st.empty()) return;
    //     node=st.top();
    //     st.pop();
    //     node=node->right;
    // }
    if(root==nullptr) return;
    st.push(root);
    while(!st.empty())
    {
        node=st.top();
        cout<<" "<<node->data;
        st.pop();
        if(node->right != nullptr) st.push(node->right);
        if(node->left != nullptr) st.push(node->left);
    }
}
void expressionTrees::prefixExpression(treeNode* root){
    treeNode* node=root;
    if(node==nullptr) return;
    cout<<node->data<<" ";
    prefixExpression(node->left);
    prefixExpression(node->right);

}
void expressionTrees::postfixExpression(treeNode* root){
     treeNode* node=root;
     if(node==nullptr) return;
     postfixExpression(node->left);
     postfixExpression(node->right);
     cout<<node->data<<" ";
}
void expressionTrees::postfixExpressionWithoutRecursion(treeNode* root){
    stack<treeNode*> s1;
    stack<treeNode*> s2;
    treeNode* node=root;
    s1.push(node);
    while(!s1.empty()){
        node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left != nullptr) {
            s1.push(node->left);
        }
        if(node->right != nullptr){
            s1.push(node->right);
        }

    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}


int main(){
    treeNode* root;
    expressionTrees T;
    // char expr[5];
    // for(int i=0;i<3;i++){
    //     cin>>expr[i];
    // }
    //string expr="ab+ef*g*-";
    string expr;
    cout<<"Enter postfix Expression: "<<"\n";
    cin>>expr;
    root=T.createExpressionTree(expr);
    cout<<"\n"<<"Expression Tree has been created"<<"\n";
    // char ch='Y';
    // char O;
    // do{
    //     cout<<"Enter expression"<<"\n";
    //     cin>>O;
    //     root=T.createExpressionTree(root,O);
    //     cout<<"Continue? Y/N";
    //     cin>>ch;
    // }while(ch=='Y');
    cout<<"\n"<<"Equivalent Infix Expression: (Inorder Traversal using recursion)"<<"\n";
    T.infixExpression(root);
    cout<<"\n"<<"Equivalent Infix Expression: (Inorder Traversal without using recursion)"<<"\n";
    T.infixExpressionWithoutRecursion(root);
    cout<<"\n"<<"Equivalent Prefix Expression: (Preorder Traversal using recursion)"<<"\n";
    T.prefixExpression(root);
    cout<<"\n"<<"Equivalent Prefix Expression: (Preorder Traversal without using recursion)"<<"\n";
    T.prefixExpressionWithoutRecursion(root);
    cout<<"\n"<<"Equivalent Postfix Expression: (Postorder Traversal using recursion)"<<"\n";
    T.postfixExpression(root);
    cout<<"\n"<<"Equivalent Postfix Expression: (Postorder Traversal without using recursion)"<<"\n";
    T.postfixExpressionWithoutRecursion(root);
    return 0;
}
