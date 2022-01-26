class Solution
{
public:
    bool che(int mid, vector<int> &A, int t)
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
        if (c == t)
            return true;
        return false;
    }

    int splitArray(vector<int> &A, int t)
    {

        int ans = -1;
        int l = INT_MAX, r = 0;

        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        for (auto h : A)
        {
            r += h;
            l = min(l, h);
        }

        while (l <= r)
        {
            int mid = r - (r - l) / 2;

            if (che(mid, A, t))
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