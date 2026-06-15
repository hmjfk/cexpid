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
#if !defined (REDUC_H)
#define REDUC_H
// ISO/IEC TS 18661-4 (Floating-point extensions for C)に規定の関数
#define __STDC_IEC_60559_FUNCS_REDUCTION__ 202401L


#if defined (__STDC_IEC_60559_BFP__)
// reduc_sum functions
double reduc_sum(size_t n, const double p[static n]);
float reduc_sumf(size_t n, const float p[static n]);
long double reduc_suml(size_t n, const long double p[static n]);

_Float16 reduc_sumf16(size_t n, const _Float16 p[static n]);
_Float32 reduc_sumf32(size_t n, const _Float32 p[static n]);
_Float64 reduc_sumf64(size_t n, const _Float64 p[static n]);
_Float128 reduc_sumf128(size_t n, const _Float128 p[static n]);

_Float16x reduc_sumf16x(size_t n, const _Float16x p[static n]);
_Float32x reduc_sumf32x(size_t n, const _Float32x p[static n]);
_Float64x reduc_sumf64x(size_t n, const _Float64x p[static n]);
_Float128x reduc_sumf128x(size_t n, const _Float128x p[static n]);

// reduc_sumabs functions
double reduc_sumabs(size_t n, const double p[static n]);
float reduc_sumabsf(size_t n, const float p[static n]);
long double reduc_sumabsf(size_t n, const long double p[static n]);

_Float16 reduc_sumabsf16(size_t n, const _Float16 p[static n]);
_Float32 reduc_sumabsf32(size_t n, const _Float32 p[static n]);
_Float64 reduc_sumabsf64(size_t n, const _Float64 p[static n]);
_Float128 reduc_sumabsf128(size_t n, const _Float128 p[static n]);

_Float16x reduc_sumabsf16x(size_t n, const _Float16x p[static n]);
_Float32x reduc_sumabsf32x(size_t n, const _Float32x p[static n]);
_Float64x reduc_sumabsf64x(size_t n, const _Float64x p[static n]);
_Float128x reduc_sumabsf128x(size_t n, const _Float128x p[static n]);

// reduc_sumsq functions
double reduc_sumsq(size_t n, const double p[static n]);
float reduc_sumsqf(size_t n, const float p[static n]);
long double reduc_sumsql(size_t n, const long double p[static n]);

_Float16 reduc_sumsqf16(size_t n, const _Float16 p[static n]);
_Float32 reduc_sumsqf32(size_t n, const _Float32 p[static n]);
_Float64 reduc_sumsqf64(size_t n, const _Float64 p[static n]);
_Float128 reduc_sumsqf128(size_t n, const _Float128 p[static n]);

_Float16x reduc_sumsqf16x(size_t n, const _Float16x p[static n]);
_Float32x reduc_sumsqf32x(size_t n, const _Float32x p[static n]);
_Float64x reduc_sumsqf64x(size_t n, const _Float64x p[static n]);
_Float128x reduc_sumsqf128x(size_t n, const _Float128x p[static n]);

// reduc_sumprod functions
double reduc_sumprod(       size_t              n,
                            const double        p[static n],
                            const double        q[static n]);
float reduc_sumprodf(       size_t              n,
                            const float         p[static n],
                            const float         q[static n]);
long double reduc_sumprodl( size_t              n,
                            const long double   p[static n],
                            const long double   q[static n]);

_Float16 reduc_sumprodf16(  size_t              n,
                            const _Float16      p[static n],
                            const _Float16      q[static n]);
_Float32 reduc_sumprodf32(  size_t              n,
                            const _Float32      p[static n],
                            const _Float32      q[static n]);
_Float64 reduc_sumprodf64(  size_t              n,
                            const _Float64      p[static n],
                            const _Float64      q[static n]);
_Float128 reduc_sumprodf128(size_t              n,
                            const _Float128     p[static n],
                            const _Float128     q[static n]);

_Float16x reduc_sumprodf16x(size_t              n,
                            const _Float16x     p[static n],
                            const _Float16x     q[static n]);
