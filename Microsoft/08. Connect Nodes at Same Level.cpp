void connect(Node *A)
{
    if (!A)
        return;

    queue<Node *> q;

    q.push(A);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            if (i != n - 1)
            {
                t->nextRight = q.front();
            }
        }
    }
    return;
}