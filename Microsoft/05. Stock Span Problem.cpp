vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans(n);
    stack<pair<int, int>> st;
    //   ans[0]=1;
    //   st.push({price[0],0});
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first <= price[i])
        {
            st.pop();
            //   c=st.top().second;
        }
        if (st.empty())
            ans[i] = i + 1;
        else
            ans[i] = abs(st.top().second - i);

        st.push({price[i], i});
    }
    return ans;
}