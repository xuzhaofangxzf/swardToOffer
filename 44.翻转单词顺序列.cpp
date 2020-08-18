/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

*/

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
        {
            return "";
        }
        str.erase(0, str.find_first_not_of(" ")); //删除左边空格
        str.erase(str.find_last_not_of(" ") + 1); //删除右边空格
        string res = "";
        int r = str.size() - 1; // 右边界
        int i = str.size() - 1;
        while (i >= 0)
        {
            while (i >=0 && str.at(i) != ' ')
            {
                i--;
            }
            res.append(str.substr(i + 1, r + 1) + " ");
            while (i >=0 && str.at(i) == ' ') i--;
            r = i;
        }
        res.erase(res.find_last_not_of(" ") + 1); //删除右边空格

        return res;
    }
};


    string reverseWords(string s) {
        if (s.empty())
        {
            return "";
        }
        s.erase(0, s.find_first_not_of(" ")); //删除左边空格
        s.erase(s.find_last_not_of(" ") + 1); //删除右边空格
        string res = "";
        int r = s.size() - 1; // 右边界
        int i = s.size() - 1;
        while (i >= 0)
        {
            while (i >=0 && s.at(i) != ' ')
            {
                i--;
            }
            res.append(s.substr(i + 1, r + 1) + " ");
            while (i >=0 && s.at(i) == ' ') i--;
            r = i;
        }
        res.erase(res.find_last_not_of(" ") + 1); //删除右边空格

        return res;
    }
    }