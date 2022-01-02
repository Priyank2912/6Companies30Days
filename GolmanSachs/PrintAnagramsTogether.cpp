
vector<vector<string>> Anagrams(vector<string> &A)
{

    vector<vector<string>> ans;

    unordered_map<string, vector<string>> m;

    for (auto h : A)
    {
        string f = h;
        sort(f.begin(), f.end());
        m[f].push_back(h);
    }
    for (auto y : m)
        ans.push_back(y.second);

    return ans;
}
