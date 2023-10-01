#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a;i<b;i++)
const int N=1e5+2,MOD=1e9+7;
vi adj[N];
int main()
{
    int n,m;
    cin>>n>>m;
    vvi adjm(n+1,vi(m+1));
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"Adjancy matrix of above graph is "<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
    if(adjm[3][7]==1){
        cout<<"there is an edge between 3 and 7"<<endl;
    }else{
        cout<<"no edge"<<endl;
    }
    cout<<endl<<endl;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"\nAdjancy list of above graph is "<<endl;
    rep(i,1,n+1){
        cout<<i<<"->";
        vector<int> ::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
 return 0;
}