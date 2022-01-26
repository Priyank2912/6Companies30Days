class Solution
{
public:
    bool che(int i, int j, int x, vector<vector<char>> &A, string &s, vector<vector<int>> &vis)
    {

        if (vis[i][j])
            return false;
        if (x == s.size())
            return true;

        vis[i][j] = 1;

        if (i > 0 && s[x] == A[i - 1][j])
        {
            if (che(i - 1, j, x + 1, A, s, vis))
            {
                return true;
            }
        }

        if (i < A.size() - 1 && s[x] == A[i + 1][j])
        {
            if (che(i + 1, j, x + 1, A, s, vis))
            {
                return true;
            }
        }

        if (j > 0 && s[x] == A[i][j - 1])
        {
            if (che(i, j - 1, x + 1, A, s, vis))
            {
                return true;
            }
        }

        if (j < A[0].size() - 1 && s[x] == A[i][j + 1])
        {
            if (che(i, j + 1, x + 1, A, s, vis))
            {
                return true;
            }
        }

        vis[i][j] = 0;

        return false;
    }

    bool isWordExist(vector<vector<char>> &A, string s)
    {
        int n = A.size();
        int m = A[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (A[i][j] == s[0] && che(i, j, 1, A, s, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};