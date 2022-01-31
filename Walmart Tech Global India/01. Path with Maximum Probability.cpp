class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &A, vector<double> &B, int start, int end)
    {

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < A.size(); i++)
        {
            adj[A[i][0]].push_back({A[i][1], B[i]});
            adj[A[i][1]].push_back({A[i][0], B[i]});
        }

        priority_queue<pair<double, int>> q;
        vector<double> vis(n, 0);
        vis[start] = 1;
        q.push({1.0, start});

        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();
            for (auto v : adj[u])
            {
                double p = v.second;
                int node = v.first;
                if (vis[node] < vis[u] * p)
                {
                    vis[node] = vis[u] * p;
                    q.push({vis[u] * p, node});
                }
            }
        }
        return vis[end];
    }
};