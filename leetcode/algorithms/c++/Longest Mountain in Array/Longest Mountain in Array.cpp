class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int res = 0;
        bool isUp = false;
        bool isDown = false;
        bool isStart = false;
        int n = A.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // cout << i << " " << isUp << " " << isDown << " " << isStart << " " << cnt << endl;
            if (!isStart)
            {
                if (A[i] < A[i + 1])
                {
                    isStart = true;
                    isUp = true;
                    isDown = false;
                    cnt = 1;
                    continue;
                }
            }
            else
            {
                if (isUp)
                {
                    if (A[i] < A[i + 1])
                    {
                        ++cnt;
                        continue;
                    }
                    else if (A[i] == A[i + 1])
                    {
                        isStart = false;
                        isUp = false;
                        isDown = false;
                        cnt = 0;
                        continue;
                    }
                    else
                    {
                        isUp = false;
                        isDown = true;
                        ++cnt;
                        continue;
                    }
                }
                if (isDown)
                {
                    if (A[i] > A[i + 1])
                    {
                        ++cnt;
                        res = max(res, cnt);
                        continue;
                    }
                    else if (A[i] == A[i + 1])
                    {
                        isStart = false;
                        isUp = false;
                        isDown = false;
                        res = max(res, cnt + 1);
                        cnt = 0;
                        continue;
                    }
                    else
                    {
                        isStart = true;
                        isUp = true;
                        isDown = false;
                        res = max(res, cnt + 1);
                        cnt = 1;
                        continue;
                    }
                }
            }
        }
        // cout << n << " " << isUp << " " << isDown << " " << isStart << " " << cnt << endl;
        if (isStart && isDown)
            res = max(res, cnt + 1);
        return res;
    }
};