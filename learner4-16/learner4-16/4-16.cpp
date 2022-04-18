#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

////创建一个Person的类
//class Person
//{
//	/*
//	*	对象的初始化和清理
//		1、构造函数 进行初始化操作
//		构造函数没有返回值，不用写void
//		函数名与类名相同
//		构造函数可以有参数，可以发生重载
//		创建对象的时候，构造函数会自动调用，而且只调用一次。
//	*/
//
//
//	/*
//		2.析构函数 
//		没有返回值不写void
//		函数与类名相同，在名称前加个~
//		析构函数不可以有参数，不可以发生重载
//		对象再销毁前自动调用析构函数，而且只调用一次。
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
////即使程序员不主动创建构造函数或者析构函数，系统自动创建一个空的构造函数和析构函数。
////构造函数
//Person::Person()
//{
//	cout << "创建对象的时候系统默认调用一次\n";
//}
////析构函数
//Person::~Person()
//{
//	cout << "对象销毁时系统调用一次析构函数\n";
//}
//
//int main()
//{
//	//new一个对象
//	//创建时默认调用一次构造函数
//	//销毁时默认调用一次析构函数
//	Person p;
//
//	return 0;
//}




//类的学习

////创建Person的类
//class Person
//{
//	/*
//		属性是name、sex。age、car
//		行为是get_xxx，set_xxx
//	*/
//
//
//
//	//里面是类的成员
//	
//	//公共：类外可以访问，类内也可以访问
//public:
//	string name;
//	//给car赋值，带参
//	void set_car_name(string car_name)
//	{
//		 car=car_name;
//	}
//	//读取car的名字,无参
//	string get_car_name()
//	{
//		return car;
//	}
//	//写入性别
//	void set_sex(string sex_c)
//	{
//		sex = sex_c;
//	}
//	//读取性别
//	string get_sex()
//	{
//		return sex;
//	}
//	//设置年龄
//	void set_age(int P_age)
//	{
//		//判断年龄是否合法0<age&& age<150;
//		if (0 > P_age || P_age > 150)
//		{
//			//不符合返回age=0；
//			age = 0;
//			cout << "年龄有误（年龄小于0或者大于150）\n";
//			return ;
//		}
//		age = P_age;
//	}
//	//读取年龄
//	int get_age()
//	{
//		return age;
//	}
//
//	//保护权限：类外访问不了，类内可以访问
//protected:
//	string car;
//	int age=0;
//	
//	//私人：类外访问不了，类内可以访问
//private:
//	string sex;
//};
//
//int main()
//{
//	////通过类外访问Person的成员。
//	////创建一个对象
//	//Person p1;
//	////给成员p1赋值（名字）
//	//p1.name = "张三";
//	////out of p1.name
//	//cout << p1.name << endl;//张三
//
//	////通过类内访问类内protected and private
//	//
//	////读取与写入car的值
//	//p1.set_car_name("法拉利");
//	//cout << p1.get_car_name() << endl;
//
//	////读取与写入sex的值
//	//p1.set_sex("男");
//	//cout << p1.get_sex() << endl;
//
//
//	//创建另一个对象p2
//	Person p2;
//	//给名字、坐骑、性别、年龄
//	p2.name = "李四";
//	p2.set_car_name("奔驰");
//	p2.set_sex("女");
//	p2.set_age(18);
//	//修改age
//	p2.set_age(20);
//	//读取p2信息
//	cout << "姓名：" << p2.name << "\t坐骑:" << p2.get_car_name() << "\t性别：" << p2.get_sex() <<
//		"\t年龄："<<p2.get_age() << endl;
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
//int sum_arr(int arr[], int n);//函数定义
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






//文本输入

//const int SIZE = 60;
//int main()
//{
//	using namespace std;
//	char filename[SIZE];
//	ifstream inFile;//创建文件输入
//	cout << "enter name of data file:";
//	cin.getline(filename, SIZE);
//	inFile.open(filename);//关联inFile和文件
//	if (!inFile.is_open())
//	{
//		cout << "could not open the file" << filename << endl;
//		cout << "program terminating.\n";
//		exit(EXIT_FAILURE);//退出失败
//	}
//	double value;
//	double sum = 0.0;
//	int count = 0;//记输入的个数
//
//	inFile >> value;//输入第一个数值
//	while (inFile.good())//判断输入有没有停止
//	{
//		++count;//计数+1；
//		sum += value;//记总
//		inFile >> value;//输入下个数值
//	}
//	if (inFile.eof())
//	{
//		//判断文件关了吗
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
/// 文本输出
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
//	ofstream outFile;//创建一个outFile的类
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
//	//在文件夹：C:\Users\97674\Desktop\龚瑞谉\个人\Cpp练习\learner4-16\learner4-16 里有个carinfo.txt
//	//的txt文本。
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
////中断语句，跳出循环
// 
////continue跳过循环体剩下的部分，开始新一轮循环
////break跳过循环部分，到达下一条语句。
//int main()
//{
//	using namespace std;
//	char line[ArSize];
//	int space = 0;
//
//	cout<< "enter a line of text :\n";
//	cin.get(line, ArSize);//输入一行大小为ArSize的字符串
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
//	cout << sanmu<<endl;//函数sanmu的地址
//	cout << i << endl;
//
//	return 0;
//}


