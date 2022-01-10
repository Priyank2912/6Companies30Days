int isValid(vector<vector<int>> A)
{
    unordered_map<int, unordered_set<int>> mp1, mp2, mp3;
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j])
            {
                int val = A[i][j];
                if (mp1[i].count(val))
                {
                    return false;
                }
                if (mp2[j].count(val))
                {
                    return false;
                }
                int box = (i / 3) * 3 + j / 3;
                if (mp3[box].count(val))
                {
                    return false;
                }
                mp1[i].insert(A[i][j]);
                mp2[j].insert(A[i][j]);
                mp3[box].insert(A[i][j]);
            }
        }
    }
    return true;
}