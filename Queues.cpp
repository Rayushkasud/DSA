#include<iostream>
#include<queue>
using namespace std;int main(){
    queue<int> Q;
    priority_queue<int> max_PQ; //max by default
    priority_queue<int ,vector<int>,greater<int> >min_PQ;
    int input;
    cout<<"Enter value";
    while(input){
      cin>>input;
      if(input){
          Q.push(input); 
          max_PQ.push(input); 
          min_PQ.push(input); 
      }  
    }
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop(); 
    }
    while(!max_PQ.empty()){
        cout<<max_PQ.top()<<" ";
        max_PQ.pop(); 
    }
    while(!min_PQ.empty()){
        cout<<min_PQ.top()<<" ";
        min_PQ.pop(); 
    }



    return 0;
}