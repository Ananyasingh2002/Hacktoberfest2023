#include<iostream>
#include<queue>
using namespace std;
class stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        N=0;
    }
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        N--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return N;
    }
};
int main()
{
    stack s;
     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.size()<<endl;
 return 0;
}