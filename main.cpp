#include <iostream>
#include "autoptr.h"

int main() {
	autoptr<int> ptr(new int(15));
	std::cout << *ptr << std::endl;

	autoptr<int> ptr2 = ptr.release();
	//std::cout << *ptr << std::endl; //can't cout nullptr
	std::cout << *ptr2 << std::endl;

	autoptr<int> ptr3 = std::move(ptr2);
	std::cout << *ptr3 << std::endl;
}