#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int count = 0;
        for(int i = 0;i<100;i++)
        {
            if((a % i != 0) && (b % i != 0) && (c % i != 0))
            {
                count = i;
                break;
            }
        }
        cout << count << endl;
    }
	// your code goes here
	return 0;
}