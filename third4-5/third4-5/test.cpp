#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<cstring>




//struct jiegouti
//{
//	//�������Դ����ṹ���ͬʱ�����ṹ���������ֵ
//	//��������ô�㣬�ṹ�������֮���Ƚ���
//	int age;
//}p1={12};
//
//struct MyStruct
//{
//	char ch[10];
//}s3,s4;//Ҳ������ô�����ṹ�����s3,s4
//
//int main()
//{
//	using namespace std;
//	//s1��s2�нṹ�������ch�нṹ���Ա
//	MyStruct s1 = { "ABCDEF" };
//	MyStruct s2 = s1;//���Գ�Ա֮�丳ֵ��s2.ch=ABCDEF
//	s3 = { "qwer" };
//	s4 = { "opug" };
//	cout<<s1.ch[2]<<endl;//C
//	cout << s1.ch[5]<<endl ;//F
//	cout << s1.ch[4]+1 <<endl;//70,s1.ch[4]��ӡE��+1֮���Զ�ת��Ϊint���ͣ���69+1=70
//	cout <<(int) 'A'<<endl;//65,ǿתint
//	cout << (int)'F' << endl;//70
//	//��ӡs2����Ϣ����s1һ��
//	cout << s1.ch << endl;//ABCDEF
//	cout << s2.ch << endl;//ABCDEF
//	cout << s3.ch << endl;//qwer
//	cout << s4.ch << endl;//opug
//	cout<<p1.age;//12
//	return 0;
//}




//����person�Ľṹ��

//struct person
//{
//	//�ṹ���Ա name/age/id
//	char name[20];
//	int age;
//	long id;
//};
//int main()
//{
//	using namespace std;
//	//1.�����ṹ��person��Ա��p1��p2��
//	person p1={"zhangsan",18,232};//����Ա��p1��ֵ,C++����ʡ��struct
//	cout << p1.name<<endl;//ͨ��p1.name���ʳ�Ա����
//	cout << p1.age<<endl;//age
//	cout << p1.id<<endl;//id
//	struct person p2={"sdaf",15,45};
//	cout << p2.name << endl;//ͨ��p2.name���ʳ�Ա����
//	cout << p2.age << endl;//age
//	cout << p2.id << endl;//id
//	p2.age = 99;//���Ը��ĳ�Ա��Ϣage
//	cout << p2.age<<endl;
//	//2.�ṹ������
//	person pi[] =
//	{
//		{"lisi",12,31},
//		{"grs",23,23},
//		{"xiangjiao",45,21}
//	};
//	int i;
//	for ( i = 0; i < 3; i++)
//	{
//		cout <<"������" <<i<< pi[i].name << endl;
//		cout << "���䣺" <<i<< pi[i].age << endl;
//		cout << "ѧ�ţ�" <<i<< pi[i].id << endl;
//	}
//	return 0;
//}






//int main()
//{
//	using namespace std;
//	char charr[20];//����δ��ʼ��ʱ��trelen(charr)ʱ���ֵ
//	string str;//δ��ʼ����string�����Զ���0
//
//	cout << "lengeh of string in charr before input: " << strlen(charr) << endl;//δ��ʼ��charrʱ���о���
//	cout << "lengch of string in str before input: " << str.size() << endl;//size������\n
//	cout << "enter a line of text:\n";
//	cin.getline(charr, 20);//��������charr������ֵʱ��strlen(charr)���Լ������\n������ַ�����
//	cout << "you entered:" << charr << endl;
//	cout << "enter another line of text: \n";
//	getline(cin, str);
//	cout << "you entered: " << str << endl;
//	cout << "length of string in charr after input:" << strlen(charr) << endl;
//	cout << "length of string in str after input: " << str.size() << endl;
//	return 0;
//}



//int main()
//{
//	using namespace std;
//	//�ַ������Ի��ำֵ�����鲻��
//	string str1="abcd";
//	string str2=str1;
//	//�ַ����������ƴ��
//	string str3 = str1 + str2;
//	cout << str2<<endl;//abcd
//	cout << str3<<endl;//abcdabcd
//	//������strcpy��ch1��ch2)�����ַ������鸴��
//	char ch1[] =  "qwer";
//	char ch2[10];
//	const char ch3[] = "f";
//	//strcpy(ch2,ch1);//strcpyֻ������char����֮�临�ƣ�strcpy��Ŀ�꣬����������
//	//strcat(ch1, ch2);//strcat���ַ������ӵ��ַ�����ĩβ��ע�⣬�����������С
//
//	//��һ�ָ��ƺ͸�����strcpy��ctrcat����
//	//ʹ��strncpyʱҪע�⣬\n���ᱻ���ƹ�ȥ�������룬��countҪ����\n��ַʱ���������ܲ�����
//	strncpy(ch2, ch1,8);//��count=3ʱch2=qwe�����ӡ����
//	strncat(ch2, ch3, 1);
//	strncat(ch1, ch2, 5);//��count=2ʱch1=qwerqw,count=5ʱch1=qwerqwer
//	cout << ch2<<endl;
//	cout << ch1<<endl;
//	cout << str1.size() << endl;
//	cout << strlen(ch1)<<endl;//������\n
//	return 0;
//}



//int main()
//{
//	using namespace std;
//	char charr1[20];
//	char charr2[20] = "jaguar";
//	string str1;
//	string str2="panther";
//
//	cout << "enter a kind of feline: ";
//	cin >> charr1;
//	cout << "enter an other of feline: ";
//	cin >> str1;
//	cout << "here are some felines: ";
//	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
//	cout << "the third letter in" << charr2 << " is " << charr2[2] << endl;//charr2[2]��ȡ����g'
//	cout << "the third letter in" << str2 << " is " << str2[2] << endl;//str2[2]��ȡ����n'
//	return 0;
//}




