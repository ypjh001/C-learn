#include "函数对象（仿函数).h"

//仿函数实现
int MyAdd::operator()(int v1, int v2)
{

    return v1+v2;
}

void test_Add()
{
    MyAdd add;
    //1.函数对象在使用时，可以向普通函数那样调用，可以有参数，可以有返回值。
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
   // 2.函数对象超出普通函数的概念，函数对象可以有自己的状态。
    Myprint myprint;
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    myprint("Hello World");
    cout <<"myprint调用的次数：" << myprint.count << endl;

    //3.函数对象可以作为参数传递。 
    doprint(myprint,"1+1=2");
}