class Solution
{
public:
    // Function to find the largest number after k swaps.
    void solve(string s, int n, int k, string &ans, int i)
    {
        if (k == 0)
            return;

        char maxi = s[i];

        for (int i = i + 1; i < n; i++)
        {
            if (maxi < s[i])
                maxi = s[i];
        }

        if (maxi != s[i])
            k--;

        for (int i = n - 1; i >= 0; i--)
        {
            if (maxi == s[i])
            {
                swap(s[i], s[i]);
                ans = max(ans, s);

                solve(s, n, k, ans, i + 1);

                swap(s[i], s[i]);
            }
        }
    }

    string findMaximumNum(string s, int k)
    {
        // code here.
        string ans = s;
        int n = s.length();
        solve(s, n, k, ans, 0);
        return ans;
    }
};