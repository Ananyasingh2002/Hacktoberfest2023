#include <bits/stdc++.h>
using namespace std;
// This function will generate an odd-size magic square only.
void magicSquareGenerator(int s)
{
    int magic_Square[s][s];
    // This will initialize all locations of the magic square to 0
    memset(magic_Square, 0, sizeof(magic_Square));
    // here, r is the row index, and c is the column index for the first number
    int r = s / 2;
    int c = s - 1;
    //  generating magic square
    for (int num = 1; num <= s * s;) {
        if (r == -1 && c == s) // Third condition
        {
            c = s - 2;
            r = 0;
        }
        else {
            if (c == s)
                c = 0;
            if (r < 0)
                r = s - 1;
        }
        if (magic_Square[r][c]) // second condition
        {
            c -= 2;
            r++;
            continue;
        }
        else
            magic_Square[r][c] = num++;
        c++;
        r--; // 1st condition
    }

    // Print magic square
    cout << "The Magic Square has:"<<s<<" rows and "<<s<<" columns.";
    cout <<"\nThe Magic Sum is: "<< s * (s * s + 1) / 2 << ":\n";
    for (r = 0; r < s; r++) {
        for (c = 0; c < s; c++)
            // displaying the magic square.
            cout << setw(4) << magic_Square[r][c] << " ";
        cout << endl;
    }
}

int main()
{ //Code expects only odd sizes
    int s;
    cout<<"Enter the size of the Magic Square: ";
    cin>>s;
    while(s%2==0){
        cout<<"Plz Enter an odd number :"<<endl;
        cout<<"Enter the size of the Magic Square: ";
        cin>>s;
    }
    magicSquareGenerator(s);
    return 0;
}
