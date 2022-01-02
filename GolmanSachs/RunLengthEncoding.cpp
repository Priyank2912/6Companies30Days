string encode(string src)
{

    int s = 1;

    int n = src.size();
    string ans = "";
    char c = src[0];
    for (int i = 1; i < n; i++)
    {
        if (src[i] == c)
            s++;
        else
        {
            ans += c;
            ans += to_string(s);
            s = 1;
            c = src[i];
        }
    }
    ans += c;
    ans += to_string(s);
    return ans;
}