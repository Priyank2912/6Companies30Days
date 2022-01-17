bool geti(int A[], int sum, int n)
{
    int mp[sum + 1];
    for (int i = 0; i < sum + 1; i++)
        mp[i] = 0;

    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= A[i]; j--)
        {
            if (mp[j - A[i]] == 1)
                mp[j] = 1;
        }
    }

    if (mp[sum] == 1)
        return true;

    return false;
}

int equalPartition(int n, int A[])
{

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];

    if (sum & 1)
        return 0;
    sum = sum >> 1;

    if (!geti(A, sum, n))
        return 0;
    return 1;
}