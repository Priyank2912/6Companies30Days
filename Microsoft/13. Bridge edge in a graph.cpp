void dfs(int node, vector<int> &v, vector<int> adj[], int c, int d)
{
    v[node] = 1;

    for (auto e : adj[node])
    {
        if ((node == c and e == d) or (node == d and e == c))
        {
            continue;
        }

        if (!v[e])
        {
            dfs(e, v, adj, c, d);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<int> v(V, 0);

    dfs(c, v, adj, c, d);
    if (!v[d])
        return 1;
    else
        return 0;
}