vector<int> spirallyTraverse(vector<vector<int>> A, int r, int c)
{

    vector<vector<int>> b{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ans;

    int nr = A.size();
    if (nr == 0)
        return ans;

    int nc = A[0].size();
    if (nc == 0)
        return ans;

    vector<int> S{nc, nr - 1};

    int c = 0;
    int u = 0, d = -1;
    while (S[c % 2])
    {
        for (int i = 0; i < S[c % 2]; ++i)
        {
            u += b[c][0];
            d += b[c][1];
            ans.push_back(A[u][d]);
        }
        S[c % 2]--;
        c = (c + 1) % 4;
    }
    return ans;
}