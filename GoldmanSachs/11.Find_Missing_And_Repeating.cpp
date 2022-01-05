int *findTwoElement(int *A, int n)
{

    int xor1;
    int x = 0;
    int y = 0;

    xor1 = A[0];

    for (int i = 1; i < n; i++)
        xor1 = xor1 ^ A[i];

    for (int i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    int xr = xor1 & ~(xor1 - 1);

    for (int i = 0; i < n; i++)
    {
        if (A[i] & xr)

            xr = xr ^ A[i];

        else

            y = y ^ A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & x)

            x = x ^ i;

        else

            y = y ^ i;
    }

    static int b[5];
    b[0] = x;
    b[1] = y;
    bool che = false;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == b[1])
        {
            swap(b[0], b[1]);
            break;
        }
    }
    return b;
}