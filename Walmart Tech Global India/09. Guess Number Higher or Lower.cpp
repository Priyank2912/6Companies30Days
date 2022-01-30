class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> mp;

    int geti(int l, int h)
    {

        if (l >= h)
            return 0;
        if (mp[l].count(h))
            return mp[l][h];

        int a = INT_MAX;

        for (int i = l; i <= h; i++)
        {
            int t = i + max(geti(l, i - 1), geti(i + 1, h));
            a = min(a, t);
        }

        return mp[l][h] = a;
    }
    int getMoneyAmount(int n)
    {
        return geti(1, n);
    }
};