_Float32x reduc_sumprodf32x(size_t              n,
                            const _Float32x     p[static n],
                            const _Float32x     q[static n]);
_Float64x reduc_sumprodf64x(size_t              n,
                            const _Float64x     p[static n],
                            const _Float64x     q[static n]);
_Float128x reduc_sumprodf128x(
                            size_t              n,
                            const _Float128x    p[static n],
                            const _Float128x    q[static n]);

// scaled_prod functions
double scaled_prod(         size_t              n,
                            const double        p[static restrict n],
                            long int* restrict  sfptr);
float scaled_prodf(         size_t              n,
                            const float         p[static restrict n],
                            long int* restrict  sfptr);
long double scaled_prodl(   size_t              n,
                            const long double   p[static restrict n],
                            long int* restrict  sfptr);

_Float16 scaled_prodf16(size_t              n,
                        const _Float16      p[static restrict n],
                        long int* restrict  sfptr);
_Float32 scaled_prodf32(size_t              n,
                        const _Float32      p[static restrict n],
                        long int* restrict  sfptr);
_Float64 scaled_prodf64(size_t              n,
                        const _Float64      p[static restrict n],
                        long int* restrict  sfptr);
_Float128 scaled_prodf128(
                        size_t              n,
                        const _Float128     p[static restrict n],
                        long int* restrict  sfptr);

_Float16x scaled_prodf16x(
                        size_t              n,
                        const _Float16x     p[static restrict n],
                        long int* restrict  sfptr);
_Float32x scaled_prodf32x(
                        size_t              n,
                        const _Float32x     p[static restrict n],
                        long int* restrict  sfptr);
_Float64x scaled_prodf64x(
                        size_t              n,
                        const _Float64x     p[static restrict n],
                        long int* restrict sfptr);
_Float128x scaled_prodf128x(
                        size_t              n,
                        const _Float128x    p[static restrict n],
                        long int* restrict  sfptr);

// scaled_prodsum functions
double scaled_prodsum(      size_t              n,
                            const double        p[static restrict n],
                            const double        q[static restrict n],
                            long int* restrict  sfptr);
float scaled_prodsumf(      size_t              n,
                            const float         p[static restrict n],
                            const float         q[static restrict n],
                            long int* restrict  sfptr);
long double scaled_prodsuml(size_t              n,
                            const long double   p[static restrict n],
                            const long double   q[static restrict n],
                            long int* restrict  sfptr);

_Float16 scaled_prodsumf16( size_t              n,
                            const _Float16      p[static restrict n],
                            const _Float16      q[static restrict n],
                            long int* restrict  sfptr);
_Float32 scaled_prodsumf32( size_t              n,
                            const _Float32      p[static restrict n],
                            const _Float32      q[static restrict n],
                            long int* restrict  sfptr);
_Float64 scaled_prodsumf64( size_t              n,
                            const _Float64      p[static restrict n],
                            const _Float64      q[static restrict n],
                            long int* restrict  sfptr);
_Float128 scaled_prodsumf128(
                            size_t              n,
                            const _Float128     p[static restrict n],
                            const _Float128     q[static restrict n],
                            long int* restrict  sfptr);

_Float16x scaled_prodsumf16x(
                            size_t              n,
                            const _Float16x     p[static restrict n],
                            const _Float16x     q[static restrict n],
                            long int* restrict  sfptr);
_Float32x scaled_prodsumf32x( size_t              n,
                            const _Float32x     p[static restrict n],
                            const _Float32x     q[static restrict n],
                            long int* restrict  sfptr);
_Float64x scaled_prodsumf64x(
                            size_t              n,
                            const _Float64x     p[static restrict n],
                            const _Float64x     q[static restrict n],
                            long int* restrict  sfptr);
_Float128x scaled_prodsumf128x(
                            size_t              n,
                            const _Float128x    p[static restrict n],
                            const _Float128x    q[static restrict n],
                            long int* restrict  sfptr);

// scaled_proddiff functions
double scaled_proddiff(         size_t              n,
                                const double        p[static restrict n],
                                const double        q[static restrict n],
                                long int* restrict  sfptr);
