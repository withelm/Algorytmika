class Solution
{
private:
    vector<unsigned long long int> t;
    int n = 71 + 1;
    void init()
    {
        t.resize(n);
        t[1] = 0;
        t[2] = 1;
        t[3] = 4;
        t[4] = 9;
        t[5] = 121;
        t[6] = 484;
        t[7] = 10201;
        t[8] = 12321;
        t[9] = 14641;
        t[10] = 40804;
        t[11] = 44944;
        t[12] = 1002001;
        t[13] = 1234321;
        t[14] = 4008004;
        t[15] = 100020001;
        t[16] = 102030201;
        t[17] = 104060401;
        t[18] = 121242121;
        t[19] = 123454321;
        t[20] = 125686521;
        t[21] = 400080004;
        t[22] = 404090404;
        t[23] = 10000200001;
        t[24] = 10221412201;
        t[25] = 12102420121;
        t[26] = 12345654321;
        t[27] = 40000800004;
        t[28] = 1000002000001;
        t[29] = 1002003002001;
        t[30] = 1004006004001;
        t[31] = 1020304030201;
        t[32] = 1022325232201;
        t[33] = 1024348434201;
        t[34] = 1210024200121;
        t[35] = 1212225222121;
        t[36] = 1214428244121;
        t[37] = 1232346432321;
        t[38] = 1234567654321;
        t[39] = 4000008000004;
        t[40] = 4004009004004;
        t[41] = 100000020000001;
        t[42] = 100220141022001;
        t[43] = 102012040210201;
        t[44] = 102234363432201;
        t[45] = 121000242000121;
        t[46] = 121242363242121;
        t[47] = 123212464212321;
        t[48] = 123456787654321;
        t[49] = 400000080000004;
        t[50] = 10000000200000001;
        t[51] = 10002000300020001;
        t[52] = 10004000600040001;
        t[53] = 10020210401202001;
        t[54] = 10022212521222001;
        t[55] = 10024214841242001;
        t[56] = 10201020402010201;
        t[57] = 10203040504030201;
        t[58] = 10205060806050201;
        t[59] = 10221432623412201;
        t[60] = 10223454745432201;
        t[61] = 12100002420000121;
        t[62] = 12102202520220121;
        t[63] = 12104402820440121;
        t[64] = 12122232623222121;
        t[65] = 12124434743442121;
        t[66] = 12321024642012321;
        t[67] = 12323244744232321;
        t[68] = 12343456865434321;
        t[69] = 12345678987654321;
        t[70] = 40000000800000004;
        t[71] = 40004000900040004;
    }

public:
    unsigned long long int convert(string x)
    {
        unsigned long long int result = 0;
        for (auto &i : x)
        {
            result = result * 10 + (i - '0');
        }
        return result;
    }

    int superpalindromesInRange(string left, string right)
    {
        int res = 0;
        auto l = convert(left);
        auto r = convert(right);
        init();
        for (int i = 1; i < n; i++)
        {
            res += t[i] >= l && t[i] <= r;
        }
        return res;
    }
};