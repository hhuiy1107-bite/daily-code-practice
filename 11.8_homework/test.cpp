#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//class Solution {
//public:
//    int myAtoi(string str) {
//        size_t n = str.size();
//        size_t pos = 0;
//
//        //第一步清除所有的空格
//        while (pos < n && str[pos] == ' ')
//        {
//            pos++;
//        }
//
//        //第二步判断数字前的正负号
//        int flag = 1;
//        if (str[pos] == '-')
//        {
//            flag = -1;
//            pos++;
//
//        }
//        else
//        {
//            flag = 1;
//        }
//
//
//        //第三步读取数字
//        int ret = 0;
//        while (pos < n && str[pos] >= '0' && str[pos] <= '9')
//        {
//            int arr = str[pos] - '0';
//            ret = ret * 10 + arr;
//            pos++;
//        }
//
//        return ret * flag;
//    }
//};

//int main()
//{
//    string st = "+1";
//    Solution solu;
//    int i = solu.myAtoi(st);
//    cout << i << endl;
//}



class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
    //写法行不通是因为这样会导致错失位数，如果仅仅看123 + 11 来说是正确的，但是如果1234 + 11， 则会将中间的2丢失
        //int head = 0;
        //if (n1 > n2)
        //{
        //    head = num1[0];
        //}
        //else
        //{
        //    head = num2[0];
        //}

        string ret;
        int flag = 0;
        //n1到头/n2到头 
        while((n1 >= 0) && (n2 >= 0))
        {
            int re = ((num1[n1] - '0') + (num2[n2] - '0') + (flag));
       
                flag = re / 10;
                re %= 10;
    
            ret.insert(0, 1,re + '0');
            n1--;
            n2--;
        }

        // 2. 如果 num1 更长，把 num1 剩下的高位继续加完
        while (n1 >= 0)
        {
            int re = (num1[n1] - '0') + flag;
            flag = re / 10;
            re %= 10;

            ret.insert(0, 1, re + '0');
            n1--;
        }

        // 3. 如果 num2 更长，把 num2 剩下的高位继续加完
        while (n2 >= 0)
        {
            int re = (num2[n2] - '0') + flag;
            flag = re / 10;
            re %= 10;

            ret.insert(0, 1, re + '0');
            n2--;
        }

        if (flag > 0)
        {
            ret.insert(0, 1, flag + '0');
        }

        return ret;
    }
};



int main()
{
    string num1("456");
    string num2("77");

    Solution s;
    string ret = s.addStrings(num1, num2);
    
    cout << ret.c_str() << endl;

    return 0;
}