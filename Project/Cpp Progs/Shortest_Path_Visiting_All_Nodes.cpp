class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodes = graph.size();
        set<pair<int,int>>vis;
        queue<vector<int>>q;
        int allVisited = (1 << nodes)-1;

        for(int i=0; i<nodes; i++)
        {   
            int maskvalue = (1<<i);
            q.push({i,maskvalue,0});
            vis.insert({i,maskvalue});
        }

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it[0];
            int masking = it[1];
            int cost = it[2];
            if(allVisited==masking)
            {
                return cost;
            }
            for(auto &adj : graph[node])
            {   
                
                int bothvismask = masking;
                bothvismask = bothvismask | (1<<adj);
                if(vis.find({adj,bothvismask})==vis.end())
                {
                    q.push({adj,bothvismask,cost+1});
                    vis.insert({adj,bothvismask});
                }
            }
        }
        return -1;

    }
};
