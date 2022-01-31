class Solution
{
public:
    vector<int> recoverArray(int n, vector<int> &V)
    {
        vector<int> ans, A(move(V)), B;

        sort(A.begin(), A.end());

        while (A.size() > 1)
        {
            int d = A[1] - A[0], z = 0, i = 0;
            for (auto t = A.begin(), h = t; h != A.end(); ++h)
            {
                int s = *h;
                if (i != B.size() && B[i] == s)
                    ++i;
                else
                {
                    z += s == 0;
                    *t++ = s;
                    B.push_back(s + d);
                }
            }
            A.resize(B.size());

            if (z != 0)
                ans.push_back(d);

            else
            {
                ans.push_back(-d);
                swap(A, B);
            }
            B.clear();
        }
        return ans;
    }
};