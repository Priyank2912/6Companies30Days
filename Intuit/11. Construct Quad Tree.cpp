class Solution
{
public:
    Node *geti(vector<vector<int>> &A, int a, int b, int c, int d, int factor)
    {
        int sum = 0;
        for (int i = a; i < b; i++)
        {
            for (int j = c; j < d; j++)
            {
                sum += A[i][j];
            }
        }

        Node *dp;

        if (sum == 0)
            dp = new Node(false, true);

        else if (sum == (factor * factor))

            dp = new Node(true, true);

        else
        {
            dp = new Node(false, false);
            factor /= 2;

            dp->topLeft = geti(A, a, a + factor, c, c + factor, factor);

            dp->topRight = geti(A, a, a + factor, c + factor, d, factor);

            dp->bottomLeft = geti(A, a + factor, b, c, c + factor, factor);

            dp->bottomRight = geti(A, a + factor, b, c + factor, d, factor);
        }
        return dp;
    }

    Node *construct(vector<vector<int>> &A)
    {
        int n = A.size();
        if (n == 0)
            return NULL;
        Node *ans;
        ans = geti(A, 0, n, 0, n, n);
        return ans;
    }
};