#include <iostream>
using namespace std;
int main()
{
	int i,j;
	int k,l;
	cin>>k>>l;
	int arr[k][l];
	for (i = 0; i < k; i++)
	   for (j = 0; j < l; j++)
			cin>>arr[i][j];
	int g=0,a[10],b[10],v[10];
	for (int i = 0; i < k; ++i) 
    {
		for (int j = 0; j < l; ++j) 
		{
			if(arr[i][j]!=0)
			{
			    v[g]=arr[i][j];
			    a[g]=i;
			    b[g]=j;
			    g++;
			}
		}
    }
    int array[10][10];
    for(int x=0;x<g;x++)
        arr[0][x]=a[x];
    for(int x=0;x<g;x++)
        arr[1][x]=b[x];
    for(int x=0;x<g;x++)
        arr[2][x]=v[x];
    cout<<endl<<"R C N"<<endl;
    for(int q=0;q<g;q++){
        for(int w=0;w<3;w++){
            cout<<arr[w][q]<<" ";
        }
        cout<<endl;
    }
	return 0;
}