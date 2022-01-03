int minSubArrayLen(int target, vector<int> &nums)
{

    int n = nums.size();
    int i = 0, j = 0;
    int sumi = 0;
    int ans = INT_MAX;

    while (j < n)
    {
        sumi += nums[j];
        while (i != j && sumi - nums[i] >= target)
        {
            sumi -= nums[i];
            i++;
        }
        if (sumi >= target)
        {
            ans = min(ans, j - i + 1);
        }
        j++;
    }
    // if(sumi>=target)ans=min(ans,j-i+1);
    if (ans == INT_MAX)
        return 0;
    return ans;
}