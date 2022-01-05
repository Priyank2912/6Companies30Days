string printMinNumberForPattern(string s)
{

    string ans = "";

    int i = 0;
    int cur = 1;
    int cnt = 0;
    while (i < s.length())
    {

        char ch = s[i];

        if (i == 0 && ch == 'I')
        {
            ans += to_string(cur);
            cur++;
        }

        if (ch == 'D')
        {
            cnt++;
        }

        int j = i + 1;
        while (j < s.length() && s[j] == 'D')
        {
            cnt++;
            j++;
        }

        int k = cnt;
        while (cnt >= 0)
        {
            ans += to_string(cur + cnt);
            cnt--;
        }

        cur += (k + 1);
        cnt = 0;
        i = j;
    }

    return ans;
}