float scaled_proddifff(         size_t              n,
                                const float         p[static restrict n],
                                const float         q[static restrict n],
                                long int* restrict  sfptr);
long double scaled_proddiffl(   size_t              n,
                                const long double   p[static restrict n],
                                const long double   q[static restrict n],
                                long int* restrict  sfptr);

_Float16 scaled_proddifff16(    size_t              n,
                                const _Float16      p[static restrict n],
                                const _Float16      q[static restrict n],
                                long int* restrict  sfptr);
_Float32 scaled_proddifff32(    size_t              n,
                                const _Float32      p[static restrict n],
                                const _Float32      q[static restrict n],
                                long int* restrict  sfptr);
_Float64 scaled_proddifff64(    size_t              n,
                                const _Float64      p[static restrict n],
                                const _Float64      q[static restrict n],
                                long int* restrict  sfptr);
_Float128 scaled_proddifff128(  size_t              n,
                                const _Float128     p[static restrict n],
                                const _Float128     q[static restrict n],
                                long int* restrict  sfptr);

_Float16x scaled_proddifff16x(  size_t             n,
                                const _Float16x    p[static restrict n],
                                const _Float16x    q[static restrict n],
                                long int* restrict  sfptr);
_Float32x scaled_proddifff32x(  size_t             n,
                                const _Float32x    p[static restrict n],
                                const _Float32x    q[static restrict n],
                                long int* restrict  sfptr);
_Float64x scaled_proddifff64x(  size_t             n,
                                const _Float64x    p[static restrict n],
                                const _Float64x    q[static restrict n],
                                long int* restrict  sfptr);
_Float128x scaled_proddifff128x(size_t              n,
                                const _Float128x    p[static restrict n],
                                const _Float128x    q[static restrict n],
                                long int* restrict  sfptr);

#endif // end __STDC_IEC_60559_BFP__

#if defined(__STDC_IEC_60559_DFP__)

// reduc_sum functions for decimal type
_Decimal32 reduc_sumd32(size_t n, const _Decimal32 p[static n]);
_Decimal64 reduc_sumd64(size_t n, const _Decimal64 p[static n]);
_Decimal128 reduc_sumd128(size_t n, const _Decimal128 p[static n]);

_Decimal32x reduc_sumd32x(size_t n, const _Decimal32x p[static n]);
_Decimal64x reduc_sumd64x(size_t n, const _Decimal64x p[static n]);
_Decimal128x reduc_sumd128x(size_t n, const _Decimal128x p[static n]);

// reduc_sumabs functions for decimal type
_Decimal32 reduc_sumabsd32(size_t n, const _Decimal32 p[static n]);
_Decimal64 reduc_sumabsd64(size_t n, const _Decimal64 p[static n]);
_Decimal128 reduc_sumabsd128(size_t n, const _Decimal128 p[static n]);

_Decimal32x reduc_sumabsd32x(size_t n, const _Decimal32x p[static n]);
_Decimal64x reduc_sumabsd64x(size_t n, const _Decimal64x p[static n]);
_Decimal128x reduc_sumabsd128x(size_t n, const _Decimal128x p[static n]);

// reduc_sumsq functions for decimal type
_Decimal32 reduc_sumsqd32(size_t n, const _Decimal32 p[static n]);
_Decimal64 reduc_sumsqd64(size_t n, const _Decimal64 p[static n]);
_Decimal128 reduc_sumsqd128(size_t n, const _Decimal128 p[static n]);

_Decimal32x reduc_sumsqd32x(size_t n, const _Decimal32x p[static n]);
_Decimal64x reduc_sumsqd64x(size_t n, const _Decimal64x p[static n]);
_Decimal128x reduc_sumsqd128x(size_t n, const _Decimal128x p[static n]);


// reduc_sumprod functions for decimal type
_Decimal32 reduc_sumprodd32(size_t                  n,
                            const _Decimal32        p[static n],
                            const _Decimal32        q[static n]);
_Decimal64 reduc_sumprodd64(size_t                  n,
                            const _Decimal64        p[static n],
                            const _Decimal64        q[static n]);
