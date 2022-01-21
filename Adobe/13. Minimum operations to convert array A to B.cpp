int minInsAndDel(int A[], int B[], int N, int M)
{

    vector<int> ans;
    unordered_set<int> set;

    for (int i = 0; i < M; i++)
    {
        set.insert(B[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (set.find(A[i]) != set.end())
        {
            auto x = lower_bound(ans.begin(), ans.end(), A[i]);

            if (x == ans.end())
                ans.push_back(A[i]);
            else
                *x = A[i];
        }
    }
    return (N + M - 2 * ans.size());
}