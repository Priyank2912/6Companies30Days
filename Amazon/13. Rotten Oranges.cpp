int orangesRotting(vector<vector<int>> &A)
{

    vector<int> v = {-1, 0, 1, 0, -1};

    int m = A.size();
    int n = A[0].size();

    queue<pair<int, int>> q;
    int cnt = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 2)
                q.push({i, j});
            if (A[i][j] == 1)
                cnt++;
        }
    int ans = -1;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int r = p.first + v[i];
                int c = p.second + v[i + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && A[r][c] == 1)
                {
                    A[r][c] = 2;
                    q.push({r, c});
                    cnt--;
                }
            }
        }
        ans++;
    }

    if (cnt > 0)
        return -1;
    if (ans == -1)
        return 0;
    return ans;
}
