class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto g : adj[node])
        {
            if (vis[g] == 0)
                dfs(g, vis, adj);
        }
    }

    int findCircleNum(vector<vector<int>> &A)
    {

        int n = A.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};