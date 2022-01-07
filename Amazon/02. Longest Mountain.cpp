int longestMountain(vector<int> &A)
{

    int ans = 0, up = 0, down = 0;
    int n = A.size();
    for (int i = 1; i < A.size(); ++i)
    {
        if (down && A[i - 1] < A[i] || A[i - 1] == A[i])
        {
            up = 0;
            down = 0;
        }

        if (A[i - 1] < A[i])
            up++;
        if (A[i - 1] > A[i])
            down++;

        if (up != 0 && down != 0)
            ans = max(ans, up + down + 1);
    }

    return ans;
}