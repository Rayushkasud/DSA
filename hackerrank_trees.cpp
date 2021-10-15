#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  Node *ParentFind(Node* root , int val){
      Node *temp,*parent;
      parent = nullptr;
      temp=root;
     
        while(temp->data != val){
            parent = temp;
            if(val > temp->data )
                temp = temp->right;
            
            else 
                temp = temp->left;
            
        }
        if(temp->data == val )
        return parent;
        else return root;
  }
    Node *lca(Node *root, int v1,int v2) {
		Node *parentNode1 = ParentFind(root,v1);
        Node *parentNode2 = ParentFind(root,v2);
        while(parentNode1 != parentNode2){
          if(parentNode1 == nullptr && parentNode2 != nullptr ) 
          {
              return parentNode2;
          } 
          else if(parentNode2 == nullptr && parentNode1 != nullptr)
          return parentNode1;
          else {
          parentNode1 = ParentFind(root , parentNode1->data);
          parentNode2 = ParentFind(root , parentNode2->data);  
          }
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
