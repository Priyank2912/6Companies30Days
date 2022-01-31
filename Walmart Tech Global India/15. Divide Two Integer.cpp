class Solution
{
public:
    int divide(int a, int b)
    {
        if (a == 0)
            return 0;
        if (b == 1)
            return a;
        if (b == -1)
            return a == INT_MIN ? INT_MAX : 0 - a;

        bool che = (a < 0) ^ (b < 0);

        int cnt = 0;
        long long a = abs(a);
        long long b = abs(b);
        int ct = 1;

        while (b <= a)
        {
            cnt += ct;
            a = a - b;
            b = b << 1;
            ct = ct << 1;
        }

        b = abs(b);
        while (b <= a)
        {
            cnt++;
            a -= b;
        }
        return che ? 0 - cnt : cnt;
    }