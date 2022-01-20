pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int maxi = 0;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], {i, 0}});

        maxi = max(maxi, arr[i][0]);
    }

    pair<int, pair<int, int>> minRange = {maxi - pq.top().first, {maxi, pq.top().first}};

    while (pq.size() == k)
    {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int curRow = curr.second.first;
        int curCol = curr.second.second;

        if (curCol + 1 < n)
        {
            pq.push({arr[curRow][curCol + 1], {curRow, curCol + 1}});
            maxi = max(maxi, arr[curRow][curCol + 1]);

            if (maxi - pq.top().first < minRange.first)
            {
                minRange = {maxi - pq.top().first, {maxi, pq.top().first}};
            }
        }
    }

    return {minRange.second.second, minRange.second.first};
}