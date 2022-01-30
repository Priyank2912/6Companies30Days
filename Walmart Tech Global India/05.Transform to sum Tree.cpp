class Solution
{
public:
    int geti(Node *A)
    {
        if (!A)
            return 0;

        int l = geti(A->l);
        int r = geti(A->r);

        int temp = A->data;
        A->data = l + r;

        return temp + A->data;
    }
    void toSumTree(Node *A)
    {

        geti(A);
    }
}