int numberOfBoomerangs(vector<vector<int>> &A)
{

    int ans = 0;
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {

        unordered_map<long, int> mp;

        for (int j = 0; j < n; ++j)
        {

            if (j == i)
                continue;

            int a = A[i][1] - A[j][1];
            int b = A[i][0] - A[j][0];

            int c = a * a;
            c += b * b;

            mp[c]++;
        }

        for (auto p : mp)
            ans += p.second * (p.second - 1);
    }

    return ans;
}