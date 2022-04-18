#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<cstring>




//struct jiegouti
//{
//	//甚至可以创建结构体的同时创建结构体变量并赋值
//	//不建议怎么搞，结构体变量多之后会比较乱
//	int age;
//}p1={12};
//
//struct MyStruct
//{
//	char ch[10];
//}s3,s4;//也可以这么创建结构体变量s3,s4
//
//int main()
//{
//	using namespace std;
//	//s1和s2叫结构体变量，ch叫结构体成员
//	MyStruct s1 = { "ABCDEF" };
//	MyStruct s2 = s1;//可以成员之间赋值：s2.ch=ABCDEF
//	s3 = { "qwer" };
//	s4 = { "opug" };
//	cout<<s1.ch[2]<<endl;//C
//	cout << s1.ch[5]<<endl ;//F
//	cout << s1.ch[4]+1 <<endl;//70,s1.ch[4]打印E，+1之后自动转换为int类型，变69+1=70
//	cout <<(int) 'A'<<endl;//65,强转int
//	cout << (int)'F' << endl;//70
//	//打印s2的信息，与s1一样
//	cout << s1.ch << endl;//ABCDEF
//	cout << s2.ch << endl;//ABCDEF
//	cout << s3.ch << endl;//qwer
//	cout << s4.ch << endl;//opug
//	cout<<p1.age;//12
//	return 0;
//}




//定义person的结构体

//struct person
//{
//	//结构体成员 name/age/id
//	char name[20];
//	int age;
//	long id;
//};
//int main()
//{
//	using namespace std;
//	//1.创建结构体person成员名p1和p2；
//	person p1={"zhangsan",18,232};//给成员名p1赋值,C++可以省略struct
//	cout << p1.name<<endl;//通过p1.name访问成员名字
//	cout << p1.age<<endl;//age
//	cout << p1.id<<endl;//id
//	struct person p2={"sdaf",15,45};
//	cout << p2.name << endl;//通过p2.name访问成员名字
//	cout << p2.age << endl;//age
//	cout << p2.id << endl;//id
//	p2.age = 99;//可以更改成员信息age
//	cout << p2.age<<endl;
//	//2.结构体数组
//	person pi[] =
//	{
//		{"lisi",12,31},
//		{"grs",23,23},
//		{"xiangjiao",45,21}
//	};
//	int i;
//	for ( i = 0; i < 3; i++)
//	{
//		cout <<"姓名：" <<i<< pi[i].name << endl;
//		cout << "年龄：" <<i<< pi[i].age << endl;
//		cout << "学号：" <<i<< pi[i].id << endl;
//	}
//	return 0;
//}






//int main()
//{
//	using namespace std;
//	char charr[20];//数组未初始化时，trelen(charr)时随机值
//	string str;//未初始化的string长度自动是0
//
//	cout << "lengeh of string in charr before input: " << strlen(charr) << endl;//未初始化charr时，有警告
//	cout << "lengch of string in str before input: " << str.size() << endl;//size不包含\n
//	cout << "enter a line of text:\n";
//	cin.getline(charr, 20);//当给数组charr输入数值时，strlen(charr)可以计算出除\n以外的字符长度
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
//	//字符串可以互相赋值，数组不行
//	string str1="abcd";
//	string str2=str1;
//	//字符串可以相加拼接
//	string str3 = str1 + str2;
//	cout << str2<<endl;//abcd
//	cout << str3<<endl;//abcdabcd
//	//可以用strcpy（ch1，ch2)进行字符串数组复制
//	char ch1[] =  "qwer";
//	char ch2[10];
//	const char ch3[] = "f";
//	//strcpy(ch2,ch1);//strcpy只能用与char类型之间复制，strcpy（目标，复制样本）
//	//strcat(ch1, ch2);//strcat将字符串附加到字符数组末尾。注意，数组的容量大小
//
//	//另一种复制和附加与strcpy和ctrcat类似
//	//使用strncpy时要注意，\n不会被复制过去，会乱码，，count要大于\n地址时，机器才能不乱码
//	strncpy(ch2, ch1,8);//当count=3时ch2=qwe，会打印乱码
//	strncat(ch2, ch3, 1);
//	strncat(ch1, ch2, 5);//当count=2时ch1=qwerqw,count=5时ch1=qwerqwer
//	cout << ch2<<endl;
//	cout << ch1<<endl;
//	cout << str1.size() << endl;
//	cout << strlen(ch1)<<endl;//不包含\n
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
//	cout << "the third letter in" << charr2 << " is " << charr2[2] << endl;//charr2[2]读取到‘g'
//	cout << "the third letter in" << str2 << " is " << str2[2] << endl;//str2[2]读取到’n'
//	return 0;
//}




