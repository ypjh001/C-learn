#include "String容器.h"

/*
	string的构造函数：
		1.string;							//创建一个空的字符串 例如：string str；
		2.string（const char* s）;			//使用字符串s初始化
		3.string（const string& str）;		//使用一个string对象初始化另一个string对象
		4.string（int n,char c）;			//使用n个字符c初始化；

*/

void test_learn_construction_String()	//construction 构造
{

	//1.创建一个空的字符串 例如：string str；
	string s1;
	s1 = "S1";
	cout << s1 << endl;
	//使用字符串s初始化

	string s2("S2");
	
	cout << s2 << endl;

	//拷贝构造
	string s3(s2);
	cout << s3 << endl;	//s2拷给s3

	string s4(5, 'a');
	cout << s4 << endl;//输出aaaaa

	cout << string(3, 'w') << endl;
}


/*
	string的赋值操作：
		1.string& operator=(const& char* s);			//char*类型字符串赋值给当前的字符串
		2.string& operator=（const string &s）;			//把字符串s赋值给当前的字符串
		3.string& operator=（char c）;					//字符赋值给当前的字符串
		4.string& assign（const char *s）;				//把字符串s赋值给当前的字符串
		5.string& assign（const char *s,int n）;		//把字符串的前n个字符赋值给当前字符串
		6.string& assign（const string &s）;			//把字符串s赋值给当前字符串
		7.string& assign(int n,char c);					//用n个字符c赋给当前字符串

*/

//字符串赋值
void test_learn_assignment_string()	//assignement 赋值
{
	//1.string & operator=(const& char* s);				//char*类型字符串赋值给当前的字符串
	string s1 = "Hello Word";
	cout << "s1=" << s1 << endl;	//s1=Hello Word
	
	//2.string & operator=（const string & s）;			//把字符串s赋值给当前的字符串
	string s2 = s1;
	cout << "s2=" << s2 << endl;	//s2=Hello Word

	//3.string & operator=（const char c）;					//字符赋值给当前的字符串
	
	string s3="Y";
	//string s3 = 'Y';  //error
	
	cout << "s3=" << s3 << endl;	//s3=Y
	//为什么不能这样呢？
	//string s3 = 'Y';	//'Y'是char类型 “Y”是string类型


	//4.string & assign（const char* s）;				//把字符串s赋值给当前的字符串
	string s4;
	s4.assign("ABCDEFGHIJKLNM");
	cout <<"s4=" << s4 << endl;	//s4=ABCDEFGHIJKLNM


	//5.string & assign（const char* s, int n）;		//把字符串的前n个字符赋值给当前字符串
	string s5;
	s5.assign("ABCDEFGHIJKLNM",5);	//s5=ABCDE
	cout <<"s5=" << s5 << endl;

	//6.string & assign（const string & s）;			//把字符串s赋值给当前字符串
	
	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;	//s6=ABCDE

	//7.string & assign(int n, char c);					//用n个字符c赋给当前字符串
	string s7;
	s7.assign(5,'c');
	cout << "s7=" << s7 << endl;	//s7=ccccc

	//8				//吧s4的第五个开始，复制过来		
	string s8;
	s8.assign(s4, 5);
	cout << "s8=" << s8 << endl;	//s8=FGHIJKLNM

}

//字符串拼接
void test_learn_link_string()	//link 连接
{
	//string字符串拼接：实现在字符串尾拼接字符串
		
		//1.string & operator+=(const char* str);				//重载+=操作符
	string s1="ABC";
	s1 += "EF";
	cout<<"s1=" << s1 << endl;	//s1=ABCEF
		
		//2.string & operator+=(const char c);					//重载+=操作符
	string s2=s1;
	s2 += 'G';
	cout << "s2=" << s2 << endl;	//s2=ABCEFG
		//3.string & operator+=(const string & str);			//重载+=操作符
		
	string s3="T";
	s3 += s2;
	cout << "s3=" << s3 << endl;	//s3=TABCEFG
		
		//4.string & append(const char* s);					//把操作符s连接到当前字符串的尾部
	string s4="YP";
	s4.append("JH");
	cout << "s4=" << s4 << endl;	//s4=YPJH
		//5.string & append(const char* s, int n);				//把操作符s的前n个字符连接到当前字符串的尾部
	string s5="ZXC";
	s5.append("QWERDFB", 3);
	cout << "s5=" << s5 << endl;	//s5=ZXCQWE

		
		//6.string & append(const string & s);					//同operator+=（const string& str）
	string s6="ASD";
	s6.append(s5);
	cout << "s6=" << s6 << endl;	//s6=ASDZXCQWE		
		
		//7.string & append(const string & s, int pos, int n);	//字符串s中，从第pos开始的n个字符连接到字符串尾部
	string s7 = "WWW.";
	s7.append(s5, 2, 2);
	cout << "s7=" << s7 << endl;	//s7=WWW.CQ

}

