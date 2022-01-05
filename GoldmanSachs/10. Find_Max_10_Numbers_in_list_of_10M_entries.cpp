vector<int> solve()
{

    priority_queue<int, vector<int>, greater<int>> q;

    ll n;
    while (cin >> n)
    {
        if (q.size() < 10)
        {
            q.push(n);
        }
        else
        {
            int h = q.top();
            if (n > h)
            {
                q.pop();
                q.push(n);
            }
        }
    }

    vector<int> ans;

    while (!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}