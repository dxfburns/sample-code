// SlopeOneCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <fcntl.h>
using namespace std;

class Rating
{
public:
	float Value;
	int Freq;
	
	Rating():Value(0), Freq(0){}
	Rating(int v, int f) : Value(v), Freq(f) {
		
	}

	float getAverageValue() {
		if (Freq != 0) {
			Value = Value == NULL ? 0 : Value;
			return Value / Freq;
		}

		return 0;
	}
};

class RatingDifferenceCollection : public map<string, Rating*> {
public:
	bool contains(int,int);
	Rating* getRating(int, int);
	void setRating(int,int,Rating*);
	string getKey(int,int);
};

string RatingDifferenceCollection::getKey(int Item1Id, int Item2Id) {
	return (Item1Id < Item2Id) ? Item1Id + "/" + Item2Id : Item2Id + "/" + Item1Id;
}

bool RatingDifferenceCollection::contains(int Item1Id, int Item2Id) {
	map<string,Rating*>::iterator iter = this->find(getKey(Item1Id, Item2Id));
	return iter != this->end();
}

Rating* RatingDifferenceCollection::getRating(int Item1Id, int Item2Id) {
	if(contains(Item1Id,Item2Id)) {
		return this->at(getKey(Item1Id,Item2Id));
	}

	return NULL;
}

void RatingDifferenceCollection::setRating(int Item1Id, int Item2Id, Rating* rating) {
	this->insert(make_pair(getKey(Item1Id,Item2Id),rating));
}

#include <iostream>
class Base {
private:
	virtual void f() { cout << "Base::f" << endl; }
public:
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

void run_virtual_fun() {
	typedef void(*Fun)(void);

	Base b;
	Fun fun = NULL;

	cout << "虚函数表地址：" << &b << "," << (int*)(&b)  << endl;
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

	fun = (Fun)*((int*)*(int*)(&b)); //(Fun)((int*)*(int*)(&b));
	fun();
	fun = (Fun)*((int*)(*(int*)(&b))+1);
	fun();
}

class A
{
private:
 int x;
 int y;
public:
 void sety()
 {
  y=5;
 }
 void print()
 {
  cout<<"x="<<x<<endl<<"y="<<y<<endl;
 }
 virtual void f() {
 cout<<"virtual f()"<<endl;
 }
  virtual void g() {
 cout<<"virtual g()"<<endl;
 }
};

void test_addr()
{
	typedef void(*Fun)(void);

  A a;
  a.sety();
  a.print();
  int *p=(int *)&a;//对象a的内存模型里面，只有非静态数据成员，所以是合理的。
  int *q=(int*)*p;
  Fun fun = (Fun)*q;
  fun();
  fun = (Fun)*++q;
  fun();
  *++p=9;
  a.print();
    *++p=11;
  a.print();
}

struct LinkNode {
	int data;
	LinkNode* next;
};


void print_linknode(LinkNode * node) {
	LinkNode *tmp = node;
	while (tmp)
	{
		cout << tmp->data << "  "; 
		tmp = tmp->next;
	}
	cout << endl;
}

LinkNode * reverse(LinkNode* head) {
	if(head == NULL) {
		return NULL;
	}

	LinkNode *pre, *cur, *ne;
	pre = head;
	cur = head->next;
	head->next = NULL;

	while(cur != NULL) {
		ne = cur->next;
		cur->next = pre;
		pre = cur;
		cur = ne;
	}

	head = pre;
	return head;
	//print_linknode(head);
}

void test_reverse_linknode() {
	LinkNode *head;
	LinkNode node1, node2, node3, node4;
	node1.data = 1;
	node1.next = &node2;
	node2.data = 2;
	node2.next = &node3;
	node3.data = 3;
	node3.next = &node4;
	node4.data = 4;
	node4.next = NULL;

	head = &node1;
	print_linknode(head);

	LinkNode *h = reverse(head);
	print_linknode(h);
}

void test(const char* pStr) {
	char szStr[10] = {0};
	cout<< "sizeof(*pStr) : " << sizeof(*pStr) << endl;
	cout<< "strlen(pStr): " << strlen(pStr) << endl;

	if(strlen(pStr) <= sizeof(szStr)) {
		strcpy_s(szStr, pStr);
	}
}

void test2(const char* pStr){
	printf("%d,%d\n",sizeof(pStr),strlen(pStr));
}

#define M 7
int a[M], sum[M];

int max_sum_pos(int left, int right, int* start, int* end) {
	int i, max = 0;
	sum[left] = a[left];
	*start = left;
	for(i=left + 1; i<= right; ++i) {
		if(sum[i - 1] > 0) {
			sum[i] = sum[i-1] + a[i];
		} else {
			sum[i] = a[i];
			*start = i;
		}
		if(sum[i] > max) {
			max = sum[i];
			*end = i;
		}
	}
	return max;
}

#include <stdio.h>
void test_max_sum_pos() {
	int n, max_sum, start, end, i;
	scanf_s("%d", &n);

	 for (i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }

	 start = end = 0;
	 max_sum = max_sum_pos(0, n-1, &start, &end);
    printf("maxsum = %d, start = %d, end = %d\n", max_sum, start, end);

}

extern void run_mytest();

void func2(int *pb)
{
      pb = new int(5); /// pb重新申请了堆空间
}

void func1()
{
       int *pa = NULL;

       func2(pa); /// 函数返回后pa仍然是空指针

       delete pa; /// pa仍然是空指针，pb申请的空间并没有被delete掉

}

void UpperCase( char str[] ) // 将 str 中的小写字母转换成大写字母

{

    for( size_t i=0; i<sizeof(str)/sizeof(str[0]); ++i )

        if( 'a'<=str[i] && str[i]<='z' )

            str[i] -= ('a'-'A' );

}

int Func_stdcall(int nParam1, int nParam2, ...) 
 { 
     return 1; 
 } 
  
