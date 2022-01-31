class Solution
{
public:
    void geti(int i, int j, int a, int b, int &ans, vector<vector<int>> &vis)
    {
        if (i < 0 || i >= a || j < 0 || j >= b || vis[i][j])
            return;

        if (i == a - 1 && j == b - 1)
        {
            ans += 1;
            return;
        }

        vis[i][j] = 1;
        geti(i, j + 1, a, b, ans, vis);
        geti(i + 1, j, a, b, ans, vis);
        vis[i][j] = 0;
    }
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // code here
        int ans = 0;
        vector<vector<int>> vis(a, vector<int>(b, 0));
        geti(0, 0, a, b, ans, vis);
        return ans;
    }
};