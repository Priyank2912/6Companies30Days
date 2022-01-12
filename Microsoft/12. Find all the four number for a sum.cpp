vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = j + 1, r = n - 1;
            int q = k - arr[i] - arr[j];

            while (l < r)
            {
                if (arr[l] + arr[r] == q)
                {
                    vector<int> b = {arr[i], arr[j], arr[l], arr[r]};
                    ans.push_back(b);
                    while (arr[l] == arr[l + 1])
                        l++;
                    while (arr[r] == arr[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (arr[l] + arr[r] < q)
                    l++;
                else
                    r--;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}