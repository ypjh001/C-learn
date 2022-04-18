#include<string>
#include <iostream>
#include<cstring>


int main()
{
	using namespace std;
	int tacos[10] = { 5,2,8,4,1,2,2,4,6,8 };
	int* pt = tacos;//传了首元素地址5过去
	pt = pt + 1;//首元素（5）地址+1，指向第二个元素地址2
	int* pe = &tacos[9];//传了第九个元素地址（8）过去
	pe = pe - 1;
	int diff = pe - pt;
	return 0;
}



////指针、数组、指针算术
//int main()
//{
//	using namespace std;
//	double wages[3] = { 100.0,200.0,300.0 };
//	short stacks[3] = { 3,2,1 };
//	double* pw = wages;
//	short* ps = &stacks[0];
//	cout << "pw地址：" << pw << endl << "*pw指向元素：" << *pw << endl;//指向第一个元素,pw首元素地址，*pw首元素100.0
//	cout << "double类型大小：" << sizeof(double) <<"字节" << endl;//8
//	pw = pw + 1;
//	cout << "pw = pw + 1之后"<<endl;
//	cout << "pw地址:" << pw << endl << "*pw指向元素：" << *pw << endl;//指向第二个元素，pw指向第二个元素地址，*pw指向第二个元素200.0
//
//	cout << "-------------------------"<<endl;
//	cout << "ps地址：" << ps << endl << "*ps指向元素：" << *ps << endl;
//	cout <<"short类型大小：" << sizeof(short) << "字节" << endl;
//	ps = ps + 1;
//	cout << "ps = ps + 1之后" << endl;
//	cout << "ps地址：" << ps << endl << "*ps指向元素：" << *ps << endl;
//	cout << "-------------------------" << endl;
//	cout << "wages是整个数组地址，大小：" << sizeof(wages) <<"字节" << endl;//3*8=24
//	cout <<"pw是指针地址，指针大小：" << sizeof(pw) <<"字节" << endl;//单个double地址占8位
//	return 0;
//}



////使用new来创建动态数组
////动态数组：的好处是，编译时，运行阶段需要数组是创建，不需要是不创建，达到节省空间的目的
////静态数组：编写程序时直接创建一个数组，编译时创建一个大小固定的数组，不用时占空间，浪费空间。
//int main()
//{
//	using namespace std;
//	//psome=数组首元素地址
//	int* psome = new int[10];//创建一个包含10个int元素的数组
//	psome[0] = 0.2;
//	psome[1] = 0.5;
//	psome[2] = 0.8;
//	cout << psome[0]<<endl;
//	psome = psome + 1;
//	cout << psome[0] << endl;
//	cout << psome[1] << endl;
//	psome = psome - 1;
//	cout << psome[0] << endl;
//	cout << psome[1] << endl;
//	delete[]psome;
//	//delete[] psome;//释放new创建的数组内存块
//	return 0;
//}



//int main()
//{
//	using namespace std;
//
//	int* ps = new int;
//	//不要创建连个指向同一内存块的指针
//	//int* pi = ps;
//	//delete pi;
//
//
//	////new 分配一个int大小的地址给ps指向
//	//int* ps = new int;
//	////delete 释放分配的内存空间
//	//delete ps;
//	//int i = 15;
//	//int* pi = &i;
//	////delete只能释放有new分配的地址
//	////delete pi; //err
//
//	return 0;
//}




//int main()
//{
//	using namespace std;
//	int night = 1001;
//	int* pt = new int;
//	*pt = 1001;
//
//	cout << "night value:";
//	cout << night << ":location" << &night << endl;
//	cout << "int ";
//	cout << "value= " << *pt << ": location " << pt << endl;
//	double* pd = new double;
//	*pd = 10000001.0;
//	cout << "double ";
//	cout << "value :" << *pd << ": location" << pd << endl;
//	cout << "location of pointer pd: " << &pd << endl;
//	cout << "size of pt =" << sizeof(pt);//地址pt的长度8
//	cout << ": size of *pt= " << sizeof(*pt) << endl;//1001的长度4
//	cout << "size of pd = " << sizeof pd;//地址pd的长度8
//	cout << ": size of *pd = " << sizeof(*pd) << endl;//10000001.0长度8
//	return 0;
//}




//指针
//int main()
//{
//	using namespace std;
//	int* pn = new int;
//	*pn = 1001;
//	cout << pn<<endl;	//地址
//	cout << *pn << endl;//1001
//
//
//	/*cout << &pn<<endl;
//	cout << &pn + 1<<endl;
//	cout << sizeof(pn);*/
//
//
//	//int i = 6;//创建变量（地址）i
//	//int* pi = &i;//创建指针变量pi存i的地址；
//	//cout << &pi << endl;//访问pi的地址
//	//cout << &i<<endl;//访问i的地址
//	//cout << pi << endl;//取出i的地址
//	//cout << i << endl;//i是变量也是地址，直接访问i=6
//	//cout << *pi << endl;//解引号符，访问6
//	//cout << sizeof(int*) << endl;
//
//
//	return 0;
//}




////枚举enum
//enum colour
//{
//	red,orange,yellow,green,blue,violet,indigo,ultraviolet	//对应0-7
//};
//
//int main()
//{
//	using namespace std;
//	colour c1 = yellow;//2
//	int i = green+blue;//3+4
//	i += yellow;//7+2
//	cout << c1<<endl;//2
//	cout << i <<endl;//9
//	return 0;
//}











////共用体标识符---union,是一种数据格式，储存不同的数据类型。但只能同时存储其中一种类型
//union MyUnion
//{
//	//int_val long_val double_val都是myunio的成员
//	int int_val;
//	long long_val;
//	double double_val;
//};
////共用体可以创建在结构体内
//struct MyStruct
//{
//	std::string name;//string 要有using namespcae std
//	int age;
//	union public_Union
//	{
//		int int_val;
//		long long_val;
//	}val;
//
//};
//int main()
//{
//	using namespace std;
//	MyUnion u1;
//	u1.double_val = 13.05;
//	u1.int_val = 12;
//	MyStruct s1 = { "张三",13 };	
//	cout << u1.double_val<<endl;
//	cout << u1.int_val<<endl;
//	return 0;
//}