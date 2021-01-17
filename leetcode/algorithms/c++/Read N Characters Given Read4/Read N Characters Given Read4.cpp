class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int result = 0;
        char *tmp2 = new char[6]();
        int tmp = read4(tmp2);

        while (tmp != 0)
        {

            for (int i = 0; i < tmp; i++)
            {

                buf[i + result] = tmp2[i];
            }
            result += tmp;
            tmp = read4(tmp2);
        }
        buf[n] = 0;
        return result;
    }
};