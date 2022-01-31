class Solution
{
public:
    int mp[501][501];
    int solve(int i, int j, vector<int> &A)
    {
        if (i == j)
            return A[i];

        if (i + 1 == j)
            return max(A[i], A[j]);

        if (mp[i][j] != -1)
            return mp[i][j];
        int a = A[i] + min(solve(i + 2, j, A), solve(i + 1, j - 1, A));
        int b = A[j] + min(solve(i, j - 2, A), solve(i + 1, j - 1, A));

        return mp[i][j] = max(a, b);
    }
    bool stoneGame(vector<int> &A)
    {

        int n = A.size();
        memset(mp, -1, sizeof(mp));
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += A[i];
        sum /= 2;

        int t = solve(0, n - 1, A);
        if (t > sum)
            return 1;
        return 0;
    }
};