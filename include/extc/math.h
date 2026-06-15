/*
    cexpid - C言語の言語機能強化部品集
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
// deg → rad function
double rad(double value);

// rad → deg function
double deg(double value);

// 角度変換関数
typedef enum 
{
    Deg,
    Rad,
    Grd
} 角度;

double 角度変換関数(double val, 角度 変換前の単位, 角度 変換後の単位);

// gcd and lcm function
int gcd(int a, int b);
int lcm(int a, int b);

// factorial
intmax_t factorial(intmax_t exponent);
intmax_t factorial2(intmax_t exponent);

// combination function
unsigned long comb(unsigned int n, unsigned int r);

// permutation function
unsigned long perm(unsigned int n, unsigned int r);

// nested combination function
int ncomb(unsigned int n, unsigned int r);

// midpoint finction (C Version)
double midpoint(double a, double b);
void* pmidpoint(void* a, void* b);

// Numeric radix conversion function
int numbase(int a, int conv);

// inf function (go言語と同じ仕様)
double inf(double value);

// lerp function (C++を参考とした。)
double lerp(double a, double b, float t);

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
bool Ismultiple(uint64_t multiple, uint64_t num);

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