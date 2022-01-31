class Solution
{
public:
    bool comp(auto a, auto b)
    {
        return a.first > b.second;
    }
    int maxPerformance(int n, vector<int> &a, vector<int> &b, int k)
    {

        vector<pair<int, int>> A;

        for (int i = 0; i < n; i++)
            A.push_back({b[i], a[i]});

        sort(A.begin(), A.end(), comp);

        priority_queue<int> q;
        long long speedd = 0, ans = 0;

        for (auto it : A)
        {
            speedd += it.second;

            q.push(-it.second);

            if (q.size() > k)
            {
                speedd -= abs(q.top());
                q.pop();
            }

            ans = max(ans, it.first * speedd);
        }

        return ans % 1000000007;
    }
};