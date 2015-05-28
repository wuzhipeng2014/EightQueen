// PrintPermuation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


//输出一个字符串的所有可能的排列
//void pp(char *s, char * b, char *e)
//{
//	if (*b==‘\0’)  //考虑此处为什么不能是b==e
//	{
//		cout << s << endl;
//		return;
//	}
//	else
//	{
//		for (char *cur = b; cur != e; cur++)
//		{
//			//将第一个元素与指定元素进行交换
//			char tmp = *b;
//			*b = *cur;
//			*cur = tmp;
//			//递归处理交换第一个元素之外剩下的元素
//			pp(s, b + 1, e);
//			//恢复交换前的顺序，以便于下次交换不同的元素
//			tmp = *b;
//			*b = *cur;
//			*cur = tmp;
//		}
//	}
//}

//判断一个排列是否满足八皇后问题的条件
bool isEightQueen(char * c, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = i+1; j < len; j++)
		{
			int rd = i - j;
			int cd = c[i] - c[j];
			if (abs(rd)==abs(cd))
			{
				return false;
			}
		}
	}

	return true;
}


//输出所有满足八皇后问题的条件的排列
static int mycount = 0;
void pp(char *s, char * b, char *e,int len)
{
	if (*b =='\0')     //为什么不能是b==e作为结束条件
	{
		if (isEightQueen(s,len))
		{
			cout << mycount++ << ":  ";
			cout << s << endl;
			return;
		}
		
	}
	else
	{
		for (char *cur = b; cur !=e ; cur++)
		{
			//将第一个元素与指定元素进行交换
			char tmp = *b;
			*b = *cur;
			*cur = tmp;
			//递归处理交换第一个元素之外剩下的元素
			pp(s, b + 1, e,len);
			//恢复交换前的顺序，以便于下次交换不同的元素
			tmp = *b;
			*b = *cur;
			*cur = tmp;
		}
	}
}

//给定一个字符串，打印该字符串的全排列（剑指offer p154 test28）
void pp(char * s, int len)
{
	char * b = s;
	char *e = &s[len];
	pp(s, b, e,len);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[] = "12345678";
	/*cout << s << endl;
	cout << "s.len = " << sizeof(s) << endl;*/
	pp(s,sizeof(s));

	///*int*/ a[] = {1,2,3,7,6,4,8,5};
	bool re= isEightQueen(s, 8);
	cout << re << endl;
	return 0;
}

