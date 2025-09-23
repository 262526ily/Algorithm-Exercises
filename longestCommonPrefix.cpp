#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = strs[0];
        int n=0;
        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (j >= strs[i].size() || s[j] != strs[i][j])
                    return s.substr(0, n);
            }
            n++;
        }
        return s.substr(0, n);
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    string res = s.longestCommonPrefix(strs);
}