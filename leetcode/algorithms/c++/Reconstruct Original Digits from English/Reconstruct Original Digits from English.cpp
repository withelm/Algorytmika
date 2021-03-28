class Solution
{
private:
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> kub;
    vector<int> result;

    void remove(int x)
    {
        int val = result[x];
        for (auto &x : numbers[x])
            kub[x] -= val;
    }

public:
    string originalDigits(string s)
    {
        kub.resize(255);
        result.resize(10);
        for (auto &x : s)
            ++kub[x];

        result[0] = kub['z'];
        remove(0);
        result[2] = kub['w'];
        remove(2);
        result[4] = kub['u'];
        remove(4);
        result[6] = kub['x'];
        remove(6);
        result[8] = kub['g'];
        remove(8);

        result[1] = kub['o'];
        remove(1);
        result[3] = kub['h'];
        remove(3);
        result[5] = kub['f'];
        remove(5);
        result[7] = kub['s'];
        remove(7);
        result[9] = kub['i'];

        string answer = "";
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < result[i]; j++)
                answer += i + '0';

        return answer;
    }
};