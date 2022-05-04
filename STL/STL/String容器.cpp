#include "String����.h"

/*
	string�Ĺ��캯����
		1.string;							//����һ���յ��ַ��� ���磺string str��
		2.string��const char* s��;			//ʹ���ַ���s��ʼ��
		3.string��const string& str��;		//ʹ��һ��string�����ʼ����һ��string����
		4.string��int n,char c��;			//ʹ��n���ַ�c��ʼ����

*/

void test_learn_construction_String()	//construction ����
{

	//1.����һ���յ��ַ��� ���磺string str��
	string s1;
	s1 = "S1";
	cout << s1 << endl;
	//ʹ���ַ���s��ʼ��

	string s2("S2");
	
	cout << s2 << endl;

	//��������
	string s3(s2);
	cout << s3 << endl;	//s2����s3

	string s4(5, 'a');
	cout << s4 << endl;//���aaaaa

	cout << string(3, 'w') << endl;
}


/*
	string�ĸ�ֵ������
		1.string& operator=(const& char* s);			//char*�����ַ�����ֵ����ǰ���ַ���
		2.string& operator=��const string &s��;			//���ַ���s��ֵ����ǰ���ַ���
		3.string& operator=��char c��;					//�ַ���ֵ����ǰ���ַ���
		4.string& assign��const char *s��;				//���ַ���s��ֵ����ǰ���ַ���
		5.string& assign��const char *s,int n��;		//���ַ�����ǰn���ַ���ֵ����ǰ�ַ���
		6.string& assign��const string &s��;			//���ַ���s��ֵ����ǰ�ַ���
		7.string& assign(int n,char c);					//��n���ַ�c������ǰ�ַ���

*/

//�ַ�����ֵ
void test_learn_assignment_string()	//assignement ��ֵ
{
	//1.string & operator=(const& char* s);				//char*�����ַ�����ֵ����ǰ���ַ���
	string s1 = "Hello Word";
	cout << "s1=" << s1 << endl;	//s1=Hello Word
	
	//2.string & operator=��const string & s��;			//���ַ���s��ֵ����ǰ���ַ���
	string s2 = s1;
	cout << "s2=" << s2 << endl;	//s2=Hello Word

	//3.string & operator=��const char c��;					//�ַ���ֵ����ǰ���ַ���
	
	string s3="Y";
	//string s3 = 'Y';  //error
	
	cout << "s3=" << s3 << endl;	//s3=Y
	//Ϊʲô���������أ�
	//string s3 = 'Y';	//'Y'��char���� ��Y����string����


	//4.string & assign��const char* s��;				//���ַ���s��ֵ����ǰ���ַ���
	string s4;
	s4.assign("ABCDEFGHIJKLNM");
	cout <<"s4=" << s4 << endl;	//s4=ABCDEFGHIJKLNM


	//5.string & assign��const char* s, int n��;		//���ַ�����ǰn���ַ���ֵ����ǰ�ַ���
	string s5;
	s5.assign("ABCDEFGHIJKLNM",5);	//s5=ABCDE
	cout <<"s5=" << s5 << endl;

	//6.string & assign��const string & s��;			//���ַ���s��ֵ����ǰ�ַ���
	
	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;	//s6=ABCDE

	//7.string & assign(int n, char c);					//��n���ַ�c������ǰ�ַ���
	string s7;
	s7.assign(5,'c');
	cout << "s7=" << s7 << endl;	//s7=ccccc

	//8				//��s4�ĵ������ʼ�����ƹ���		
	string s8;
	s8.assign(s4, 5);
	cout << "s8=" << s8 << endl;	//s8=FGHIJKLNM

}

//�ַ���ƴ��
void test_learn_link_string()	//link ����
{
	//string�ַ���ƴ�ӣ�ʵ�����ַ���βƴ���ַ���
		
		//1.string & operator+=(const char* str);				//����+=������
	string s1="ABC";
	s1 += "EF";
	cout<<"s1=" << s1 << endl;	//s1=ABCEF
		
		//2.string & operator+=(const char c);					//����+=������
	string s2=s1;
	s2 += 'G';
	cout << "s2=" << s2 << endl;	//s2=ABCEFG
		//3.string & operator+=(const string & str);			//����+=������
		
	string s3="T";
	s3 += s2;
	cout << "s3=" << s3 << endl;	//s3=TABCEFG
		
		//4.string & append(const char* s);					//�Ѳ�����s���ӵ���ǰ�ַ�����β��
	string s4="YP";
	s4.append("JH");
	cout << "s4=" << s4 << endl;	//s4=YPJH
		//5.string & append(const char* s, int n);				//�Ѳ�����s��ǰn���ַ����ӵ���ǰ�ַ�����β��
	string s5="ZXC";
	s5.append("QWERDFB", 3);
	cout << "s5=" << s5 << endl;	//s5=ZXCQWE

		
		//6.string & append(const string & s);					//ͬoperator+=��const string& str��
	string s6="ASD";
	s6.append(s5);
	cout << "s6=" << s6 << endl;	//s6=ASDZXCQWE		
		
		//7.string & append(const string & s, int pos, int n);	//�ַ���s�У��ӵ�pos��ʼ��n���ַ����ӵ��ַ���β��
	string s7 = "WWW.";
	s7.append(s5, 2, 2);
	cout << "s7=" << s7 << endl;	//s7=WWW.CQ

}

