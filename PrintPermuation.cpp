// PrintPermuation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


//���һ���ַ��������п��ܵ�����
//void pp(char *s, char * b, char *e)
//{
//	if (*b==��\0��)  //���Ǵ˴�Ϊʲô������b==e
//	{
//		cout << s << endl;
//		return;
//	}
//	else
//	{
//		for (char *cur = b; cur != e; cur++)
//		{
//			//����һ��Ԫ����ָ��Ԫ�ؽ��н���
//			char tmp = *b;
//			*b = *cur;
//			*cur = tmp;
//			//�ݹ鴦������һ��Ԫ��֮��ʣ�µ�Ԫ��
//			pp(s, b + 1, e);
//			//�ָ�����ǰ��˳���Ա����´ν�����ͬ��Ԫ��
//			tmp = *b;
//			*b = *cur;
//			*cur = tmp;
//		}
//	}
//}

//�ж�һ�������Ƿ�����˻ʺ����������
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


//�����������˻ʺ����������������
static int mycount = 0;
void pp(char *s, char * b, char *e,int len)
{
	if (*b =='\0')     //Ϊʲô������b==e��Ϊ��������
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
			//����һ��Ԫ����ָ��Ԫ�ؽ��н���
			char tmp = *b;
			*b = *cur;
			*cur = tmp;
			//�ݹ鴦������һ��Ԫ��֮��ʣ�µ�Ԫ��
			pp(s, b + 1, e,len);
			//�ָ�����ǰ��˳���Ա����´ν�����ͬ��Ԫ��
			tmp = *b;
			*b = *cur;
			*cur = tmp;
		}
	}
}

//����һ���ַ�������ӡ���ַ�����ȫ���У���ָoffer p154 test28��
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

