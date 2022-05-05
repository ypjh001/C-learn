#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;

/*
	map：
		1.所有的元素都是pari（关联容器）
		2.pari中第一个元素是key，起索引作用，第二个元素为value（实值）
		3.所有元素根据key的值来自动排序

		优点：根据key中快速找到value值

	map与multimap区别
		1.map不允许有重复key值
		2.multimap允许有重复key值
*/

//map构造
void test_structurn_map();

//大小和交换
void tset_SizeAndSwap_map();

//map的插入和删除
void test_InsertAndDelete_map();