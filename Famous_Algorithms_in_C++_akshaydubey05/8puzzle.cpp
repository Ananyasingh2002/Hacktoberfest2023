#include <bits/stdc++.h>
using namespace std;

#define N 3
stack<vector<vector<int>>> path;
map<vector<vector<int>>, vector<vector<int>>> parent;
queue<vector<vector<int>>> q;

void solve(vector<vector<int>> &initial, vector<vector<int>> final, map<vector<vector<int>>, int> &m)
{
    while (!q.empty())
    {
        vector<vector<int>> temp;
        temp = q.front();
        q.pop();
        m[temp] = 1;
        if (temp == final)
        {
            path.push(temp);
            while (parent[temp] != initial)
            {
                path.push(parent[temp]);
                temp = parent[temp];
            }
            path.push(initial);
            return;
        }

        int x, y;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        vector<vector<int>> t;
        if (x != N - 1)
        {
            swap(temp[x][y], temp[x + 1][y]);
            if (m[temp] != 1)
            {
                q.push(temp);
                t = temp;
            }
            swap(temp[x][y], temp[x + 1][y]);
            if (m[t] != 1)
                parent[t] = temp;
        }
        if (x != 0)
        {
            swap(temp[x][y], temp[x - 1][y]);
            if (m[temp] != 1)
            {
                q.push(temp);
                t = temp;
            }
            swap(temp[x][y], temp[x - 1][y]);
            if (m[t] != 1)
                parent[t] = temp;
        }
        if (y != 0)
        {
            swap(temp[x][y], temp[x][y - 1]);
            if (m[temp] != 1)
            {
                q.push(temp);
                t = temp;
            }
            swap(temp[x][y], temp[x][y - 1]);
            if (m[t] != 1)
                parent[t] = temp;
        }
        if (y != N - 1)
        {
            swap(temp[x][y], temp[x][y + 1]);
            if (m[temp] != 1)
            {
                q.push(temp);
                t = temp;
            }
            swap(temp[x][y], temp[x][y + 1]);
            if (m[t] != 1)
                parent[t] = temp;
        }
    }
}

int main()
{
    vector<vector<int>> initial = {{1, 2, 3},
                                   {5, 6, 0},
                                   {7, 8, 4}};
    vector<vector<int>> final = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 0}};
    map<vector<vector<int>>, int> m;
    q.push(initial);
    solve(initial, final, m);
    while (!path.empty())
    {
        vector<vector<int>> t = path.top();
        path.pop();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << t[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}