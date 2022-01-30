class Solution
{
public:
    int height(int n)
    {
        return (sqrt(1 + 8 * n) - 1) / 2;
    }
};