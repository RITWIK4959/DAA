#include<iostream>
#include<climits>
using namespace std;

#define v 4
void dfs(int graph[v][v],bool visited[], int vertex){
    visited[vertex] = true;
    for(int i = 0;i<v;i++){
        if(graph[vertex][i]&&!visited[i]){
            dfs(graph,visited,i);
        }
    }
    
}
bool iscompare(int graph[v][v]){
   bool visited[v] = {false};
    dfs(graph,visited,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
void prims(int graph[v][v]){
    int key[v],parent[v];
    bool mstset[v] = {false};
    fill(key,key+v,INT_MAX);
    key[0] = 0;
    parent[0] = -1;
    for(int count=0;count<v-1;count++){
        int u = -1;
        for(int i=0;i<v;i++){
            if(!mstset[i]&&(u==-1||key[i]<key[u])){
                u = i;
            }
        }
        mstset[u] = true;
        for(int j=0;j<v;j++){
            if(graph[u][j]&&!mstset[j]&&graph[u][j]<key[j]){
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    for(int k = 1;k<v;k++){
        cout<<parent[k]<<"-"<<graph[k][parent[k]]<<endl;;
    }
}
int main(){
    int graph[v][v] = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    if(iscompare(graph)){
        prims(graph);
    }else{
        cout<<"no"<<endl;
    }
}