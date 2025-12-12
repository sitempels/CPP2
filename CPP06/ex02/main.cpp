
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"

class Wrong : public Base {};

Base *generate() {
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	std::cout << "Random: ";
	switch (random) {
		case 0:
			std::cout << "A was chosen" <<std::endl;
			return new A();
		case 1:
			std::cout << "B was chosen" <<std::endl;
			return new B();
		case 2:
			std::cout << "C was chosen" <<std::endl;
			return new C();
		default:
			return new A();;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Type: A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p)) {
		std::cout << "Type: B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p)) {
		std::cout << "Type: C" << std::endl;
		return;
	}
	std::cout << "Type: Unknown" << std::endl;
}

void identify(Base &p) {

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return;
	} catch (std::exception &e) {}

	std::cout << "Type: Unknown" << std::endl;
}

int main() {
	std::cout << "--- Test with random instance ---" << std::endl;

	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << std::endl << "--- Test with Wrong ---" << std::endl;
	Wrong wrong;
	identify(&wrong);
	identify(wrong);

	std::cout << std::endl << "--- Test with NULL ---" << std::endl;
	Base *null = NULL;
	identify(null);

	return 0;
}
