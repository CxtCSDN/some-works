#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 1 || str.size() == 0)
            return 0;
        int flag = 1;
        int res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (i == 0 && str[i] == '-')
                flag = -1;
            else {
                if (i != 0 && !isdigit(str[i])) {
                    return 0;
                }
                else {
                    res = res * 10 + (str[i] - '0');
                }
            }
        }
        return res * flag;
    }
    string addStrings(string num1, string num2) {
        int carry = 0;
        int index1 = num1.size() - 1, index2 = num2.size() - 1;
        string ans;
        int _num1 = 0, _num2 = 0, sum = 0;
        while (index1 >= 0 || index2 >= 0 || carry != 0) {
            if (index1 >= 0)
                _num1 = num1[index1--] - '0';
            if (index2 >= 0)
                _num2 = num2[index2--] - '0';
            sum = _num1 + _num2 + carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
            _num1 = _num2 = 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string reverseStr(string s, int k) {
        int left = 0, right = 0;
        while (right < s.size()) {
            right += 2 * k;
            if (s.size() - left < k) {
                reverse(s.begin() + left, s.begin() + s.size());
                return s;
            }
            if (right > s.size()) {
                reverse(s.begin() + left, s.begin() + left + k);
                return s;
            }
            reverse(s.begin() + left, s.begin() + left + k);
            left = right;
        }

        return s;
    }
    string reverseWords(string s) {
        string index = " ";
        int curPos = 0;
        int prePos = 0;
        while ((curPos = s.find_first_of(index, curPos)) != string::npos) {
            reverse(s.begin() + prePos, s.begin() + curPos);
            prePos = ++curPos;
        }
        if (prePos != s.size()) {
            reverse(s.begin() + prePos, s.begin() + s.size());
        }
        return s;
    }
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        int carry = 0;
        int index1 = num1.size() - 1, index2 = num2.size() - 1;
        string ans;
        int _num1 = 0, _num2 = 0;//每一位数
        int mul = 0;//乘积之和
        int index = 1;//乘第几个数，模拟乘法
        vector<string>results(num1.size()+num2.size());
        int i = 0;
        while (index2 >= 0) {
            while (index1 >= 0 || carry != 0) {
                if (index1 >= 0)
                    _num1 = num1[index1--] - '0';
                _num2 = num2[index2] - '0';
                mul = _num1 * _num2 + carry;
                carry = mul / 10;
                results[i].append(to_string(mul % 10));
                _num1 = 0;
            }
            reverse(results[i].begin(), results[i].end());
            index2--;
            index1 = num1.size() - 1;
            i++;
        }
        int strNum = 0;
        string strIndex = "";
        while (strNum < results.size()) {
            ans = addStrings(results[strNum++] += strIndex, ans);
            strIndex += "0";
        }
        return ans;
    }
};
//int main(int argc, char* argv[])
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//
//	int size_pos = 0;
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos){
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	//How are you 
//	if (size_prev_pos != strText.size()){
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//
//}

int main()
{
    cout << Solution().multiply("123", "456");
    return 0;
}
