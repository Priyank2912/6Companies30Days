class Solution
{
public:
    void solve(vector<vector<int>> &A, int i, int j, int prev, vector<vector<int>> &adj)
    {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
        {
            return;
        }
        if (adj[i][j] == 1)
            return;
        if (A[i][j] < prev)
            return;

        adj[i][j] = 1;

        solve(A, i + 1, j, A[i][j], adj);
        solve(A, i - 1, j, A[i][j], adj);
        solve(A, i, j + 1, A[i][j], adj);
        solve(A, i, j - 1, A[i][j], adj);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &A)
    {
        vector<vector<int>> ans;
        int n = A.size(), m = A[0].size();
        if (n < 1)
            return ans;

        vector<vector<int>> adj1(n, vector<int>(m, 0));
        vector<vector<int>> adj2(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            solve(A, 0, i, INT_MIN, adj1);
            solve(A, n - 1, i, INT_MIN, adj2);
        }

        for (int i = 0; i < n; i++)
        {
            solve(A, i, 0, INT_MIN, adj1);
            solve(A, i, m - 1, INT_MIN, adj2);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (adj1[i][j] == 1 && adj2[i][j] == 1)
                {
                    vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};