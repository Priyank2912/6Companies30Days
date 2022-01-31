class Solution
{
public:
    bool winnerOfGame(string A)
    {

        int n = A.size();
        if (n < 3)
            return false;

        int A = 0, B = 0, che = 0, gayu = 0;
        vector<int> v;
        int end_a = -1, end_b = -1;

        if (A[0] == 'A')
            che = true;
        else
            gayu = true;

        for (int i = 0; i < n;)
        {
            while (i < n && A[i] == 'A')
            {
                A++;
                i++;
            }
            if (A)
                v.push_back(A);
            A = 0;

            while (i < n && A[i] == 'B')
            {
                B++;
                i++;
            }
            if (B)
                v.push_back(B);
            B = 0;
        }

        int size = v.size();
        int c = 1, start;

        while (1)
        {
            if (c == 1)
            {
                if (che == 1)
                    start = 0;
                else
                    start = 1;

                if (end_a != -1)
                    start = end_a;
                for (int i = start; i < size; i += 2)
                {
                    if (v[i] > 2)
                    {
                        v[i] -= 1;
                        c = 0;
                        end_a = i;
                        break;
                    }
                }
                if (c)
                {
                    return false;
                }
            }
            else
            {
                if (che == 1)
                    start = 1;
                else
                    start = 0;

                if (end_b != -1)
                    start = end_b;
                for (int i = start; i < size; i += 2)
                {
                    if (v[i] > 2)
                    {
                        v[i] -= 1;
                        c = 1;
                        end_b = i;
                        break;
                    }
                }
                if (c == 0)
                    return true;
            }
        }
        return false;
    }
};