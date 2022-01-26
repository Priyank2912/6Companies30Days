int missingNumber(const string &s)
{

    /* VERY IMP QUES!!!!*/
    int len = s.size();
    int max_window = min(6, len / 2);

    for (int w = 1; w <= max_window; ++w)
    {
        int last_num = 0;
        int num = 0;
        bool malyu = true;
        bool gayu = false;
        int ans = -1;

        for (int i = 0; i < w; ++i)
        {
            last_num = last_num * 10 + s[i] - '0';
        }

        int window_size = (int)log10(last_num + 1) + 1;

        for (int d = w; d < len; d += window_size)
        {
            window_size = (int)log10(last_num + 1) + 1;
            num = 0;
            for (int i = 0; i < window_size; ++i)
            {
                num = num * 10 + s[d + i] - '0';
            }

            if (num != last_num + 1 && (int)log10(last_num + 1) < (int)log10(last_num + 2))
            {
                num = 0;
                window_size = (int)log10(last_num + 2) + 1;
                for (int i = 0; i < window_size; ++i)
                {
                    num = num * 10 + s[d + i] - '0';
                }
            }

            if (num == last_num + 2)
            {
                if (malyu)
                {
                    malyu = false;
                    gayu = true;
                    ans = last_num + 1;
                }
                else
                {
                    gayu = false;
                    break;
                }
            }
            else if (num != last_num + 1)
            {
                gayu = false;
                break;
            }
            last_num = num;
        }

        if (gayu)
        {
            return ans;
        }
    }

    return -1;
}