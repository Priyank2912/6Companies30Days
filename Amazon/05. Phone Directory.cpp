vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    set<string> s;
    vector<vector<string>> ans(s.size());
    for (int i = 0; i < n; i++)
    {
        s.insert(contact[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (auto it : s)
        {
            if (s.substr(0, i + 1) == it.substr(0, i + 1))
            {
                ans[i].push_back(it);
            }
        }
        if (ans[i].size() == 0)
        {
            ans[i].push_back(to_string(0));
        }
    }
    return ans;
}