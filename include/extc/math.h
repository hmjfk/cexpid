/*
    cexpid - POSIX指向のC言語汎用部品集
    Copyright (C) 2025 - Denkousi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#if !defined(EXTMATH_H)
#define EXTMATH_H
#include<stdint.h>

// math constant
constexpr double pi = 3.141592653589793238462643383279502;
constexpr double e =  2.718281828459045235360287471352662;

// deg -> rad function
double rad(double value);

// rad -> deg function
double deg(double value);

// 角度変換関数
typedef enum { Deg, Rad, Grd } angle;

double angleconv(double v, angle before, angle after);

// return: x^^2
double pow2(double x);

// return: x^^3
double pow3(double x);

// return: sqrt(pow2(x) + pow2(y) + pow3(z))
double hypot3(double x, double y, double z);
// return: rootn(x, n) * m
double rootnm(double x, uint64_t n, int64_t m);

// gcd and lcm function
int gcd(int a, int b)[[reproducible]];
int lcm(int a, int b);

// factorial
uintmax_t factorial(unsigned int exponent)[[reproducible]];
uintmax_t factorial2(unsigned int exponent)[[reproducible]];

// combination function
unsigned long comb(const unsigned int n, unsigned int r);

// permutation function
unsigned long perm(unsigned int n, unsigned int r);

// nested combination function
int ncomb(unsigned int n, unsigned int r);

// midpoint finction (from C++ std::midpoint)
double midpoint(double a, double b);

// Numeric radix conversion function
int radix(int a, int conv);

// inf function (from go)
double inf(double value);

// lerp function (from C++ std::lerp)
double lerp(const double a, const double b, const double t)[[unsequenced]];

// sum total function
/*
概要
初項a,末項b,一般項を使用者が定義した関数のアドレスgtの総和
*/
int sum(int a,int b, typeof(int (int))* gt);

/*
概要
初項a,末項b,一般項を使用者が定義した関数のアドレスgtの総乗
*/
int product(int a,int b, typeof(int (int))* gt);

/*
算術的に高次方程式を解く関数
*/
// 戻り値の型
struct return_result
{
    double _Complex* x; //解の配列先頭
    uint8_t res_num;    //解の数（解の配列要素数）
};
// その数が素数かどうか調べる
bool isprime(uint64_t a);

// その数がnの倍数であるか調べる。
bool ismultiple(int64_t multiple, int64_t num);

// その数が偶数であるか調べる。
inline bool iseven(int64_t num);
inline bool iseven(int64_t num)
{ return ismultiple(2, num); }

// その数が奇数であるか調べる。
inline bool isodd(int64_t num);
inline bool isodd(int64_t num)
{ return !iseven(num); }

// sign function
bool sign(const int s)[[unsequenced]];

inline double changesign(const double x) [[unsequenced]];
inline double changesign(const double x) [[unsequenced]]
{
    return -x;
}

// 許容誤差の範囲内か調べる。
bool accerr(double a, double b, double e);

// 繰り返し二乗法によるpow
double mdl_pow(double x);

// 以下はLibreofficeの関数
/*
fourier
frequency
growth
linest
logest
mdeterm
minverse
mmult
munit
sumproduct
sumx2my2
sumx2py2
sumxmy2
transpose
trend
color

euroconvart
feven
multinomial
fodd
cproduct
nvrand
nvbetweenrand
rawsubtract
sec
sech
seriessum
factdouble
// advround: libreofficeのround
advround
*/
#endif // end EXTMATH_H