 int __cdecl Func_cdecl(int nParam1, int nParam2, ...) 
 { 
     return 1; 
 } 

 void Run_Test() {
	char* ptr[1024];
    printf("sizeof ptr: %d\n", sizeof(ptr));

	int num = 43;
	int k= printf("%d\n",printf("%d",printf("%d",num)));//4321
	int a[] = {1,2,3,4,5,6};
	int i = 2;
	printf("%d-%d,%d\n",i++,++i,++i);//4-5,5
	i=0;
	printf("%d %d %d %d\n",i++,i++,++i,++i,printf("d"));//d3 2 4 4
	i=8; 
	printf("%d %d %d %d\n",++i,--i,i++,i--);
 }

void Advert_Test() {
	int func = Func_stdcall(1, 2); 
  
     func = Func_cdecl(1, 2, 6,7); 
		//unsigned char A = 0;
	//int num = 0;
	//for(; A < 255; A++)
	//{
	//	num += A;
	//}
	//cout << "num = " << num << endl;

	char* a; int* b; long* c;char* d[5];
	cout<<sizeof(a) << endl;//4
	cout<<sizeof(b) << endl;//4
	cout<<sizeof(c) << endl;//4
	cout<<sizeof(d) << endl;//20

	int aa[] = {1,2,3,4,5};
	int offset = 2;
	printf_s("%d-%d", aa[++offset], aa[offset++]);//5-3
}

extern void new_test_run();

#include <stdlib.h> 
 int atexit(void (*function)(void)); 
 void fn1( void ), fn2( void ), fn3( void ), fn4( void ); 
 void run_ttest();
 int bitmap_run();
 void run_mem_pool();
 void run_linknode_merge();
 void run_top_k();
 void run_quick_sort();

 struct Foo {
    Foo() {}
    Foo(int) {}
    void fun() {}
};

 void run_kmp() ;
 void run_design_pattern();

int _tmain(int argc, _TCHAR* argv[])
{    
	run_design_pattern();
	run_kmp(); 
	run_quick_sort();
	run_top_k();
	//Foo a(10); //语句1  
    //a.fun(); //语句2  
    Foo b(); //语句3  
    //b.fun(); //语句4  
	//run_linknode_merge();
	Run_Test();
	run_mem_pool();
	bitmap_run();
	//run_ttest();
	new_test_run();
	//Advert_Test() ;
	/*func1();
	run_mytest();*/
	 //test_max_sum_pos();
	char str[] = "aBcDe";
	cout << "str字符长度为: " << sizeof(str)/sizeof(str[0]) << endl;

	atexit( fn1 ); 
    atexit( fn2 ); 
    atexit( fn3 ); 
    atexit( fn4 ); 
    printf( "This is executed first.\n" ); 

//UpperCase( str );
//
//cout << str << endl;
//
//	char ch[10] = {0};
//	char* p = "abcdefg";
//	strcpy_s(ch,p);
//	test2(ch);
//
//	test_reverse_linknode();
//
//	test_addr();
//	run_virtual_fun();
//
//	typedef map<int,float> mm;
//
//	map<int,float> m;
//	m.insert(mm::value_type(1,3));
//	m.insert(pair<int,float>(5,7));
//	m.insert(make_pair(2,4.5));
//	m[3] = 5;
//	
//	RatingDifferenceCollection matrix;
//
//	mm::const_iterator iter;
//	for(iter=m.begin(); iter!=m.end();++iter) {
//		for(mm::const_iterator it=m.begin();it!=m.end();++it) {
//			if(iter->first == it->first) continue;
//			Rating* rating = NULL;
//			if(matrix.contains(iter->first,it->first)) {
//				rating = matrix[matrix.getKey(iter->first,it->first)];
//			}else {
//				Rating rt;
//				rating = &rt;
//				matrix.insert(pair<string,Rating*>(matrix.getKey(iter->first,it->first),rating));
//			}
//			rating->Value += iter->second - it->second;
//			rating->Freq += 1;
//		}
//	}

	return 0;
}

void fn1() 
 { 
   printf( "next.\n" ); 
 } 

void fn2() 
 { 
   printf( "executed " ); 
 } 

void fn3() 
 { 
   printf( "is " ); 
 } 

void fn4() 
 { 
   printf( "This " ); 
 }
