stack<int> S;
vector<int> vis;
vector<int> P;
bool che;
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
    if (che)
        return;

    vis[node] = true;
    P[node] = true;

    for (int i : mp[node])
    {
        if (P[i] == true)
            che = true;
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
    che = false;
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

    if (che)
        return {};
    return Ans;
}