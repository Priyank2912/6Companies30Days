bool geti(int a[], map<pair<int, int>, bool> &mp, int i, int n, int mid)
{
    if (mid == 0)
        return true;
    if (i == n)
        return false;

    if (mp.find({mid, i}) != mp.end())
        return mp[{mid, i}];
    return mp[{mid, i}] = geti(a, mp, i + 1, n, mid) || geti(a, mp, i + 1, n, mid - a[i]);
}

bool che(int &mid, int a[], int &n)
{
    map<pair<int, int>, bool> mp;
    return geti(a, mp, 0, n, mid);
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int l = 0, r = sum / 2;
    // cout<<r<<" "<<l;
    int ans = 0;
    for (int i = 0; i <= r; i++)
    {
        int mid = i;
        // cout<<ans<<" ";
        if (che(mid, arr, n, sum))
        {
            ans = mid;
        }
    }
    // cout<<ans<<" ";
    return sum - ans - ans;
}