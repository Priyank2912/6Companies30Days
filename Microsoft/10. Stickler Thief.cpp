unordered_map<int, int> m;

int geti(int arr[], int n, int i)
{
    if (i >= n)
        return 0;
    if (m.find(i) != m.end())
        return m[i];
    return m[i] = max(arr[i] + geti(arr, n, i + 2), geti(arr, n, i + 1));
}

int FindMaxSum(int arr[], int n)
{
    m.clear();
    return geti(arr, n, 0);
}