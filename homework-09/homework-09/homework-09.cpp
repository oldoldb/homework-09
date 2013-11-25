// homework-09.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;
class MyRightShiftStr
{
public:
	MyRightShiftStr();
	~MyRightShiftStr();
	bool GetString();
	bool GetK();
	void PrintResult();
	void ReverseStr(int left,int right);
	void RightShift();
	void UptrShift();
private:
	string str;
	int k;
	int n;
};


MyRightShiftStr::MyRightShiftStr()
{
}

MyRightShiftStr::~MyRightShiftStr()
{
}
bool MyRightShiftStr::GetString()
{
	cout<<"Please input the str you want to RightShift: "<<endl;
	try
	{
		if(getline(cin,str)==nullptr)
		{
			throw("Input Error");
		}
	}
	catch(char *ExceptionStr)
	{
		cout<<"Exception: "<<ExceptionStr<<endl;
		return false;
	}
	n=str.length();
}
bool MyRightShiftStr::GetK()
{
	cout<<"Please input the K: "<<endl;
	try
	{
		if(scanf_s("%d",&k)!=1)
		{
			throw("Input Error");
		}
	}
	catch(char *ExceptionStr)
	{
		cout<<"Exception: "<<ExceptionStr<<endl;
		return false;
	}
	if(k<0)
	{
		k=n+k%n;
	}
}
void MyRightShiftStr::UptrShift()
{
	unique_ptr<string>p(new string(str));
	for(int i=0;i<k;i++)
	{
		char ch=(*p)[n-1];
		for(int j=n-1;j>0;j--)
		{
			(*p)[j]=(*p)[j-1];
		}
		(*p)[0]=ch;
	}
	cout<<*p<<endl;
}
void MyRightShiftStr::RightShift()
{
	k%=n;
	ReverseStr(0,n-k-1);
	ReverseStr(n-k,n-1);
	ReverseStr(0,n-1);
}
void MyRightShiftStr::ReverseStr(int left,int right)
{
	for( ;left<right;left++,right--)
	{
		char temp=str[right];
		str[right]=str[left];
		str[left]=temp;
	}
}
void MyRightShiftStr::PrintResult()
{
	cout<<"The str after RightShift: "<<endl;
	cout<<str<<endl;
}

class MyCountStr
{
public:
	MyCountStr();
	~MyCountStr();
	bool GetString();
	bool GetChar();
	void CountLambda();

private:
	string str;
	char ch;
	int cnt;
};

MyCountStr::MyCountStr()
{
}

MyCountStr::~MyCountStr()
{
}

bool MyCountStr::GetString()
{
	cout<<"Please input the str you want to Count: "<<endl;
	try
	{
		if(getline(cin,str)==nullptr)
		{
			throw("Input Error");
		}
	}
	catch(char *ExceptionStr)
	{
		cout<<"Exception: "<<ExceptionStr<<endl;
		return false;
	}
}

bool MyCountStr::GetChar()
{
	cout<<"Please input the char you want to Count: "<<endl;
	try
	{
		if((ch=getc(stdin))==NULL)
		{
			throw("Input Error");
		}
	}
	catch(char *ExceptionStr)
	{
		cout<<"Exception: "<<ExceptionStr<<endl;
		return false;
	}
}

void MyCountStr::CountLambda()
{
	cnt=count_if(str.cbegin(),str.cend(),[=](char tempCh){return tempCh==ch;});
	cout<<"The num of "<<ch<<" is "<<cnt<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	while(true)
	{
		MyCountStr myCS=MyCountStr::MyCountStr();
		if(!myCS.GetString())
		{
			continue;
		}
		if(!myCS.GetChar())
		{
			continue;
		}
		myCS.CountLambda();
		myCS.~MyCountStr();
		break;
	}
	while(true)
	{
		MyRightShiftStr myRSS=MyRightShiftStr::MyRightShiftStr();
		if(!myRSS.GetString())
		{
			continue;
		}
		if(!myRSS.GetK())
		{
			continue;
		}
		myRSS.RightShift();
		myRSS.PrintResult();
//		myRSS.UptrShift();
		myRSS.~MyRightShiftStr();
		break;
	}
	return 0;
}

