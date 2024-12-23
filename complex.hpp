#ifndef INCLUDE_COMPLEX_H_
#define INCLUDE_COMPLEX_H_

#include <cmath>
#include <iostream>
#include <vector>


class complex {
private:
	long double real, imag;
public:
	complex(long double real = 1.0L, long double imag = 0.0L) : real(real), imag(imag) {}

	long double Re() const {
		return this->real;
	}
	long double Im() const {
		return this->imag;
	}
	long double Abs() const {
		return sqrt(this->real * this->real + this->imag * this->imag);
	}
	long double Arg() const {
		return atan2(this->imag, this->real);
	}
	complex operator~() const {
		return complex{ this->real, -this->imag };
	}

	complex Pow(int deg);
	std::vector<complex> Rt(unsigned int n);
	complex Rt(unsigned int n, unsigned int k);

	friend bool operator==(const complex& lhs, const complex& rhs);
	friend complex operator+(const complex& lhs, const complex& rhs);
	void operator+=(const complex& rhs) {
		*this = (*this) + rhs;
	}
	friend complex operator-(const complex& lhs, const complex& rhs);
	void operator-=(const complex& rhs) {
		*this = (*this) - rhs;
	}
	friend complex operator*(const complex& lhs, const complex& rhs);
	void operator*=(const complex& rhs) {
		*this = (*this) * rhs;
	}
	friend complex operator/(const complex& lhs, const complex& rhs);
	void operator/=(const complex& rhs) {
		*this = (*this) / rhs;
	}
};

complex complex::Pow(int deg) {
	if (deg == 0) { return complex{ }; }

	int n = abs(deg);
	size_t size_n = log2(n) + 1;

	std::vector<complex> results(size_n);
	results[0] = *this;
	for (int i = 0; i < size_n - 1; ++i) {
		results[i + 1] = results[i] * results[i];
	}

	std::vector<bool> bin(size_n);
	for (int i = 0; i < size_n; ++i) {
		bin[i] = n % 2;
		n /= 2;
	}

	complex z{ };
	for (int i = 0; i < size_n; ++i) {
		if (bin[i]) {
			z *= results[i];
		}
	}

	return (deg > 0) ? z : (1 / z);
}
std::vector<complex> complex::Rt(unsigned int n) {
	long double pi = 4 * atan(1.0L);
	std::vector<complex> z(n);

	for (int i = 0; i < n; ++i) {
		z[i] = pow(this->Abs(), 1 / n) * ::complex{ cos((this->Arg() + 2 * pi * i) / n), sin((this->Arg() + 2 * pi * i) / n) };
	}

	return z;
}
complex complex::Rt(unsigned int n, unsigned int k) {
	long double pi = 4 * atan(1.0L);

	return pow(this->Abs(), 1 / n) * ::complex{ cos((this->Arg() + 2 * pi * k) / n), sin((this->Arg() + 2 * pi * k) / n) };
}

bool operator==(const complex& lhs, const complex& rhs) {
	return lhs.real == rhs.real && lhs.imag == rhs.imag;
}
complex operator+(const complex& lhs, const complex& rhs) {
	return complex{ rhs.real + lhs.real, rhs.imag + lhs.imag };
}
complex operator-(const complex& lhs, const complex& rhs) {
	return complex{ rhs.real - lhs.real, rhs.imag - lhs.imag };
}
complex operator*(const complex& lhs, const complex& rhs) {
	return complex{ rhs.real * lhs.real - rhs.imag * lhs.imag, rhs.real * lhs.imag + rhs.imag * lhs.real };
}
complex operator/(const complex& lhs, const complex& rhs) {
	return complex{ (rhs.real * rhs.imag + lhs.real * lhs.imag) / (rhs.imag * rhs.imag + lhs.imag * lhs.imag),
					(rhs.imag * lhs.real - rhs.real * lhs.imag) / (rhs.imag * rhs.imag + lhs.imag * lhs.imag)
	};
}


std::ostream& operator<<(std::ostream& os, const complex& z) {
	if (z.Re() != 0 && z.Im() != 0 && abs(z.Im()) != 1) {
		os << z.Re() << ' ' << (z.Im() == abs(z.Im()) ? '+' : '-') << ' ' << abs(z.Im()) << 'i';
	} else if (z.Re() == 0 && z.Im() != 0 && abs(z.Im() != 1)) {
		os << z.Im() << 'i';
	} else if (z.Re() == 0 && abs(z.Im() == 1)) {
		os << (z.Im() == abs(z.Im()) ? '+' : '-') << 'i';
	} else if (z.Re() != 0 && abs(z.Im() == 1)) {
		os << z.Re() << ' ' << (z.Im() == abs(z.Im()) ? '+' : '-') << ' ' << 'i';
	} else {
		os << z.Re();
	}

	return os;
}
std::ostream& operator<<(std::ostream& os, const std::vector<complex>& z) {
	size_t size_z = z.size();
	if (size_z > 0) {
		os << "{ ";
		for (int i = 0; i < size_z-1; ++i) {
			os << z[i] << ", ";
		}
		os << z[size_z - 1] << " }";
	}

	return os;
}


#endif // INCLUDE_COMPLEX_H_
