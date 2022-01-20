bool che(char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}

int atoi(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;

    int ans = 0;
    int gayu = 1;

    int i = 0;

    if (s[0] == '-')
    {
        gayu = -1;
        i++;
    }

    for (i; i < n; ++i)
    {
        if (!che(s[i]))
            return -1;
        ans = ans * 10 + s[i] - '0';
    }

    return gayu * ans;
}