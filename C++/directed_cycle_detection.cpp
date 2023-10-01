#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
bool iscycle(int src,vector<vector<int> > &adj,vector<bool> &visited, vector<int> &stack){
    stack[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    stack[src]=false;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle=false;
    vector<int> stack(n,0);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"Cycle is present"<<endl;
    }else{
        cout<<"Cycle is not present"<<endl;
    }
 return 0;
}