class Solution
{
public:
    vector<int> find3Numbers(vector<int> A, int n)
    {

        vector<int> v(n);
        v[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            v[i] = min(A[i], v[i - 1]);
        }

        vector<int> mx(n);
        mx[n - 1] = A[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            mx[i] = max(A[i], mx[i + 1]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > v[i] && A[i] < mx[i])
            {
                ans.push_back(v[i]);
                ans.push_back(A[i]);
                ans.push_back(mx[i]);
                return ans;
            }
        }
        return ans;
    }
};