#include "�������󣨷º���).h"

//�º���ʵ��
int MyAdd::operator()(int v1, int v2)
{

    return v1+v2;
}

void test_Add()
{
    MyAdd add;
    //1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ��
    cout << add(10, 53) << endl;
}


void Myprint::operator()(string text)
{
    cout << text << endl;
    this->count++;
}

void doprint(Myprint&mp,string text)
{

    mp(text);
}

void test_print()
{
   // 2.�������󳬳���ͨ�����ĸ����������������Լ���״̬��
    Myprint myprint;
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    cout <<"myprint���õĴ�����" << myprint.count << endl;

    //3.�������������Ϊ�������ݡ� 
    doprint(myprint,"1+1=2");
}