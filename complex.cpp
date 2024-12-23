#include <iostream>

#include "complex.hpp"


int main() {
	complex a = { 3, 4 }, b = { 2, 1 };

	std::cout << "1 = " << (complex(1)) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "Re(a) = " << a.Re() << std::endl;
	std::cout << "Im(a) = " << a.Im() << std::endl;
	std::cout << "|a| = " << a.Abs() << std::endl;
	std::cout << "~a = " << ~a << std::endl;
	std::cout << "a * ~a = " << (a * ~a) << std::endl;
	std::cout << "a = " << a << ", (a == a) = " << int(a == a) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", (a == b) = " << int(a == b) << std::endl;
	std::cout << "a = " << a << ", 1 + a = " << (1 + a) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a + b = " << (a + b) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a - b = " << (a - b) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a * b = " << (a * b) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a / b = " << (a / b) << std::endl;
	std::cout << "a = " << a << ", a ^ 7 = " << a.Pow(7) << std::endl;
	std::cout << "a = " << a << ", Rt(a, 5) = " << a.Rt(4) << std::endl;
	std::cout << "a = " << a << ", Rt(a, 5, 0) = " << a.Rt(4, 0) << std::endl;

	return 0;
}
