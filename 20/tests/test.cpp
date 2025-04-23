#include "../a.h"
#include <iostream>

int main() {
	if (a(2) == 6) {
		std::cout << "Good\n";
	} else {
		std::cout << "Bad\n";
		return 1;
	}
}