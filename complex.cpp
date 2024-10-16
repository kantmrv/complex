#include <iostream>
#include <cmath>


class complex {
private:
	double real, imag;
public:
	complex(double real, double imag = 0.0) : real(real), imag(imag) {}

	double Re() const {
		return this->real;
	}
	double Im() const {
		return this->imag;
	}
	double Abs() const {
		return sqrt(this->real * this->real + this->imag * this->imag);
	}

	complex operator~() {
		return complex{ this->real, -this->imag };
	}
	bool operator=(complex const& other) {
		return this->real == other.real && this->imag == other.imag;
	}
	complex operator+(complex const& other) {
		return complex{ this->real + other.real, this->imag + other.imag };
	}
	complex operator-(complex const& other) {
		return complex{ this->real - other.real, this->imag - other.imag };
	}
	complex operator*(complex const& other) {
		return complex{ this->real * other.real - this->imag * other.imag,
						this->real * other.imag + this->imag * other.real
		};
	}
	complex operator/(complex const& other) {
		return complex{ (this->real * this->imag + other.real * other.imag) /
							(this->imag * this->imag + other.imag * other.imag),
						(this->imag * other.real - this->real * other.imag) /
							(this->imag * this->imag + other.imag * other.imag)
		};
	}
};

std::ostream& operator<<(std::ostream& os, complex const& c) {
	return os << "( " << c.Re() << "; " << c.Im() << " )";
}

int main() {
	complex a = { 3, 4 }, b = { 2, 1 };
	std::cout << "a = " << a << std::endl;
	std::cout << "Re(a) = " << a.Re() << std::endl;
	std::cout << "Im(a) = " << a.Im() << std::endl;
	std::cout << "|a| = " << a.Abs() << std::endl;
	std::cout << "~a = " << ~a << std::endl;
	std::cout << "a * ~a = " << a * ~a << std::endl;
	std::cout << "a = " << a << ", 1 = " << (complex)1 << ", a + 1 = " << a + 1 << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a * b = " << a * b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a + b = " << a + b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a - b = " << a - b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a * b = " << a * b << std::endl;
	std::cout << "a = " << a << ", b = " << b << ", a / b = " << a / b << std::endl;

	return 0;
}
