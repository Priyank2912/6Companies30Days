vector<string> winner(string arr[], int n)
{

    unordered_map<string, int> mp;
    for (int j = 0; j < n; j++)
        mp[arr[j]]++;
    string ans = "";
    int c = 0;
    for (auto g : mp)
    {
        if (g.second > c)
        {

            ans = g.first;
            c = g.second;
        }
        else if (g.second == c)
        {

            if (g.first < ans)
            {
                ans = g.first;
                c = g.second;
            }
        }
    }

    return {ans, to_string(c)};
}