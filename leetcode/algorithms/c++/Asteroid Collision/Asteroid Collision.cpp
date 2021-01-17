class Solution
{
private:
    bool run(vector<int> &asteroids)
    {
        int index = 0;
        bool r = false;
        while (index < asteroids.size())
        {
            if (index + 1 < asteroids.size())
            {
                //cout << asteroids[index] << " " << asteroids[index + 1] << endl;
                if (asteroids[index] > 0 && asteroids[index + 1] < 0)
                {
                    if (asteroids[index] == -asteroids[index + 1])
                    {
                        asteroids.erase(asteroids.begin() + index);
                        asteroids.erase(asteroids.begin() + index);
                        r = true;
                        continue;
                    }
                    if (asteroids[index] < -asteroids[index + 1])
                    {
                        asteroids.erase(asteroids.begin() + index);
                        r = true;
                        continue;
                    }
                    if (asteroids[index] > -asteroids[index + 1])
                    {
                        asteroids.erase(asteroids.begin() + index + 1);
                        r = true;
                        continue;
                    }
                }
            }
            ++index;
        }
        return r;
    }

public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        while (run(asteroids))
            ;
        return asteroids;
    }
};