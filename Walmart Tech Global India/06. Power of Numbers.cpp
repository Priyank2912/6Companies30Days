class Solution
{
public:
    long long mfastPower(long long a, long long b, long long c)
    {
        long long ans = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                ans = ((ans % c) * (a % c) % c);
            }
            a = ((a % c) * (a % c)) % c;
            b = b >> 1;
        }

        return ans;
    }

    long long power(int N, int R)
    {

        return mfastPower(N, R, 1000000007);
    }
};
