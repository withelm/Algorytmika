class Solution
{
private:
    map<string, int> datas;
    bool isInit = false;
    void init()
    {
        isInit = true;
        datas[""] = 0;
        datas["A"] = 1;
        datas["B"] = 2;
        datas["C"] = 3;
        datas["D"] = 4;
        datas["E"] = 5;
        datas["F"] = 6;
        datas["G"] = 7;
        datas["H"] = 8;
        datas["I"] = 9;
        datas["J"] = 10;
        datas["K"] = 11;
        datas["L"] = 12;
        datas["M"] = 13;
        datas["N"] = 14;
        datas["O"] = 15;
        datas["P"] = 16;
        datas["Q"] = 17;
        datas["R"] = 18;
        datas["S"] = 19;
        datas["T"] = 20;
        datas["U"] = 21;
        datas["V"] = 22;
        datas["W"] = 23;
        datas["X"] = 24;
        datas["Y"] = 25;
        datas["Z"] = 26;
        datas["AA"] = 27;
        datas["BA"] = 53;
        datas["CA"] = 79;
        datas["DA"] = 105;
        datas["EA"] = 131;
        datas["FA"] = 157;
        datas["GA"] = 183;
        datas["HA"] = 209;
        datas["IA"] = 235;
        datas["JA"] = 261;
        datas["KA"] = 287;
        datas["LA"] = 313;
        datas["MA"] = 339;
        datas["NA"] = 365;
        datas["OA"] = 391;
        datas["PA"] = 417;
        datas["QA"] = 443;
        datas["RA"] = 469;
        datas["SA"] = 495;
        datas["TA"] = 521;
        datas["UA"] = 547;
        datas["VA"] = 573;
        datas["WA"] = 599;
        datas["XA"] = 625;
        datas["YA"] = 651;
        datas["ZA"] = 677;
        datas["AAA"] = 703;
        datas["BAA"] = 1379;
        datas["CAA"] = 2055;
        datas["DAA"] = 2731;
        datas["EAA"] = 3407;
        datas["FAA"] = 4083;
        datas["GAA"] = 4759;
        datas["HAA"] = 5435;
        datas["IAA"] = 6111;
        datas["JAA"] = 6787;
        datas["KAA"] = 7463;
        datas["LAA"] = 8139;
        datas["MAA"] = 8815;
        datas["NAA"] = 9491;
        datas["OAA"] = 10167;
        datas["PAA"] = 10843;
        datas["QAA"] = 11519;
        datas["RAA"] = 12195;
        datas["SAA"] = 12871;
        datas["TAA"] = 13547;
        datas["UAA"] = 14223;
        datas["VAA"] = 14899;
        datas["WAA"] = 15575;
        datas["XAA"] = 16251;
        datas["YAA"] = 16927;
        datas["ZAA"] = 17603;
        datas["AAAA"] = 18279;
        datas["BAAA"] = 35855;
        datas["CAAA"] = 53431;
        datas["DAAA"] = 71007;
        datas["EAAA"] = 88583;
        datas["FAAA"] = 106159;
        datas["GAAA"] = 123735;
        datas["HAAA"] = 141311;
        datas["IAAA"] = 158887;
        datas["JAAA"] = 176463;
        datas["KAAA"] = 194039;
        datas["LAAA"] = 211615;
        datas["MAAA"] = 229191;
        datas["NAAA"] = 246767;
        datas["OAAA"] = 264343;
        datas["PAAA"] = 281919;
        datas["QAAA"] = 299495;
        datas["RAAA"] = 317071;
        datas["SAAA"] = 334647;
        datas["TAAA"] = 352223;
        datas["UAAA"] = 369799;
        datas["VAAA"] = 387375;
        datas["WAAA"] = 404951;
        datas["XAAA"] = 422527;
        datas["YAAA"] = 440103;
        datas["ZAAA"] = 457679;
        datas["AAAAA"] = 475255;
        datas["BAAAA"] = 932231;
        datas["CAAAA"] = 1389207;
        datas["DAAAA"] = 1846183;
        datas["EAAAA"] = 2303159;
        datas["FAAAA"] = 2760135;
        datas["GAAAA"] = 3217111;
        datas["HAAAA"] = 3674087;
        datas["IAAAA"] = 4131063;
        datas["JAAAA"] = 4588039;
        datas["KAAAA"] = 5045015;
        datas["LAAAA"] = 5501991;
        datas["MAAAA"] = 5958967;
        datas["NAAAA"] = 6415943;
        datas["OAAAA"] = 6872919;
        datas["PAAAA"] = 7329895;
        datas["QAAAA"] = 7786871;
        datas["RAAAA"] = 8243847;
        datas["SAAAA"] = 8700823;
        datas["TAAAA"] = 9157799;
        datas["UAAAA"] = 9614775;
        datas["VAAAA"] = 10071751;
        datas["WAAAA"] = 10528727;
        datas["XAAAA"] = 10985703;
        datas["YAAAA"] = 11442679;
        datas["ZAAAA"] = 11899655;
        datas["AAAAAA"] = 12356631;
        datas["BAAAAA"] = 24238007;
        datas["CAAAAA"] = 36119383;
        datas["DAAAAA"] = 48000759;
        datas["EAAAAA"] = 59882135;
        datas["FAAAAA"] = 71763511;
        datas["GAAAAA"] = 83644887;
        datas["HAAAAA"] = 95526263;
        datas["IAAAAA"] = 107407639;
        datas["JAAAAA"] = 119289015;
        datas["KAAAAA"] = 131170391;
        datas["LAAAAA"] = 143051767;
        datas["MAAAAA"] = 154933143;
        datas["NAAAAA"] = 166814519;
        datas["OAAAAA"] = 178695895;
        datas["PAAAAA"] = 190577271;
        datas["QAAAAA"] = 202458647;
        datas["RAAAAA"] = 214340023;
        datas["SAAAAA"] = 226221399;
        datas["TAAAAA"] = 238102775;
        datas["UAAAAA"] = 249984151;
        datas["VAAAAA"] = 261865527;
        datas["WAAAAA"] = 273746903;
        datas["XAAAAA"] = 285628279;
        datas["YAAAAA"] = 297509655;
        datas["ZAAAAA"] = 309391031;
        datas["AAAAAAA"] = 321272407;
        datas["BAAAAAA"] = 630188183;
        datas["CAAAAAA"] = 939103959;
        datas["DAAAAAA"] = 1248019735;
        datas["EAAAAAA"] = 1556935511;
        datas["FAAAAAA"] = 1865851287;
    }

public:
    int titleToNumber(string s)
    {
        if (!isInit)
            init();

        int result = 0;
        while (s != "")
        {
            string tmp = s;
            string tmp2;
            for (int i = 1; i < tmp.size(); i++)
            {
                tmp[i] = 'A';
                tmp2.push_back('A');
            }
            result += datas[tmp] - datas[tmp2];
            s.erase(0, 1);
        }
        return result;
    }
};
