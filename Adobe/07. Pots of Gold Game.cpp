int t[1000][1000];

int geti(vector<int> &A, int n, int i, int j)
{
    if (i == j)
        return t[i][j] = A[i];

    if (j == i + 1)
        return t[i][j] = max(A[i], A[j]);

    if (t[i][j] != -1)
        return t[i][j];

    return t[i][j] = max(A[i] + min(geti(A, n, i + 2, j), geti(A, n, i + 1, j - 1)),
                         A[j] + min(geti(A, n, i + 1, j - 1), geti(A, n, i, j - 2)));
}

int maxCoins(vector<int> &A, int n)
{
    memset(t, -1, sizeof t);

    return geti(A, n, 0, n - 1);
}