vector<vector<char>> keypad =
    {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}};

vector<string> ans;
void geti(int A[], string res, int index, int n)
{

    if (index == n)
    {
        ans.push_back(res);
        return;
    }

    int digit = A[index];

    int l = keypad[digit].size();

    for (int i = 0; i < l; i++)
    {
        geti A, res + keypad[digit][i], index + 1, n);
    }
}

vector<string> possibleWords(int a[], int n)
{
    string y = "";
    geti(a, y, 0, n);
    return ans;
}