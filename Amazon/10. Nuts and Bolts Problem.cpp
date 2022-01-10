void matchPairs(char A[], char B[], int n)
{
    unordered_map<char, int> m;
    char arr[] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;
    }

    int j = 0;

    for (int i = 0; i < 9; i++)
    {
        if (m.find(arr[i]) != m.end())
            A[j++] = arr[i];
    }

    m.clear();
    for (int i = 0; i < n; i++)
    {
        m[B[i]]++;
    }

    j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (m.find(arr[i]) != m.end())
            B[j++] = arr[i];
    }
}