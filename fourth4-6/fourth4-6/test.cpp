#include<string>
#include <iostream>
#include<cstring>


int main()
{
	using namespace std;
	int tacos[10] = { 5,2,8,4,1,2,2,4,6,8 };
	int* pt = tacos;//������Ԫ�ص�ַ5��ȥ
	pt = pt + 1;//��Ԫ�أ�5����ַ+1��ָ��ڶ���Ԫ�ص�ַ2
	int* pe = &tacos[9];//���˵ھŸ�Ԫ�ص�ַ��8����ȥ
	pe = pe - 1;
	int diff = pe - pt;
	return 0;
}



////ָ�롢���顢ָ������
//int main()
//{
//	using namespace std;
//	double wages[3] = { 100.0,200.0,300.0 };
//	short stacks[3] = { 3,2,1 };
//	double* pw = wages;
//	short* ps = &stacks[0];
//	cout << "pw��ַ��" << pw << endl << "*pwָ��Ԫ�أ�" << *pw << endl;//ָ���һ��Ԫ��,pw��Ԫ�ص�ַ��*pw��Ԫ��100.0
//	cout << "double���ʹ�С��" << sizeof(double) <<"�ֽ�" << endl;//8
//	pw = pw + 1;
//	cout << "pw = pw + 1֮��"<<endl;
//	cout << "pw��ַ:" << pw << endl << "*pwָ��Ԫ�أ�" << *pw << endl;//ָ��ڶ���Ԫ�أ�pwָ��ڶ���Ԫ�ص�ַ��*pwָ��ڶ���Ԫ��200.0
//
//	cout << "-------------------------"<<endl;
//	cout << "ps��ַ��" << ps << endl << "*psָ��Ԫ�أ�" << *ps << endl;
//	cout <<"short���ʹ�С��" << sizeof(short) << "�ֽ�" << endl;
//	ps = ps + 1;
//	cout << "ps = ps + 1֮��" << endl;
//	cout << "ps��ַ��" << ps << endl << "*psָ��Ԫ�أ�" << *ps << endl;
//	cout << "-------------------------" << endl;
//	cout << "wages�����������ַ����С��" << sizeof(wages) <<"�ֽ�" << endl;//3*8=24
//	cout <<"pw��ָ���ַ��ָ���С��" << sizeof(pw) <<"�ֽ�" << endl;//����double��ַռ8λ
//	return 0;
//}



////ʹ��new��������̬����
////��̬���飺�ĺô��ǣ�����ʱ�����н׶���Ҫ�����Ǵ���������Ҫ�ǲ��������ﵽ��ʡ�ռ��Ŀ��
////��̬���飺��д����ʱֱ�Ӵ���һ�����飬����ʱ����һ����С�̶������飬����ʱռ�ռ䣬�˷ѿռ䡣
//int main()
//{
//	using namespace std;
//	//psome=������Ԫ�ص�ַ
//	int* psome = new int[10];//����һ������10��intԪ�ص�����
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
//	//delete[] psome;//�ͷ�new�����������ڴ��
//	return 0;
//}



//int main()
//{
//	using namespace std;
//
//	int* ps = new int;
//	//��Ҫ��������ָ��ͬһ�ڴ���ָ��
//	//int* pi = ps;
//	//delete pi;
//
//
//	////new ����һ��int��С�ĵ�ַ��psָ��
//	//int* ps = new int;
//	////delete �ͷŷ�����ڴ�ռ�
//	//delete ps;
//	//int i = 15;
//	//int* pi = &i;
//	////deleteֻ���ͷ���new����ĵ�ַ
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
//	cout << "size of pt =" << sizeof(pt);//��ַpt�ĳ���8
//	cout << ": size of *pt= " << sizeof(*pt) << endl;//1001�ĳ���4
//	cout << "size of pd = " << sizeof pd;//��ַpd�ĳ���8
//	cout << ": size of *pd = " << sizeof(*pd) << endl;//10000001.0����8
//	return 0;
//}




//ָ��
//int main()
//{
//	using namespace std;
//	int* pn = new int;
//	*pn = 1001;
//	cout << pn<<endl;	//��ַ
//	cout << *pn << endl;//1001
//
//
//	/*cout << &pn<<endl;
//	cout << &pn + 1<<endl;
//	cout << sizeof(pn);*/
//
//
//	//int i = 6;//������������ַ��i
//	//int* pi = &i;//����ָ�����pi��i�ĵ�ַ��
//	//cout << &pi << endl;//����pi�ĵ�ַ
//	//cout << &i<<endl;//����i�ĵ�ַ
//	//cout << pi << endl;//ȡ��i�ĵ�ַ
//	//cout << i << endl;//i�Ǳ���Ҳ�ǵ�ַ��ֱ�ӷ���i=6
//	//cout << *pi << endl;//�����ŷ�������6
//	//cout << sizeof(int*) << endl;
//
//
//	return 0;
//}




////ö��enum
//enum colour
//{
//	red,orange,yellow,green,blue,violet,indigo,ultraviolet	//��Ӧ0-7
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











////�������ʶ��---union,��һ�����ݸ�ʽ�����治ͬ���������͡���ֻ��ͬʱ�洢����һ������
//union MyUnion
//{
//	//int_val long_val double_val����myunio�ĳ�Ա
//	int int_val;
//	long long_val;
//	double double_val;
//};
////��������Դ����ڽṹ����
//struct MyStruct
//{
//	std::string name;//string Ҫ��using namespcae std
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
//	MyStruct s1 = { "����",13 };	
//	cout << u1.double_val<<endl;
//	cout << u1.int_val<<endl;
//	return 0;
//}