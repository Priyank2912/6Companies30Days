int minSteps(int n)
{
    n = abs(n);

    int sum = 0, ans = 0;
    while (sum < n || (sum - n) % 2 != 0)
    {
        ans++;
        sum += ans;
    }
    return ans;
}