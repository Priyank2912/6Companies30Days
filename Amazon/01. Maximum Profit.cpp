int numi;
int geti(int arr[], int c, int i, int k, vector<vector<vector<int>>> &mp)
{
    if (i == numi || k == 0)
        return 0;
    if (mp[c][i][k] != -1)
        return mp[c][i][k];
    if (!c)
        return mp[c][i][k] = max(-arr[i] + geti(arr, 1, i + 1, k, mp), geti(arr, c, i + 1, k, mp));
    else
        return mp[c][i][k] = max(arr[i] + geti(arr, 0, i + 1, k - 1, mp), geti(arr, c, i + 1, k, mp));
}

int maxProfit(int k, int n, int A[])
{
    int ans = 0;
    if (k >= n / 2)
    {
        for (int i = 1; i < n; i++)
            ans += max(0, A[i] - A[i - 1]);
        return ans;
    }
    numi = n;
    vector<vector<vector<int>>> mp(3, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    return geti(A, 0, 0, k, mp);
}