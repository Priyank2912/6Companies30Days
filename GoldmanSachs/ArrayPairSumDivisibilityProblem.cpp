bool canPair(vector<int> nums, int k)
{

    unordered_map<int, int> m;

    for (auto g : nums)
    {

        if (g % k == 0)
        {
            if (m[0] == 0)
                m[0]++;
            else
                m[0]--;
        }
        else if (m[k - g % k] != 0)
        {
            m[k - g % k]--;
        }
        else
            m[g % k]++;
    }

    for (auto g : m)
    {
        if (g.second != 0)
            return false;
    }
    return true;
}