#include "stdafx.h"
#include <iostream>
using namespace std;

struct
{
  char a;
  short b;
  char c;
}S1;

struct
{
  char  a;
  char  b;
  short c;
}S2; 

class A
{
int i;
float ii;
char iii1;
int iii2;
char iii3;
};

class B
{
int f();
};

typedef int (*func)(int);
int sig_chid(int id) 
{
    size_t t;
    t= 1000;
    int i =3;
    return t+i;
}
#include <map>
void new_test_run() {
	func fn = sig_chid;
    printf("%d\n",sizeof(fn));
   A aa;
  int a[10];
  int *p=a;
  int (*q)[10];
  int *s[10];
  int **s1[10][4];
  A (*f)();
  cout<<sizeof(S1)<<endl;
  cout<<sizeof(S2)<<endl;
  cout<<sizeof(short)<<endl;
  cout<<sizeof(a)<<endl;
  cout<<sizeof(p)<<endl;
  cout<<sizeof(q)<<endl;
  cout<<sizeof(s)<<endl;
  cout<<sizeof(s1)<<endl;
  cout<<sizeof(f)<<endl;
  cout<<sizeof(aa)<<endl;
  cout<<sizeof(map<int,A>)<<endl;
  unsigned  int i=2;
  int j=-2;
  cout<<i+j<<endl;

}

static char str[] = "i am a string.";
//static char* str = "i am a string.";// can not modify any charactor since it is in const zone
static char* modi_str(char* str, size_t idx,char ch) {
	str[idx] = ch;
	return str;
}

void run_modi_str() {
	char* str_modi = modi_str(str,10,'!');
	printf("orig string: %s\n", str);
	printf("modi string: %s\n", str_modi);
}

typedef struct link {
	int data;
	link* next;
} my_link;

my_link* merge(my_link* a, my_link* b) {
	my_link* result = NULL;

	if(a==NULL) {
		return b;
	}

	if(b == NULL) {
		return a;
	}

	if(a->data < b->data) {
		result = a;
		result->next = merge(a->next, b);
	} else {
		result = b;
		result->next = merge(a,b->next);
	}

	return result;
}

void merge_sort(int a[], int len_a, int idx_a, int b[], int len_b, int idx_b, int* c) {
	if(idx_a == len_a) {
		*c = b[idx_b];
		return;
	} 
	if(idx_b == len_b) {
		*c = a[idx_a];
		return;
	} 

	if(a[idx_a] < b[idx_b]) {
		*c = a[idx_a] ;
		merge_sort(a, len_a, ++idx_a,b,len_b,idx_b,++c);
	} else {
		*c = b[idx_b];
		merge_sort(a, len_a, idx_a,b,len_b,++idx_b,++c);
	}
}

void run_array_merge() {
	int a[] = {1,3,5,7};
	int b[] = {2,6};
	int c[6] = {0};

	merge_sort(a,4,0,b,2,0,c);

	for(int i = 0;i<6;i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
}

void run_linknode_merge() {
	run_modi_str();
	run_array_merge();

	my_link* ml_a1 = (my_link*) malloc(sizeof(my_link));
	my_link* ml_a2 = (my_link*) malloc(sizeof(my_link));
	my_link* ml_a3 = (my_link*) malloc(sizeof(my_link));
	my_link* ml_a4 = (my_link*) malloc(sizeof(my_link));

	my_link* ml_b1 = (my_link*) malloc(sizeof(my_link));
	my_link* ml_b2 = (my_link*) malloc(sizeof(my_link));

	ml_a1->data = 1;
	ml_a1->next = ml_a2;
	ml_a2->data = 3;
	ml_a2->next = ml_a3;
	ml_a3->data = 6;
	ml_a3->next = ml_a4;
	ml_a4->data = 9;
	ml_a4->next = 0;

	ml_b1->data = 2;
	ml_b1->next = ml_b2;
	ml_b2->data = 7;
	ml_b2->next = 0;

	my_link* result = merge(ml_a1, ml_b1);

	while(result!=NULL) {
		printf("%d ", result->data);
		result = result->next;
	}
	printf("\n");
}

typedef struct seq_str {
	char string[100];
	int length;
} seq_str;

void get_next(seq_str p, int next[]) {
	int i, j;
	next[0] = -1;
	i = 0;//指向字符串每个字符的指针
	j = -1;

	while(i < p.length) {
		if(j == -1 || p.string[i] == p.string[j]){
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}

	for(i = 0; i < p.length; ++i) {
		printf("%d", next[i]);
	}
}

int kmp(seq_str t, seq_str p, int next[]) {
	int i = 0, j = 0;
	while (i < t.length && j <p.length) {
		if(j== -1 || t.string[i] == p.string[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
	}

	if (j == p.length) return i- p.length;
	else return -1;
}

void run_kmp() {
	char c = 0;
    c -= 129;
    printf("c:%d, %c\n", c, c);//127
	char* str = NULL;
	char s[13] ;
	str = s;
    strcpy_s(s, "i am a student");
    printf("%s\n", str);
	
	seq_str t,p;
	int next[50];

	strcpy_s(t.string,"i am kaka");
	t.length=strlen(t.string);
	strcpy_s(p.string,"kaka");
	p.length = strlen(p.string);

	get_next(p,next);
	int res = kmp(t,p,next);
	printf("\n%d\n", res);
}
