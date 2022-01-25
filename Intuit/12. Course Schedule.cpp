stack<int> S;
vector<int> vis;
vector<int> P;
bool cycle;
map<int, vector<int>> mp;

void DFS(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
            geti(i);
    }
}

void geti(int node)
{
    if (cycle)
        return;

    vis[node] = true;
    P[node] = true;

    for (int i : mp[node])
    {
        if (P[i] == true)
            cycle = true;
        if (!vis[i])
            geti(i);
    }

    S.push(node);
    P[node] = false;
}

vector<int> findOrder(int n, vector<vector<int>> &A)
{
    vector<int> Ans;
    vis.assign(n, false);
    P.assign(n, false);
    cycle = false;
    for (auto i : A)
    {
        mp[i[1]].push_back(i[0]);
    }

    DFS(n);

    while (!S.empty())
    {
        Ans.push_back(S.top());
        S.pop();
    }

    if (cycle)
        return {};
    return Ans;
}