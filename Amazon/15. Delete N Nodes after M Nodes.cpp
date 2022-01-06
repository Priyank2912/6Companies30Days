void linkdelete(struct Node *head, int M, int N)
{

    Node *prev = head, *t;
    int count = 1;

    while (prev)
    {
        for (count = 1; count < M && prev; count++)
            prev = prev->next;

        if (prev == NULL)
            return;

        t = prev->next;
        for (count = 1; count <= N && t; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }

        prev->next = t;
        prev = t;
    }
}