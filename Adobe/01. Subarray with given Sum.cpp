vector<int> subarraySum(int arr[], int n, long long s)
{
    int i = 0, j = 0;
    long long h = 0;
    vector<int> ans;
    while (j < n)
    {
        h += arr[j];
        if (h > s)
        {
            while (i < j && h > s)
            {
                h -= arr[i];
                i++;
            }
        }
        if (h == s)
        {
            return {i + 1, j + 1};
        }
        j++;
    }
    return {-1};
}