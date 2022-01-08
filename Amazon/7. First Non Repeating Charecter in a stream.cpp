string FirstNonRepeating(string str)
{

    queue<char> q;
    string ans = "";
    int charCount[26] = {0};

    for (int i = 0; str[i]; i++)
    {

        q.push(str[i]);

        charCount[str[i] - 'a']++;
        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                ans += q.front();
                break;
            }
        }

        if (q.empty())
            ans += '#';
    }
    return ans;
}