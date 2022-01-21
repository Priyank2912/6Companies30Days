int mp[1001][1001];
int geti(int n, int x, int i, int j)
{
    if (n == 0)
        return 1;
    if (i > j)
        return 0;
    if (mp[n][i] != -1)
        return mp[n][i];

    int a = pow(i, x);
    if (a <= n)
        return mp[n][i] = geti(n - a, x, i + 1, j) + geti(n, x, i + 1, j);
    return mp[n][i] = 0;
}

int numOfWays(int n, int x)
{

    memset(mp, -1, sizeof mp);
    return geti(n, x, 1, n);
}