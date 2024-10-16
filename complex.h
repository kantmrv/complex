#include <cmath>
#include <iostream>


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

	friend bool operator==(complex const& lhs, complex const& rhs);
	friend complex operator+(complex const& lhs, complex const& rhs);
	friend complex operator-(complex const& lhs, complex const& rhs);
	friend complex operator*(complex const& lhs, complex const& rhs);
	friend complex operator/(complex const& lhs, complex const& rhs);
};

bool operator==(complex const& lhs, complex const& rhs) {
	return lhs.real == rhs.real && lhs.imag == rhs.imag;
}
complex operator+(complex const& lhs, complex const& rhs) {
	return complex{ rhs.real + lhs.real, rhs.imag + lhs.imag };
}
complex operator-(complex const& lhs, complex const& rhs) {
	return complex{ rhs.real - lhs.real, rhs.imag - lhs.imag };
}
complex operator*(complex const& lhs, complex const& rhs) {
	return complex{ rhs.real * lhs.real - rhs.imag * lhs.imag,
					rhs.real * lhs.imag + rhs.imag * lhs.real
	};
}
complex operator/(complex const& lhs, complex const& rhs) {
	return complex{ (rhs.real * rhs.imag + lhs.real * lhs.imag) /
						(rhs.imag * rhs.imag + lhs.imag * lhs.imag),
					(rhs.imag * lhs.real - rhs.real * lhs.imag) /
						(rhs.imag * rhs.imag + lhs.imag * lhs.imag)
	};
}

std::ostream& operator<<(std::ostream& os, complex const& complex) {
	if (complex.Re() != 0 && complex.Im() != 0 && abs(complex.Im()) != 1) {
		return os << complex.Re() << ' ' << (complex.Im() == abs(complex.Im()) ? '+' : '-') << ' ' << abs(complex.Im()) << 'i';
	} else if (complex.Re() == 0 && complex.Im() != 0 && abs(complex.Im() != 1)) {
		return os << complex.Im() << 'i';
	} else if (complex.Re() == 0 && abs(complex.Im() == 1)) {
		return os << (complex.Im() == abs(complex.Im()) ? '+' : '-') << 'i';
	} else if (complex.Re() != 0 && abs(complex.Im() == 1)) {
		return os << complex.Re() << ' ' << (complex.Im() == abs(complex.Im()) ? '+' : '-') << ' ' << 'i';
	} else {
		return os << complex.Re();
	}
}
