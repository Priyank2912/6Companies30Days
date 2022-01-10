int minTime(Node *A, int target)
{

    unordered_map<Node *, int> mp1;
    unordered_map<Node *, Node *> mp2;

    queue<Node *> q;
    q.push(A);
    Node *t = NULL;

    mp2.insert({A, A});
    mp1.insert({A, 0});
    while (!q.empty())
    {
        int n1 = q.size();
        while (n1)
        {
            Node *k = q.front();
            if (k->data == target)
            {
                t = k;
            }
            if (k->left)
            {
                Node *k1 = k->left;
                mp2.insert({k1, k});
                mp1.insert({k1, 0});
                q.push(k->left);
            }
            if (k->right)
            {
                Node *k1 = k->right;
                mp2.insert({k1, k});
                mp1.insert({k1, 0});
                q.push(k->right);
            }
            q.pop();
            n1--;
        }
    }

    q.push(t);

    int cnt = 0;
    while (!q.empty())
    {
        int n1 = q.size();
        // cout<<i<<endl;
        while (n1)
        {
            Node *k = q.front();

            if (mp1[k] == 0)
            {

                if (k->left && !mp1[k->left])
                {
                    q.push(k->left);
                }
                if (k->right && !mp1[k->right])
                {
                    q.push(k->right);
                }
                if (mp2[k] != k && !mp1[mp2[k]])
                {
                    q.push(mp2[k]);
                }
            }
            mp1[k] = 1;
            q.pop();
            n1--;
        }
        cnt++;
    }
    cnt--;
    return cnt;
}