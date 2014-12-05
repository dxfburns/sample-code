#include "stdafx.h"
#include <iostream>
using namespace std;

void adjust_heap(int* arr, const size_t len, size_t pos) {
	int min;
	size_t child = (pos * 2) + 1;

	while(1) {
		if(child + 1 < len) {
			min = arr[child] < arr[child + 1] ? arr[child] : arr[++child];
		} else if (child + 1 == len){
			 min = arr[child];
		} else {
			break;
		}

		if(arr[pos] > min) {
			arr[child] = arr[pos];
			arr[pos] = min;
			pos = child;
			child = (pos * 2) + 1;
		} else {
			break;
		}
	}
}

void build_heap(int* arr, const int k) {
	int i;
	for(i = k/2 -1; i>=0; --i) {
		adjust_heap(arr,k, i);
	}
}

void top_k(const int* arr, const size_t len, int* arr_k, const size_t k) {
	size_t i;
	for(i = 0; i<k; ++i) {
		arr_k[i] = arr[i];
	}
	build_heap(arr_k,k);
	for(; i < len; ++i) {
		arr_k[0] = arr[i];
		adjust_heap(arr_k,k,0);
	}
}

void run_top_k() {
	int a[] = {8,1,2,7,6,3,9,4};//{8,1,2,7,3,4,5,6,9};
#define K 4
	size_t i=0;
	int arr_k[K];
	top_k(a,6,arr_k,K+1);
	for(; i<K+1;++i) {
		printf("%d ", arr_k[i]);
	}
}