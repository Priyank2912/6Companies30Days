void rotate(vector<vector<int>> &A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            swap(A[i][j], A[j][i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, a = n - 1; j < a; j++, a--)
            swap(A[j][i], A[a][i]);
    }
}