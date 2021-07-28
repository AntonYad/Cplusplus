class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int j = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                reverse(str.begin() + j, str.begin() + i);
                j = i + 1;
            }
        }
        reverse(str.begin() + j, str.end());
        return str;
    }
};