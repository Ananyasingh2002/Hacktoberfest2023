#include<iostream>
using namespace std;
int main()
{
 cout<<"1:Diagonal Matrix"<<endl;
 cout<<"2:Square Matrix"<<endl;
 cout<<"3:Tri-Diagonal Matrix"<<endl;
 cout<<"4:Upper-Triangular Matrix"<<endl;
 cout<<"5:Lower-Triangular Matrix"<<endl;
 cout<<"6:Symmetric Matrix"<<endl;
 int ch,r,c;
 cout<<"Enter your choice"<<endl;
 cin>>ch;
 switch(ch)
 {
    case 1:
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    {
    cout<<"Enter the matrix"<<endl;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i!=j)
            {
                if(a[i][j]==0)
                count++;
            }
            else
            {
                if(a[i][j]!=0)
                count++;
            }
        }
    }
    if(count==(r*c))
    cout<<"It is a Diagonal Matrix"<<endl;
    else
    cout<<"It is not a Diagonal Matrix"<<endl;
    }
    else
    cout<<"A square matrix can only be a Diagonal Matrix"<<endl;
    break;

    case 2:
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    cout<<"It is a Square Matrix"<<endl;
    else
    cout<<"It is not a Square Matrix"<<endl;
    break;

    case 3:
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    {
    cout<<"Enter the matrix"<<endl;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if((i-j)==1||(i-j)==0||(i-j)==-1)
            {
                if(a[i][j]!=0)
                count++;
            }
            else
            {
                if(a[i][j]==0)
                count++;
            }
        }
    }
    if(count==(r*c))
    cout<<"It is a Tri-Diagonal Matrix"<<endl;
    else
    cout<<"It is not a Tri-Diagonal Matrix"<<endl;
    }
    else
    cout<<"A square matrix can only be a Tri-Diagonal Matrix"<<endl;
    break;

    case 4:
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    {
    cout<<"Enter the matrix"<<endl;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i>=j)
            {
                if(a[i][j]!=0)
                count++;
            }
            else
            {
                if(a[i][j]==0)
                count++;
            }
        }
    }
    if(count==(r*c))
    cout<<"It is a Lower-Triangular Matrix"<<endl;
    else
    cout<<"It is not a Lower-Triangular Matrix"<<endl;
    }
    else
    cout<<"A square matrix can only be a Lower-Triangular Matrix"<<endl;
    break;

    case 5:
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    {
    cout<<"Enter the matrix"<<endl;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<=j)
            {
                if(a[i][j]!=0)
                count++;
            }
            else
            {
                if(a[i][j]==0)
                count++;
            }
        }
    }
    if(count==(r*c))
    cout<<"It is a Upper-Triangular Matrix"<<endl;
    else
    cout<<"It is not a Upper-Triangular Matrix"<<endl;
    }
    else
    cout<<"A square matrix can only be a Upper-Triangular Matrix"<<endl;
    break;

    case 6: int r,c;
    cout<<"Enter the number of rows"<<endl;
    cin>>r;
    cout<<"Enter the number of columns"<<endl;
    cin>>c;
    if(r==c)
    {
    cout<<"Enter the matrix"<<endl;
    int a[r][c];int b[c][r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           b[j][i]=a[i][j];
        }
    }
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==b[i][j])
            {
              count++;
            }
        }
    }
    if(count==(r*c))
    cout<<"It is a Symmetric Matrix"<<endl;
    else
    cout<<"It is not a Symmetric Matrix"<<endl;
    }
    else
    cout<<"A square matrix can only be a Symmetric Matrix"<<endl;
    break;
 }
}