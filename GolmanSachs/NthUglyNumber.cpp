ull getNthUglyNo(int n)
{
    vector<ull> m(n + 1);

    int a = 0, b = 0, c = 0;
    m[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        m[i] = min({2 * m[a], 3 * m[b], 5 * m[c]});

        if (2 * m[a] == m[i])
        {
            a++;
        }

        if (3 * m[b] == m[i])
        {
            b++;
        }

        if (5 * m[c] == m[i])
        {
            c++;
        }
    }

    return m[n - 1];
}