string nextPalin(string s)
{
    int n = s.size();
    if (n <= 3)
    {
        return "-1";
    }

    int mid = n / 2 - 1;
    int i, j;

    for (i = mid - 1; i >= 0; i--)
        if (s[i] < s[i + 1])
            break;

    if (i < 0)
    {

        return "-1";
    }

    int mini;

    for (j = mid; j >= 0; j--)
    {
        if (s[j] > s[i])
        {
            mini = j;
            break;
        }
    }

    swap(s[i], s[mini]);

    swap(s[n - i - 1], s[n - mini - 1]);

    reverse(s.begin() + i + 1, s.begin() + mid + 1);
    if (n % 2 == 0)
        reverse(s.begin() + mid + 1, s.begin() + n - i - 1);
    else
        reverse(s.begin() + mid + 2, s.begin() + n - i - 1);

    return s;
}