//int main()
//{
//	using namespace std;
//
//	cout << "��ķ���ʲôʱ�򽨵�"<<endl;
//	int year;
//	cin >> year;
//	//(cin >> year).get();	//����������������
//	cin.get();//����year���и�\0����������У�cin.get()����ȡ��\0��
//
//	cout << "���ڵĵ�ַ��ʲô" << endl;
//	char address[80];
//	cin.getline(address, 80);
//	cout << "������ʱ��" << year<<endl;
//	cout << "��ַ�� " << address << endl;
//	cout << "����	" << endl;
//
//
//
//
//	//const int Arsize = 20;//���峣����20
//	//char name[Arsize];//����char(�ֽ��ͣ�����name������20
//	//char dessert[Arsize];//����char(�ֽ��ͣ�����dessert������20
//	//cout << "enter your name:\n";
//	////cin.getline(name,20);
//	////cin.get(name, Arsize).get();//�ڶ���get()��ʾ��\0��Ū��������ֹ�´�����ʱ��ֱ�ӵ���\0,���޷���������
//	//cin.get(name, Arsize);//��������һ���ַ���
//	//cin.clear();
//	//cout << "enter you favorite dessert:\n";
//	////cin >> dessert;
//	//cin.get(dessert, 20).get();
//	//cout << "i have some delicious  " << dessert;
//	//cout << "  for you ," << name << ",\n";
//
//	return 0;
//}



//int main()
//{
//	using namespace std;
//	//char ch = 'S';
//
//	cout<<strlen("abcdef")<<endl;
//	cout << sizeof("abcdef");
//	return 0;
//}





//�����±����ϰ


//int main()
//{
//	using namespace std;
//	double  renkou = 7245713546;
//	double zgrk = 1452187654;
//	float zhanbi = (zgrk / renkou)*100;
//	cout << "�����˿���" << renkou<<endl;
//	cout << "�й��˿���" << zgrk<<endl;
//	cout << "�й��˿�ռ��" << zhanbi << "%";
//	return 0;
//}





//int main()
//{
//	//4
//	using namespace std;
//	cout << "����������������__��__ʱ__��__��" << endl;
//	long s = 0;
//	cin >> s;
//	int day = s / (24 * 60 * 60);
//	int hour = (s - 24 * 60 * 60 * 365)/(60*60);
//	int mint = (s - day * 24 * 60 * 60-hour*60*60)/60;
//	int fen = s - day * 24 * 60 * 60 - hour * 60 * 60 - mint * 60;
//	cout <<"ʱ�任�㣺" << day << "��";
//	cout << hour<<"ʱ" ;
//	cout << mint << "��" ;
//	cout << fen << "��" ;
//	return 0;
//}






//int main()
//{
//	//3
//	using namespace std;
//	const float dtm = 60;
//	const float dts = 3600;
//	cout << "Plece enter a latitude in degrees,minutes,and seconds." << endl;
//	int degrees;
//	cin >> degrees;
//	cout << "First .degrees is " << degrees << endl;
//	int minutes;
//	cin >> minutes;
//	cout << "Next .minutes is " << minutes << endl;
//	int seconds;
//	cin >> seconds;
//	cout << "End .seconds is " << seconds << endl;
//	float huansuan = degrees + minutes / dtm + seconds / dts;
//	cout << degrees << " degrees ," << minutes << " minutes ," << seconds << " seconds ,=" <<huansuan<<endl ;
//	return 0;
//}







//int main()
//{
//	//1Ӣ��=12Ӣ�磬1Ӣ��=0.0254m
//	using namespace std;
//	const float huanmi = 0.0245;
//	const int ycyc = 12;
//	const float yb = 2.2;
//	float yingchun;
//	int yingchi;
//	float tizhong;
//	float BMI=0;
//	cout << "�����뼸Ӣ��" << endl;
//	cin >> yingchi;
//	cout << yingchi << "Ӣ��" << endl;
//	cout << "������Ӣ��" << endl;
//	cin >> yingchun;
//	cout << yingchun << "Ӣ��" << endl;
//	float mi = (yingchi * ycyc + yingchun) * huanmi;
//	cout << "������������:" << mi<< "��"<<endl;
//	cout << "��������,��λӢ��" << endl;
//	cin >> tizhong;
//	float qk = tizhong / yb;
//	cout << "�����ǧ��" <<qk  << "ǧ��" << endl;
//	cout << "��Ľ���ָ��BMIΪ" << pow((qk / mi), 2);
//	return 0;
//}






//int main()
//{
//	//1
//	using namespace std;
//	const float ychsdw = 30.48;
//	const float ychs = 2.54;
//	int shengao;
//	cout << "���������" << endl;
//	cin >> shengao;
//	cout << "ת����Ӣ��:__________\b\b\b\b\b\b\b " << shengao * ychsdw << endl;
//	cout << "ת����Ӣ��:__________\b\b\b\b\b\b\b" << shengao * ychs << endl;
//	return 0;
//}








//int main()
//{
//	using namespace std;
//	//cout << "Hello World"<<endl;
//	int a = { 10 };
//	int d = {};
//	double b = 3.14f;
//	int c = a * b;
//	cout <<  c << endl;
//	return 0;
//}