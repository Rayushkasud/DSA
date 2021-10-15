/* RAYUSHKA SUD CSE 3 2193191
   Assignment 5
   BFS and DFS Of a Graph */
#include <iostream>
#include <stack>
#include<queue>
#include<vector>
#include<ctype.h>
#include<cstring>
using namespace std;

class Traversals{
    vector<int> AdjacencyList[50];
    int V;
    public:
    void AddEdge(int to, int from){
        AdjacencyList[from].push_back(to);
        AdjacencyList[to].push_back(from);
    }

    void BFSTraversal(int startVertex){
        queue<int> q;
        int vertex;
        bool visitedArray[50]={false};
        q.push(startVertex);
        while(!q.empty()){
        vertex=q.front();
        if(!visitedArray[vertex])
           cout<<vertex<<" ";
        q.pop();
        visitedArray[vertex]=true;
        for(auto it:AdjacencyList[vertex]){
                if(!visitedArray[it])
                q.push(it);
            }
        }
      
        }

    void DFSTraversal(int startVertex){
        stack<int> s;
        int vertex;
        bool visited[50]={false};
        s.push(startVertex);
        while(!s.empty()){
        vertex=s.top();
            if(!visited[vertex])
            cout<<vertex<<" ";
        s.pop();
        visited[vertex]=true;
        for(auto nbr:AdjacencyList[vertex]){
            if(!visited[nbr])
            s.push(nbr);
        }
        }
    }
};

int main(){
    Traversals T;
    int Vertices,Edges,to,from,start;
    cout<<"Enter number of vertices"<<endl;
    cin>>Vertices;
    cout<<"Enter number of edges"<<endl;
    cin>>Edges;
    while(Edges--){
        cout<<"add edge to from?"<<"\n";
        cin>>to>>from;
        T.AddEdge(to,from);
    }
    cout<<"\n"<<"Enter start vertex"<<"\n";
    cin>>start;
    cout<<"BFS Traversal of Entered Graph"<<"\n";
    T.BFSTraversal(start);
    cout<<"\n"<<"DFS Traversal of Entered Graph"<<"\n";
    T.DFSTraversal(start);
}