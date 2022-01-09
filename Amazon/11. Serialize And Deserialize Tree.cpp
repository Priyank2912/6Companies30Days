void get(Node *A, vector<int> &ans)
{
    if (!A)
        return;
    get(A->left, ans);
    ans.push_back(A->data);
    get(A->right, ans);
}

vector<int> serialize(Node *root)
{
    vector<int> ans;
    get(root, ans);
    return ans;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &A)
{

    stack<Node *> s;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (s.size() < 2)
        {
            Node *t = new Node(A[i]);
            s.push(t);
        }
        else
        {
            Node *y = s.top();
            s.pop();
            Node *t = new Node(A[i]);
            Node *r = s.top();
            s.pop();
            y->left = r;
            y->right = t;
            s.push(y);
        }
    }

    if (s.size() > 1)
    {
        if (s.size() == 2)
        {
            Node *r = s.top();
            s.pop();
            Node *t = s.top();
            r->left = t;
            return r;
        }
        else
        {
            Node *r = s.top();
            s.pop();
            Node *t = s.top();
            r->left = t;
            s.pop();
            Node *q = s.top();
            r->right = q;
            return r;
        }
    }
    return s.top();
}