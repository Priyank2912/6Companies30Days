class Solution
{
public:
    bool che(int mid, vector<int> &A, int h)
    {
        int x = 0;
        for (auto g : A)
        {
            if (g % mid)
                x += g / mid + 1;
            else
                x += g / mid;
        }
        return x <= h;
    }

    int minEatingSpeed(vector<int> &A, int h)
    {

        int ans = 0;
        int l = 1, r = INT_MIN;
        for (auto g : A)
            r = max(r, g);

        while (l <= r)
        {
            int mid = r - (r - l) / 2;
            if (che(mid, A, h))
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