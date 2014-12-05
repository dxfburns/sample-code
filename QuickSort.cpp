#include "stdafx.h"
#include <iostream>
using namespace std;

void quick_sort(int* arr, int start, int end) {
	if(start < end) {
		int key = arr[start];
		int low = start;
		int high = end;

		while(low < high) {
			while (low < high && arr[high] > key){
				high--;
			}
			arr[low] = arr[high];

			while(low < high && arr[low] < key) {
				low++;
			}
			arr[high] = arr[low];
		}
		arr[low] = key;

		quick_sort(arr, start, low - 1);
		quick_sort(arr, low + 1, end);
	}
}

void run_quick_sort() {
	int arr[] = {2,4,9,3,6,7,1,5};
	quick_sort(arr,0,7);

	int i = 0;
	for(; i < 8; ++i) {
		printf("%d ", arr[i]);
	}
}