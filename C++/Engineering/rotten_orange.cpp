#include<iostream>
#include<queue>
using namespace std;
struct ele{
    int x,y;
};
int main()
{
    int n,m;
    cin>>n>>m;
    queue<ele> q;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==2){
                ele k;
                k.x=i;
                k.y=j;
                q.push(k);
            }
        }
    }
    int days=-1;//as in end we will count one more when all our operations are done therefore need to subtract 1 
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
        ele l=q.front();
        if(a[(l.x)-1][l.y]==1 && (l.x)-1>=0 && l.y>=0 && (l.x)-1<n && l.y<m){
            a[(l.x)-1][l.y]=2;
            ele g;
            g.x=(l.x)-1;
            g.y=l.y;
            q.push(g);
        }
        if(a[l.x][(l.y)-1]==1 && (l.y)-1>=0 && l.x>=0 && l.x<n && (l.y)-1<m ){
            a[l.x][(l.y)-1]=2;
            ele g;
            g.x=l.x;
            g.y=(l.y)-1;
            q.push(g);
        }
        if(a[(l.x)+1][l.y]==1 && (l.x)+1<n && l.y>=0 && (l.x)+1>=0 && l.y<m){
            a[(l.x)+1][l.y]=2;
            ele g;
            g.x=(l.x)+1;
            g.y=l.y;
            q.push(g);
        }
        if(a[l.x][(l.y)+1]==1 && (l.y)+1<m && l.x>=0 && l.x<n && (l.y)+1>=0){
            a[l.x][(l.y)+1]=2;
            ele g;
            g.x=l.x;
            g.y=(l.y)+1;
            q.push(g);
        }
        q.pop();
        }
        days++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                count++;
            }
        }
    }
    if(count>0){
        cout<<"-1"<<endl;
    }else{
        cout<<days<<endl;
    }
 return 0;
}