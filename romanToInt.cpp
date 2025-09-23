#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> hashtable = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (hashtable[s[i + 1]] > hashtable[s[i]])
            {
                res -= hashtable[s[i]];
            }
            else
            {
                res += hashtable[s[i]];
            }
        }
        return res + hashtable[s[s.size() - 1]];
    }
    int romanToInt(string s)
    {
        int num = 0;
        // num+判断
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'M' || s[i] == 'D')
                num += (s[i] == 'M') ? 1000 : 500;
            if (s[i] == 'L' || s[i] == 'V')
                num += (s[i] == 'L') ? 50 : 5;
            if (s[i] == 'C')
                num += (s[i + 1] == 'D' || s[i + 1] == 'M') ? -100 : 100;
            if (s[i] == 'X')
                num += (s[i + 1] == 'L' || s[i + 1] == 'C') ? -10 : 10;
            if (s[i] == 'I')
                num += (s[i + 1] == 'V' || s[i + 1] == 'X') ? -1 : 1;
        }
        return num;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution so;
    int n = so.romanToInt(s);
}