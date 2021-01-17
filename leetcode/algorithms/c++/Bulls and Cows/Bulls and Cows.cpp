class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                ++bull;
                secret[i] = 1;
                guess[i] = 2;
            }
        }
        vector<int> kub(300, 0);
        vector<int> kub2(300, 0);
        for (int i = 0; i < secret.size(); i++)
            ++kub[secret[i]];
        for (int i = 0; i < guess.size(); i++)
            ++kub2[guess[i]];
        for (int i = 0; i < 300; i++)
        {
            cow += min(kub[i], kub2[i]);
        }
        string result = "";
        result += to_string(bull);
        result += 'A';
        result += to_string(cow);
        result += 'B';
        return result;
    }
};