#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

////����һ��Person����
//class Person
//{
//	/*
//	*	����ĳ�ʼ��������
//		1�����캯�� ���г�ʼ������
//		���캯��û�з���ֵ������дvoid
//		��������������ͬ
//		���캯�������в��������Է�������
//		���������ʱ�򣬹��캯�����Զ����ã�����ֻ����һ�Ρ�
//	*/
//
//
//	/*
//		2.�������� 
//		û�з���ֵ��дvoid
//		������������ͬ��������ǰ�Ӹ�~
//		���������������в����������Է�������
//		����������ǰ�Զ�������������������ֻ����һ�Ρ�
//	*/
//public:
//	
//	Person();
//
//
//	~Person();
//
//private:
//
//};
////��ʹ����Ա�������������캯����������������ϵͳ�Զ�����һ���յĹ��캯��������������
////���캯��
//Person::Person()
//{
//	cout << "���������ʱ��ϵͳĬ�ϵ���һ��\n";
//}
////��������
//Person::~Person()
//{
//	cout << "��������ʱϵͳ����һ����������\n";
//}
//
//int main()
//{
//	//newһ������
//	//����ʱĬ�ϵ���һ�ι��캯��
//	//����ʱĬ�ϵ���һ����������
//	Person p;
//
//	return 0;
//}




//���ѧϰ

////����Person����
//class Person
//{
//	/*
//		������name��sex��age��car
//		��Ϊ��get_xxx��set_xxx
//	*/
//
//
//
//	//��������ĳ�Ա
//	
//	//������������Է��ʣ�����Ҳ���Է���
//public:
//	string name;
//	//��car��ֵ������
//	void set_car_name(string car_name)
//	{
//		 car=car_name;
//	}
//	//��ȡcar������,�޲�
//	string get_car_name()
//	{
//		return car;
//	}
//	//д���Ա�
//	void set_sex(string sex_c)
//	{
//		sex = sex_c;
//	}
//	//��ȡ�Ա�
//	string get_sex()
//	{
//		return sex;
//	}
//	//��������
//	void set_age(int P_age)
//	{
//		//�ж������Ƿ�Ϸ�0<age&& age<150;
//		if (0 > P_age || P_age > 150)
//		{
//			//�����Ϸ���age=0��
//			age = 0;
//			cout << "������������С��0���ߴ���150��\n";
//			return ;
//		}
//		age = P_age;
//	}
//	//��ȡ����
//	int get_age()
//	{
//		return age;
//	}
//
//	//����Ȩ�ޣ�������ʲ��ˣ����ڿ��Է���
//protected:
//	string car;
//	int age=0;
//	
//	//˽�ˣ�������ʲ��ˣ����ڿ��Է���
//private:
//	string sex;
//};
//
//int main()
//{
//	////ͨ���������Person�ĳ�Ա��
//	////����һ������
//	//Person p1;
//	////����Աp1��ֵ�����֣�
//	//p1.name = "����";
//	////out of p1.name
//	//cout << p1.name << endl;//����
//
//	////ͨ�����ڷ�������protected and private
//	//
//	////��ȡ��д��car��ֵ
//	//p1.set_car_name("������");
//	//cout << p1.get_car_name() << endl;
//
//	////��ȡ��д��sex��ֵ
//	//p1.set_sex("��");
//	//cout << p1.get_sex() << endl;
//
//
//	//������һ������p2
//	Person p2;
//	//�����֡�����Ա�����
//	p2.name = "����";
//	p2.set_car_name("����");
//	p2.set_sex("Ů");
//	p2.set_age(18);
//	//�޸�age
//	p2.set_age(20);
//	//��ȡp2��Ϣ
//	cout << "������" << p2.name << "\t����:" << p2.get_car_name() << "\t�Ա�" << p2.get_sex() <<
//		"\t���䣺"<<p2.get_age() << endl;
//	return 0;
//}




//const int ArSize = 8;
//int sum_arr(int arr[], int n);
//int main()
//{
//	using namespace std;
//	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
//	cout << sizeof(cookies) << "=sizeof cookies"<<endl;
//	int sum = sum_arr(cookies, ArSize);
//	cout << sum << endl;
//	sum = sum_arr(cookies, 3);
//	cout << sum << endl;
//	sum = sum_arr(cookies+4, 3);
//	cout << sum << endl;
//	
//	return 0;
//}
//int sum_arr(int arr[], int n)
//{
//	using namespace std;
//	int total = 0;
//	cout << arr << endl;
//	cout << sizeof(arr) << endl;
//	for (int i = 0; i < n; i++)
//	{
//		total = total + arr[i];
//	}
//	return total;
//
//}



