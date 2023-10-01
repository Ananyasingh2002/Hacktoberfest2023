#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define ss second
#define ff first
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int k;
    cin>>k;
    vector<vector<int> > a(k);
    rep(i,0,k){
        int size;
        cin>>size;
        a[i]=vector<int>(size);
        rep(j,0,a[i][j]){
            cin>>a[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue<pii,vector<pii>, greater<pii> > pq;
    rep(i,0,k){
        pii p;
        p.ff=a[i][0];
        p.ss=i;
        pq.push(p);
    }
    vi ans;
    while(!pq.empty()){
        pii x=pq.top();
        pq.pop();
        if(idx[x.ss]+1<a[x.ss].size()){
            pii p;
            p.ff=a[x.ss][idx[x.ss]+1];
            p.ss=x.ss;
            pq.push(p);
        }
        idx[x.ss]+=1;
    }
    rep(i,0,ans.size()){
        cout<<ans[i]<<endl;
    }
    cout<<endl;
    return 0;
}