//int main()
//{
//	using namespace std;
//
//	cout << "你的房子什么时候建的"<<endl;
//	int year;
//	cin >> year;
//	//(cin >> year).get();	//或者用左边这个方法
//	cin.get();//输入year后，有个\0在输入队列中，cin.get()就是取出\0，
//
//	cout << "你在的地址是什么" << endl;
//	char address[80];
//	cin.getline(address, 80);
//	cout << "建立的时间" << year<<endl;
//	cout << "地址是 " << address << endl;
//	cout << "结束	" << endl;
//
//
//
//
//	//const int Arsize = 20;//定义常变量20
//	//char name[Arsize];//定义char(字节型）数组name，长度20
//	//char dessert[Arsize];//定义char(字节型）数组dessert，长度20
//	//cout << "enter your name:\n";
//	////cin.getline(name,20);
//	////cin.get(name, Arsize).get();//第二个get()表示把\0给弄出来，防止下次输入时，直接调用\0,而无法正常输入
//	//cin.get(name, Arsize);//键盘输入一行字符串
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





//第三章编程练习


//int main()
//{
//	using namespace std;
//	double  renkou = 7245713546;
//	double zgrk = 1452187654;
//	float zhanbi = (zgrk / renkou)*100;
//	cout << "世界人口有" << renkou<<endl;
//	cout << "中国人口有" << zgrk<<endl;
//	cout << "中国人口占比" << zhanbi << "%";
//	return 0;
//}





//int main()
//{
//	//4
//	using namespace std;
//	cout << "请输入秒数，返回__天__时__分__秒" << endl;
//	long s = 0;
//	cin >> s;
//	int day = s / (24 * 60 * 60);
//	int hour = (s - 24 * 60 * 60 * 365)/(60*60);
//	int mint = (s - day * 24 * 60 * 60-hour*60*60)/60;
//	int fen = s - day * 24 * 60 * 60 - hour * 60 * 60 - mint * 60;
//	cout <<"时间换算：" << day << "天";
//	cout << hour<<"时" ;
//	cout << mint << "分" ;
//	cout << fen << "秒" ;
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
//	//1英尺=12英寸，1英寸=0.0254m
//	using namespace std;
//	const float huanmi = 0.0245;
//	const int ycyc = 12;
//	const float yb = 2.2;
//	float yingchun;
//	int yingchi;
//	float tizhong;
//	float BMI=0;
//	cout << "请输入几英尺" << endl;
//	cin >> yingchi;
//	cout << yingchi << "英尺" << endl;
//	cout << "请输入英寸" << endl;
//	cin >> yingchun;
//	cout << yingchun << "英寸" << endl;
//	float mi = (yingchi * ycyc + yingchun) * huanmi;
//	cout << "估计你的身高是:" << mi<< "米"<<endl;
//	cout << "输入体重,单位英镑" << endl;
//	cin >> tizhong;
//	float qk = tizhong / yb;
//	cout << "换算成千克" <<qk  << "千克" << endl;
//	cout << "你的健康指标BMI为" << pow((qk / mi), 2);
//	return 0;
//}






//int main()
//{
//	//1
//	using namespace std;
//	const float ychsdw = 30.48;
//	const float ychs = 2.54;
//	int shengao;
//	cout << "请输入身高" << endl;
//	cin >> shengao;
//	cout << "转换成英尺:__________\b\b\b\b\b\b\b " << shengao * ychsdw << endl;
//	cout << "转换成英寸:__________\b\b\b\b\b\b\b" << shengao * ychs << endl;
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