#include "stdafx.h"
#include <iostream>
using namespace std;

struct AB {
	AB(){
		std::cout<<"A";
	}
};

struct BB:public AB {
	BB(){
		std::cout<<"B";
	}
};

struct CB {
	CB(){
		std::cout<<"C";
	}
	BB b;
	AB a;
};

void run_ttest() {
	CB c;
}