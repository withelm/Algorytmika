class Solution
{
private:
    map<int, string> base;
    vector<string> t = {"", "Thousand", "Million", "Billion"};
    void init()
    {

        base[1] = "One";
        base[2] = "Two";
        base[3] = "Three";
        base[4] = "Four";
        base[5] = "Five";
        base[6] = "Six";
        base[7] = "Seven";
        base[8] = "Eight";
        base[9] = "Nine";
        base[10] = "Ten";
        base[11] = "Eleven";
        base[12] = "Twelve";
        base[13] = "Thirteen";
        base[14] = "Fourteen";
        base[15] = "Fifteen";
        base[16] = "Sixteen";
        base[17] = "Seventeen";
        base[18] = "Eighteen";
        base[19] = "Nineteen";
        base[20] = "Twenty";
        base[21] = "Twenty One";
        base[22] = "Twenty Two";
        base[23] = "Twenty Three";
        base[24] = "Twenty Four";
        base[25] = "Twenty Five";
        base[26] = "Twenty Six";
        base[27] = "Twenty Seven";
        base[28] = "Twenty Eight";
        base[29] = "Twenty Nine";
        base[30] = "Thirty";
        base[31] = "Thirty One";
        base[32] = "Thirty Two";
        base[33] = "Thirty Three";
        base[34] = "Thirty Four";
        base[35] = "Thirty Five";
        base[36] = "Thirty Six";
        base[37] = "Thirty Seven";
        base[38] = "Thirty Eight";
        base[39] = "Thirty Nine";
        base[40] = "Forty";
        base[41] = "Forty One";
        base[42] = "Forty Two";
        base[43] = "Forty Three";
        base[44] = "Forty Four";
        base[45] = "Forty Five";
        base[46] = "Forty Six";
        base[47] = "Forty Seven";
        base[48] = "Forty Eight";
        base[49] = "Forty Nine";
        base[50] = "Fifty";
        base[51] = "Fifty One";
        base[52] = "Fifty Two";
        base[53] = "Fifty Three";
        base[54] = "Fifty Four";
        base[55] = "Fifty Five";
        base[56] = "Fifty Six";
        base[57] = "Fifty Seven";
        base[58] = "Fifty Eight";
        base[59] = "Fifty Nine";
        base[60] = "Sixty";
        base[61] = "Sixty One";
        base[62] = "Sixty Two";
        base[63] = "Sixty Three";
        base[64] = "Sixty Four";
        base[65] = "Sixty Five";
        base[66] = "Sixty Six";
        base[67] = "Sixty Seven";
        base[68] = "Sixty Eight";
        base[69] = "Sixty Nine";
        base[70] = "Seventy";
        base[71] = "Seventy One";
        base[72] = "Seventy Two";
        base[73] = "Seventy Three";
        base[74] = "Seventy Four";
        base[75] = "Seventy Five";
        base[76] = "Seventy Six";
        base[77] = "Seventy Seven";
        base[78] = "Seventy Eight";
        base[79] = "Seventy Nine";
        base[80] = "Eighty";
        base[81] = "Eighty One";
        base[82] = "Eighty Two";
        base[83] = "Eighty Three";
        base[84] = "Eighty Four";
        base[85] = "Eighty Five";
        base[86] = "Eighty Six";
        base[87] = "Eighty Seven";
        base[88] = "Eighty Eight";
        base[89] = "Eighty Nine";
        base[90] = "Ninety";
        base[91] = "Ninety One";
        base[92] = "Ninety Two";
        base[93] = "Ninety Three";
        base[94] = "Ninety Four";
        base[95] = "Ninety Five";
        base[96] = "Ninety Six";
        base[97] = "Ninety Seven";
        base[98] = "Ninety Eight";
        base[99] = "Ninety Nine";
    }

public:
    string numberToWords(int num)
    {
        init();
        if (num == 0)
            return "Zero";

        string r = "";
        int index = 0;
        while (num > 0)
        {
            int val = num % 1000;
            string v = "";
            if (val / 100 != 0)
            {
                v = base[val / 100] + " " + "Hundred";
            }
            if (val % 100 != 0)
            {
                if (v.size() > 0)
                    v = v + " " + base[val % 100];
                else
                    v = base[val];
            }
            if (v.size() > 0 && t[index].size() > 0)
            {
                v = v + " " + t[index];
            }
            ++index;
            if (r.size() == 0)
                r = v;
            else
            {
                if (v.size() > 0)
                    r = v + " " + r;
            }

            num /= 1000;
        }
        return r;
    }
};