/* RAYUSHKA SUD CSE 3 2193191
DIJIKSRA'S ALGORITHM
*/
#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<queue>
using namespace std;
class AdjList{
public:
vector< pair<int,int> > Adj[100];
int V;
public:
AdjList(int numOfVertices){
    V=numOfVertices;
}


void addEdge(int to ,int from,int weight){
        Adj[from].push_back(make_pair(to,weight));
        Adj[to].push_back(make_pair(from,weight));    
        }
void displayList(){
for(int i=0;i<V;i++){
    for(auto j: Adj[i]){
        cout<<"->"<<j.first<<","<<j.second;
    }
    cout<<"\n";
}
}
public:
void Dijikstra(){
    priority_queue< pair<int , int > , vector<pair <int , int> >,greater<pair< int , int> > >PQ;
    vector<int> distArray(V,INT_MAX);	
	vector<bool> visited(V,false);	

    int source,dist,temp;
    cout<<"Enter source node";
    cin>>source;
    distArray[source]=0;
    PQ.push(make_pair(distArray[source],source));

    while(!PQ.empty()){
        temp=PQ.top().second;
        distArray[temp]=PQ.top().first;
        if(visited[temp]==false){
        PQ.pop();
        visited[temp]=true;}

        for(auto neighbour: Adj[temp]){
            dist=distArray[temp]+neighbour.second;
            if(dist<=distArray[neighbour.first] && visited[neighbour.first]==false){
                distArray[neighbour.first]=dist;
            PQ.push(make_pair(distArray[neighbour.first] , neighbour.first));
            }
            
        }

    }
    for(int i=0;i<V;i++){
        cout<<i<<"th vertex dist from source: "<<distArray[i]<<"\n";
    }

}
};
int main(){
    int nodes,edges,to,from,weight;
    cout<<"Enter number of nodes";
    cin>>nodes;
    AdjList list(nodes);
    cout<<"Enter number of edges";
    cin>>edges;
    while(edges--){
    cout<<"Add edges to from and weight";
    cin>>to>>from>>weight;
    list.addEdge(to,from,weight);
    }
    list.displayList();
    cout<<"\n"<<"The shortest distance of each vertex from the source is:"<<"\n";
    list.Dijikstra();
}
