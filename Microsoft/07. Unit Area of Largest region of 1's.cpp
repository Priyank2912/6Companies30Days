int findMaxArea(vector<vector<int>> &grid)
{

    int ans = 0;
    int c = 0;

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                queue<pair<int, int>> qw;
                qw.push({i, j});
                c = 0;
                grid[i][j] = 0;
                while (!qw.empty())
                {
                    int p = qw.front().first;
                    int q = qw.front().second;
                    qw.pop();
                    c++;
                    // cout<<c<<" ";
                    if (p > 0 && grid[p - 1][q] == 1)
                    {
                        qw.push({p - 1, q});
                        grid[p - 1][q] = 0;
                    }
                    if (q > 0 && grid[p][q - 1] == 1)
                    {
                        qw.push({p, q - 1});
                        grid[p][q - 1] = 0;
                    }
                    if (p < n - 1 && grid[p + 1][q] == 1)
                    {
                        qw.push({p + 1, q});
                        grid[p + 1][q] = 0;
                    }
                    if (q < m - 1 && grid[p][q + 1] == 1)
                    {
                        qw.push({p, q + 1});
                        grid[p][q + 1] = 0;
                    }

                    if (p > 0 && q > 0 && grid[p - 1][q - 1] == 1)
                    {
                        qw.push({p - 1, q - 1});
                        grid[p - 1][q - 1] = 0;
                    }
                    if (p > 0 && q < m - 1 && grid[p - 1][q + 1] == 1)
                    {
                        qw.push({p - 1, q + 1});
                        grid[p - 1][q + 1] = 0;
                    }
                    if (p < n - 1 && q > 0 && grid[p + 1][q - 1] == 1)
                    {
                        qw.push({p + 1, q - 1});
                        grid[p + 1][q - 1] = 0;
                    }
                    if (p < n - 1 && q < m - 1 && grid[p + 1][q + 1] == 1)
                    {
                        qw.push({p + 1, q + 1});
                        grid[p + 1][q + 1] = 0;
                    }
                }
                ans = max(ans, c);
            }
        }
    }
    return ans;
}