_Decimal128 reduc_sumprodd128(
                            size_t                  n,
                            const _Decimal128       p[static n],
                            const _Decimal128       q[static n]);

_Decimal32x reduc_sumprodd32x(  size_t              n,
                                const _Decimal32x   p[static n],
                                const _Decimal32x   q[static n]);
_Decimal64x reduc_sumprodd64x(  size_t              n,
                                const _Decimal64x   p[static n],
                                const _Decimal64x   q[static n]);
_Decimal128x reduc_sumprodd128x(size_t              n,
                                const _Decimal128x  p[static n],
                                const _Decimal128x  q[static n]);


// scaled_prod functions for decimal type
_Decimal32 scaled_prodd32(  size_t              n,
                            const _Decimal32    p[static restrict n],
                            long int* restrict  sfptr);
_Decimal64 scaled_prodd64(  size_t              n,
                            const _Decimal64    p[static restrict n],
                            long int* restrict  sfptr);
_Decimal128 scaled_prodd128(size_t              n,
                            const _Decimal128   p[static restrict n],
                            long int* restrict  sfptr);

_Decimal32x scaled_prodd32x(size_t              n,
                            const _Decimal32x   p[static restrict n],
                            long int* restrict  sfptr);
_Decimal64x scaled_prodd64x(size_t              n,
                            const _Decimal64x   p[static restrict n],
                            long int* restrict  sfptr);
_Decimal128x scaled_prodd128x(
                            size_t              n,
                            const _Decimal128x  p[static restrict n],
                            long int* restrict  sfptr);

// scaled_prodsum functions for decimal type
_Decimal32 scaled_prodsumd32(   size_t              n,
                                const _Decimal32    p[static restrict n],
                                const _Decimal32    q[static restrict n],
                                long int* restrict  sfptr);
_Decimal64 scaled_prodsumd64(   size_t              n,
                                const _Decimal64    p[static restrict n],
                                const _Decimal64    q[static restrict n],
                                long int* restrict  sfptr);
_Decimal128 scaled_prodsumd128( size_t              n,
                                const _Decimal128   p[static restrict n],
                                const _Decimal128   q[static restrict n],
                                long int* restrict  sfptr);

_Decimal32x scaled_prodsumd32x( size_t              n,
                                const _Decimal32x   p[static restrict n],
                                const _Decimal32x   q[static restrict n],
                                long int* restrict  sfptr);
_Decimal64x scaled_prodsumd64x( size_t              n,
                                const _Decimal64x   p[static restrict n],
                                const _Decimal64x   q[static restrict n],
                                long int* restrict  sfptr);
_Decimal128x scaled_prodsumd128x(
                                size_t              n,
                                const _Decimal128x  p[static restrict n],
                                const _Decimal128x  q[static restrict n],
                                long int* restrict  sfptr);

// scaled_proddiff functions for decimal type
_Decimal32 scaled_proddiffd32(  size_t              n,
                                const _Decimal32    p[static restrict n],
                                const _Decimal32    q[static restrict n],
                                long int* restrict  sfptr);
_Decimal64 scaled_proddiffd64(  size_t              n,
                                const _Decimal64    p[static restrict n],
                                const _Decimal64    q[static restrict n],
                                long int* restrict  sfptr);
_Decimal128 scaled_proddiffd128(size_t              n,
                                const _Decimal128   p[static restrict n],
                                const _Decimal128   q[static restrict n],
                                long int* restrict  sfptr);

_Decimal32x scaled_proddiffd32x(size_t              n,
                                const _Decimal32x   p[static restrict n],
                                const _Decimal32x   q[static restrict n],
                                long int* restrict  sfptr);
_Decimal64x scaled_proddiffd64x(size_t              n,
                                const _Decimal64x   p[static restrict n],
                                const _Decimal64x   q[static restrict n],
                                long int* restrict  sfptr);
_Decimal128x scaled_proddiffd128x(
                                size_t              n,
                                const _Decimal128x  p[static restrict n],
                                const _Decimal128x  q[static restrict n],
                                long int* restrict  sfptr);

#endif // end __STDC_IEC_60559_DFP__
#endif // end REDUC_H