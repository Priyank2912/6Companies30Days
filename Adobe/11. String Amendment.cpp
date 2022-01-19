string amendSentence(string s)
{
    string ans = "";
    string h = "";

    for (auto g : s)
    {
        if (g >= 'A' && g <= 'Z')
        {
            if (h != "")
            {
                ans += h;
                ans += " ";
            }
            h = "";
            h += tolower(g);
        }
        else
            h += g;
    }
    ans += h;
    return ans;
}