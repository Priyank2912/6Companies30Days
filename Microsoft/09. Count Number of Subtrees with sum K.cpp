void geti(Node *A, int x, int &ans)
{
    if (!A)
        return;
    geti(A->left, x, ans);
    geti(A->right, x, ans);

    if (A->left)
        A->data += A->left->data;
    if (A->right)
        A->data += A->right->data;
    if (A->data == x)
        ans++;
}

int countSubtreesWithSumX(Node *root, int X)
{
    int ans = 0;
    geti(root, X, ans);
    return ans;
}