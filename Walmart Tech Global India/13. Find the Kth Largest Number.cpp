class Solution
{
public:
    struct cmp
    {
        bool operator()(string a, string b)
        {
            if (a.length() != b.length())
                return a.length() > b.length();
            return a > b;
        }
    };

    string kthLargestNumber(vector<string> &A, int k)
    {

        int n = A.size();
        priority_queue<string, vector<string>, cmp> q;

        for (int i = 0; i < n; i++)
        {
            q.push(A[i]);

            if (q.size() > k)
                q.pop();
        }

        return q.top();
    }
};