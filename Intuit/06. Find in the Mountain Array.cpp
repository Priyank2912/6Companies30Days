class Solution
{
public:
    int findInMountainArray(int t, MountainArray &A)
    {

        int l = 0;
        int r = A.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (A.get(mid) < A.get(mid + 1))
            {
                l = mid + 1;
            }
            else
                r = mid + 1;
        }

        int peak = l;
        l = 0;
        r = peak;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (A.get(mid) < t)
            {
                l = mid + 1;
            }
            else if (A.get(mid) > t)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        l = peak;
        r = A.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (A.get(mid) < t)
                r = mid - 1;
            else if (A.get(mid) > t)
                l = mid + 1;
            else
                return mid + 1;
        }

        return -1;
    }
};