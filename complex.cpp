#include "complex.h"


int main() {
	complex a = { 3, 4 }, b = { 2, 1 };
	
	std::cout << "a = " << a << std::endl;
	std::cout << "Re(a) = " << a.Re() << std::endl;
	std::cout << "Im(a) = " << a.Im() << std::endl;
	std::cout << "|a| = " << a.Abs() << std::endl;
	std::cout << "~a = " << ~a << std::endl;
	std::cout << "a * ~a = " << a * ~a << std::endl;
	std::cout << "a = " << a << ", (a == a) = " << int(a == a) << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", (a == b) = " << int(a == b) << std::endl;
	std::cout << "a = " << a << ", 1 = " << complex(1) << ", a + 1 = " << a + 1 << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a + b = " << a + b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a - b = " << a - b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a * b = " << a * b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a / b = " << a / b << std::endl;

	return 0;
}
