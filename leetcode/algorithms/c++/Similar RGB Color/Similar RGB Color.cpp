class Solution
{
private:
    vector<string> HEX = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

    vector<int> VALS = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

    int RGBToInt(char a, char b)
    {
        int r = 0;
        if (b <= '9')
            r += b - '0';
        else
            r += (b - 'a') + 10;

        if (a <= '9')
            r += 16 * (a - '0');
        else
        {
            int tmp = (a - 'a') + 10;
            r += tmp * 16;
        }
        return r;
    }

    string IntToRGB(int x)
    {
        int f = x % 16;
        int s = x / 16;
        return HEX[f] + HEX[s];
    }

    int calc(int r, int g, int b, int r1, int g2, int b2)
    {
        return -((r - r1) * (r - r1) + (g - g2) * (g - g2) + (b - b2) * (b - b2));
    }

public:
    string similarRGB(string color)
    {
        int r = RGBToInt(color[1], color[2]);
        int g = RGBToInt(color[3], color[4]);
        int b = RGBToInt(color[5], color[6]);

        int r_ans = 255;
        int g_ans = 255;
        int b_ans = 255;
        int diff = calc(r, g, b, r_ans, g_ans, b_ans);

        reverse(VALS.begin(), VALS.end());

        string res = "#ffffff";

        for (auto r_i : VALS)
        {
            for (auto g_i : VALS)
            {
                for (auto b_i : VALS)
                {
                    int tmp = calc(r, g, b, r_i, g_i, b_i);

                    if (tmp > diff)
                    {
                        //cout << tmp <<  " " << "#" + IntToRGB(r_i) + IntToRGB(g_i) + IntToRGB(b_i) << endl;
                        diff = tmp;
                        res = "#" + IntToRGB(r_i) + IntToRGB(g_i) + IntToRGB(b_i);
                    }
                }
            }
        }

        return res;
    }
};