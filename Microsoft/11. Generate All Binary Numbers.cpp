vector<string> generate(int N)
{
    vector<string> ans;
    for (int i = 1; i <= N; i++)
    {
        string s = "";
        int k = i;
        while (k)
        {

            if (k & 1)
                s += '1';
            else
                s += '0';
            k = k / 2;
        }
        reverse(s.begin(), s.end());
        ans.push_back(s);
    }
    return ans;
}
