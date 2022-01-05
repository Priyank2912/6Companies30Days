unordered_map<int, int> m;
int MOD = 1000000007;

int geti(string &s, int i, int n)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (m.find(i) != m.end())
        return m[i];
    if (s[i] == '0')
        return 0;
    if (s[i] == '1')
        return m[i] = (geti(s, i + 1, n) % MOD + geti(s, i + 2, n) % MOD) % MOD;
    if (s[i] == '2' && i < n - 1 && s[i + 1] <= '6')
        return m[i] = (geti(s, i + 2, n) % MOD + geti(s, i + 1, n) % MOD) % MOD;
    return m[i] = geti(s, i + 1, n) % MOD;
}

int CountWays(string str)
{

    m.clear();
    int n = str.size();
    return geti(str, 0, n);
}