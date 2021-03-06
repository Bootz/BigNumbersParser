#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <mpir.h>
#include "MathHelper.h"
#include "ParserException.h"

using namespace std;

namespace BigNumbersParser
{
	/**
	 * Integer number.
	 */
	class Integer
	{
	public:
		Integer();
		Integer(const int precision, const int num);
		Integer(const int num);
		Integer(const int precision, const double num);
		Integer(const Integer& source);
		Integer(const string& num);
		~Integer();

	public:
		typedef Integer value_type;
		
		Integer& operator=(const Integer& source);
		Integer& operator=(const string& num);
		Integer& operator=(const mpz_t& source);
		
		Integer operator+();
		Integer operator-();
		
		friend Integer operator+(const Integer& num1, const Integer& num2);
		friend Integer operator+(const Integer& num1, const int num2);
		friend Integer operator+(const int num1, const Integer& num2);

		friend Integer operator-(const Integer& num1, const Integer& num2);
		friend Integer operator-(const Integer& num1, const int num2);
		friend Integer operator-(const int num1, const Integer& num2);

		friend Integer operator*(const Integer& num1, const Integer& num2);
		friend Integer operator*(const Integer& num1, const int num2);
		friend Integer operator*(const int num1, const Integer& num2);

		friend Integer operator/(const Integer& num1, const Integer& num2);
		friend Integer operator/(const Integer& num1, const int num2);
		friend Integer operator/(const int num1, const Integer& num2);

		friend Integer operator%(const Integer& num1, const Integer& num2);
		friend Integer operator%(const Integer& num1, const int num2);
		friend Integer operator%(const int num1, const Integer& num2);
		
	public:
		void operator+=(const Integer& num);

		void operator-=(const Integer& num);

		void operator*=(const Integer& num);

		void operator/=(const Integer& num);

		void operator%=(const Integer& num);

	public:
		void operator=(const int num);
		
		operator int() const;

	public:
		friend bool operator==(const Integer& num1, const Integer& num2);
		friend bool operator==(const Integer& num1, const int num2);
		friend bool operator==(const int num1, const Integer& num2);

		friend bool operator!=(const Integer& num1, const Integer& num2);
		friend bool operator!=(const Integer& num1, const int num2);
		friend bool operator!=(const int num1, const Integer& num2);

		friend bool operator>(const Integer& num1, const Integer& num2);
		friend bool operator>(const Integer& num1, const int num2);
		friend bool operator>(const int num1, const Integer& num2);

		friend bool operator>=(const Integer& num1, const Integer& num2);
		friend bool operator>=(const Integer& num1, const int num2);
		friend bool operator>=(const int num1, const Integer& num2);

		friend bool operator<(const Integer& num1, const Integer& num2);
		friend bool operator<(const Integer& num1, const int num2);
		friend bool operator<(const int num1, const Integer& num2);

		friend bool operator<=(const Integer& num1, const Integer& num2);
		friend bool operator<=(const Integer& num1, const int num2);
		friend bool operator<=(const int num1, const Integer& num2);

	public:
		friend Integer pow(const Integer& num1, const Integer& num2);

		friend Integer abs(const Integer& num);

		friend Integer fact(const Integer& num);

	public:
		int GetPrecision() const;
		void SetPrecision(int precision);

	public:
		bool IsNan();
		string ToString() const;
		static Integer FromString(const std::string& str);

#ifdef _DEBUG
		string ToString(int exp, int accuracy) const;
#endif

	private:
#ifdef TRACE_OUTPUT
		void UpdateNumberStr();
#endif
		
	private:
		mpz_t number; ///< The number

#ifdef TRACE_OUTPUT
		string numberStr; ///< String representation for debug.
#endif
	};
}

#endif