//字符串查找与替换
void test_learn_findAndreplace_string()
{
	//string的查找和替换
		
	//注意：find和rfin的不一样
	//	find从左边往右开始找
	//	rfind从有往左开始找
	//1.int find(const string & str, int pos = 0) const;			//查找str第一次出现的位置，从第pos开始查找
	string s1 = "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP";
	string ss1 = "GH";
	//s1.find(s1, 5);
	cout << "s1.find(ss1,2)=" << s1.find(ss1, 2) << endl;//从第二个开始（C）数，第一次出现ss1(GH)的位置
	
	//2.int find(const char* s, int pos = 0) const;				//查找s第一次出现的位置，从第pos开始查找
	string s2 = s1;
	cout << "ABCDEFGHIJKLNMOP中J的位置在第：" << s2.find('J', 0)<<endl;//在s2中从第0的位置开始查找J第一次出现的位置
	
	//3.int find(const char* s, int pos = 0, int n) const;		//从第pos开始查找s的前n个字符第一次的位置
	string s3 = s1;
	cout<<s3.find("KL", 0,2)<<endl;
	
	//4.int find(const char c, int pos = 0) const;				//查找字符c第一次出现的位置
	
	string s4 = s1;
	cout << "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP中从第8个位置开始找第一次H的位置在：" << s4.find('H', 8) << endl;//从第8个位置开始查找H第一次出现的位置下标
	
	//5.int rfind(const string & str, int pos = npos) const;		//查找str最后一次出现的位置，从pos开始查找
	
	string s5 = s1;
	string ss5 = "OP";
	cout<<"ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP中数到23时OP出现的位置：" << s5.rfind(ss5, 23)<<endl;
	
	//6.int rfind(const char* s, int pos = npos) const;			//查找s最后一次出现的位置，从pos开始查找
	string s6 = s1;
	cout << "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP中M第一次出现的位置（从后往前找）：" << s6.rfind('M', 31)<<endl;
	
	//7.int rfind(const char* s, int pos, int n) const;			//从pos开始查找s的前n个字符最后一次位置
	string s7 = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJ";
	cout << s7.rfind("GHI", 31, 2)<<endl;//
	
	//8.int rfind(const char c, int pos = 0) const;				//查找字符c最后一次出现的位置,从第pos开始查找
	
	
	//9.int replace(int pos, int n, const string & str);			//替换从pos开始的n个字符为字符串str
	string s8 = s7;
	cout << s8.replace(4, 3, "11111");//第4个开始后面3个字符替换“11111”。
	
	//10.int replace(int pos, int n, const char* s);			//替换从pos开始的n个字符为字符s		

}

//字符串比较
void test_compare_string()
{

	string str1 = "Ahello";
	string str2 = "Ahello";
	string str3 = "Bhello";
	//compare主要用于比较两个string是否相等
	if (str1.compare(str2)==0)
	{
		cout << "arr1=arr2" << endl;
	}
	else
	{
		cout << "arr1≠arr2";
	}
	if (str1.compare(str3)>0)
	{
		cout << "str1>str3";
	}
	else
	{
		cout << "str1<str3" << endl;
	}

}

//字符串存取访问
void test_access_string()
{
	string str1 = "hello";

	for (int i = 0; i < str1.size(); i++)
	{
		//1.通过[]访问
		cout << str1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str1.size(); i++)
	{
		//2.通过at访问
		cout << str1.at(i) << " ";
	}
	cout << endl;
	//修改字符
	str1[2] = 'A';
	cout << str1 << endl;
	str1.at(3) = 'B';
	cout << str1 << endl;
}

//字符串插入和删除
void test_insertAnddelete_string()
{
	string str1 = "hello";

	//插入
	str1.insert(1, "222");
	cout << str1 << endl;

	//删除
	str1.erase(1, 3);
	cout << str1 << endl;
}

//字符串子串
void test_subStr()
{
	string str1 = "abcdef";


	cout<<str1.substr(1,3)<<endl;//从第1个开始截3个字符，返回一个字符

	//截取email的用户名
	string email = "ypjhdemail@163.com";

	cout << email.substr(0, email.find("@"))<<endl;
}