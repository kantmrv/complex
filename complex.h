#include <iostream>
#include <vector>


class complex {
private:
	long double real, imag;
public:
	complex(long double real = 1.0, long double imag = 0.0) : real(real), imag(imag) {}

	long double Re() const {
		return this->real;
	}
	long double Im() const {
		return this->imag;
	}
	long double Abs() const {
		return sqrt(this->real * this->real + this->imag * this->imag);
	}
	complex operator~() const {
		return complex{ this->real, -this->imag };
	}

	friend bool operator==(complex const& lhs, complex const& rhs);

	friend complex operator+(complex const& lhs, complex const& rhs);
	void operator+=(complex const& rhs) {
		*this = (*this) + rhs;
	}

	friend complex operator-(complex const& lhs, complex const& rhs);
	void operator-=(complex const& rhs) {
		*this = (*this) - rhs;
	}

	friend complex operator*(complex const& lhs, complex const& rhs);
	void operator*=(complex const& rhs) {
		*this = (*this) * rhs;
	}

	friend complex operator/(complex const& lhs, complex const& rhs);
	void operator/=(complex const& rhs) {
		*this = (*this) / rhs;
	}

	complex operator^(int rhs) {
		if (rhs == 0) { return complex{ }; }

		int n = abs(rhs);
		int size_n = log2(n) + 1;

		std::vector<complex> results(size_n);
		results[0] = *this;
		for (int i = 0; i < size_n - 1; ++i) {
			results[i + 1] = results[i] * results[i];
		}

		std::vector<bool> bin(size_n);
		for (int i = 0; i < bin.size(); ++i) {
			bin[i] = n % 2;
			n /= 2;
		}

		complex complex{ };
		for (int i = 0; i < size_n; ++i) {
			if (bin[i]) {
				complex *= results[i];
			}
		}

		return (rhs > 0) ? complex : (1 / complex);
	}
	void operator^=(int const& rhs) {
		*this = (*this) ^ rhs;
	}
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
