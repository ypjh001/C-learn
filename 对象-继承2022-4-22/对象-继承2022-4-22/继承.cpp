//����̳�
#include<iostream>
using namespace std;

//����I
class Base1
{
	friend void test1();
public:
	Base1();
	~Base1();
	int A=0;
	void func_test()
	{
		cout << "Base1�ĺ�������" << endl;
	}
	void func_test(int a)
	{
		cout << "Base1�ĺ������ص���" << endl;
	}
protected:
	int B=0;
private:
	int C=0;

};

Base1::Base1()
{
}

Base1::~Base1()
{
}

//����I�̳и���I,public�̳�ʱ�����˸����˽�г�Ա���ܼ̳�֮�⣬�����Ķ���public���͵ĳ�Ա
class Son1 :public  Base1
{
public:
	friend void test1();
	Son1();
	~Son1();
	void fangwen();
	int A = 100;
	void func_test()
	{
		cout << "Son1�ĺ�������" << endl;
	}
private:

};

Son1::Son1()
{

}

Son1::~Son1()
{
}

void Son1::fangwen()
{
	Son1 S1;
	S1.A = 10;		//����	����������̳�ʱҲ����	����Ȩ�ޣ�����		���� ����
	S1.B = 20;		//����	����������̳�ʱҲ����	����Ȩ�ޣ����⺯��	���� ���ʣ�������ͨ����Ԫ���ʡ�
	//S1.C = 30;	//erro,C�Ǹ����˽�г�Ա������˽�����ԣ����಻�ܼ̳У����������������ɳ�ԱC�������ܵ��ú���ʾ����ϵͳ���أ�,ͬ������Ԫ���Է��ʸ����˽�г�Ա
	cout << "fangwen";
	
}
void test1()
{
	Son1 S1;
	S1.A = 10;
	S1.B = 20;
	S1.C = 30;
	cout <<"Son1��" << S1.A << endl;
	cout << "Son1��" << S1.B << endl;
	cout << "Son1��" << S1.C << endl;
	S1.fangwen();
}

void tongchengyuan_test4()
{
	//���и���ĳ�Ա������ĳ�Ա������ͬʱ��ֱ�ӷ���ֻ�ܷ�������ĳ�Ա��
	//���Ҫ���ʸ���ĳ�Աʱ��Ҫ��������	Base1::
	Son1 S4;
	cout <<"Sone1:" << S4.A << endl;
	cout << "Base1:" << S4.Base1::A << endl;
}

void tonghanshu_test5()
{
	//�����ຯ���븸�ຯ��ͬ���ǣ�ֱ�ӵ������ȵ������ຯ�������ຯ�����ظ�������������ͬ���ĺ�����(�����������أ�
	//Ҫ���ʸ����������ͬ����������Ҫ�������� Base::
	//
	Son1 S5;
	//S5.func_test(5);//erro,���ֱ����ô����void func_test(int a),������û�иú���������ʱ�����������򱨴���ôҪ���ʸ���������ͬ�������غ�������Ҫ�������� Base::
	S5.func_test();
	S5.Base1::func_test();
	S5.Base1::func_test(5);
}

//---------------------------------------------------
//����II
class Base2
{
	friend void test2();//��Ԫvoid test2����
public:
	Base2();
	~Base2();
	int A=0;
protected:
	int B=0;
private:
	int C=0;
};

Base2::Base2()
{
}

Base2::~Base2()
{
}
//����II�̳и���II
class Son2:protected Base2
{
	friend void test2();//��Ԫvoid test2����
public:
	Son2();
	~Son2();
private:

};

Son2::Son2()
{
}

Son2::~Son2()
{
}

void test2()
{
	Son2 S2;
	S2.A = 10;//�����̳�----����Ϊ����	����̳�ʱ��	��������	����Ԫ���Է���
	S2.B = 20;//�����̳�----����Ϊ����	����̳�ʱ��	��������	����Ԫ���Է���
	S2.C = 30;//�����̳�----����Ϊ˽��	����̳�ʱ��	˽������	����Ԫ���Է���
	cout << "Son2��" << S2.A << endl;
	cout << "Son2��" << S2.B << endl;
	cout << "Son2��" << S2.C << endl;
}

//-------------------------------------------
//����III
class Base3
{
	friend void test3();//��Ԫvoid test3����
public:
	Base3();
	~Base3();
	int A=0;
protected:
	int B=0;
private:
	int C=0;
};

Base3::Base3()
{
	cout << "Base3�Ĺ��캯������" << endl;
}

Base3::~Base3()
{
	cout << "Base3��������������" << endl;
}

//����3�̳и���3
class Son3:private Base3
{
	friend void test3();//��Ԫvoid test3����
public:
	Son3();
	~Son3();

private:

};

Son3::Son3()
{
	cout << "Son3�Ĺ��캯������" << endl;
}

Son3::~Son3()
{
	cout << "Son3��������������" << endl;
}

void test3()
{
	/*
		���ഴ�����ʱ���ȵ��ø���Ĺ��캯�����ڵ������౾��Ĺ��캯����
		�������ٶ���ʱ���ȵ�������������������ڵ��ø��������������
	*/
	Son3 S3;
	S3.A = 10;//˽�˼̳�---����Ϊ����	����̳�ʱ��	˽������	����Ԫ���Է���
	S3.B = 20;//˽�˼̳�---����Ϊ����	����̳�ʱ��	˽������	����Ԫ���Է���
	S3.C = 30;//˽�˼̳�---����Ϊ˽��	����̳�ʱ��	˽������	����Ԫ���Է���
	cout << "Son3��" << S3.A << endl;
	cout << "Son3��" << S3.B << endl;
	cout << "Son3��" << S3.C << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//tongchengyuan_test4();
	tonghanshu_test5();
	return 0;
}