class Solution
{
public:
    bool che(int mid, vector<int> &A, int m)
    {
        int q = 0;
        int c = 1;

        for (auto y : A)
        {
            if (q + y <= mid)
                q += y;
            else
            {
                c++;
                q = y;
            }
        }
        // cout << c << " " << q << endl;
        if (c == m)
            return true;
        return false;
    }

    int splitArray(vector<int> &nums, int m)
    {

        int ans = -1;
        int l = INT_MAX, r = 0;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        for (auto h : nums)
        {
            r += h;
            l = min(l, h);
        }

        while (l <= r)
        {
            int mid = r - (r - l) / 2;

            if (che(mid, nums, m))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};