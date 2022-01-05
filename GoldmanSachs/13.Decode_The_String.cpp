string decodedString(string s)
{

    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ']')
        {
            string a;
            while (!st.empty() && st.top() != '[')
            {
                a = st.top() + a;
                st.pop();
            }

            st.pop();
            string num;

            while (!st.empty() && (st.top() >= '0' && st.top() <= '9'))
            {
                num += st.top();
                st.pop();
            }

            reverse(num.begin(), num.end());
            int number = stoi(num);

            string t;
            for (int j = 0; j < number; j++)
                t += a;
            for (char c : t)
                st.push(c);
        }
        else
            st.push(s[i]);
    }
    string ans;
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}