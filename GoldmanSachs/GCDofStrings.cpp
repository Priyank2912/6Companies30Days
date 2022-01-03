class Solution
{
public:
    string gcdOfStrings(string a, string b)
    {

        if (a.size() > b.size())
        {
            swap(a, b);
        }

        for (int i = a.size(); i >= 1; i--)
        {

            if (a.size() % i != 0)
                continue;
            if (b.size() % i != 0)
                continue;

            string s = a.substr(0, i);
            bool che = true;

            for (int j = 0; j < a.size(); j += i)
            {
                if (a.substr(j, i) != s)
                {
                    che = false;
                    break;
                }
            }

            if (!che)
                continue;

            for (int j = 0; j < b.size(); j += i)
            {
                if (b.substr(j, i) != s)
                {
                    che = false;
                    break;
                }
            }

            if (!che)
                continue;

            return s;
        }
        return "";
    }
};