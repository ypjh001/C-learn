#include<iostream>
#include"函数对象（仿函数).h"
#include"谓词.hpp"
#include"内建函数对象.hpp"
#include"常用算法.hpp"

using namespace std;

void test_imit_func()
{

	 //test_Add();

	  test_print();
}

void test_predicate()
{
	//test_one_pridicate();

	test_tow_pridicate();
}

void test_intofunc()
{
	test_negage();//测试取反

	test_plus();//测试加法

	test_great();//测试大于

	test_logic();//测试逻辑
}


void test_common_algorithm()
{
	//test_for_each();//测试遍历

	//test_transfrom();//测试搬运

	//===========================查找====================
	 //test_find();//测试查找

	 //test_find_if();//测试条件查找
	
	 //test_adjacent_find();//测试查找相邻同元素

	 //test_binary_seach();//测试二分查找

	 //test_count();	//统计个数

	 //test_count_if();	//统计满足条件的个数

	//===========================排序====================
	 //test_sort();//排序sort

	 //test_random_shufle();//洗牌，打乱random_shuffle

	 //test_merge();//合并容器1和容器2到新容器3里

	 //test_reverse();//反转

	//===========================拷贝====================

	//test_copy();//拷贝--指定范围拷贝到另一个容器里

	//test_replace();//将容器内指定范围旧元素修改为新元素

	//test_replace_if();//容器内指定范围内满足条件的元素换为新元素

	//test_swap();	//swap互换两个容器

	//==================常用算术生成算法================== 
	
	//test_accumulate();//计算容器元素累计总和

	//test_fill();//向容器中添加元素

	//==================常用合集算法================== 

	//test_set_intersection();//求两个容器的交集

	//test_set_union();	//求两个容器的并集

	test_set_difference();//求两个容器的差集
}


int main()
{
	//test_imit_func();


	//test_predicate();


	
	//test_intofunc();

	test_common_algorithm();

	
}