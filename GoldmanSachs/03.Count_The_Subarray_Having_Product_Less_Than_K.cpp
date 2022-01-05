int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{

    long long int ans = 0;
    int i = 0, j = 0;

    long long int q = 1;
    while (j < n)
    {
        q *= a[j];
        while (i != j)
        {
            if (q < k)
                break;
            q /= a[i];
            i++;
        }
        if (q < k)
            ans += j - i + 1;
        j++;
    }
    return ans;
}