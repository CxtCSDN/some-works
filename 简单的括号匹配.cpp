#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>m_s;
        for (char val : s) {
            switch (val) {
            case '(':
            case '{':
            case '[': {
                m_s.push(val);
                break;
            }
            case ')':
            case '}':
            case ']': {
                if (m_s.empty())
                    return false;
                char tmp = m_s.top();
                m_s.pop();
                if (val == ')' && tmp != '('
                    || val == '}' && tmp != '{'
                    || val == ']' && tmp != '[')
                    return false;
            }
            default:
                break;
            }
        }
        return m_s.empty();
    }
};