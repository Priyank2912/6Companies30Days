class Solution
{
public:
    int minSwaps(vector<vector<int>> &A)
    {
        int n = A.size();
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (A[i][j] != 0)
                {
                    break;
                }
                count++;
            }
            a[i] = count;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++)
        {
            int req_trailing_zero = (n - 1) - i;

            if (a[i] >= req_trailing_zero)
            {
                continue;
            }
            int val = a[i];
            int j = i + 1;
            while (j < n)
            {
                swap(val, a[j]);
                if (val >= req_trailing_zero)
                {
                    break;
                }
                j++;
            }

            if (j == n)
            {
                return -1;
            }
            swaps += (j - i);
            a[i] = val;
        }

        return swaps;
    }
};