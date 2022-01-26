class Solution
{
public:
    int maxDistance(vector<vector<int>> &A)
    {
        int n = A.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<pair<int, int>> q;

        int water = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                else
                {
                    water++;
                }
            }
        }

        if (q.size() == 0 or water == 0)
        {
            return -1;
        }

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int ans = -1;
        while (!q.empty())
        {

            int K = q.size();

            for (int i = 0; i < K; i++)
            {

                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for (int j = 0; j < 4; j++)
                {

                    int a = r + dir[j][0];
                    int b = c + dir[j][1];

                    if (a >= 0 && a < n && b >= 0 && b < n && !vis[a][b])
                    {
                        q.push({a, b});
                        vis[a][b] = 1;
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};