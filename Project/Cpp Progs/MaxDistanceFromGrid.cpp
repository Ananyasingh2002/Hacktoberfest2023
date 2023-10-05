#include <bits/stdc++.h>
using namespace std;

#define INF 99999999
#define MAXR 12
#define MAXC 12
#define MAXMASK 2048
#define MAXHOUSE 12

// stores distance taking source
// as every dirty tile
int dist[MAXR][MAXC][MAXHOUSE];

// memoization for dp states
int dp[MAXHOUSE][MAXMASK];

// stores coordinates for
// dirty tiles
vector<pair<int, int> > dirty;

// Directions
int X[] = { -1, 0, 0, 1 };
int Y[] = { 0, 1, -1, 0 };

char arr[21][21];

// len : number of dirty tiles + 1
// limit : 2 ^ len -1
// r, c : number of rows and columns
int len, limit, r, c;

// Returns true if current position
// is safe to visit
// else returns false
// Time Complexity : O(1)
bool safe(int x, int y)
{
	if (x >= r or y >= c or x < 0 or y < 0)
		return false;
	if (arr[x][y] == '#')
		return false;
	return true;
}

// runs BFS traversal at tile idx
// calculates distance to every cell
// in the grid
// Time Complexity : O(r*c)
void getDist(int idx)
{

	// visited array to track visited cells
	bool vis[21][21];
	memset(vis, false, sizeof(vis));

	// getting current position
	int cx = dirty[idx].first;
	int cy = dirty[idx].second;

	// initializing queue for bfs
	queue<pair<int, int> > pq;
	pq.push({ cx, cy });

	// initializing the dist to max
	// because some cells cannot be visited
	// by taking source cell as idx
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= c; j++)
			dist[i][j][idx] = INF;

	// base conditions
	vis[cx][cy] = true;
	dist[cx][cy][idx] = 0;

	while (!pq.empty()) {
		auto x = pq.front();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			cx = x.first + X[i];
			cy = x.second + Y[i];
			if (safe(cx, cy)) {
				if (vis[cx][cy])
					continue;
				vis[cx][cy] = true;
				dist[cx][cy][idx]
					= dist[x.first][x.second][idx] + 1;
				pq.push({ cx, cy });
			}
		}
	}
}

// Dynamic Programming state transition recursion
// with memoization. Time Complexity: O(n*n*2 ^ n)
int solve(int idx, int mask)
{
	// goal state
	if (mask == limit)
		return dist[0][0][idx];

	// if already visited state
	if (dp[idx][mask] != -1)
		return dp[idx][mask];

	int ret = INT_MAX;

	// state transition relation
	for (int i = 0; i < len; i++) {
		if ((mask & (1 << i)) == 0) {
			int newMask = mask | (1 << i);
			ret = min(ret,
					solve(i, newMask)
						+ dist[dirty[i].first]
								[dirty[i].second][idx]);
		}
	}

	// adding memoization and returning
	return dp[idx][mask] = ret;
}

void init()
{
	// initializing containers
	memset(dp, -1, sizeof(dp));
	dirty.clear();

	// populating dirty tile positions
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '*')
				dirty.push_back({ i, j });
		}

	// inserting ronot's location at the
	// beginning of the dirty tile
	dirty.insert(dirty.begin(), { 0, 0 });

	len = dirty.size();

	// calculating LIMIT_MASK
	limit = (1 << len) - 1;

	// precalculating distances from all
	// dirty tiles to each cell in the grid
	for (int i = 0; i < len; i++)
		getDist(i);
}

int main(int argc, char const* argv[])
{
	// Test case #1:
	//	 .....*.
	//	 ...#...
	//	 .*.#.*.
	//	 .......

	char A[4][7]
		= { { '.', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '*', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '.', '.', '.', '.' } };

	r = 4;
	c = 7;

	cout << "The given grid : " << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << A[i][j] << " ";
			arr[i][j] = A[i][j];
		}
		cout << endl;
	}

	// - initialization
	// - precalculations
	init();

	int ans = solve(0, 1);

	cout << "Minimum distance for the given grid : ";
	cout << ans << endl;

	// Test Case #2
	//	 ...#...
	//	 ...#.*.
	//	 ...#...
	//	 .*.#.*.
	//	 ...#...

	char Arr[5][7]
		= { { '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '.', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' },
			{ '.', '*', '.', '#', '.', '*', '.' },
			{ '.', '.', '.', '#', '.', '.', '.' } };

	r = 5;
	c = 7;

	cout << "The given grid : " << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << Arr[i][j] << " ";
			arr[i][j] = Arr[i][j];
		}
		cout << endl;
	}

	// - initialization
	// - precalculations
	init();
	ans = solve(0, 1);
	cout << "Minimum distance for the given grid : ";
	if (ans >= INF)
		cout << "not possible" << endl;
	else
		cout << ans << endl;

	return 0;
}
