#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ipair pair<long long,long long>
#define MAXN 110000
#define inf 1LL<<55
vector<ipair>adj_list[MAXN];
vector<long long>dis(MAXN,inf);
vector<long long>parent(MAXN,0);

void dijikstra(ll src)
{
          priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
          dis[src]=0;
          pq.push(make_pair(dis[src],src));
          
          while(!pq.empty())
          {
                    ll u=pq.top().second;
                    pq.pop();
                    for(auto p:adj_list[u])
                    {
                              ll v=p.first;
                              ll weight=p.second;
                              if(dis[v]>dis[u]+weight)
                              {
                              dis[v]=dis[u]+weight;
                              parent[v]=u;
                              pq.push(make_pair(dis[v],v));
                              }
                    }
          }
}
int main()
{
          ll v;ll e;cin>>v>>e;
          for(ll i=0;i<e;i++)
          {
                    ll u;ll v;ll cost;cin>>u>>v>>cost;
                    adj_list[u].push_back(make_pair(v,cost));
                    adj_list[v].push_back(make_pair(u,cost));
          }
          parent[1]=-1;
          dijikstra(1);
          
          if(parent[v]==0)
          {
                    cout<<-1<<endl;
                    return 0;
          }
          stack<ll>path;
          path.push(v);
          ll i=v;
          while(parent[i]!=-1)
          {
              path.push(parent[i]);
              i=parent[i];
          }
          
          while(!path.empty())
          {
                    cout<<path.top()<<" ";
                    path.pop();
          }
          return 0;
}
