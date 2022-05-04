#pragma once
#include<iostream>
using namespace std;
#include<string>

/*
	String	本质是一个类
		char*是指针
		string是类，类内部封装char*,管理这个字符串。是一个char*容器
	
	特点：
		string类封装了很多成员方法
		例如：查找find	拷贝copy	删除delete	插入insert
		string管理char*所分配的空间，不用担心复制越界和取值越界等，由类内部负责

	string的构造函数：
		1.string;							//创建一个空的字符串 例如：string str；
		2.string（const char* s）;			//使用字符串s初始化
		3.string（const string& str）;		//使用一个string对象初始化另一个string对象
		4.string（int n,char c）;			//使用n个字符c初始化；
		

	string的赋值操作：
		1.string& operator=(const& char* s);			//char*类型字符串赋值给当前的字符串
		2.string& operator=（const string &s）;			//把字符串s赋值给当前的字符串
		3.string& operator=（char c）;					//字符赋值给当前的字符串
		4.string& assign（const char *s）;				//把字符串s赋值给当前的字符串
		5.string& assign（const char *s,int n）;		//把字符串的前n个字符赋值给当前字符串
		6.string& assign（const string &s）;			//把字符串s赋值给当前字符串
		7.string& assign(int n,char c);					//用n个字符c赋给当前字符串


	string字符串拼接：实现在字符串尾拼接字符串
		1.string& operator+=(const char* str);				//重载+=操作符
		2.string& operator+=(const char c);					//重载+=操作符
		3.string& operator+=(const string& str);			//重载+=操作符
		4.string& append(const char* s);					//把操作符s连接到当前字符串的尾部
		5.string& append(const char* s,int n);				//把操作符s的前n个字符连接到当前字符串的尾部
		6.string& append(const string& s);					//同operator+=（const string& str）
		7.string& append(const string& s,int pos,int n);	//字符串s中，从第pos开始的n个字符连接到字符串尾部
		

	string的查找和替换
		1.int find(const string& str ,int pos=0) const;			//查找str第一次出现的位置，从第pos开始查找
		2.int find(const char* s ,int pos=0) const;				//查找s第一次出现的位置，从第pos开始查找
		3.int find(const char* s ,int pos=0,int n) const;		//从第pos开始查找s的前n个字符第一次的位置
		4.int find(const char c ,int pos=0) const;				//查找字符c第一次出现的位置
		5.int rfind(const string& str ,int pos=npos) const;		//查找str最后一次出现的位置，从pos开始查找
		6.int rfind(const char* s ,int pos=npos) const;			//查找s最后一次出现的位置，从pos开始查找
		7.int rfind(const char* s,int pos,int n) const;			//从pos开始查找s的前n个字符最后一次位置
		8.int rfind(const char c ,int pos=0) const;				//查找字符c最后一次出现的位置,从第pos开始查找
		9.int replace(int pos,int n,const string& str);			//替换从pos开始的n个字符为字符串str
		10.int replace(int pos,int n,const char* s);			//替换从pos开始的n个字符为字符s		


	string的字符串比较
		比较是按照字符的ASCII码进行对比
		 = 返回0
		 > 返回1
		 < 返回-1


	string字符存取
		1.char& operator[](int n)	//通过[]方式取字符
		2.char& ar(int n);			//通过at方法获取字符


	string插入、删除

	string子串
		在字符串中截取一小段

		
*/


//string构造函数
void test_learn_construction_String();

//字符串赋值
void test_learn_assignment_string();

//字符串拼接
void test_learn_link_string();

//字符串查找和替换
void test_learn_findAndreplace_string();


//字符串比较
void test_compare_string();


//字符串数据访问
void test_access_string();


//字符串插入和删除
void test_insertAnddelete_string();

//字符串子串
void test_subStr();
