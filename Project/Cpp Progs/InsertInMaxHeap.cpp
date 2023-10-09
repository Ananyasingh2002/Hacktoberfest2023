#include<bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &v, int value){
    // We insert the value in last position and
    // Check if it's correct postion or not??
    v.push_back(value);
    int i = v.size() - 1;
    while(i>0){
        int parent = i/2;
        if(v[parent] < v[i]){
            swap(v[parent],v[i]);
            i=parent;
        }
        else{
            return;
        }

    }

}

int main(){
    // Input Vector
    vector<int> input;
    input.push_back(50);
    input.push_back(40);

    // Value that will be inserted
    int value = 60;
    insertHeap(input, value);

    for(int i=0;i<input.size();i++){
        cout<<input[i]<<" ";
    }

    return 0;
}
