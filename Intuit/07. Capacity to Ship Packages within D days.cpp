int che(vector<int> &A, int mid)
{
    int c = 0, int ans = 1;
    for (auto y : A)
    {
        c += y;
        if (c > mid)
        {
            ans++;
            c = y;
        }
    }
    return ans;
}

int shipWithinDays(vector<int> &A, int k)
{
    int l = INT_MIN, r = 0;
    for (auto h : A)
    {
        r += h;
        l = max(l, h);
    }
    int ans = -1;
    while (l <= r)
    {
        int mid = r - (r - l) / 2;
        if (che(A, mid) <= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}