//�ַ����������滻
void test_learn_findAndreplace_string()
{
	//string�Ĳ��Һ��滻
		
	//ע�⣺find��rfin�Ĳ�һ��
	//	find��������ҿ�ʼ��
	//	rfind��������ʼ��
	//1.int find(const string & str, int pos = 0) const;			//����str��һ�γ��ֵ�λ�ã��ӵ�pos��ʼ����
	string s1 = "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP";
	string ss1 = "GH";
	//s1.find(s1, 5);
	cout << "s1.find(ss1,2)=" << s1.find(ss1, 2) << endl;//�ӵڶ�����ʼ��C��������һ�γ���ss1(GH)��λ��
	
	//2.int find(const char* s, int pos = 0) const;				//����s��һ�γ��ֵ�λ�ã��ӵ�pos��ʼ����
	string s2 = s1;
	cout << "ABCDEFGHIJKLNMOP��J��λ���ڵڣ�" << s2.find('J', 0)<<endl;//��s2�дӵ�0��λ�ÿ�ʼ����J��һ�γ��ֵ�λ��
	
	//3.int find(const char* s, int pos = 0, int n) const;		//�ӵ�pos��ʼ����s��ǰn���ַ���һ�ε�λ��
	string s3 = s1;
	cout<<s3.find("KL", 0,2)<<endl;
	
	//4.int find(const char c, int pos = 0) const;				//�����ַ�c��һ�γ��ֵ�λ��
	
	string s4 = s1;
	cout << "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP�дӵ�8��λ�ÿ�ʼ�ҵ�һ��H��λ���ڣ�" << s4.find('H', 8) << endl;//�ӵ�8��λ�ÿ�ʼ����H��һ�γ��ֵ�λ���±�
	
	//5.int rfind(const string & str, int pos = npos) const;		//����str���һ�γ��ֵ�λ�ã���pos��ʼ����
	
	string s5 = s1;
	string ss5 = "OP";
	cout<<"ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP������23ʱOP���ֵ�λ�ã�" << s5.rfind(ss5, 23)<<endl;
	
	//6.int rfind(const char* s, int pos = npos) const;			//����s���һ�γ��ֵ�λ�ã���pos��ʼ����
	string s6 = s1;
	cout << "ABCDEFGHIJKLNMOPABCDEFGHIJKLNMOP��M��һ�γ��ֵ�λ�ã��Ӻ���ǰ�ң���" << s6.rfind('M', 31)<<endl;
	
	//7.int rfind(const char* s, int pos, int n) const;			//��pos��ʼ����s��ǰn���ַ����һ��λ��
	string s7 = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJ";
	cout << s7.rfind("GHI", 31, 2)<<endl;//
	
	//8.int rfind(const char c, int pos = 0) const;				//�����ַ�c���һ�γ��ֵ�λ��,�ӵ�pos��ʼ����
	
	
	//9.int replace(int pos, int n, const string & str);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ���str
	string s8 = s7;
	cout << s8.replace(4, 3, "11111");//��4����ʼ����3���ַ��滻��11111����
	
	//10.int replace(int pos, int n, const char* s);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ�s		

}

//�ַ����Ƚ�
void test_compare_string()
{

	string str1 = "Ahello";
	string str2 = "Ahello";
	string str3 = "Bhello";
	//compare��Ҫ���ڱȽ�����string�Ƿ����
	if (str1.compare(str2)==0)
	{
		cout << "arr1=arr2" << endl;
	}
	else
	{
		cout << "arr1��arr2";
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

//�ַ�����ȡ����
void test_access_string()
{
	string str1 = "hello";

	for (int i = 0; i < str1.size(); i++)
	{
		//1.ͨ��[]����
		cout << str1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str1.size(); i++)
	{
		//2.ͨ��at����
		cout << str1.at(i) << " ";
	}
	cout << endl;
	//�޸��ַ�
	str1[2] = 'A';
	cout << str1 << endl;
	str1.at(3) = 'B';
	cout << str1 << endl;
}

//�ַ��������ɾ��
void test_insertAnddelete_string()
{
	string str1 = "hello";

	//����
	str1.insert(1, "222");
	cout << str1 << endl;

	//ɾ��
	str1.erase(1, 3);
	cout << str1 << endl;
}

//�ַ����Ӵ�
void test_subStr()
{
	string str1 = "abcdef";


	cout<<str1.substr(1,3)<<endl;//�ӵ�1����ʼ��3���ַ�������һ���ַ�

	//��ȡemail���û���
	string email = "ypjhdemail@163.com";

	cout << email.substr(0, email.find("@"))<<endl;
}