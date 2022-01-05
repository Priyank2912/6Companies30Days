long long squaresInChessBoard(long long N)
{

    long long n = 0;
    n = N * (N + 1) * (2 * N + 1) / 6;
    return n;
}