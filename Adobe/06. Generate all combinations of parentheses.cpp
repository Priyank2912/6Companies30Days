vector<string> ans;

void geti(string s, int c, int r, int n)
{
    if (n == c && r == 0)
        ans.push_back(s);

    if (c < n)
        geti(s + '(', c + 1, r + 1, n);
    if (r > 0)
        geti(s + ')', c, r - 1, n);
}

vector<string> AllParenthesis(int n)
{

    string s = "";
    geti(s, 0, 0, n);
    return ans;
}