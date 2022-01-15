bool che(int node, vector<int> adj[], vector<int> a, vector<int> b)
{
    a[node] = 1;
    b[node] = 1;
    for (auto it : adj[node])
    {
        if (!a[it])
        {
            if (che(it, adj, a, b))
                return true;
        }
        else if (b[it])
        {
            return true;
        }
    }
    b[node] = 0;
    return false;
}

bool geti(int n, vector<int> adj[])
{
    vector<int> a[n], b[n];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            if (che(i, adj, a, b))
            {
                return true;
            }
        }
    }
    return false;
}

bool isPossible(int n, vector<pair<int, int>> &prerequisites)
{

    vector<int> adj[n];

    for (auto h : prerequisites)
        adj[h.second].push_back(h.first);

    if (geti(n, adj))
        return false;
    return true;
}