//int sum_arr(int arr[], int n)
//{
//	int total = 0;
//	for (int i = 0; i < n; i++)
//	{
//		total = total + arr[i];
//	}
//	return total;
//}
//const int ArSize = 8;
//int sum_arr(int arr[], int n);//��������
//int main()
//{
//	using namespace std;
//	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
//	int sum = sum_arr(cookies, ArSize);//call sum_arr function
//	cout << "total cookies eatrn:" << sum << endl;
//	return 0;
//}
//int sum_arr2(int arr[], int n)
//{
//	int total = 0;
//	for (int i = 0; i < n; i++)
//	{
//		total = total + arr[i];
//	}
//	return 0;
//}






//�ı�����

//const int SIZE = 60;
//int main()
//{
//	using namespace std;
//	char filename[SIZE];
//	ifstream inFile;//�����ļ�����
//	cout << "enter name of data file:";
//	cin.getline(filename, SIZE);
//	inFile.open(filename);//����inFile���ļ�
//	if (!inFile.is_open())
//	{
//		cout << "could not open the file" << filename << endl;
//		cout << "program terminating.\n";
//		exit(EXIT_FAILURE);//�˳�ʧ��
//	}
//	double value;
//	double sum = 0.0;
//	int count = 0;//������ĸ���
//
//	inFile >> value;//�����һ����ֵ
//	while (inFile.good())//�ж�������û��ֹͣ
//	{
//		++count;//����+1��
//		sum += value;//����
//		inFile >> value;//�����¸���ֵ
//	}
//	if (inFile.eof())
//	{
//		//�ж��ļ�������
//		cout << "enter of file reached.\n";
//	}
//	else if(inFile.fail())
//	{
//		cout << "input terminated by data mismatch.\n";
//	}
//	else
//	{
//		cout << "input terminated for unknow reason.\n";
//	}
//	if (count == 0)
//		cout << "no data processed.\n";
//	else
//	{
//		cout << "items read:" << count << endl;
//		cout << "sum:" << sum << endl;
//		cout << "average:" << sum / count << endl;
//	}
//	inFile.close();
//	return 0;
//}



/// <summary>
/// �ı����
/// </summary>
/// <returns></returns>
 
//int main()
//{
//	using namespace std;
//
//	char automobile[50];
//	int year;
//	double a_price;
//	double d_price;
//
//	ofstream outFile;//����һ��outFile����
//	outFile.open("carinfo.txt");
//
//	cout << "ennter the make and model of automobile :";
//	cin.getline(automobile, 50);
//	cout << "enter the model year:";
//	cin >> year;
//	cout << "enter the original asking price:";
//	cin >> a_price;
//	d_price = 0.913 * a_price;
//
//	cout << fixed;
//	cout.precision(2);
//	cout.setf(ios_base::showpoint);
//	cout << "make and model:" << automobile << endl;
//	cout << "year:" << year << endl;
//	cout << "was asking $ " << a_price << endl;
//	cout << "now asking $ " << d_price << endl;
//
//	//���ļ��У�C:\Users\97674\Desktop\����ן\����\Cpp��ϰ\learner4-16\learner4-16 ���и�carinfo.txt
//	//��txt�ı���
//	outFile << fixed;
//	outFile.precision(2);
//	outFile.setf(ios_base::showpoint);
//	outFile << "make and model:" << automobile << endl;
//	outFile << "year:" << year << endl;
//	outFile << "was asking $ " << a_price << endl;
//	outFile << "now asking $ " << d_price << endl;
//
//	outFile.close();
//	return 0;
//}




//const int ArSize = 80;
//
////break and continue
////�ж���䣬����ѭ��
// 
////continue����ѭ����ʣ�µĲ��֣���ʼ��һ��ѭ��
////break����ѭ�����֣�������һ����䡣
//int main()
//{
//	using namespace std;
//	char line[ArSize];
//	int space = 0;
//
//	cout<< "enter a line of text :\n";
//	cin.get(line, ArSize);//����һ�д�СΪArSize���ַ���
//	cout << "complete line:\n" << line << endl;
//	cout << "line through first period :\n";
//	for (int i = 0; line[i] != '\0'; i++)
//	{
//		cout << line[i];
//		if (line[i]=='.')
//		{
//			break;
//		}
//		if (line[i]!=' ')
//		{
//			continue;
//		}
//		space++;
//	}
//	cout << "\n" << space << "space\n";
//	cout << "done.\n";
//	return 0;
//}






//int sanmu(int a,int b)
//{
//
//	return a > b ? a : b;
//}
//
//int main()
//{
//	using namespace std;
//	
//	//cout << "fuck you";
//	int i;
//	i=sanmu(2, 15);
//	cout << sanmu<<endl;//����sanmu�ĵ�ַ
//	cout << i << endl;
//
//	return 0;
//}


