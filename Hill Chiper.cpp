#include <bits/stdc++.h>

using namespace std;

float mes[3][1],a[3][3],b[3][3],c[3][3],decr[3][1],enc[3][1];

void encryption();
void decryption();
void getkeymessage();
void inverse();

void getkeymessage()
{
    char msg[3];
    cout<<"ENTER THE 3X3 MATRIX:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
            c[i][j]=a[i][j];
        }
    }
    cout<<"Enter the message:";
    cin>>msg;
    for(int i=0;i<3;i++)
    {
        mes[i][0]=msg[i]-'a';
    }
}

void encryption()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<3;k++)
            {
                enc[i][j]+=a[i][k]*mes[k][j];
            }
        }
    }
    cout<<"Encryption message:";
    for(int i=0;i<3;i++)
    {
        cout<<(char)(fmod(enc[i][0],26)+'a');
    }
    cout<<'\n';
}
void decryption()
{
    inverse();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<3;k++)
            {
                decr[i][j]+=b[i][k]*enc[k][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<(char)(fmod(decr[i][0],26)+'a');
    }
    cout<<'\n';
}

void inverse()
{
    float p,q;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                b[i][j]=1;
            }
            else
            {
                b[i][j]=0;
            }
        }
    }
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<3;i++)
        {
            p=c[i][k];
            q=c[k][k];
            for(int j=0;j<3;j++)
            {
                if(i!=k)
                {
                    b[i][j]=b[i][j]*q-b[k][j]*p;
                    c[i][j]=c[i][j]*q-c[k][j]*p;
                }
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            b[i][j]/=c[i][i];       
        }
    }
    cout<<"Inverse of the matrix:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int main() {
    getkeymessage();
    encryption();
    decryption();
}
