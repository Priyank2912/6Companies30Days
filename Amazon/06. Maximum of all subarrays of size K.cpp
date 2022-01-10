vector<int> max_of_subarrays(int *A, int n, int k)
{

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && q.front() == i - k)
            q.pop_front();

        while (!q.empty() && A[q.back()] < A[i])
            q.pop_back();

        q.push_back(i);

        if (i >= k - 1)
            ans.push_back(A[q.front()]);
    }

    return ans;
}