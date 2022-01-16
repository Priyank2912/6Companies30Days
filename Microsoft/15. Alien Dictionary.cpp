void dfs(int node, vector<vector<int>> &adj, vector<int> &v, string &ans)
{
    v[node] = 1;
    for (auto f : adj[node])
    {
        if (!v[f])
            dfs(f, adj, v, ans);
    }
    char f = node + 'a';
    ans += f;
}

string findOrder(string A[], int n, int k)
{
    vector<vector<int>> adj(k);
    for (int i = 0; i < n - 1; i++)
    {
        string a = A[i];
        string b = A[i + 1];

        for (int j = 0; j < min(a.size(), b.size()); j++)
        {
            if (a[j] != b[j])
            {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }

    vector<int> v(k, 0);
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (v[i] == 0)
            dfs(i, adj, v, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}