map<string, pair<int, string>> mp;

pair<int, string> matrixChainOrderUtil(int p[], int l, int r)
{

    if (l + 1 == r)
        return {0, "" + string(1, l + 'A')};
    string st = to_string(l) + ";" + to_string(r);
    if (mp[st] != 0)
        return mp[st];

    int mini = INT_MAX;
    string minString;
    for (int k = l + 1; k < r; k++)
    {
        auto p1 = matrixChainOrderUtil(p, l, k), p2 = matrixChainOrderUtil(p, k, r);
        if (p1.first + p2.first + p[l] * p[k] * p[r] < mini)
        {
            mini = p1.first + p2.first + p[l] * p[k] * p[r];

            minString = p1.second + p2.second;
        }
    }
    return mp[st] = {mini, "(" + minString + ")"};
}

string matrixChainOrder(int A[], int n)
{
    return matrixChainOrderUtil(A, 0, n - 1).second;
}