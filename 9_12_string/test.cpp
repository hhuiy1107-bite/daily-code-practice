#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//int main()
//{
//	//string st1 = "abcdef";
//	//cout << st1 << endl;
//	//cout << st1.size() << endl;
//	//cout << st1.capacity() << endl;
//
//	//long long i = stoll(st1, nullptr, 16);
//	//cout << i << endl;
//
//	/*char a = '1';
//	printf("%d\n", a);
//	cout << a - '0' << endl;*/
//	 
//
//	//char a = '1';
//	//char b = '2';
//	//char c = '3';
//	//char d = '4';
//	//string st1;
//	////st.insert(0, 1, a);
//	////st.insert(st.begin(), 1, a);
//	//st1.insert(st1.begin(), 4, 'a');
//	//cout << st1 << endl;
//	//st1.pop_back();
//	//cout << st1 << endl;
//	//st.push_back(a);
//	//st.push_back(b);
//	//st.push_back(c);
//	//st.push_back(d);
//
//	/*st += a;
//	st += b;
//	st += c;
//	st += d;
//	cout << st << endl;
//
//	reverse(st.begin(), st.end());
//	cout << st << endl;*/
//
//
//
//	string st = "abcdef";
//
//	st.erase(3, 2);
//	cout << st << endl;
//
//	st.erase(1);
//	cout << st << endl;
//	return 0;
//}



#include <iostream>
using namespace std;

int is_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else {
        return false;
    }
}


int main() 
{
    int a, b, c;
    int month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    while (cin >> a >> b >> c)
    { // 注意 while 处理多个 case

        int ret = 0;
        if ( (a >= 1900 && a <= 2200) && (b >= 1 && b <= 12))
        {
            for (int i = 1; i < b; i++)
            {
                if (i == 2 && is_year(i) == 1)
                {
                    ret += 29;
                }

                else 
                {
                    ret += month[i];
                }
            }

            ret += c;
            cout << ret << endl;
        }
        else 
        {
            continue;
        }
    }

    return 0;
}
