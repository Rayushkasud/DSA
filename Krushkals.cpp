/* RAYUSHKA SUD CSE 3 2193191
DIJIKSRA'S ALGORITHM
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parents[50];
int find(int x){
    if(parents[x]==x){
        return x;
    }
    return find(parents[x]);
}

void Union(int x, int y){
    int px= find(x);
    int py= find(y);
    parents[px]=py;
}
int main(){
    for(int i=0;i<50;i++){
        parents[i]=i;
    }
    int vertices,numOfEdges;
    int source,dest,edgeWt;
    vector<pair<int, pair<int , int> > > edges;
    cout<<"Enter number of Vertices and edges"<<"\n";
    cin>>vertices>>numOfEdges;
    cout<<"Enter the to, from and weight of edge "<<"\n";
    for(int i=0;i<numOfEdges;i++){
        cin>>source>>dest>>edgeWt;
        edges.push_back(make_pair(edgeWt,make_pair(source,dest)));
    }
    int mst_cost=0,mst_edges=0;
    int mst_next=0;
    sort(edges.begin(),edges.end());
    cout<<"MIN SPANING TREE"<<"\n";
    while((mst_edges < vertices-1)||mst_next<numOfEdges){
        source=edges[mst_next].second.first;
        dest=edges[mst_next].second.second;
        edgeWt=edges[mst_next].first;

        if(find(source) != find(dest)){
            Union(source,dest);
            mst_cost += edgeWt;
            cout<<source<<" "<<dest<<" "<<edgeWt<<"\n";
            mst_edges++;
        }
        mst_next++;

    }
    cout<<"Cost Of Min Spanning Tree:"<<mst_cost;
}
/* 1 2 4
1 3 8
2 3 11
2 4 8
3 6 7
3 7 1
6 7 6
7 8 2
8 5 14
4 5 7
5 9 9
8 9 10 */