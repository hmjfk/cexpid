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
#if !defined(MATH_H)
#define MATH_H
#include <math.h>

#define FP_FAST_FADD 1
#define FP_FAST_FADDL 1
#define FP_FAST_DADDL 1
#define FP_FAST_FSUB 1
#define FP_FAST_FSUBL 1
#define FP_FAST_DSUBL 1
#define FP_FAST_FMUL 1
#define FP_FAST_FMULL 1
#define FP_FAST_DMULL 1
#define FP_FAST_FDIV 1
#define FP_FAST_FDIVL 1
#define FP_FAST_DDIVL 1
#define FP_FAST_FSQRT 1
#define FP_FAST_FSQRTL 1
#define FP_FAST_DSQRTL 1
#define FP_FAST_FFMA 1
#define FP_FAST_FFMAL 1
#define FP_FAST_DFMAL 1

#define FP_FAST_D32ADDD64 1
#define FP_FAST_D32ADDD128 1
#define FP_FAST_D64ADDD128 1
#define FP_FAST_D32SUBD64 1
#define FP_FAST_D32SUBD128 1
#define FP_FAST_D64SUBD128 1
#define FP_FAST_D32MULD64 1
#define FP_FAST_D32MULD128 1
#define FP_FAST_D64MULD128 1
#define FP_FAST_D32DIVD64 1
#define FP_FAST_D32DIVD128 1
#define FP_FAST_D64DIVD128 1
#define FP_FAST_D32FMAD64 1
#define FP_FAST_D32FMAD128 1
#define FP_FAST_D64FMAD128 1
#define FP_FAST_D32SQRTD64 1
#define FP_FAST_D32SQRTD128 1
#define FP_FAST_D64SQRTD128 1

/*
_Decimal32_tと_Decimal64_tだけは規格書で正確な定義がある。
それ以外は実装定義となっており、この部品集では実装できない。
*/
#if defined(__STDC_IEC_60559_DFP__)

#if DEC_EVAL_METHOD == 0
typedef _Decimal32 _Decimal32_t;
typedef _Decimal64 _Decimal64_t;
#elif DEC_EVAL_METHOD == 1
typedef _Decimal64 _Decimal32_t;
typedef _Decimal64 _Decimal64_t;
#elif DEC_EVAL_METHOD == 2
typedef _Decimal128 _Decimal32_t;
typedef _Decimal128 _Decimal64_t;
#else
#error DEC_EVAL_METHOD is implementation-defined.
#endif

#endif // end __STDC_IEC_60559_DFP__

// __STDC_WANT_IEC_60559_TYPES_EXT__が定義されているときは、__STDC_WANT_IEC_60559_EXT__も定義する。
#if defined (__STDC_WANT_IEC_60559_TYPES_EXT__) && !defined(__STDC_WANT_IEC_60559_EXT__)
#define __STDC_WANT_IEC_60559_EXT__
#endif // end __STDC_WANT_IEC_60559_EXT__ macro check


// 附属書F (ISO/IEC 60559 floating-point arithmetic)に規定の関数群
#if defined(__STDC_WANT_IEC_60559_EXT__)

// glibcではすでに実装済み
#if defined(__STDC_IEC_60559_BFP__)

int totalorder(const double* x, const double* y);
int totalorderf(const float* x, const float* y);
int totalorderl(const long double* x, const long double* y);

int totalordermag(const double* x, const double* y);
int totalordermagf(const float* x, const float* y);
int totalordermagl(const long double* x, const long double* y);

double getpayload(const double* x);
float getpayloadf(const float* x);
long double getpayloadl(const long double* x);

int setpayload(double* res, double pl);
int setpayloadf(float* res, float pl);
int setpayloadl(long double* res, long double pl);

int setpayloadsig(double* res, double pl);
int setpayloadsigf(float* res, float pl);
int setpayloadsigl(long double* res, long double pl);

#endif // end __STDC_IEC_60559_BFP__
#if defined(__STDC_IEC_60559_DFP__)

int totalorderd32(const _Decimal32* x, const _Decimal32* y);
int totalorderd64(const _Decimal64* x, const _Decimal64* y);
int totalorderd128(const _Decimal128* x, const _Decimal128* y);

int totalordermagd32(const _Decimal32* x, const _Decimal32* y);
int totalordermagd64(const _Decimal64* x, const _Decimal64* y);
int totalordermagd128(const _Decimal128* x, const _Decimal128* y);

_Decimal32 getpayloadd32(const _Decimal32* x);
_Decimal64 getpayloadd64(const _Decimal64* x);
_Decimal128 getpayloadd128(const _Decimal128* x);

int setpayloadd32(_Decimal32* res, _Decimal32 pl);
int setpayloadd64(_Decimal64* res, _Decimal64 pl);
int setpayloadd128(_Decimal128* res, _Decimal128 pl);

int setpayloadsigd32(_Decimal32* res, _Decimal32 pl);
int setpayloadsigd64(_Decimal64* res, _Decimal64 pl);
int setpayloadsigd128(_Decimal128* res, _Decimal128 pl);

#endif // end __STDC_IEC_60559_DFP__
#endif // end __STDC_WANT_IEC_60559_EXT__

// 附属書H (ISO/IEC 60559 interchange and extended types)に規定の関数群
#if defined(__STDC_WANT_IEC_60559_TYPES_EXT__)
#if defined(__STDC_IEC_60559_BFP__)

_Float16 acosf16(_Float16 x);
_Float32 acosf32(_Float32 x);
_Float64 acosf64(_Float64 x);
_Float128 acosf128(_Float128 x);

_Float16 asinf16(_Float16 x);
_Float32 asinf32(_Float32 x);
_Float64 asinf64(_Float64 x);
_Float128 asinf128(_Float128 x);

_Float16 atanf16(_Float16 x);
_Float32 atanf32(_Float32 x);
_Float64 atanf64(_Float64 x);
_Float128 atanf128(_Float128 x);

_Float16 atan2f16(_Float16 y, _Float16 x);
_Float32 atan2f32(_Float32 y, _Float32 x);
_Float64 atan2f64(_Float64 y, _Float64 x);
_Float128 atan2f128(_Float128 y, _Float128 x);

_Float16 cosf16(_Float16 x);
_Float32 cosf32(_Float32 x);
_Float64 cosf64(_Float64 x);
_Float128 cosf128(_Float128 x);

_Float16 sinf16(_Float16 x);
_Float32 sinf32(_Float32 x);
_Float64 sinf64(_Float64 x);
_Float128 sinf128(_Float128 x);

_Float16 tanf16(_Float16 x);
_Float32 tanf32(_Float32 x);
_Float64 tanf64(_Float64 x);
_Float128 tanf128(_Float128 x);

_Float16 acospif16(_Float16 x);
_Float32 acospif32(_Float32 x);
_Float64 acospif64(_Float64 x);
_Float128 acospif128(_Float128 x);

_Float16 asinpif16(_Float16 x);
_Float32 asinpif32(_Float32 x);
_Float64 asinpif64(_Float64 x);
_Float128 asinpif128(_Float128 x);

_Float16 atanpif16(_Float16 x);
_Float32 atanpif32(_Float32 x);
_Float64 atanpif64(_Float64 x);
_Float128 atanpif128(_Float128 x);

_Float16 atan2pif16(_Float16 y, _Float16 x);
_Float32 atan2pif32(_Float32 y, _Float32 x);
_Float64 atan2pif64(_Float64 y, _Float64 x);
_Float128 atan2pif128(_Float128 y, _Float128 x);

_Float16 cospif16(_Float16 x);
_Float32 cospif32(_Float32 x);
_Float64 cospif64(_Float64 x);
_Float128 cospif128(_Float128 x);

_Float16 sinpif16(_Float16 x);
_Float32 sinpif32(_Float32 x);
_Float64 sinpif64(_Float64 x);
_Float128 sinpif128(_Float128 x);

_Float16 tanpif16(_Float16 x);
_Float32 tanpif32(_Float32 x);
_Float64 tanpif64(_Float64 x);
_Float128 tanpif128(_Float128 x);

_Float16 acoshf16(_Float16 x);
_Float32 acoshf32(_Float32 x);
_Float64 acoshf64(_Float64 x);
_Float128 acoshf128(_Float128 x);

_Float16 asinhf16(_Float16 x);
_Float32 asinhf32(_Float32 x);
_Float64 asinhf64(_Float64 x);
_Float128 asinhf128(_Float128 x);

_Float16 atanhf16(_Float16 x);
_Float32 atanhf32(_Float32 x);
_Float64 atanhf64(_Float64 x);
_Float128 atanhf128(_Float128 x);

_Float16 coshf16(_Float16 x);
_Float32 coshf32(_Float32 x);
_Float64 coshf64(_Float64 x);
_Float128 coshf128(_Float128 x);

_Float16 sinhf16(_Float16 x);
_Float32 sinhf32(_Float32 x);
_Float64 sinhf64(_Float64 x);
_Float128 sinhf128(_Float128 x);

_Float16 tanhf16(_Float16 x);
_Float32 tanhf32(_Float32 x);
_Float64 tanhf64(_Float64 x);
_Float128 tanhf128(_Float128 x);

_Float16 expf16(_Float16 x);
_Float32 expf32(_Float32 x);
_Float64 expf64(_Float64 x);
_Float128 expf128(_Float128 x);

_Float16 exp10f16(_Float16 x);
_Float32 exp10f32(_Float32 x);
_Float64 exp10f64(_Float64 x);
_Float128 exp10f128(_Float128 x);

_Float16 exp10m1f16(_Float16 x);
_Float32 exp10m1f32(_Float32 x);
_Float64 exp10m1f64(_Float64 x);
_Float128 exp10m1f128(_Float128 x);

_Float16 exp2f16(_Float16 x);
_Float32 exp2f32(_Float32 x);
_Float64 exp2f64(_Float64 x);
_Float128 exp2f128(_Float128 x);

_Float16 exp2m1f16(_Float16 x);
_Float32 exp2m1f32(_Float32 x);
_Float64 exp2m1f64(_Float64 x);
_Float128 exp2m1f128(_Float128 x);

_Float16 expm1f16(_Float16 x);
_Float32 expm1f32(_Float32 x);
_Float64 expm1f64(_Float64 x);
_Float128 expm1f128(_Float128 x);

_Float16 frexpf16(_Float16 value, int* exp);
_Float32 frexpf32(_Float32 value, int* exp);
_Float64 frexpf64(_Float64 value, int* exp);
_Float128 frexpf128(_Float128 value, int* exp);

int ilogbf16(_Float16 x);
int ilogbf32(_Float32 x);
int ilogbf64(_Float128 x);
int ilogbf128(_Float128 x);

_Float16 ldexpf16(_Float16 value, int exp);
_Float32 ldexpf32(_Float32 value, int exp);
_Float64 ldexpf64(_Float64 value, int exp);
_Float128 ldexpf128(_Float128 value, int exp);

long int llogbf16(_Float16 x);
long int llogbf32(_Float32 x);
long int llogbf64(_Float64 x);
long int llogbf128(_Float128 x);

_Float16 logf16(_Float16 x);
_Float32 logf32(_Float32 x);
_Float64 logf64(_Float64 x);
_Float128 logf128(_Float128 x);

_Float16 log10f16(_Float16 x);
_Float32 log10f32(_Float32 x);
_Float64 log10f64(_Float64 x);
_Float128 log10f128(_Float128 x);

_Float16 log10p1f16(_Float16 x);
_Float32 log10p1f32(_Float32 x);
_Float64 log10p1f64(_Float64 x);
_Float128 log10p1f128(_Float128 x);

_Float16 log1pf16(_Float16 x);
_Float32 log1pf32(_Float32 x);
_Float16 logp1f16(_Float16 x);
_Float32 logp1f32(_Float32 x);
_Float64 log1pf64(_Float64 x);

_Float128 log1pf128(_Float128 x);

_Float64 logp1f64(_Float64 x);
_Float128 logp1f128(_Float128 x);

_Float16 log2f16(_Float16 x);
_Float32 log2f32(_Float32 x);
_Float64 log2f64(_Float64 x);
_Float128 log2f128(_Float128 x);

_Float16 log2p1f16(_Float16 x);
_Float32 log2p1f32(_Float32 x);
_Float64 log2p1f64(_Float64 x);
_Float128 log2p1f128(_Float128 x);

_Float16 logbf16(_Float16 x);
_Float32 logbf32(_Float32 x);
_Float64 logbf64(_Float64 x);
_Float128 logbf128(_Float128 x);

_Float16 modff16(_Float16 x, _Float16* iptr);
_Float32 modff32(_Float32 x, _Float32* iptr);
_Float64 modff64(_Float64 x, _Float64* iptr);
_Float128 modff128(_Float128 x, _Float128* iptr);

_Float16 scalbnf16(_Float16 value, int exp);
_Float32 scalbnf32(_Float32 value, int exp);
_Float64 scalbnf64(_Float64 value, int exp);
_Float128 scalbnf128(_Float128 value, int exp);

_Float16 scalblnf16(_Float16 value, long int exp);
_Float32 scalblnf32(_Float32 value, long int exp);
_Float64 scalblnf64(_Float64 value, long int exp);
_Float128 scalblnf128(_Float128 value, long int exp);

_Float16 cbrtf16(_Float16 x);
_Float32 cbrtf32(_Float32 x);
_Float64 cbrtf64(_Float64 x);
_Float128 cbrtf128(_Float128 x);

_Float16 compounf16(_Float16 x, long long int n);
_Float32 compounf32(_Float32 x, long long int n);
_Float64 compounf64(_Float64 x, long long int n);
_Float128 compounf128(_Float128 x, long long int n);

_Float16 fabsf16(_Float16 x);
_Float32 fabsf32(_Float32 x);
_Float64 fabsf64(_Float64 x);
_Float128 fabsf128(_Float128 x);

_Float16 hypotf16(_Float16 x, _Float16 y);
_Float32 hypotf32(_Float32 x, _Float32 y);
_Float64 hypotf64(_Float64 x, _Float64 y);
_Float128 hypotf128(_Float128 x, _Float128 y);

_Float16 powf16(_Float16 x, _Float16 y);
_Float32 powf32(_Float32 x, _Float32 y);
_Float64 powf64(_Float64 x, _Float64 y);
_Float128 powf128(_Float128 x, _Float128 y);

_Float16 pownf16(_Float16 x, long long int n);
_Float32 pownf32(_Float32 x, long long int n);
_Float64 pownf64(_Float64 x, long long int n);
_Float128 pownf128(_Float128 x, long long int n);

_Float16 powrf16(_Float16 x, _Float16 y);
_Float32 powrf32(_Float32 x, _Float32 y);
_Float64 powrf64(_Float64 x, _Float64 y);
_Float128 powrf128(_Float128 x, _Float128 y);

_Float16 rootnf16(_Float16 x, long long int n);
_Float32 rootnf32(_Float32 x, long long int n);
_Float64 rootnf64(_Float64 x, long long int n);
_Float128 rootnf128(_Float128 x, long long int n);

_Float16 rsqrtf16(_Float16 x);
_Float32 rsqrtf32(_Float32 x);
_Float64 rsqrtf64(_Float64 x);
_Float128 rsqrtf128(_Float128 x);

_Float16 sqrtf16(_Float16 x);
_Float32 sqrtf32(_Float32 x);
_Float64 sqrtf64(_Float64 x);
_Float128 sqrtf128(_Float128 x);

_Float16 erff16(_Float16 x);
_Float32 erff32(_Float32 x);
_Float64 erff64(_Float64 x);
_Float128 erff128(_Float128 x);

_Float16 erfcf16(_Float16 x);
_Float32 erfcf32(_Float32 x);
_Float64 erfcf64(_Float64 x);
_Float128 erfcf128(_Float128 x);

_Float16 lgammaf16(_Float16 x);
_Float32 lgammaf32(_Float32 x);
_Float64 lgammaf64(_Float64 x);
_Float128 lgammaf128(_Float128 x);

_Float16 tgammaf16(_Float16 x);
_Float32 tgammaf32(_Float32 x);
_Float64 tgammaf64(_Float64 x);
_Float128 tgammaf128(_Float128 x);

_Float16 ceilf16(_Float16 x);
_Float32 ceilf32(_Float32 x);
_Float64 ceilf64(_Float64 x);
_Float128 ceilf128(_Float128 x);

_Float16 floorf16(_Float16 x);
_Float32 floorf32(_Float32 x);
_Float64 floorf64(_Float64 x);
_Float128 floorf128(_Float128 x);

_Float16 nearbyintf16(_Float16 x);
_Float32 nearbyintf32(_Float32 x);
_Float64 nearbyintf64(_Float64 x);
_Float128 nearbyintf128(_Float128 x);

_Float16 rintf16(_Float16 x);
_Float32 rintf32(_Float32 x);
_Float64 rintf64(_Float64 x);
_Float128 rintf128(_Float128 x);

long int lrintf16(_Float16 x);
long int lrintf32(_Float32 x);
long int lrintf64(_Float64 x);
long int lrintf128(_Float128 x);

long long int llrintf16(_Float16 x);
long long int llrintf32(_Float32 x);
long long int llrintf64(_Float64 x);
long long int llrintf128(_Float128 x);

_Float16 roundf16(_Float16 x);
_Float32 roundf32(_Float32 x);
_Float64 roundf64(_Float64 x);
_Float128 roundf128(_Float128 x);

long int lroundf16(_Float16 x);
long int lroundf32(_Float32 x);
long int lroundf64(_Float64 x);
long int lroundf128(_Float128 x);

long long int llroundf16(_Float16 x);
long long int llroundf32(_Float32 x);
long long int llroundf64(_Float64 x);
long long int llroundf128(_Float128 x);

_Float16 roundevenf16(_Float16 x);
_Float32 roundevenf32(_Float32 x);
_Float64 roundevenf64(_Float64 x);
_Float128 roundevenf128(_Float128 x);

_Float16 truncf16(_Float16 x);
_Float32 truncf32(_Float32 x);
_Float64 truncf64(_Float64 x);
_Float128 truncf128(_Float128 x);

_Float16 fromfpf16(_Float16 x, int rnd, unsigned int width);
_Float32 fromfpf32(_Float32 x, int rnd, unsigned int width);
_Float64 fromfpf64(_Float64 x, int rnd, unsigned int width);
_Float128 fromfpf128(_Float128 x, int rnd, unsigned int width);

_Float16 ufromfpf16(_Float16 x, int rnd, unsigned int width);
_Float32 ufromfpf32(_Float32 x, int rnd, unsigned int width);
_Float64 ufromfpf64(_Float64 x, int rnd, unsigned int width);
_Float128 ufromfpf128(_Float128 x, int rnd, unsigned int width);

_Float16 fromfpxf16(_Float16 x, int rnd, unsigned int width);
_Float32 fromfpxf32(_Float32 x, int rnd, unsigned int width);
_Float64 fromfpxf64(_Float64 x, int rnd, unsigned int width);
_Float128 fromfpxf128(_Float128 x, int rnd, unsigned int width);

_Float16 ufromfpxf16(_Float16 x, int rnd, unsigned int width);
_Float32 ufromfpxf32(_Float32 x, int rnd, unsigned int width);
_Float64 ufromfpxf64(_Float64 x, int rnd, unsigned int width);
_Float128 ufromfpxf128(_Float128 x, int rnd, unsigned int width);

_Float16 fmodf16(_Float16 x, _Float16 y);
_Float32 fmodf32(_Float32 x, _Float32 y);
_Float64 fmodf64(_Float64 x, _Float64 y);

_Float128 fmodf128(_Float128 x, _Float128 y);
_Float16 remainderf16(_Float16 x, _Float16 y);
_Float32 remainderf32(_Float32 x, _Float32 y);
_Float64 remainderf64(_Float64 x, _Float64 y);

_Float128 remainderf128(_Float128 x, _Float128 y);
_Float16 remquof16(_Float16 x, _Float16 y, int* quo);
_Float32 remquof32(_Float32 x, _Float32 y, int* quo);

_Float16 copysignf16(_Float16 x, _Float16 y);
_Float32 copysignf32(_Float32 x, _Float32 y);
_Float64 copysignf64(_Float64 x, _Float64 y);
_Float128 copysignf128(_Float128 x, _Float128 y);

_Float16 nanf16(const char* tagp);
_Float32 nanf32(const char* tagp);
_Float64 nanf64(const char* tagp);
_Float128 nanf128(const char* tagp);

_Float16 nextafterf16(_Float16 x, _Float16 y);
_Float32 nextafterf32(_Float32 x, _Float32 y);
_Float64 nextafterf64(_Float64 x, _Float64 y);
_Float128 nextafterf128(_Float128 x, _Float128 y);

_Float16 nextupf16(_Float16 x);
_Float32 nextupf32(_Float32 x);
_Float64 nextupf64(_Float64 x);
_Float128 nextupf128(_Float128 x);

_Float16 nextdownf16(_Float16 x);
_Float32 nextdownf32(_Float32 x);
_Float64 nextdownf64(_Float64 x);
_Float128 nextdownf128(_Float128 x);

int canonicalizef16(_Float16* cx, const _Float16* x);
int canonicalizef32(_Float32* cx, const _Float32* x);
int canonicalizef64(_Float64* cx, const _Float64* x);
int canonicalizef128(_Float128* cx, const _Float128* x);

_Float16 fdimf16(_Float16 x, _Float16 y);
_Float32 fdimf32(_Float32 x, _Float32 y);
_Float64 fdimf64(_Float64 x, _Float64 y);
_Float128 fdimf128(_Float128 x, _Float128 y);

_Float16 fmaximumf16(_Float16 x, _Float16 y);
_Float32 fmaximumf32(_Float32 x, _Float32 y);
_Float64 fmaximumf64(_Float64 x, _Float64 y);
_Float128 fmaximumf128(_Float128 x, _Float128 y);

_Float16 fminimumf16(_Float16 x, _Float16 y);
_Float32 fminimumf32(_Float32 x, _Float32 y);
_Float64 fminimumf64(_Float64 x, _Float64 y);
_Float128 fminimumf128(_Float128 x, _Float128 y);

_Float16 fmaximum_magf16(_Float16 x, _Float16 y);
_Float32 fmaximum_magf32(_Float32 x, _Float32 y);
_Float64 fmaximum_magf64(_Float64 x, _Float64 y);
_Float128 fmaximum_magf128(_Float128 x, _Float128 y);

_Float16 fminimum_magf16(_Float16 x, _Float16 y);
_Float32 fminimum_magf32(_Float32 x, _Float32 y);
_Float64 fminimum_magf64(_Float64 x, _Float64 y);
_Float128 fminimum_magf128(_Float128 x, _Float128 y);

_Float16 fmaximum_numf16(_Float16 x, _Float16 y);
_Float32 fmaximum_numf32(_Float32 x, _Float32 y);
_Float64 fmaximum_numf64(_Float64 x, _Float64 y);
_Float128 fmaximum_numf128(_Float128 x, _Float128 y);

_Float16 fminimum_numf16(_Float16 x, _Float16 y);
_Float32 fminimum_numf32(_Float32 x, _Float32 y);
_Float64 fminimum_numf64(_Float64 x, _Float64 y);
_Float128 fminimum_numf128(_Float128 x, _Float128 y);

_Float16 fmaximum_mag_numf16(_Float16 x, _Float16 y);
_Float32 fmaximum_mag_numf32(_Float32 x, _Float32 y);
_Float64 fmaximum_mag_numf64(_Float64 x, _Float64 y);
_Float128 fmaximum_mag_numf128(_Float128 x, _Float128 y);

_Float16 fminimum_mag_numf16(_Float16 x, _Float16 y);
_Float32 fminimum_mag_numf32(_Float32 x, _Float32 y);
_Float64 fminimum_mag_numf64(_Float64 x, _Float64 y);
_Float128 fminimum_mag_numf128(_Float128 x, _Float128 y);

_Float16 fmaf16(_Float16 x, _Float16 y, _Float16 z);
_Float32 fmaf32(_Float32 x, _Float32 y, _Float32 z);
_Float64 fmaf64(_Float64 x, _Float64 y, _Float64 z);
_Float128 fmaf128(_Float128 x, _Float128 y, _Float128 z);

int totalorderf16(const _Float16* x, const _Float16* y);
int totalorderf32(const _Float32* x, const _Float32* y);
int totalorderf64(const _Float64* x, const _Float64* y);
int totalorderf128(const _Float128* x, const _Float128* y);

int totalordermagf16(const _Float16* x, const _Float16* y);
int totalordermagf32(const _Float32* x, const _Float32* y);
int totalordermagf64(const _Float64* x, const _Float64* y);
int totalordermagf128(const _Float128* x, const _Float128* y);

_Float16 getpayloadf16(const _Float16* x);
_Float32 getpayloadf32(const _Float32* x);
_Float64 getpayloadf64(const _Float64* x);
_Float128 getpayloadf128(const _Float128* x);

int setpayloadf16(_Float16* res, _Float16 pl);
int setpayloadf32(_Float32* res, _Float32 pl);
int setpayloadf64(_Float64* res, _Float64 pl);
int setpayloadf128(_Float128* res, _Float128 pl);

int setpayloadsigf16(_Float16* res, _Float16 pl);
int setpayloadsigf32(_Float32* res, _Float32 pl);
int setpayloadsigf64(_Float64* res, _Float64 pl);
int setpayloadsigf128(_Float128* res, _Float128 pl);


// math functions for _FloatNx type
_Float16x acosf16x(_Float16x x);
_Float32x acosf32x(_Float32x x);
_Float64x acosf64x(_Float64x x);
_Float128x acosf128x(_Float128x x);

_Float16x asinf16x(_Float16x x);
_Float32x asinf32x(_Float32x x);
_Float64x asinf64x(_Float64x x);
_Float128x asinf128x(_Float128x x);

_Float16x atanf16x(_Float16x x);
_Float32x atanf32x(_Float32x x);
_Float64x atanf64x(_Float64x x);
_Float128x atanf128x(_Float128x x);

_Float16x atan2f16x(_Float16x y, _Float16x x);
_Float32x atan2f32x(_Float32x y, _Float32x x);
_Float64x atan2f64x(_Float64x y, _Float64x x);
_Float128x atan2f128x(_Float128x y, _Float128x x);

_Float16x cosf16x(_Float16x x);
_Float32x cosf32x(_Float32x x);
_Float64x cosf64x(_Float64x x);
_Float128x cosf128x(_Float128x x);

_Float16x sinf16x(_Float16x x);
_Float32x sinf32x(_Float32x x);
_Float64x sinf64x(_Float64x x);
_Float128x sinf128x(_Float128x x);

_Float16x tanf16x(_Float16x x);
_Float32x tanf32x(_Float32x x);
_Float64x tanf64x(_Float64x x);
_Float128x tanf128x(_Float128x x);

_Float16x acospif16x(_Float16x x);
_Float32x acospif32x(_Float32x x);
_Float64x acospif64x(_Float64x x);
_Float128x acospif128x(_Float128x x);

_Float16x asinpif16x(_Float16x x);
_Float32x asinpif32x(_Float32x x);
_Float64x asinpif64x(_Float64x x);
_Float128x asinpif128x(_Float128x x);

_Float16x atanpif16x(_Float16x x);
_Float32x atanpif32x(_Float32x x);
_Float64x atanpif64x(_Float64x x);
_Float128x atanpif128x(_Float128x x);

_Float16x atan2pif16x(_Float16x y, _Float16x x);
_Float32x atan2pif32x(_Float32x y, _Float32x x);
_Float64x atan2pif64x(_Float64x y, _Float64x x);
_Float128x atan2pif128x(_Float128x y, _Float128x x);

_Float16x cospif16x(_Float16x x);
_Float32x cospif32x(_Float32x x);
_Float64x cospif64x(_Float64x x);
_Float128x cospif128x(_Float128x x);

_Float16x sinpif16x(_Float16x x);
_Float32x sinpif32x(_Float32x x);
_Float64x sinpif64x(_Float64x x);
_Float128x sinpif128x(_Float128x x);

_Float16x tanpif16x(_Float16x x);
_Float32x tanpif32x(_Float32x x);
_Float64x tanpif64x(_Float64x x);
_Float128x tanpif128x(_Float128x x);

_Float16x acoshf16x(_Float16x x);
_Float32x acoshf32x(_Float32x x);
_Float64x acoshf64x(_Float64x x);
_Float128x acoshf128x(_Float128x x);

_Float16x asinhf16x(_Float16x x);
_Float32x asinhf32x(_Float32x x);
_Float64x asinhf64x(_Float64x x);
_Float128x asinhf128x(_Float128x x);

_Float16x atanhf16x(_Float16x x);
_Float32x atanhf32x(_Float32x x);
_Float64x atanhf64x(_Float64x x);
_Float128x atanhf128x(_Float128x x);

_Float16x coshf16x(_Float16x x);
_Float32x coshf32x(_Float32x x);
_Float64x coshf64x(_Float64x x);
_Float128x coshf128x(_Float128x x);

_Float16x sinhf16x(_Float16x x);
_Float32x sinhf32x(_Float32x x);
_Float64x sinhf64x(_Float64x x);
_Float128x sinhf128x(_Float128x x);

_Float16x tanhf16x(_Float16x x);
_Float32x tanhf32x(_Float32x x);
_Float64x tanhf64x(_Float64x x);
_Float128x tanhf128x(_Float128x x);

_Float16x expf16x(_Float16x x);
_Float32x expf32x(_Float32x x);
_Float64x expf64x(_Float64x x);
_Float128x expf128x(_Float128x x);

_Float16x exp10f16x(_Float16x x);
_Float32x exp10f32x(_Float32x x);
_Float64x exp10f64x(_Float64x x);
_Float128x exp10f128x(_Float128x x);

_Float16x exp10m1f16x(_Float16x x);
_Float32x exp10m1f32x(_Float32x x);
_Float64x exp10m1f64x(_Float64x x);
_Float128x exp10m1f128x(_Float128x x);

_Float16x exp2f16x(_Float16x x);
_Float32x exp2f32x(_Float32x x);
_Float64x exp2f64x(_Float64x x);
_Float128x exp2f128x(_Float128x x);

_Float16x exp2m1f16x(_Float16x x);
_Float32x exp2m1f32x(_Float32x x);
_Float64x exp2m1f64x(_Float64x x);
_Float128x exp2m1f128x(_Float128x x);

_Float16x expm1f16x(_Float16x x);
_Float32x expm1f32x(_Float32x x);
_Float64x expm1f64x(_Float64x x);
_Float128x expm1f128x(_Float128x x);

_Float16x frexpf16x(_Float16x value, int* exp);
_Float32x frexpf32x(_Float32x value, int* exp);
_Float64x frexpf64x(_Float64x value, int* exp);
_Float128x frexpf128x(_Float128x value, int* exp);

int ilogbf16x(_Float16x x);
int ilogbf32x(_Float32x x);
int ilogbf64x(_Float128x x);
int ilogbf128x(_Float128x x);

_Float16x ldexpf16x(_Float16x value, int exp);
_Float32x ldexpf32x(_Float32x value, int exp);
_Float64x ldexpf64x(_Float64x value, int exp);
_Float128x ldexpf128x(_Float128x value, int exp);

long int llogbf16x(_Float16x x);
long int llogbf32x(_Float32x x);
long int llogbf64x(_Float64x x);
long int llogbf128x(_Float128x x);

_Float16x logf16x(_Float16x x);
_Float32x logf32x(_Float32x x);
_Float64x logf64x(_Float64x x);
_Float128x logf128x(_Float128x x);

_Float16x log10f16x(_Float16x x);
_Float32x log10f32x(_Float32x x);
_Float64x log10f64x(_Float64x x);
_Float128x log10f128x(_Float128x x);
_Float16x log10p1f16x(_Float16x x);
_Float32x log10p1f32x(_Float32x x);
_Float64x log10p1f64x(_Float64x x);
_Float128x log10p1f128x(_Float128x x);

_Float16x log1pf16x(_Float16x x);
_Float32x log1pf32x(_Float32x x);
_Float16x logp1f16x(_Float16x x);
_Float32x logp1f32x(_Float32x x);
_Float64x log1pf64x(_Float64x x);
_Float128x log1pf128x(_Float128x x);
_Float64x logp1f64x(_Float64x x);
_Float128x logp1f128x(_Float128x x);

_Float16x log2f16x(_Float16x x);
_Float32x log2f32x(_Float32x x);
_Float64x log2f64x(_Float64x x);
_Float128x log2f128x(_Float128x x);
_Float16x log2p1f16x(_Float16x x);
_Float32x log2p1f32x(_Float32x x);
_Float64x log2p1f64x(_Float64x x);
_Float128x log2p1f128x(_Float128x x);

_Float16x logbf16x(_Float16x x);
_Float32x logbf32x(_Float32x x);
_Float64x logbf64x(_Float64x x);
_Float128x logbf128x(_Float128x x);

_Float16x modff16x(_Float16x x, _Float16x* iptr);
_Float32x modff32x(_Float32x x, _Float32x* iptr);
_Float64x modff64x(_Float64x x, _Float64x* iptr);
_Float128x modff128x(_Float128x x, _Float128x* iptr);

_Float16x scalbnf16x(_Float16x value, int exp);
_Float32x scalbnf32x(_Float32x value, int exp);
_Float64x scalbnf64x(_Float64x value, int exp);
_Float128x scalbnf128x(_Float128x value, int exp);

_Float16x scalblnf16x(_Float16x value, long int exp);
_Float32x scalblnf32x(_Float32x value, long int exp);
_Float64x scalblnf64x(_Float64x value, long int exp);
_Float128x scalblnf128x(_Float128x value, long int exp);

_Float16x cbrtf16x(_Float16x x);
_Float32x cbrtf32x(_Float32x x);
_Float64x cbrtf64x(_Float64x x);
_Float128x cbrtf128x(_Float128x x);

_Float16x compounf16x(_Float16x x, long long int n);
_Float32x compounf32x(_Float32x x, long long int n);
_Float64x compounf64x(_Float64x x, long long int n);
_Float128x compounf128x(_Float128x x, long long int n);

_Float16x fabsf16x(_Float16x x);
_Float32x fabsf32x(_Float32x x);
_Float64x fabsf64x(_Float64x x);
_Float128x fabsf128x(_Float128x x);

_Float16x hypotf16x(_Float16x x, _Float16x y);
_Float32x hypotf32x(_Float32x x, _Float32x y);
_Float64x hypotf64x(_Float64x x, _Float64x y);
_Float128x hypotf128x(_Float128x x, _Float128x y);

_Float16x powf16x(_Float16x x, _Float16x y);
_Float32x powf32x(_Float32x x, _Float32x y);
_Float64x powf64x(_Float64x x, _Float64x y);
_Float128x powf128x(_Float128x x, _Float128x y);

_Float16x pownf16x(_Float16x x, long long int n);
_Float32x pownf32x(_Float32x x, long long int n);
_Float64x pownf64x(_Float64x x, long long int n);
_Float128x pownf128x(_Float128x x, long long int n);

_Float16x powrf16x(_Float16x x, _Float16x y);
_Float32x powrf32x(_Float32x x, _Float32x y);
_Float64x powrf64x(_Float64x x, _Float64x y);
_Float128x powrf128x(_Float128x x, _Float128x y);

_Float16x rootnf16x(_Float16x x, long long int n);
_Float32x rootnf32x(_Float32x x, long long int n);
_Float64x rootnf64x(_Float64x x, long long int n);
_Float128x rootnf128x(_Float128x x, long long int n);

_Float16x rsqrtf16x(_Float16x x);
_Float32x rsqrtf32x(_Float32x x);
_Float64x rsqrtf64x(_Float64x x);
_Float128x rsqrtf128x(_Float128x x);

_Float16x sqrtf16x(_Float16x x);
_Float32x sqrtf32x(_Float32x x);
_Float64x sqrtf64x(_Float64x x);
_Float128x sqrtf128x(_Float128x x);

_Float16x erff16x(_Float16x x);
_Float32x erff32x(_Float32x x);
_Float64x erff64x(_Float64x x);
_Float128x erff128x(_Float128x x);

_Float16x erfcf16x(_Float16x x);
_Float32x erfcf32x(_Float32x x);
_Float64x erfcf64x(_Float64x x);
_Float128x erfcf128x(_Float128x x);

_Float16x lgammaf16x(_Float16x x);
_Float32x lgammaf32x(_Float32x x);
_Float64x lgammaf64x(_Float64x x);
_Float128x lgammaf128x(_Float128x x);

_Float16x tgammaf16x(_Float16x x);
_Float32x tgammaf32x(_Float32x x);
_Float64x tgammaf64x(_Float64x x);
_Float128x tgammaf128x(_Float128x x);

_Float16x ceilf16x(_Float16x x);
_Float32x ceilf32x(_Float32x x);
_Float64x ceilf64x(_Float64x x);
_Float128x ceilf128x(_Float128x x);

_Float16x floorf16x(_Float16x x);
_Float32x floorf32x(_Float32x x);
_Float64x floorf64x(_Float64x x);
_Float128x floorf128x(_Float128x x);

_Float16x nearbyintf16x(_Float16x x);
_Float32x nearbyintf32x(_Float32x x);
_Float64x nearbyintf64x(_Float64x x);
_Float128x nearbyintf128x(_Float128x x);

_Float16x rintf16x(_Float16x x);
_Float32x rintf32x(_Float32x x);
_Float64x rintf64x(_Float64x x);
_Float128x rintf128x(_Float128x x);

long int lrintf16x(_Float16x x);
long int lrintf32x(_Float32x x);
long int lrintf64x(_Float64x x);
long int lrintf128x(_Float128x x);

long long int llrintf16x(_Float16x x);
long long int llrintf32x(_Float32x x);
long long int llrintf64x(_Float64x x);
long long int llrintf128x(_Float128x x);

_Float16x roundf16x(_Float16x x);
_Float32x roundf32x(_Float32x x);
_Float64x roundf64x(_Float64x x);
_Float128x roundf128x(_Float128x x);

long int lroundf16x(_Float16x x);
long int lroundf32x(_Float32x x);
long int lroundf64x(_Float64x x);
long int lroundf128x(_Float128x x);

long long int llroundf16x(_Float16x x);
long long int llroundf32x(_Float32x x);
long long int llroundf64x(_Float64x x);
long long int llroundf128x(_Float128x x);

_Float16x roundevenf16x(_Float16x x);
_Float32x roundevenf32x(_Float32x x);
_Float64x roundevenf64x(_Float64x x);
_Float128x roundevenf128x(_Float128x x);

_Float16x truncf16x(_Float16x x);
_Float32x truncf32x(_Float32x x);
_Float64x truncf64x(_Float64x x);
_Float128x truncf128x(_Float128x x);

_Float16x fromfpf16x(_Float16x x, int rnd, unsigned int width);
_Float32x fromfpf32x(_Float32x x, int rnd, unsigned int width);
_Float64x fromfpf64x(_Float64x x, int rnd, unsigned int width);
_Float128x fromfpf128x(_Float128x x, int rnd, unsigned int width);

_Float16x ufromfpf16x(_Float16x x, int rnd, unsigned int width);
_Float32x ufromfpf32x(_Float32x x, int rnd, unsigned int width);
_Float64x ufromfpf64x(_Float64x x, int rnd, unsigned int width);
_Float128x ufromfpf128x(_Float128x x, int rnd, unsigned int width);

_Float16x fromfpxf16x(_Float16x x, int rnd, unsigned int width);
_Float32x fromfpxf32x(_Float32x x, int rnd, unsigned int width);
_Float64x fromfpxf64x(_Float64x x, int rnd, unsigned int width);
_Float128x fromfpxf128x(_Float128x x, int rnd, unsigned int width);

_Float16x ufromfpxf16x(_Float16x x, int rnd, unsigned int width);
_Float32x ufromfpxf32x(_Float32x x, int rnd, unsigned int width);
_Float64x ufromfpxf64x(_Float64x x, int rnd, unsigned int width);
_Float128x ufromfpxf128x(_Float128x x, int rnd, unsigned int width);

_Float16x fmodf16x(_Float16x x, _Float16x y);
_Float32x fmodf32x(_Float32x x, _Float32x y);
_Float64x fmodf64x(_Float64x x, _Float64x y);
_Float128x fmodf128x(_Float128x x, _Float128x y);

_Float16x remainderf16x(_Float16x x, _Float16x y);
_Float32x remainderf32x(_Float32x x, _Float32x y);
_Float64x remainderf64x(_Float64x x, _Float64x y);
_Float128x remainderf128x(_Float128x x, _Float128x y);

_Float16x remquof16x(_Float16x x, _Float16x y, int* quo);
_Float32x remquof32x(_Float32x x, _Float32x y, int* quo);

_Float16x copysignf16x(_Float16x x, _Float16x y);
_Float32x copysignf32x(_Float32x x, _Float32x y);
_Float64x copysignf64x(_Float64x x, _Float64x y);
_Float128x copysignf128x(_Float128x x, _Float128x y);

_Float16x nanf16x(const char* tagp);
_Float32x nanf32x(const char* tagp);
_Float64x nanf64x(const char* tagp);
_Float128x nanf128x(const char* tagp);

_Float16x nextafterf16x(_Float16x x, _Float16x y);
_Float32x nextafterf32x(_Float32x x, _Float32x y);
_Float64x nextafterf64x(_Float64x x, _Float64x y);
_Float128x nextafterf128x(_Float128x x, _Float128x y);

_Float16x nextupf16x(_Float16x x);
_Float32x nextupf32x(_Float32x x);
_Float64x nextupf64x(_Float64x x);
_Float128x nextupf128x(_Float128x x);

_Float16x nextdownf16x(_Float16x x);
_Float32x nextdownf32x(_Float32x x);
_Float64x nextdownf64x(_Float64x x);
_Float128x nextdownf128x(_Float128x x);

int canonicalizef16x(_Float16x* cx, const _Float16x* x);
int canonicalizef32x(_Float32x* cx, const _Float32x* x);
int canonicalizef64x(_Float64x* cx, const _Float64x* x);
int canonicalizef128x(_Float128x* cx, const _Float128x* x);

_Float16x fdimf16x(_Float16x x, _Float16x y);
_Float32x fdimf32x(_Float32x x, _Float32x y);
_Float64x fdimf64x(_Float64x x, _Float64x y);
_Float128x fdimf128x(_Float128x x, _Float128x y);

_Float16x fmaximumf16x(_Float16x x, _Float16x y);
_Float32x fmaximumf32x(_Float32x x, _Float32x y);
_Float64x fmaximumf64x(_Float64x x, _Float64x y);
_Float128x fmaximumf128x(_Float128x x, _Float128x y);

_Float16x fminimumf16x(_Float16x x, _Float16x y);
_Float32x fminimumf32x(_Float32x x, _Float32x y);
_Float64x fminimumf64x(_Float64x x, _Float64x y);
_Float128x fminimumf128x(_Float128x x, _Float128x y);

_Float16x fmaximum_magf16x(_Float16x x, _Float16x y);
_Float32x fmaximum_magf32x(_Float32x x, _Float32x y);
_Float64x fmaximum_magf64x(_Float64x x, _Float64x y);
_Float128x fmaximum_magf128x(_Float128x x, _Float128x y);

_Float16x fminimum_magf16x(_Float16x x, _Float16x y);
_Float32x fminimum_magf32x(_Float32x x, _Float32x y);
_Float64x fminimum_magf64x(_Float64x x, _Float64x y);
_Float128x fminimum_magf128x(_Float128x x, _Float128x y);

_Float16x fmaximum_numf16x(_Float16x x, _Float16x y);
_Float32x fmaximum_numf32x(_Float32x x, _Float32x y);
_Float64x fmaximum_numf64x(_Float64x x, _Float64x y);
_Float128x fmaximum_numf128x(_Float128x x, _Float128x y);

_Float16x fminimum_numf16x(_Float16x x, _Float16x y);
_Float32x fminimum_numf32x(_Float32x x, _Float32x y);
_Float64x fminimum_numf64x(_Float64x x, _Float64x y);
_Float128x fminimum_numf128x(_Float128x x, _Float128x y);

_Float16x fmaximum_mag_numf16x(_Float16x x, _Float16x y);
_Float32x fmaximum_mag_numf32x(_Float32x x, _Float32x y);
_Float64x fmaximum_mag_numf64x(_Float64x x, _Float64x y);
_Float128x fmaximum_mag_numf128x(_Float128x x, _Float128x y);

_Float16x fminimum_mag_numf16x(_Float16x x, _Float16x y);
_Float32x fminimum_mag_numf32x(_Float32x x, _Float32x y);
_Float64x fminimum_mag_numf64x(_Float64x x, _Float64x y);
_Float128x fminimum_mag_numf128x(_Float128x x, _Float128x y);

_Float16x fmaf16x(_Float16x x, _Float16x y, _Float16x z);
_Float32x fmaf32x(_Float32x x, _Float32x y, _Float32x z);
_Float64x fmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float128x fmaf128x(_Float128x x, _Float128x y, _Float128x z);

// note : AI auto genereted code
_Float16 f16addf16x(_Float16x x, _Float16x y);
_Float16 f16addf32x(_Float32x x, _Float32x y);
_Float16 f16addf64x(_Float64x x, _Float64x y);
_Float16 f16addf128x(_Float128x x, _Float128x y);
_Float32 f32addf32x(_Float32x x, _Float32x y);
_Float32 f32addf64x(_Float64x x, _Float64x y);
_Float32 f32addf128x(_Float128x x, _Float128x y);
_Float64 f64addf64x(_Float64x x, _Float64x y);
_Float64 f64addf128x(_Float128x x, _Float128x y);
_Float128 f128addf128x(_Float128x x, _Float128x y);

_Float16x f16xaddf32x(_Float32x x, _Float32x y);
_Float16x f16xaddf64x(_Float64x x, _Float64x y);
_Float16x f16xaddf128x(_Float128x x, _Float128x y);
_Float32x f32xaddf64x(_Float64x x, _Float64x y);
_Float32x f32xaddf128x(_Float128x x, _Float128x y);
_Float64x f64xaddf128x(_Float128x x, _Float128x y);

_Float16 f16subf16x(_Float16x x, _Float16x y);
_Float16 f16subf32x(_Float32x x, _Float32x y);
_Float16 f16subf64x(_Float64x x, _Float64x y);
_Float16 f16subf128x(_Float128x x, _Float128x y);
_Float32 f32subf32x(_Float32x x, _Float32x y);
_Float32 f32subf64x(_Float64x x, _Float64x y);
_Float32 f32subf128x(_Float128x x, _Float128x y);
_Float64 f64subf64x(_Float64x x, _Float64x y);
_Float64 f64subf128x(_Float128x x, _Float128x y);
_Float128 f128subf128x(_Float128x x, _Float128x y);

_Float16x f16xsubf32x(_Float32x x, _Float32x y);
_Float16x f16xsubf64x(_Float64x x, _Float64x y);
_Float16x f16xsubf128x(_Float128x x, _Float128x y);
_Float32x f32xsubf64x(_Float64x x, _Float64x y);
_Float32x f32xsubf128x(_Float128x x, _Float128x y);
_Float64x f64xsubf128x(_Float128x x, _Float128x y);

_Float16 f16mulf16x(_Float16x x, _Float16x y);
_Float16 f16mulf32x(_Float32x x, _Float32x y);
_Float16 f16mulf64x(_Float64x x, _Float64x y);
_Float16 f16mulf128x(_Float128x x, _Float128x y);
_Float32 f32mulf32x(_Float32x x, _Float32x y);
_Float32 f32mulf64x(_Float64x x, _Float64x y);
_Float32 f32mulf128x(_Float128x x, _Float128x y);
_Float64 f64mulf64x(_Float64x x, _Float64x y);
_Float64 f64mulf128x(_Float128x x, _Float128x y);
_Float128 f128mulf128x(_Float128x x, _Float128x y);

_Float16x f16xmulf32x(_Float32x x, _Float32x y);
_Float16x f16xmulf64x(_Float64x x, _Float64x y);
_Float16x f16xmulf128x(_Float128x x, _Float128x y);
_Float32x f32xmulf64x(_Float64x x, _Float64x y);
_Float32x f32xmulf128x(_Float128x x, _Float128x y);
_Float64x f64xmulf128x(_Float128x x, _Float128x y);

_Float16 f16divf16x(_Float16x x, _Float16x y);
_Float16 f16divf32x(_Float32x x, _Float32x y);
_Float16 f16divf64x(_Float64x x, _Float64x y);
_Float16 f16divf128x(_Float128x x, _Float128x y);
_Float32 f32divf32x(_Float32x x, _Float32x y);
_Float32 f32divf64x(_Float64x x, _Float64x y);
_Float32 f32divf128x(_Float128x x, _Float128x y);
_Float64 f64divf64x(_Float64x x, _Float64x y);
_Float64 f64divf128x(_Float128x x, _Float128x y);
_Float128 f128divf128x(_Float128x x, _Float128x y);

_Float16x f16xdivf32x(_Float32x x, _Float32x y);
_Float16x f16xdivf64x(_Float64x x, _Float64x y);
_Float16x f16xdivf128x(_Float128x x, _Float128x y);
_Float32x f32xdivf64x(_Float64x x, _Float64x y);
_Float32x f32xdivf128x(_Float128x x, _Float128x y);
_Float64x f64xdivf128x(_Float128x x, _Float128x y);

_Float16 f16fmaf16x(_Float16x x, _Float16x y, _Float16x z);
_Float16 f16fmaf32x(_Float32x x, _Float32x y, _Float32x z);
_Float16 f16fmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float16 f16fmaf128x(_Float128x x, _Float128x y, _Float128x z);
_Float32 f32fmaf32x(_Float32x x, _Float32x y, _Float32x z);
_Float32 f32fmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float32 f32fmaf128x(_Float128x x, _Float128x y, _Float128x z);
_Float64 f64fmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float64 f64fmaf128x(_Float128x x, _Float128x y, _Float128x z);
_Float128 f128fmaf128x(_Float128x x, _Float128x y, _Float128x z);

_Float16x f16xfmaf32x(_Float32x x, _Float32x y, _Float32x z);
_Float16x f16xfmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float16x f16xfmaf128x(_Float128x x, _Float128x y, _Float128x z);
_Float32x f32xfmaf64x(_Float64x x, _Float64x y, _Float64x z);
_Float32x f32xfmaf128x(_Float128x x, _Float128x y, _Float128x z);
_Float64x f64xfmaf128x(_Float128x x, _Float128x y, _Float128x z);

_Float16 f16sqrtf16x(_Float16x x);
_Float16 f16sqrtf32x(_Float32x x);
_Float16 f16sqrtf64x(_Float64x x);
_Float16 f16sqrtf128x(_Float128x x);
_Float32 f32sqrtf32x(_Float32x x);
_Float32 f32sqrtf64x(_Float64x x);
_Float32 f32sqrtf128x(_Float128x x);
_Float64 f64sqrtf64x(_Float64x x);
_Float64 f64sqrtf128x(_Float128x x);
_Float128 f128sqrtf128x(_Float128x x);

_Float16x f16xsqrtf32x(_Float32x x);
_Float16x f16xsqrtf64x(_Float64x x);
_Float16x f16xsqrtf128x(_Float128x x);
_Float32x f32xsqrtf64x(_Float64x x);
_Float32x f32xsqrtf128x(_Float128x x);
_Float64x f64xsqrtf128x(_Float128x x);

_Float16x f16xaddf32(_Float32 x, _Float32 y);
_Float16x f16xaddf64(_Float64 x, _Float64 y);
_Float16x f16xaddf128(_Float128 x, _Float128 y);
_Float32x f32xaddf64(_Float64 x, _Float64 y);
_Float32x f32xaddf128(_Float128 x, _Float128 y);
_Float64x f64xaddf128(_Float128 x, _Float128 y);

_Float16 f16subf32(_Float32 x, _Float32 y);
_Float16 f16subf64(_Float64 x, _Float64 y);
_Float16 f16subf128(_Float128 x, _Float128 y);
_Float32 f32subf64(_Float64 x, _Float64 y);
_Float32 f32subf128(_Float128 x, _Float128 y);
_Float64 f64subf128(_Float128 x, _Float128 y);

_Float16x f16xsubf32(_Float32 x, _Float32 y);
_Float16x f16xsubf64(_Float64 x, _Float64 y);
_Float16x f16xsubf128(_Float128 x, _Float128 y);
_Float32x f32xsubf64(_Float64 x, _Float64 y);
_Float32x f32xsubf128(_Float128 x, _Float128 y);
_Float64x f64xsubf128(_Float128 x, _Float128 y);

_Float16 f16mulf32(_Float32 x, _Float32 y);
_Float16 f16mulf64(_Float64 x, _Float64 y);
_Float16 f16mulf128(_Float128 x, _Float128 y);
_Float32 f32mulf64(_Float64 x, _Float64 y);
_Float32 f32mulf128(_Float128 x, _Float128 y);
_Float64 f64mulf128(_Float128 x, _Float128 y);

_Float16x f16xmulf32(_Float32 x, _Float32 y);
_Float16x f16xmulf64(_Float64 x, _Float64 y);
_Float16x f16xmulf128(_Float128 x, _Float128 y);
_Float32x f32xmulf64(_Float64 x, _Float64 y);
_Float32x f32xmulf128(_Float128 x, _Float128 y);
_Float64x f64xmulf128(_Float128 x, _Float128 y);

_Float16 f16divf32(_Float32 x, _Float32 y);
_Float16 f16divf64(_Float64 x, _Float64 y);
_Float16 f16divf128(_Float128 x, _Float128 y);
_Float32 f32divf64(_Float64 x, _Float64 y);
_Float32 f32divf128(_Float128 x, _Float128 y);
_Float64 f64divf128(_Float128 x, _Float128 y);

_Float16x f16xdivf32(_Float32 x, _Float32 y);
_Float16x f16xdivf64(_Float64 x, _Float64 y);
_Float16x f16xdivf128(_Float128 x, _Float128 y);
_Float32x f32xdivf64(_Float64 x, _Float64 y);
_Float32x f32xdivf128(_Float128 x, _Float128 y);
_Float64x f64xdivf128(_Float128 x, _Float128 y);

_Float16 f16fmaf32(_Float32 x, _Float32 y, _Float32 z);
_Float16 f16fmaf64(_Float64 x, _Float64 y, _Float64 z);
_Float16 f16fmaf128(_Float128 x, _Float128 y, _Float128 z);
_Float32 f32fmaf64(_Float64 x, _Float64 y, _Float64 z);
_Float32 f32fmaf128(_Float128 x, _Float128 y, _Float128 z);
_Float64 f64fmaf128(_Float128 x, _Float128 y, _Float128 z);

_Float16x f16xfmaf32(_Float32 x, _Float32 y, _Float32 z);
_Float16x f16xfmaf64(_Float64 x, _Float64 y, _Float64 z);
_Float16x f16xfmaf128(_Float128 x, _Float128 y, _Float128 z);
_Float32x f32xfmaf64(_Float64 x, _Float64 y, _Float64 z);
_Float32x f32xfmaf128(_Float128 x, _Float128 y, _Float128 z);
_Float64x f64xfmaf128(_Float128 x, _Float128 y, _Float128 z);

_Float16 f16sqrtf32(_Float32 x);
_Float16 f16sqrtf64(_Float64 x);
_Float16 f16sqrtf128(_Float128 x);
_Float32 f32sqrtf64(_Float64 x);
_Float32 f32sqrtf128(_Float128 x);
_Float64 f64sqrtf128(_Float128 x);

_Float16x f16xsqrtf32(_Float32 x);
_Float16x f16xsqrtf64(_Float64 x);
_Float16x f16xsqrtf128(_Float128 x);
_Float32x f32xsqrtf64(_Float64 x);
_Float32x f32xsqrtf128(_Float128 x);
_Float64x f64xsqrtf128(_Float128 x);
// end genereted code

_Float64x quantizef64x(_Float64x x, _Float64x y);
_Float128x quantizef128x(_Float128x x, _Float128x y);

bool samequantumf64x(_Float64x x, _Float64x y);
bool samequantumf128x(_Float128x x, _Float128x y);

_Float64x quantumf64x(_Float64x x);
_Float128x quantumf128x(_Float128x x);

long long int llquantexpf64x(_Float64x x);
long long int llquantexpf128x(_Float128x x);

void encodedecf64x(unsigned char* restrict encptr, const _Float64x* restrict xptr);
void decodedecf64x(_Float64x* restrict xptr, const unsigned char* restrict encptr);
void encodebinf64x(unsigned char* restrict encptr, const _Float64x* restrict xptr);
void decodebinf64x(_Float64x* restrict xptr, const unsigned char* restrict encptr);

int totalorderf16x(const _Float16x* x, const _Float16x* y);
int totalorderf32x(const _Float32x* x, const _Float32x* y);
int totalorderf64x(const _Float64x* x, const _Float64x* y);
int totalorderf128x(const _Float128x* x, const _Float128x* y);
int totalordermagf16x(const _Float16x* x, const _Float16x* y);
int totalordermagf32x(const _Float32x* x, const _Float32x* y);
int totalordermagf64x(const _Float64x* x, const _Float64x* y);
int totalordermagf128x(const _Float128x* x, const _Float128x* y);

_Float16x getpayloadf16x(const _Float16x* x);
_Float32x getpayloadf32x(const _Float32x* x);
_Float64x getpayloadf64x(const _Float64x* x);
_Float128x getpayloadf128x(const _Float128x* x);

int setpayloadf16x(_Float16x* res, _Float16x pl);
int setpayloadf32x(_Float32x* res, _Float32x pl);
int setpayloadf64x(_Float64x* res, _Float64x pl);
int setpayloadf128x(_Float128x* res, _Float128x pl);
int setpayloadsigf16x(_Float16x* res, _Float16x pl);
int setpayloadsigf32x(_Float32x* res, _Float32x pl);
int setpayloadsigf64x(_Float64x* res, _Float64x pl);
int setpayloadsigf128x(_Float128x* res, _Float128x pl);

#endif // __STDC_IEC_60559_BFP__


#if defined(__STDC_IEC_60559_DFP__)

// math functions for _DecimalN type
_Decimal32 acosd32(_Decimal32 x);
_Decimal64 acosd64(_Decimal64 x);
_Decimal128 acosd128(_Decimal128 x);

_Decimal32 asind32(_Decimal32 x);
_Decimal64 asind64(_Decimal64 x);
_Decimal128 asind128(_Decimal128 x);

_Decimal32 atand32(_Decimal32 x);
_Decimal64 atand64(_Decimal64 x);
_Decimal128 atand128(_Decimal128 x);

_Decimal32 atan2d32(_Decimal32 y, _Decimal32 x);
_Decimal64 atan2d64(_Decimal64 y, _Decimal64 x);
_Decimal128 atan2d128(_Decimal128 y, _Decimal128 x);

_Decimal32 cosd32(_Decimal32 x);
_Decimal64 cosd64(_Decimal64 x);
_Decimal128 cosd128(_Decimal128 x);

_Decimal32 sind32(_Decimal32 x);
_Decimal64 sind64(_Decimal64 x);
_Decimal128 sind128(_Decimal128 x);

_Decimal32 tand32(_Decimal32 x);
_Decimal64 tand64(_Decimal64 x);
_Decimal128 tand128(_Decimal128 x);

_Decimal32 acospid32(_Decimal32 x);
_Decimal64 acospid64(_Decimal64 x);
_Decimal128 acospid128(_Decimal128 x);

_Decimal32 asinpid32(_Decimal32 x);
_Decimal64 asinpid64(_Decimal64 x);
_Decimal128 asinpid128(_Decimal128 x);

_Decimal32 atanpid32(_Decimal32 x);
_Decimal64 atanpid64(_Decimal64 x);
_Decimal128 atanpid128(_Decimal128 x);

_Decimal32 atan2pid32(_Decimal32 y, _Decimal32 x);
_Decimal64 atan2pid64(_Decimal64 y, _Decimal64 x);
_Decimal128 atan2pid128(_Decimal128 y, _Decimal128 x);

_Decimal32 cospid32(_Decimal32 x);
_Decimal64 cospid64(_Decimal64 x);
_Decimal128 cospid128(_Decimal128 x);

_Decimal32 sinpid32(_Decimal32 x);
_Decimal64 sinpid64(_Decimal64 x);
_Decimal128 sinpid128(_Decimal128 x);

_Decimal32 tanpid32(_Decimal32 x);
_Decimal64 tanpid64(_Decimal64 x);
_Decimal128 tanpid128(_Decimal128 x);

_Decimal32 acoshd32(_Decimal32 x);
_Decimal64 acoshd64(_Decimal64 x);
_Decimal128 acoshd128(_Decimal128 x);

_Decimal32 asinhd32(_Decimal32 x);
_Decimal64 asinhd64(_Decimal64 x);
_Decimal128 asinhd128(_Decimal128 x);

_Decimal32 atanhd32(_Decimal32 x);
_Decimal64 atanhd64(_Decimal64 x);
_Decimal128 atanhd128(_Decimal128 x);

_Decimal32 coshd32(_Decimal32 x);
_Decimal64 coshd64(_Decimal64 x);
_Decimal128 coshd128(_Decimal128 x);

_Decimal32 sinhd32(_Decimal32 x);
_Decimal64 sinhd64(_Decimal64 x);
_Decimal128 sinhd128(_Decimal128 x);

_Decimal32 tanhd32(_Decimal32 x);
_Decimal64 tanhd64(_Decimal64 x);
_Decimal128 tanhd128(_Decimal128 x);

_Decimal32 expd32(_Decimal32 x);
_Decimal64 expd64(_Decimal64 x);
_Decimal128 expd128(_Decimal128 x);

_Decimal32 exp10d32(_Decimal32 x);
_Decimal64 exp10d64(_Decimal64 x);
_Decimal128 exp10d128(_Decimal128 x);

_Decimal32 exp10m1d32(_Decimal32 x);
_Decimal64 exp10m1d64(_Decimal64 x);
_Decimal128 exp10m1d128(_Decimal128 x);

_Decimal32 exp2d32(_Decimal32 x);
_Decimal64 exp2d64(_Decimal64 x);
_Decimal128 exp2d128(_Decimal128 x);

_Decimal32 exp2m1d32(_Decimal32 x);
_Decimal64 exp2m1d64(_Decimal64 x);
_Decimal128 exp2m1d128(_Decimal128 x);

_Decimal32 expm1d32(_Decimal32 x);
_Decimal64 expm1d64(_Decimal64 x);
_Decimal128 expm1d128(_Decimal128 x);

_Decimal32 frexpd32(_Decimal32 value, int* p);
_Decimal64 frexpd64(_Decimal64 value, int* p);
_Decimal128 frexpd128(_Decimal128 value, int* p);

int ilogbd32(_Decimal32 x);
int ilogbd64(_Decimal64 x);
int ilogbd128(_Decimal128 x);

_Decimal32 ldexpd32(_Decimal32 x, int p);
_Decimal64 ldexpd64(_Decimal64 x, int p);
_Decimal128 ldexpd128(_Decimal128 x, int p);

long int llogbd32(_Decimal32 x);
long int llogbd64(_Decimal64 x);
long int llogbd128(_Decimal128 x);

_Decimal32 logd32(_Decimal32 x);
_Decimal64 logd64(_Decimal64 x);
_Decimal128 logd128(_Decimal128 x);

_Decimal32 log10d32(_Decimal32 x);
_Decimal64 log10d64(_Decimal64 x);
_Decimal128 log10d128(_Decimal128 x);

_Decimal32 log10p1d32(_Decimal32 x);
_Decimal64 log10p1d64(_Decimal64 x);
_Decimal128 log10p1d128(_Decimal128 x);

_Decimal32 log1pd32(_Decimal32 x);
_Decimal64 log1pd64(_Decimal64 x);
_Decimal128 log1pd128(_Decimal128 x);

_Decimal32 logp1d32(_Decimal32 x);
_Decimal64 logp1d64(_Decimal64 x);
_Decimal128 logp1d128(_Decimal128 x);

_Decimal32 log2d32(_Decimal32 x);
_Decimal64 log2d64(_Decimal64 x);
_Decimal128 log2d128(_Decimal128 x);

_Decimal32 log2p1d32(_Decimal32 x);
_Decimal64 log2p1d64(_Decimal64 x);
_Decimal128 log2p1d128(_Decimal128 x);

_Decimal32 logbd32(_Decimal32 x);
_Decimal64 logbd64(_Decimal64 x);
_Decimal128 logbd128(_Decimal128 x);

_Decimal32 modfd32(_Decimal32 x, _Decimal32* iptr);
_Decimal64 modfd64(_Decimal64 x, _Decimal64* iptr);
_Decimal128 modfd128(_Decimal128 x, _Decimal128* iptr);

_Decimal32 scalbnd32(_Decimal32 x, int n);
_Decimal64 scalbnd64(_Decimal64 x, int n);
_Decimal128 scalbnd128(_Decimal128 x, int n);

_Decimal32 scalblnd32(_Decimal32 x, long int n);
_Decimal64 scalblnd64(_Decimal64 x, long int n);
_Decimal128 scalblnd128(_Decimal128 x, long int n);

_Decimal32 cbrtd32(_Decimal32 x);
_Decimal64 cbrtd64(_Decimal64 x);
_Decimal128 cbrtd128(_Decimal128 x);

_Decimal32 compoundnd32(_Decimal32 x, long long int n);
_Decimal64 compoundnd64(_Decimal64 x, long long int n);
_Decimal128 compoundnd128(_Decimal128 x, long long int n);

_Decimal32 fabsd32(_Decimal32 x);
_Decimal64 fabsd64(_Decimal64 x);
_Decimal128 fabsd128(_Decimal128 x);

_Decimal32 hypotd32(_Decimal32 x, _Decimal32 y);
_Decimal64 hypotd64(_Decimal64 x, _Decimal64 y);
_Decimal128 hypotd128(_Decimal128 x, _Decimal128 y);

_Decimal32 powd32(_Decimal32 x, _Decimal32 y);
_Decimal64 powd64(_Decimal64 x, _Decimal64 y);
_Decimal128 powd128(_Decimal128 x, _Decimal128 y);

_Decimal32 pownd32(_Decimal32 x, long long int n);
_Decimal64 pownd64(_Decimal64 x, long long int n);
_Decimal128 pownd128(_Decimal128 x, long long int n);

_Decimal32 powrd32(_Decimal32 y, _Decimal32 x);
_Decimal64 powrd64(_Decimal64 y, _Decimal64 x);
_Decimal128 powrd128(_Decimal128 y, _Decimal128 x);

_Decimal32 rootnd32(_Decimal32 x, long long int n);
_Decimal64 rootnd64(_Decimal64 x, long long int n);
_Decimal128 rootnd128(_Decimal128 x, long long int n);

_Decimal32 rsqrtd32(_Decimal32 x);
_Decimal64 rsqrtd64(_Decimal64 x);
_Decimal128 rsqrtd128(_Decimal128 x);

_Decimal32 sqrtd32(_Decimal32 x);
_Decimal64 sqrtd64(_Decimal64 x);
_Decimal128 sqrtd128(_Decimal128 x);

_Decimal32 erfd32(_Decimal32 x);
_Decimal64 erfd64(_Decimal64 x);
_Decimal128 erfd128(_Decimal128 x);

_Decimal32 erfcd32(_Decimal32 x);
_Decimal64 erfcd64(_Decimal64 x);
_Decimal128 erfcd128(_Decimal128 x);

_Decimal32 lgammad32(_Decimal32 x);
_Decimal64 lgammad64(_Decimal64 x);
_Decimal128 lgammad128(_Decimal128 x);

_Decimal32 tgammad32(_Decimal32 x);
_Decimal64 tgammad64(_Decimal64 x);
_Decimal128 tgammad128(_Decimal128 x);

_Decimal32 ceild32(_Decimal32 x);
_Decimal64 ceild64(_Decimal64 x);
_Decimal128 ceild128(_Decimal128 x);

_Decimal32 floord32(_Decimal32 x);
_Decimal64 floord64(_Decimal64 x);
_Decimal128 floord128(_Decimal128 x);

_Decimal32 nearbyintd32(_Decimal32 x);
_Decimal64 nearbyintd64(_Decimal64 x);
_Decimal128 nearbyintd128(_Decimal128 x);

_Decimal32 rintd32(_Decimal32 x);
_Decimal64 rintd64(_Decimal64 x);
_Decimal128 rintd128(_Decimal128 x);

long int lrintd32(_Decimal32 x);
long int lrintd64(_Decimal64 x);
long int lrintd128(_Decimal128 x);

long long int llrintd32(_Decimal32 x);
long long int llrintd64(_Decimal64 x);
long long int llrintd128(_Decimal128 x);

_Decimal32 roundd32(_Decimal32 x);
_Decimal64 roundd64(_Decimal64 x);
_Decimal128 roundd128(_Decimal128 x);

long int lroundd32(_Decimal32 x);
long int lroundd64(_Decimal64 x);
long int lroundd128(_Decimal128 x);

long long int llroundd32(_Decimal32 x);
long long int llroundd64(_Decimal64 x);
long long int llroundd128(_Decimal128 x);

_Decimal32 roundevend32(_Decimal32 x);
_Decimal64 roundevend64(_Decimal64 x);
_Decimal128 roundevend128(_Decimal128 x);

_Decimal32 truncd32(_Decimal32 x);
_Decimal64 truncd64(_Decimal64 x);
_Decimal128 truncd128(_Decimal128 x);

_Decimal32 fromfpd32(_Decimal32 x, int rnd, unsigned int width);
_Decimal64 fromfpd64(_Decimal64 x, int rnd, unsigned int width);
_Decimal128 fromfpd128(_Decimal128 x, int rnd, unsigned int width);

_Decimal32 ufromfpd32(_Decimal32 x, int rnd, unsigned int width);
_Decimal64 ufromfpd64(_Decimal64 x, int rnd, unsigned int width);
_Decimal128 ufromfpd128(_Decimal128 x, int rnd, unsigned int width);

_Decimal32 fromfpxd32(_Decimal32 x, int rnd, unsigned int width);
_Decimal64 fromfpxd64(_Decimal64 x, int rnd, unsigned int width);
_Decimal128 fromfpxd128(_Decimal128 x, int rnd, unsigned int width);

_Decimal32 ufromfpxd32(_Decimal32 x, int rnd, unsigned int width);
_Decimal64 ufromfpxd64(_Decimal64 x, int rnd, unsigned int width);
_Decimal128 ufromfpxd128(_Decimal128 x, int rnd, unsigned int width);

_Decimal32 fmodd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmodd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmodd128(_Decimal128 x, _Decimal128 y);

_Decimal32 remainderd32(_Decimal32 x, _Decimal32 y);
_Decimal64 remainderd64(_Decimal64 x, _Decimal64 y);
_Decimal128 remainderd128(_Decimal128 x, _Decimal128 y);

_Decimal32 copysignd32(_Decimal32 x, _Decimal32 y);
_Decimal64 copysignd64(_Decimal64 x, _Decimal64 y);
_Decimal128 copysignd128(_Decimal128 x, _Decimal128 y);

_Decimal32 nand32(const char* tagp);
_Decimal64 nand64(const char* tagp);
_Decimal128 nand128(const char* tagp);

_Decimal32 nextafterd32(_Decimal32 x, _Decimal32 y);
_Decimal64 nextafterd64(_Decimal64 x, _Decimal64 y);
_Decimal128 nextafterd128(_Decimal128 x, _Decimal128 y);

_Decimal32 nexttowardd32(_Decimal32 x, _Decimal128 y);
_Decimal64 nexttowardd64(_Decimal64 x, _Decimal128 y);
_Decimal128 nexttowardd128(_Decimal128 x, _Decimal128 y);

_Decimal32 nextupd32(_Decimal32 x);
_Decimal64 nextupd64(_Decimal64 x);
_Decimal128 nextupd128(_Decimal128 x);

_Decimal32 nextdownd32(_Decimal32 x);
_Decimal64 nextdownd64(_Decimal64 x);
_Decimal128 nextdownd128(_Decimal128 x);

int canonicalized32(_Decimal32* cx, const _Decimal32* x);
int canonicalized64(_Decimal64* cx, const _Decimal64* x);
int canonicalized128(_Decimal128* cx, const _Decimal128* x);

_Decimal32 fdimd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fdimd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fdimd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmaxd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmaxd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmaxd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmind32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmind64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmind128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmaximumd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmaximumd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmaximumd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fminimumd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fminimumd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fminimumd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmaximum_magd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmaximum_magd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmaximum_magd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fminimum_magd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fminimum_magd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fminimum_magd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmaximum_numd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmaximum_numd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmaximum_numd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fminimum_numd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fminimum_numd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fminimum_numd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmaximum_mag_numd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fmaximum_mag_numd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fmaximum_mag_numd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fminimum_mag_numd32(_Decimal32 x, _Decimal32 y);
_Decimal64 fminimum_mag_numd64(_Decimal64 x, _Decimal64 y);
_Decimal128 fminimum_mag_numd128(_Decimal128 x, _Decimal128 y);

_Decimal32 fmad32(_Decimal32 x, _Decimal32 y, _Decimal32 z);
_Decimal64 fmad64(_Decimal64 x, _Decimal64 y, _Decimal64 z);
_Decimal128 fmad128(_Decimal128 x, _Decimal128 y, _Decimal128 z);

_Decimal32 d32addd64(_Decimal64 x, _Decimal64 y);
_Decimal32 d32addd128(_Decimal128 x, _Decimal128 y);
_Decimal64 d64addd128(_Decimal128 x, _Decimal128 y);

_Decimal32 d32subd64(_Decimal64 x, _Decimal64 y);
_Decimal32 d32subd128(_Decimal128 x, _Decimal128 y);
_Decimal64 d64subd128(_Decimal128 x, _Decimal128 y);

_Decimal32 d32muld64(_Decimal64 x, _Decimal64 y);
_Decimal32 d32muld128(_Decimal128 x, _Decimal128 y);
_Decimal64 d64muld128(_Decimal128 x, _Decimal128 y);

_Decimal32 d32divd64(_Decimal64 x, _Decimal64 y);
_Decimal32 d32divd128(_Decimal128 x, _Decimal128 y);
_Decimal64 d64divd128(_Decimal128 x, _Decimal128 y);

_Decimal32 d32fmad64(_Decimal64 x, _Decimal64 y, _Decimal64 z);
_Decimal32 d32fmad128(_Decimal128 x, _Decimal128 y, _Decimal128 z);
_Decimal64 d64fmad128(_Decimal128 x, _Decimal128 y, _Decimal128 z);

_Decimal32 d32sqrtd64(_Decimal64 x);
_Decimal32 d32sqrtd128(_Decimal128 x);
_Decimal64 d64sqrtd128(_Decimal128 x);

_Decimal32 quantized32(_Decimal32 x, _Decimal32 y);
_Decimal64 quantized64(_Decimal64 x, _Decimal64 y);
_Decimal128 quantized128(_Decimal128 x, _Decimal128 y);

bool samequantumd32(_Decimal32 x, _Decimal32 y);
bool samequantumd64(_Decimal64 x, _Decimal64 y);
bool samequantumd128(_Decimal128 x, _Decimal128 y);

_Decimal32 quantumd32(_Decimal32 x);
_Decimal64 quantumd64(_Decimal64 x);
_Decimal128 quantumd128(_Decimal128 x);

long long int llquantexpd32(_Decimal32 x);
long long int llquantexpd64(_Decimal64 x);
long long int llquantexpd128(_Decimal128 x);

void encodedecd32(unsigned char encptr[restrict static 4], const _Decimal32* restrict xptr);
void encodedecd64(unsigned char encptr[restrict static 8], const _Decimal64* restrict xptr);
void encodedecd128(unsigned char encptr[restrict static 16], const _Decimal128* restrict xptr);

void decodedecd32(_Decimal32* restrict xptr, const unsigned char encptr[restrict static 4]);
void decodedecd64(_Decimal64* restrict xptr, const unsigned char encptr[restrict static 8]);
void decodedecd128(_Decimal128* restrict xptr, const unsigned char encptr[restrict static 16]);

void encodebind32(unsigned char encptr[restrict static 4], const _Decimal32* restrict xptr);
void encodebind64(unsigned char encptr[restrict static 8], const _Decimal64* restrict xptr);
void encodebind128(unsigned char encptr[restrict static 16], const _Decimal128* restrict xptr);

void decodebind32(_Decimal32* restrict xptr, const unsigned char encptr[restrict static 4]);
void decodebind64(_Decimal64* restrict xptr, const unsigned char encptr[restrict static 8]);
void decodebind128(_Decimal128* restrict xptr, const unsigned char encptr[restrict static 16]);


// math functions for _DecimalNx type
_Decimal32x acosd32x(_Decimal32x x);
_Decimal64x acosd64x(_Decimal64x x);
_Decimal128x acosd128x(_Decimal128x x);

_Decimal32x asind32x(_Decimal32x x);
_Decimal64x asind64x(_Decimal64x x);
_Decimal128x asind128x(_Decimal128x x);

_Decimal32x atand32x(_Decimal32x x);
_Decimal64x atand64x(_Decimal64x x);
_Decimal128x atand128x(_Decimal128x x);

_Decimal32x atan2d32x(_Decimal32x y, _Decimal32x x);
_Decimal64x atan2d64x(_Decimal64x y, _Decimal64x x);
_Decimal128x atan2d128x(_Decimal128x y, _Decimal128x x);

_Decimal32x cosd32x(_Decimal32x x);
_Decimal64x cosd64x(_Decimal64x x);
_Decimal128x cosd128x(_Decimal128x x);

_Decimal32x sind32x(_Decimal32x x);
_Decimal64x sind64x(_Decimal64x x);
_Decimal128x sind128x(_Decimal128x x);

_Decimal32x tand32x(_Decimal32x x);
_Decimal64x tand64x(_Decimal64x x);
_Decimal128x tand128x(_Decimal128x x);

_Decimal32x acospid32x(_Decimal32x x);
_Decimal64x acospid64x(_Decimal64x x);
_Decimal128x acospid128x(_Decimal128x x);

_Decimal32x asinpid32x(_Decimal32x x);
_Decimal64x asinpid64x(_Decimal64x x);
_Decimal128x asinpid128x(_Decimal128x x);

_Decimal32x atanpid32x(_Decimal32x x);
_Decimal64x atanpid64x(_Decimal64x x);
_Decimal128x atanpid128x(_Decimal128x x);

_Decimal32x atan2pid32x(_Decimal32x y, _Decimal32x x);
_Decimal64x atan2pid64x(_Decimal64x y, _Decimal64x x);
_Decimal128x atan2pid128x(_Decimal128x y, _Decimal128x x);

_Decimal32x cospid32x(_Decimal32x x);
_Decimal64x cospid64x(_Decimal64x x);
_Decimal128x cospid128x(_Decimal128x x);

_Decimal32x sinpid32x(_Decimal32x x);
_Decimal64x sinpid64x(_Decimal64x x);
_Decimal128x sinpid128x(_Decimal128x x);

_Decimal32x tanpid32x(_Decimal32x x);
_Decimal64x tanpid64x(_Decimal64x x);
_Decimal128x tanpid128x(_Decimal128x x);

_Decimal32x acoshd32x(_Decimal32x x);
_Decimal64x acoshd64x(_Decimal64x x);
_Decimal128x acoshd128x(_Decimal128x x);

_Decimal32x asinhd32x(_Decimal32x x);
_Decimal64x asinhd64x(_Decimal64x x);
_Decimal128x asinhd128x(_Decimal128x x);

_Decimal32x atanhd32x(_Decimal32x x);
_Decimal64x atanhd64x(_Decimal64x x);
_Decimal128x atanhd128x(_Decimal128x x);

_Decimal32x coshd32x(_Decimal32x x);
_Decimal64x coshd64x(_Decimal64x x);
_Decimal128x coshd128x(_Decimal128x x);

_Decimal32x sinhd32x(_Decimal32x x);
_Decimal64x sinhd64x(_Decimal64x x);
_Decimal128x sinhd128x(_Decimal128x x);

_Decimal32x tanhd32x(_Decimal32x x);
_Decimal64x tanhd64x(_Decimal64x x);
_Decimal128x tanhd128x(_Decimal128x x);

_Decimal32x expd32x(_Decimal32x x);
_Decimal64x expd64x(_Decimal64x x);
_Decimal128x expd128x(_Decimal128x x);

_Decimal32x exp10d32x(_Decimal32x x);
_Decimal64x exp10d64x(_Decimal64x x);
_Decimal128x exp10d128x(_Decimal128x x);

_Decimal32x exp10m1d32x(_Decimal32x x);
_Decimal64x exp10m1d64x(_Decimal64x x);
_Decimal128x exp10m1d128x(_Decimal128x x);

_Decimal32x exp2d32x(_Decimal32x x);
_Decimal64x exp2d64x(_Decimal64x x);
_Decimal128x exp2d128x(_Decimal128x x);

_Decimal32x exp2m1d32x(_Decimal32x x);
_Decimal64x exp2m1d64x(_Decimal64x x);
_Decimal128x exp2m1d128x(_Decimal128x x);

_Decimal32x expm1d32x(_Decimal32x x);
_Decimal64x expm1d64x(_Decimal64x x);
_Decimal128x expm1d128x(_Decimal128x x);

_Decimal32x frexpd32x(_Decimal32x value, int* p);
_Decimal64x frexpd64x(_Decimal64x value, int* p);
_Decimal128x frexpd128x(_Decimal128x value, int* p);

int ilogbd32x(_Decimal32x x);
int ilogbd64x(_Decimal64x x);
int ilogbd128x(_Decimal128x x);

_Decimal32x ldexpd32x(_Decimal32x x, int p);
_Decimal64x ldexpd64x(_Decimal64x x, int p);
_Decimal128x ldexpd128x(_Decimal128x x, int p);

long int llogbd32x(_Decimal32x x);
long int llogbd64x(_Decimal64x x);
long int llogbd128x(_Decimal128x x);

_Decimal32x logd32x(_Decimal32x x);
_Decimal64x logd64x(_Decimal64x x);
_Decimal128x logd128x(_Decimal128x x);

_Decimal32x log10d32x(_Decimal32x x);
_Decimal64x log10d64x(_Decimal64x x);
_Decimal128x log10d128x(_Decimal128x x);

_Decimal32x log10p1d32x(_Decimal32x x);
_Decimal64x log10p1d64x(_Decimal64x x);
_Decimal128x log10p1d128x(_Decimal128x x);

_Decimal32x log1pd32x(_Decimal32x x);
_Decimal64x log1pd64x(_Decimal64x x);
_Decimal128x log1pd128x(_Decimal128x x);

_Decimal32x logp1d32x(_Decimal32x x);
_Decimal64x logp1d64x(_Decimal64x x);
_Decimal128x logp1d128x(_Decimal128x x);

_Decimal32x log2d32x(_Decimal32x x);
_Decimal64x log2d64x(_Decimal64x x);
_Decimal128x log2d128x(_Decimal128x x);

_Decimal32x log2p1d32x(_Decimal32x x);
_Decimal64x log2p1d64x(_Decimal64x x);
_Decimal128x log2p1d128x(_Decimal128x x);

_Decimal32x logbd32x(_Decimal32x x);
_Decimal64x logbd64x(_Decimal64x x);
_Decimal128x logbd128x(_Decimal128x x);

_Decimal32x modfd32x(_Decimal32x x, _Decimal32x* iptr);
_Decimal64x modfd64x(_Decimal64x x, _Decimal64x* iptr);
_Decimal128x modfd128x(_Decimal128x x, _Decimal128x* iptr);

_Decimal32x scalbnd32x(_Decimal32x x, int n);
_Decimal64x scalbnd64x(_Decimal64x x, int n);
_Decimal128x scalbnd128x(_Decimal128x x, int n);

_Decimal32x scalblnd32x(_Decimal32x x, long int n);
_Decimal64x scalblnd64x(_Decimal64x x, long int n);
_Decimal128x scalblnd128x(_Decimal128x x, long int n);

_Decimal32x cbrtd32x(_Decimal32x x);
_Decimal64x cbrtd64x(_Decimal64x x);
_Decimal128x cbrtd128x(_Decimal128x x);

_Decimal32x compoundnd32x(_Decimal32x x, long long int n);
_Decimal64x compoundnd64x(_Decimal64x x, long long int n);
_Decimal128x compoundnd128x(_Decimal128x x, long long int n);

_Decimal32x fabsd32x(_Decimal32x x);
_Decimal64x fabsd64x(_Decimal64x x);
_Decimal128x fabsd128x(_Decimal128x x);

_Decimal32x hypotd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x hypotd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x hypotd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x powd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x powd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x powd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x pownd32x(_Decimal32x x, long long int n);
_Decimal64x pownd64x(_Decimal64x x, long long int n);
_Decimal128x pownd128x(_Decimal128x x, long long int n);

_Decimal32x powrd32x(_Decimal32x y, _Decimal32x x);
_Decimal64x powrd64x(_Decimal64x y, _Decimal64x x);
_Decimal128x powrd128x(_Decimal128x y, _Decimal128x x);

_Decimal32x rootnd32x(_Decimal32x x, long long int n);
_Decimal64x rootnd64x(_Decimal64x x, long long int n);
_Decimal128x rootnd128x(_Decimal128x x, long long int n);

_Decimal32x rsqrtd32x(_Decimal32x x);
_Decimal64x rsqrtd64x(_Decimal64x x);
_Decimal128x rsqrtd128x(_Decimal128x x);

_Decimal32x sqrtd32x(_Decimal32x x);
_Decimal64x sqrtd64x(_Decimal64x x);
_Decimal128x sqrtd128x(_Decimal128x x);

_Decimal32x erfd32x(_Decimal32x x);
_Decimal64x erfd64x(_Decimal64x x);
_Decimal128x erfd128x(_Decimal128x x);

_Decimal32x erfcd32x(_Decimal32x x);
_Decimal64x erfcd64x(_Decimal64x x);
_Decimal128x erfcd128x(_Decimal128x x);

_Decimal32x lgammad32x(_Decimal32x x);
_Decimal64x lgammad64x(_Decimal64x x);
_Decimal128x lgammad128x(_Decimal128x x);

_Decimal32x tgammad32x(_Decimal32x x);
_Decimal64x tgammad64x(_Decimal64x x);
_Decimal128x tgammad128x(_Decimal128x x);

_Decimal32x ceild32x(_Decimal32x x);
_Decimal64x ceild64x(_Decimal64x x);
_Decimal128x ceild128x(_Decimal128x x);

_Decimal32x floord32x(_Decimal32x x);
_Decimal64x floord64x(_Decimal64x x);
_Decimal128x floord128x(_Decimal128x x);

_Decimal32x nearbyintd32x(_Decimal32x x);
_Decimal64x nearbyintd64x(_Decimal64x x);
_Decimal128x nearbyintd128x(_Decimal128x x);

_Decimal32x rintd32x(_Decimal32x x);
_Decimal64x rintd64x(_Decimal64x x);
_Decimal128x rintd128x(_Decimal128x x);

long int lrintd32x(_Decimal32x x);
long int lrintd64x(_Decimal64x x);
long int lrintd128x(_Decimal128x x);

long long int llrintd32x(_Decimal32x x);
long long int llrintd64x(_Decimal64x x);
long long int llrintd128x(_Decimal128x x);

_Decimal32x roundd32x(_Decimal32x x);
_Decimal64x roundd64x(_Decimal64x x);
_Decimal128x roundd128x(_Decimal128x x);

long int lroundd32x(_Decimal32x x);
long int lroundd64x(_Decimal64x x);
long int lroundd128x(_Decimal128x x);

long long int llroundd32x(_Decimal32x x);
long long int llroundd64x(_Decimal64x x);
long long int llroundd128x(_Decimal128x x);

_Decimal32x roundevend32x(_Decimal32x x);
_Decimal64x roundevend64x(_Decimal64x x);
_Decimal128x roundevend128x(_Decimal128x x);

_Decimal32x truncd32x(_Decimal32x x);
_Decimal64x truncd64x(_Decimal64x x);
_Decimal128x truncd128x(_Decimal128x x);

_Decimal32x fromfpd32x(_Decimal32x x, int rnd, unsigned int width);
_Decimal64x fromfpd64x(_Decimal64x x, int rnd, unsigned int width);
_Decimal128x fromfpd128x(_Decimal128x x, int rnd, unsigned int width);

_Decimal32x ufromfpd32x(_Decimal32x x, int rnd, unsigned int width);
_Decimal64x ufromfpd64x(_Decimal64x x, int rnd, unsigned int width);
_Decimal128x ufromfpd128x(_Decimal128x x, int rnd, unsigned int width);

_Decimal32x fromfpxd32x(_Decimal32x x, int rnd, unsigned int width);
_Decimal64x fromfpxd64x(_Decimal64x x, int rnd, unsigned int width);
_Decimal128x fromfpxd128x(_Decimal128x x, int rnd, unsigned int width);

_Decimal32x ufromfpxd32x(_Decimal32x x, int rnd, unsigned int width);
_Decimal64x ufromfpxd64x(_Decimal64x x, int rnd, unsigned int width);
_Decimal128x ufromfpxd128x(_Decimal128x x, int rnd, unsigned int width);

_Decimal32x fmodd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmodd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmodd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x remainderd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x remainderd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x remainderd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x copysignd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x copysignd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x copysignd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x nand32x(const char* tagp);
_Decimal64x nand64x(const char* tagp);
_Decimal128x nand128x(const char* tagp);

_Decimal32x nextafterd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x nextafterd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x nextafterd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x nexttowardd32x(_Decimal32x x, _Decimal128x y);
_Decimal64x nexttowardd64x(_Decimal64x x, _Decimal128x y);
_Decimal128x nexttowardd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x nextupd32x(_Decimal32x x);
_Decimal64x nextupd64x(_Decimal64x x);
_Decimal128x nextupd128x(_Decimal128x x);

_Decimal32x nextdownd32x(_Decimal32x x);
_Decimal64x nextdownd64x(_Decimal64x x);
_Decimal128x nextdownd128x(_Decimal128x x);

int canonicalized32x(_Decimal32x* cx, const _Decimal32x* x);
int canonicalized64x(_Decimal64x* cx, const _Decimal64x* x);
int canonicalized128x(_Decimal128x* cx, const _Decimal128x* x);

_Decimal32x fdimd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fdimd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fdimd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmaxd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmaxd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmaxd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmind32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmind64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmind128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmaximumd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmaximumd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmaximumd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fminimumd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fminimumd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fminimumd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmaximum_magd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmaximum_magd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmaximum_magd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fminimum_magd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fminimum_magd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fminimum_magd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmaximum_numd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmaximum_numd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmaximum_numd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fminimum_numd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fminimum_numd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fminimum_numd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmaximum_mag_numd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fmaximum_mag_numd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fmaximum_mag_numd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fminimum_mag_numd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x fminimum_mag_numd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x fminimum_mag_numd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x fmad32x(_Decimal32x x, _Decimal32x y, _Decimal32x z);
_Decimal64x fmad64x(_Decimal64x x, _Decimal64x y, _Decimal64x z);
_Decimal128x fmad128x(_Decimal128x x, _Decimal128x y, _Decimal128x z);

_Decimal32x d32xaddd64x(_Decimal64x x, _Decimal64x y);
_Decimal32x d32xaddd128x(_Decimal128x x, _Decimal128x y);
_Decimal64x d64xaddd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x d32xsubd64x(_Decimal64x x, _Decimal64x y);
_Decimal32x d32xsubd128x(_Decimal128x x, _Decimal128x y);
_Decimal64x d64xsubd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x d32xmuld64x(_Decimal64x x, _Decimal64x y);
_Decimal32x d32xmuld128x(_Decimal128x x, _Decimal128x y);
_Decimal64x d64xmuld128x(_Decimal128x x, _Decimal128x y);

_Decimal32x d32xdivd64x(_Decimal64x x, _Decimal64x y);
_Decimal32x d32xdivd128x(_Decimal128x x, _Decimal128x y);
_Decimal64x d64xdivd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x d32xfmad64x(_Decimal64x x, _Decimal64x y, _Decimal64x z);
_Decimal32x d32xfmad128x(_Decimal128x x, _Decimal128x y, _Decimal128x z);
_Decimal64x d64xfmad128x(_Decimal128x x, _Decimal128x y, _Decimal128x z);

_Decimal32x d32xsqrtd64x(_Decimal64x x);
_Decimal32x d32xsqrtd128x(_Decimal128x x);
_Decimal64x d64xsqrtd128x(_Decimal128x x);

_Decimal32x quantized32x(_Decimal32x x, _Decimal32x y);
_Decimal64x quantized64x(_Decimal64x x, _Decimal64x y);
_Decimal128x quantized128x(_Decimal128x x, _Decimal128x y);

bool samequantumd32x(_Decimal32x x, _Decimal32x y);
bool samequantumd64x(_Decimal64x x, _Decimal64x y);
bool samequantumd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x quantumd32x(_Decimal32x x);
_Decimal64x quantumd64x(_Decimal64x x);
_Decimal128x quantumd128x(_Decimal128x x);

long long int llquantexpd32x(_Decimal32x x);
long long int llquantexpd64x(_Decimal64x x);
long long int llquantexpd128x(_Decimal128x x);

int totalorderd32x(const _Decimal32x* x, const _Decimal32x* y);
int totalorderd64x(const _Decimal64x* x, const _Decimal64x* y);
int totalorderd128x(const _Decimal128x* x, const _Decimal128x* y);

int totalordermagd32x(const _Decimal32x* x, const _Decimal32x* y);
int totalordermagd64x(const _Decimal32x* x, const _Decimal64x* y);
int totalordermagd128x(const _Decimal128x* x, const _Decimal128x* y);

_Decimal32x getpayloadd32x(const _Decimal32x* x);
_Decimal64x getpayloadd64x(const _Decimal32x* x);
_Decimal128x getpayloadd128x(const _Decimal128x* x);

int setpayloadd32x(_Decimal32x* res, _Decimal32x pl);
int setpayloadd64x(_Decimal32x* res, _Decimal64x pl);
int setpayloadd128x(_Decimal128x* res, _Decimal128x pl);

int setpayloadsigd32x(_Decimal32x* res, _Decimal32x pl);
int setpayloadsigd64x(_Decimal64x* res, _Decimal64x pl);
int setpayloadsigd128x(_Decimal128x* res, _Decimal128x pl);

#endif // end __STDC_IEC_60559_DFP__
#endif // end __STDC_WANT_IEC_60559_TYPES_EXT__

/*
ISO/IEC TS 18661-­ 4:2015 に規定の予約された識別子。現在は未実装
https://en.cppreference.com/w/c/experimental/fpext4.html は、実装任意関数と間違えている。
*/

/*
#if defined(__STDC_IEC_60559_FUNCS__)

double crexp(double x);
float crexpf(float x);
long double crexpl(long double x);

double crexpm1(double x);
float crexpm1f(float x);
long double crexpm1l(long double x);

double crexp2(double x);
float crexp2f(float x);
long double crexp2l(long double x);

double crexp2m1(double x);
float crexp2m1f(float x);
long double crexp2m1l(long double x);

double crexp10(double x);
float crexp10f(float x);
long double crexp10l(long double x);

double crexp10m1(double x);
float crexp10m1f(float x);
long double crexp10m1l(long double x);

double crlog(double x);
float crlogf(float x);
long double crlogl(long double x);

double crlog2(double x);
float crlog2f(float x);
long double crlog2l(long double x);

double crlog10(double x);
float crlog10f(float x);
long double crlog10l(long double x);

double crlog1p(double x);
float crlog1pf(float x);
long double crlog1pl(long double x);

double crlogp1(double x);
float crlogp1f(float x);
long double crlogp1l(long double x);

double crlog2p1(double x);
float crlog2p1f(float x);
long double crlog2p1l(long double x);

double crlog10p1(double x);
float crlog10p1f(float x);
long double crlog10p1l(long double x);

double crhypot(double x, double y);
float crhypotf(float x, float y);
long double crhypotl(long double x, long double y);

double crrsqrt(double x);
float crrsqrtf(float x);
long double crrsqrtl(long double x);

double crcompoundn(double x, long long int n);
float crcompoundnf(float x, long long int n);
long double crcompoundnl(long double x, long long int n);

double crrootn(double x, long long int n);
float crrootnf(float x, long long int n);
long double crrootnl(long double x, long long int n);

double crpown(double x, long long int n);
float crpownf(float x, long long int n);
long double crpownl(long double x, long long int n);

double crpow(double x, double y);
float crpowf(float x, float y);
long double crpowl(long double x, long double y);

double crpowr(double y, double x);
float crpowrf(float y, float x);
long double crpowrl(long double y, long double x);

double crsin(double x);
float crsinf(float x);
long double crsinl(long double x);

double crcos(double x);
float crcosf(float x);
long double crcosl(long double x);

double crtan(double x);
float crtanf(float x);
long double crtanl(long double x);

double crsinpi(double x);
float crsinpif(float x);
long double crsinpil(long double x);

double crcospi(double x);
float crcospif(float x);
long double crcospil(long double x);

double crtanpi(double x);
float crtanpif(float x);
long double tanpil(long double x);

double crasinpi(double x);
float crasinpif(float x);
long double crasinpil(long double x);

double cracospi(double x);
float cracospif(float x);
long double cracospil(long double x);

double cratanpi(double x);
float cratanpif(float x);
long double cratanpil(long double x);

double cratan2pi(double y, double x);
float cratan2pif(float y, float x);
long double cratan2pil(long double y, long double x);

double crasin(double x);
float crasinf(float x);
long double crasinl(long double x);

double cracos(double x);
float cracosf(float x);
long double cracosl(long double x);

double cratan(double x);
float cratanf(float x);
long double cratanl(long double x);

double cratan2(double y, double x);
float cratan2f(float y, float x);
long double cratan2l(long double y, long double x);

double crsinh(double x);
float crsinhf(float x);
long double crsinhl(long double x);

double crcosh(double x);
float crcoshf(float x);
long double crcoshl(long double x);

double crtanh(double x);
float crtanhf(float x);
long double crtanhl(long double x);


double crasinh(double x);
float crasinhf(float x);
long double crasinhl(long double x);

double cracosh(double x);
float cracoshf(float x);
long double cracoshl(long double x);

double cratanh(double x);
float cratanhf(float x);
long double cratanhl(long double x);

#if defined(__STDC_IEC_60559_BFP__)

// _FloatN

_Float16 crexpf16(_Float16 x);
_Float32 crexpf32(_Float32 x);
_Float64 crexpf64(_Float64 x);
_Float128 crexpf128(_Float128 x);

_Float16 crexpm1f16(_Float16 x);
_Float32 crexpm1f32(_Float32 x);
_Float64 crexpm1f64(_Float64 x);
_Float128 crexpm1f128(_Float128 x);

_Float16 crexp2f16(_Float16 x);
_Float32 crexp2f32(_Float32 x);
_Float64 crexp2f64(_Float64 x);
_Float128 crexp2f128(_Float128 x);

_Float16 crexp2m1f16(_Float16 x);
_Float32 crexp2m1f32(_Float32 x);
_Float64 crexp2m1f64(_Float64 x);
_Float128 crexp2m1f128(_Float128 x);

_Float16 crexp10f16(_Float16 x);
_Float32 crexp10f32(_Float32 x);
_Float64 crexp10f64(_Float64 x);
_Float128 crexp10f128(_Float128 x);

_Float16 crexp10m1f16(_Float16 x);
_Float32 crexp10m1f32(_Float32 x);
_Float64 crexp10m1f64(_Float64 x);
_Float128 crexp10m1f128(_Float128 x);

_Float16 crlogf16(_Float16 x);
_Float32 crlogf32(_Float32 x);
_Float64 crlogf64(_Float64 x);
_Float128 crlogf128(_Float128 x);

_Float16 crlog2f16(_Float16 x);
_Float32 crlog2f32(_Float32 x);
_Float64 crlog2f64(_Float64 x);
_Float128 crlog2f128(_Float128 x);

_Float16 crlog10f16(_Float16 x);
_Float32 crlog10f32(_Float32 x);
_Float64 crlog10f64(_Float64 x);
_Float128 crlog10f128(_Float128 x);

_Float16 crlog1pf16(_Float16 x);
_Float32 crlog1pf32(_Float32 x);
_Float64 crlog1pf64(_Float64 x);
_Float128 crlog1pf128(_Float128 x);

_Float16 crlogp1f16(_Float16 x);
_Float32 crlogp1f32(_Float32 x);
_Float64 crlogp1f64(_Float64 x);
_Float128 crlogp1f128(_Float128 x);

_Float16 crlog2p1f16(_Float16 x);
_Float32 crlogp1f32(_Float32 x);
_Float64 crlogp1f64(_Float64 x);
_Float128 crlogp1f128(_Float128 x);

_Float16 crlog10p1f16(_Float16 x);
_Float32 crlog10p1f32(_Float32 x);
_Float64 crlog10p1f64(_Float64 x);
_Float128 crlog10p1f128(_Float128 x);

_Float16 crhypotf16(_Float16 x, _Float16 y);
_Float32 crhypotf32(_Float32 x, _Float32 y);
_Float64 crhypotf64(_Float64 x, _Float64 y);
_Float128 crhypotf128(_Float128 x, _Float128 y);

_Float16 crrsqrtf16(_Float16 x);
_Float32 crrsqrtf32(_Float32 x);
_Float64 crrsqrtf64(_Float64 x);
_Float128 crrsqrtf128(_Float128 x);

_Float16 crcompoundnf16(_Float16 x, long long int n);
_Float32 crcompoundnf32(_Float32 x, long long int n);
_Float64 crcompoundnf64(_Float64 x, long long int n);
_Float128 crcompoundnf128(_Float128 x, long long int n);

_Float16 crrootnf16(_Float16 x, long long int n);
_Float32 crrootnf32(_Float32 x, long long int n);
_Float64 crrootnf64(_Float64 x, long long int n);
_Float128 crrootnf128(_Float128 x, long long int n);

_Float16 crpownf16(_Float16 x, long long int n);
_Float32 crpownf32(_Float32 x, long long int n);
_Float64 crpownf64(_Float64 x, long long int n);
_Float128 crpownf128(_Float128 x, long long int n);

_Float16 crpowf16(_Float16 x, _Float16 y);
_Float32 crpowf32(_Float32 x, _Float32 y);
_Float64 crpowf64(_Float64 x, _Float64 y);
_Float128 crpowf128(_Float128 x, _Float128 y);

_Float16 crpowrf16(_Float16 y, _Float16 x);
_Float32 crpowrf32(_Float32 y, _Float32 x);
_Float64 crpowrf64(_Float64 y, _Float64 x);
_Float128 crpowrf128(_Float128 y, _Float128 x);

_Float16 crsinf16(_Float16 x);
_Float32 crsinf32(_Float32 x);
_Float64 crsinf64(_Float64 x);
_Float128 crsinf128(_Float128 x);

_Float16 crcosf16(_Float16 x);
_Float32 crcosf32(_Float32 x);
_Float64 crcosf64(_Float64 x);
_Float128 crcosf128(_Float128 x);

_Float16 crtanf16(_Float16 x);
_Float32 crtanf32(_Float32 x);
_Float64 crtanf64(_Float64 x);
_Float128 crtanf128(_Float128 x);

_Float16 crsinpif16(_Float16 x);
_Float32 crsinpif32(_Float32 x);
_Float64 crsinpif64(_Float64 x);
_Float128 crsinpif128(_Float128 x);

_Float16 crcospif16(_Float16 x);
_Float32 crcospif32(_Float32 x);
_Float64 crcospif64(_Float64 x);
_Float128 crcospif128(_Float128 x);

_Float16 crtanpif16(_Float16 x);
_Float32 crtanpif32(_Float32 x);
_Float64 crtanpif64(_Float64 x);
_Float128 crtanpif128(_Float128 x);

_Float16 crasinpif16(_Float16 x);
_Float32 crasinpif32(_Float32 x);
_Float64 crasinpif64(_Float64 x);
_Float128 crasinpif128(_Float128 x);

_Float16 cracospif16(_Float16 x);
_Float32 cracospif32(_Float32 x);
_Float64 cracospif64(_Float64 x);
_Float128 cracospif128(_Float128 x);

_Float16 cratanpif16(_Float16 x);
_Float32 cratanpif32(_Float32 x);
_Float64 cratanpif64(_Float64 x);
_Float128 cratanpif128(_Float128 x);

_Float16 cratan2pif16(_Float16 y, _Float16 x);
_Float32 cratan2pif32(_Float32 y, _Float32 x);
_Float64 cratan2pif64(_Float64 y, _Float64 x);
_Float128 cratan2pif128(_Float128 y, _Float128 x);

_Float16 crasinf16(_Float16 x);
_Float32 crasinf32(_Float32 x);
_Float64 crasinf64(_Float64 x);
_Float128 crasinf128(_Float128 x);

_Float16 cracosf16(_Float16 x);
_Float32 cracosf32(_Float32 x);
_Float64 cracosf64(_Float64 x);
_Float128 cracosf128(_Float128 x);

_Float16 cratanf16(_Float16 x);
_Float32 cratanf32(_Float32 x);
_Float64 cratanf64(_Float64 x);
_Float128 cratanf128(_Float128 x);

_Float16 cratan2f16(_Float16 y, _Float16 x);
_Float32 cratan2f32(_Float32 y, _Float32 x);
_Float64 cratan2f64(_Float64 y, _Float64 x);
_Float128 cratan2f128(_Float128 y, _Float128 x);

_Float16 crsinhf16(_Float16 x);
_Float32 crsinhf32(_Float32 x);
_Float64 crsinhf64(_Float64 x);
_Float128 crsinhf128(_Float128 x);

_Float16 crcoshf16(_Float16 x);
_Float32 crcoshf32(_Float32 x);
_Float64 crcoshf64(_Float64 x);
_Float128 crcoshf128(_Float128 x);

_Float16 crtanhf16(_Float16 x);
_Float32 crtanhf32(_Float32 x);
_Float64 crtanhf64(_Float64 x);
_Float128 crtanhf128(_Float128 x);

_Float16 crasinhf16(_Float16 x);
_Float32 crasinhf32(_Float32 x);
_Float64 crasinhf64(_Float64 x);
_Float128 crasinhf128(_Float128 x);

_Float16 cracoshf16(_Float16 x);
_Float32 cracoshf32(_Float32 x);
_Float64 cracoshf64(_Float64 x);
_Float128 cracoshf128(_Float128 x);

_Float16 cratanhf16(_Float16 x);
_Float32 cratanhf32(_Float32 x);
_Float64 cratanhf64(_Float64 x);
_Float128 cratanhf128(_Float128 x);

// _FloatNx

_Float16x crexpf16x(_Float16x x);
_Float32x crexpf32x(_Float32x x);
_Float64x crexpf64x(_Float64x x);
_Float128x crexpf128x(_Float128x x);

_Float16x crexpm1f16x(_Float16x x);
_Float32x crexpm1f32x(_Float32x x);
_Float64x crexpm1f64x(_Float64x x);
_Float128x crexpm1f128x(_Float128x x);

_Float16x crexp2f16x(_Float16x x);
_Float32x crexp2f32x(_Float32x x);
_Float64x crexp2f64x(_Float64x x);
_Float128x crexp2f128x(_Float128x x);

_Float16x crexp2m1f16x(_Float16x x);
_Float32x crexp2m1f32x(_Float32x x);
_Float64x crexp2m1f64x(_Float64x x);
_Float128x crexp2m1f128x(_Float128x x);

_Float16x crexp10f16x(_Float16x x);
_Float32x crexp10f32x(_Float32x x);
_Float64x crexp10f64x(_Float64x x);
_Float128x crexp10f128x(_Float128x x);

_Float16x crexp10m1f16x(_Float16x x);
_Float32x crexp10m1f32x(_Float32x x);
_Float64x crexp10m1f64x(_Float64x x);
_Float128x crexp10m1f128x(_Float128x x);

_Float16x crlogf16x(_Float16x x);
_Float32x crlogf32x(_Float32x x);
_Float64x crlogf64x(_Float64x x);
_Float128x crlogf128x(_Float128x x);

_Float16x crlog2f16x(_Float16x x);
_Float32x crlog2f32x(_Float32x x);
_Float64x crlog2f64x(_Float64x x);
_Float128x crlog2f128x(_Float128x x);

_Float16x crlog10f16x(_Float16x x);
_Float32x crlog10f32x(_Float32x x);
_Float64x crlog10f64x(_Float64x x);
_Float128x crlog10f128x(_Float128x x);

_Float16x crlog1pf16x(_Float16x x);
_Float32x crlog1pf32x(_Float32x x);
_Float64x crlog1pf64x(_Float64x x);
_Float128x crlog1pf128x(_Float128x x);

_Float16x crlogp1f16x(_Float16x x);
_Float32x crlogp1f32x(_Float32x x);
_Float64x crlogp1f64x(_Float64x x);
_Float128x crlogp1f128x(_Float128x x);

_Float16x crlog2p1f16x(_Float16x x);
_Float32x crlogp1f32x(_Float32x x);
_Float64x crlogp1f64x(_Float64x x);
_Float128x crlogp1f128x(_Float128x x);

_Float16x crlog10p1f16x(_Float16x x);
_Float32x crlog10p1f32x(_Float32x x);
_Float64x crlog10p1f64x(_Float64x x);
_Float128x crlog10p1f128x(_Float128x x);

_Float16x crhypotf16x(_Float16x x, _Float16x y);
_Float32x crhypotf32x(_Float32x x, _Float32x y);
_Float64x crhypotf64x(_Float64x x, _Float64x y);
_Float128x crhypotf128x(_Float128x x, _Float128x y);

_Float16x crrsqrtf16x(_Float16x x);
_Float32x crrsqrtf32x(_Float32x x);
_Float64x crrsqrtf64x(_Float64x x);
_Float128x crrsqrtf128x(_Float128x x);

_Float16x crcompoundnf16x(_Float16x x, long long int n);
_Float32x crcompoundnf32x(_Float32x x, long long int n);
_Float64x crcompoundnf64x(_Float64x x, long long int n);
_Float128x crcompoundnf128x(_Float128x x, long long int n);

_Float16x crrootnf16x(_Float16x x, long long int n);
_Float32x crrootnf32x(_Float32x x, long long int n);
_Float64x crrootnf64x(_Float64x x, long long int n);
_Float128x crrootnf128x(_Float128x x, long long int n);

_Float16x crpownf16x(_Float16x x, long long int n);
_Float32x crpownf32x(_Float32x x, long long int n);
_Float64x crpownf64x(_Float64x x, long long int n);
_Float128x crpownf128x(_Float128x x, long long int n);

_Float16x crpowf16x(_Float16x x, _Float16x y);
_Float32x crpowf32x(_Float32x x, _Float32x y);
_Float64x crpowf64x(_Float64x x, _Float64x y);
_Float128x crpowf128x(_Float128x x, _Float128x y);

_Float16x crpowrf16x(_Float16x y, _Float16x x);
_Float32x crpowrf32x(_Float32x y, _Float32x x);
_Float64x crpowrf64x(_Float64x y, _Float64x x);
_Float128x crpowrf128x(_Float128x y, _Float128x x);

_Float16x crsinf16x(_Float16x x);
_Float32x crsinf32x(_Float32x x);
_Float64x crsinf64x(_Float64x x);
_Float128x crsinf128x(_Float128x x);

_Float16x crcosf16x(_Float16x x);
_Float32x crcosf32x(_Float32x x);
_Float64x crcosf64x(_Float64x x);
_Float128x crcosf128x(_Float128x x);

_Float16x crtanf16x(_Float16x x);
_Float32x crtanf32x(_Float32x x);
_Float64x crtanf64x(_Float64x x);
_Float128x crtanf128x(_Float128x x);

_Float16x crsinpif16x(_Float16x x);
_Float32x crsinpif32x(_Float32x x);
_Float64x crsinpif64x(_Float64x x);
_Float128x crsinpif128x(_Float128x x);

_Float16x crcospif16x(_Float16x x);
_Float32x crcospif32x(_Float32x x);
_Float64x crcospif64x(_Float64x x);
_Float128x crcospif128x(_Float128x x);

_Float16x crtanpif16x(_Float16x x);
_Float32x crtanpif32x(_Float32x x);
_Float64x crtanpif64x(_Float64x x);
_Float128x crtanpif128x(_Float128x x);

_Float16x crasinpif16x(_Float16x x);
_Float32x crasinpif32x(_Float32x x);
_Float64x crasinpif64x(_Float64x x);
_Float128x crasinpif128x(_Float128x x);

_Float16x cracospif16x(_Float16x x);
_Float32x cracospif32x(_Float32x x);
_Float64x cracospif64x(_Float64x x);
_Float128x cracospif128x(_Float128x x);

_Float16x cratanpif16x(_Float16x x);
_Float32x cratanpif32x(_Float32x x);
_Float64x cratanpif64x(_Float64x x);
_Float128x cratanpif128x(_Float128x x);

_Float16x cratan2pif16x(_Float16x y, _Float16x x);
_Float32x cratan2pif32x(_Float32x y, _Float32x x);
_Float64x cratan2pif64x(_Float64x y, _Float64x x);
_Float128x cratan2pif128x(_Float128x y, _Float128x x);

_Float16x crasinf16x(_Float16x x);
_Float32x crasinf32x(_Float32x x);
_Float64x crasinf64x(_Float64x x);
_Float128x crasinf128x(_Float128x x);

_Float16x cracosf16x(_Float16x x);
_Float32x cracosf32x(_Float32x x);
_Float64x cracosf64x(_Float64x x);
_Float128x cracosf128x(_Float128x x);

_Float16x cratanf16x(_Float16x x);
_Float32x cratanf32x(_Float32x x);
_Float64x cratanf64x(_Float64x x);
_Float128x cratanf128x(_Float128x x);

_Float16x cratan2f16x(_Float16x y, _Float16x x);
_Float32x cratan2f32x(_Float32x y, _Float32x x);
_Float64x cratan2f64x(_Float64x y, _Float64x x);
_Float128x cratan2f128x(_Float128x y, _Float128x x);

_Float16x crsinhf16x(_Float16x x);
_Float32x crsinhf32x(_Float32x x);
_Float64x crsinhf64x(_Float64x x);
_Float128x crsinhf128x(_Float128x x);

_Float16x crcoshf16x(_Float16x x);
_Float32x crcoshf32x(_Float32x x);
_Float64x crcoshf64x(_Float64x x);
_Float128x crcoshf128x(_Float128x x);

_Float16x crtanhf16x(_Float16x x);
_Float32x crtanhf32x(_Float32x x);
_Float64x crtanhf64x(_Float64x x);
_Float128x crtanhf128x(_Float128x x);

_Float16x crasinhf16x(_Float16x x);
_Float32x crasinhf32x(_Float32x x);
_Float64x crasinhf64x(_Float64x x);
_Float128x crasinhf128x(_Float128x x);

_Float16x cracoshf16x(_Float16x x);
_Float32x cracoshf32x(_Float32x x);
_Float64x cracoshf64x(_Float64x x);
_Float128x cracoshf128x(_Float128x x);

_Float16x cratanhf16x(_Float16x x);
_Float32x cratanhf32x(_Float32x x);
_Float64x cratanhf64x(_Float64x x);
_Float128x cratanhf128x(_Float128x x);

#endif // end __STDC_IEC_60559_BFP__


#if defined(__STDC_IEC_60559_DFP__)

// _DecimalN

_Decimal32 crexpd32(_Decimal32 x);
_Decimal64 crexpd64(_Decimal64 x);
_Decimal128 crexpd128(_Decimal128 x);

_Decimal32 crexpm1d32(_Decimal32 x);
_Decimal64 crexpm1d64(_Decimal64 x);
_Decimal128 crexpm1d128(_Decimal128 x);

_Decimal32 crexp2d32(_Decimal32 x);
_Decimal64 crexp2d64(_Decimal64 x);
_Decimal128 crexp2d128(_Decimal128 x);

_Decimal32 crexp2m1d32(_Decimal32 x);
_Decimal64 crexp2m1d64(_Decimal64 x);
_Decimal128 crexp2m1d128(_Decimal128 x);

_Decimal32 crexp10d32(_Decimal32 x);
_Decimal64 crexp10d64(_Decimal64 x);
_Decimal128 crexp10d128(_Decimal128 x);

_Decimal32 crexp10m1d32(_Decimal32 x);
_Decimal64 crexp10m1d64(_Decimal64 x);
_Decimal128 crexp10m1d128(_Decimal128 x);

_Decimal32 crlogd32(_Decimal32 x);
_Decimal64 crlogd64(_Decimal64 x);
_Decimal128 crlogd128(_Decimal128 x);

_Decimal32 crlog2d32(_Decimal32 x);
_Decimal64 crlog2d64(_Decimal64 x);
_Decimal128 crlog2d128(_Decimal128 x);

_Decimal32 crlog10d32(_Decimal32 x);
_Decimal64 crlog10d64(_Decimal64 x);
_Decimal128 crlog10d128(_Decimal128 x);

_Decimal32 crlog1pd32(_Decimal32 x);
_Decimal64 crlog1pd64(_Decimal64 x);
_Decimal128 crlog1pd128(_Decimal128 x);

_Decimal32 crlogp1d32(_Decimal32 x);
_Decimal64 crlogp1d64(_Decimal64 x);
_Decimal128 crlogp1d128(_Decimal128 x);

_Decimal32 crlogp1d32(_Decimal32 x);
_Decimal64 crlogp1d64(_Decimal64 x);
_Decimal128 crlogp1d128(_Decimal128 x);

_Decimal32 crlog10p1d32(_Decimal32 x);
_Decimal64 crlog10p1d64(_Decimal64 x);
_Decimal128 crlog10p1d128(_Decimal128 x);

_Decimal32 crhypotd32(_Decimal32 x, _Decimal32 y);
_Decimal64 crhypotd64(_Decimal64 x, _Decimal64 y);
_Decimal128 crhypotd128(_Decimal128 x, _Decimal128 y);

_Decimal32 crrsqrtd32(_Decimal32 x);
_Decimal64 crrsqrtd64(_Decimal64 x);
_Decimal128 crrsqrtd128(_Decimal128 x);

_Decimal32 crcompoundnd32(_Decimal32 x, long long int n);
_Decimal64 crcompoundnd64(_Decimal64 x, long long int n);
_Decimal128 crcompoundnd128(_Decimal128 x, long long int n);

_Decimal32 crrootnd32(_Decimal32 x, long long int n);
_Decimal64 crrootnd64(_Decimal64 x, long long int n);
_Decimal128 crrootnd128(_Decimal128 x, long long int n);

_Decimal32 crpownd32(_Decimal32 x, long long int n);
_Decimal64 crpownd64(_Decimal64 x, long long int n);
_Decimal128 crpownd128(_Decimal128 x, long long int n);

_Decimal32 crpowd32(_Decimal32 x, _Decimal32 y);
_Decimal64 crpowd64(_Decimal64 x, _Decimal64 y);
_Decimal128 crpowd128(_Decimal128 x, _Decimal128 y);

_Decimal32 crpowrd32(_Decimal32 y, _Decimal32 x);
_Decimal64 crpowrd64(_Decimal64 y, _Decimal64 x);
_Decimal128 crpowrd128(_Decimal128 y, _Decimal128 x);

_Decimal32 crsind32(_Decimal32 x);
_Decimal64 crsind64(_Decimal64 x);
_Decimal128 crsind128(_Decimal128 x);

_Decimal32 crcosd32(_Decimal32 x);
_Decimal64 crcosd64(_Decimal64 x);
_Decimal128 crcosd128(_Decimal128 x);

_Decimal32 crtand32(_Decimal32 x);
_Decimal64 crtand64(_Decimal64 x);
_Decimal128 crtand128(_Decimal128 x);

_Decimal32 crsinpid32(_Decimal32 x);
_Decimal64 crsinpid64(_Decimal64 x);
_Decimal128 crsinpid128(_Decimal128 x);

_Decimal32 crcospid32(_Decimal32 x);
_Decimal64 crcospid64(_Decimal64 x);
_Decimal128 crcospid128(_Decimal128 x);

_Decimal32 crtanpid32(_Decimal32 x);
_Decimal64 crtanpid64(_Decimal64 x);
_Decimal128 crtanpid128(_Decimal128 x);

_Decimal32 crasinpid32(_Decimal32 x);
_Decimal64 crasinpid64(_Decimal64 x);
_Decimal128 crasinpid128(_Decimal128 x);

_Decimal32 cracospid32(_Decimal32 x);
_Decimal64 cracospid64(_Decimal64 x);
_Decimal128 cracospid128(_Decimal128 x);

_Decimal32 cratanpid32(_Decimal32 x);
_Decimal64 cratanpid64(_Decimal64 x);
_Decimal128 cratanpid128(_Decimal128 x);

_Decimal32 cratan2pid32(_Decimal32 y, _Decimal32 x);
_Decimal64 cratan2pid64(_Decimal64 y, _Decimal64 x);
_Decimal128 cratan2pid128(_Decimal128 y, _Decimal128 x);

_Decimal32 crasind32(_Decimal32 x);
_Decimal64 crasind64(_Decimal64 x);
_Decimal128 crasind128(_Decimal128 x);

_Decimal32 cracosd32(_Decimal32 x);
_Decimal64 cracosd64(_Decimal64 x);
_Decimal128 cracosd128(_Decimal128 x);

_Decimal32 cratand32(_Decimal32 x);
_Decimal64 cratand64(_Decimal64 x);
_Decimal128 cratand128(_Decimal128 x);

_Decimal32 cratan2d32(_Decimal32 y, _Decimal32 x);
_Decimal64 cratan2d64(_Decimal64 y, _Decimal64 x);
_Decimal128 cratan2d128(_Decimal128 y, _Decimal128 x);

_Decimal32 crsinhd32(_Decimal32 x);
_Decimal64 crsinhd64(_Decimal64 x);
_Decimal128 crsinhd128(_Decimal128 x);

_Decimal32 crcoshd32(_Decimal32 x);
_Decimal64 crcoshd64(_Decimal64 x);
_Decimal128 crcoshd128(_Decimal128 x);

_Decimal32 crtanhd32(_Decimal32 x);
_Decimal64 crtanhd64(_Decimal64 x);
_Decimal128 crtanhd128(_Decimal128 x);

_Decimal32 crasinhd32(_Decimal32 x);
_Decimal64 crasinhd64(_Decimal64 x);
_Decimal128 crasinhd128(_Decimal128 x);

_Decimal32 cracoshd32(_Decimal32 x);
_Decimal64 cracoshd64(_Decimal64 x);
_Decimal128 cracoshd128(_Decimal128 x);

_Decimal32 cratanhd32(_Decimal32 x);
_Decimal64 cratanhd64(_Decimal64 x);
_Decimal128 cratanhd128(_Decimal128 x);

// _DecimalNx

_Decimal32x crexpd32x(_Decimal32x x);
_Decimal64x crexpd64x(_Decimal64x x);
_Decimal128x crexpd128x(_Decimal128x x);

_Decimal32x crexpm1d32x(_Decimal32x x);
_Decimal64x crexpm1d64x(_Decimal64x x);
_Decimal128x crexpm1d128x(_Decimal128x x);

_Decimal32x crexp2d32x(_Decimal32x x);
_Decimal64x crexp2d64x(_Decimal64x x);
_Decimal128x crexp2d128x(_Decimal128x x);

_Decimal32x crexp2m1d32x(_Decimal32x x);
_Decimal64x crexp2m1d64x(_Decimal64x x);
_Decimal128x crexp2m1d128x(_Decimal128x x);

_Decimal32x crexp10d32x(_Decimal32x x);
_Decimal64x crexp10d64x(_Decimal64x x);
_Decimal128x crexp10d128x(_Decimal128x x);

_Decimal32x crexp10m1d32x(_Decimal32x x);
_Decimal64x crexp10m1d64x(_Decimal64x x);
_Decimal128x crexp10m1d128x(_Decimal128x x);

_Decimal32x crlogd32x(_Decimal32x x);
_Decimal64x crlogd64x(_Decimal64x x);
_Decimal128x crlogd128x(_Decimal128x x);

_Decimal32x crlog2d32x(_Decimal32x x);
_Decimal64x crlog2d64x(_Decimal64x x);
_Decimal128x crlog2d128x(_Decimal128x x);

_Decimal32x crlog10d32x(_Decimal32x x);
_Decimal64x crlog10d64x(_Decimal64x x);
_Decimal128x crlog10d128x(_Decimal128x x);

_Decimal32x crlog1pd32x(_Decimal32x x);
_Decimal64x crlog1pd64x(_Decimal64x x);
_Decimal128x crlog1pd128x(_Decimal128x x);

_Decimal32x crlogp1d32x(_Decimal32x x);
_Decimal64x crlogp1d64x(_Decimal64x x);
_Decimal128x crlogp1d128x(_Decimal128x x);

_Decimal32x crlogp1d32x(_Decimal32x x);
_Decimal64x crlogp1d64x(_Decimal64x x);
_Decimal128x crlogp1d128x(_Decimal128x x);

_Decimal32x crlog10p1d32x(_Decimal32x x);
_Decimal64x crlog10p1d64x(_Decimal64x x);
_Decimal128x crlog10p1d128x(_Decimal128x x);

_Decimal32x crhypotd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x crhypotd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x crhypotd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x crrsqrtd32x(_Decimal32x x);
_Decimal64x crrsqrtd64x(_Decimal64x x);
_Decimal128x crrsqrtd128x(_Decimal128x x);

_Decimal32x crcompoundnd32x(_Decimal32x x, long long int n);
_Decimal64x crcompoundnd64x(_Decimal64x x, long long int n);
_Decimal128x crcompoundnd128x(_Decimal128x x, long long int n);

_Decimal32x crrootnd32x(_Decimal32x x, long long int n);
_Decimal64x crrootnd64x(_Decimal64x x, long long int n);
_Decimal128x crrootnd128x(_Decimal128x x, long long int n);

_Decimal32x crpownd32x(_Decimal32x x, long long int n);
_Decimal64x crpownd64x(_Decimal64x x, long long int n);
_Decimal128x crpownd128x(_Decimal128x x, long long int n);

_Decimal32x crpowd32x(_Decimal32x x, _Decimal32x y);
_Decimal64x crpowd64x(_Decimal64x x, _Decimal64x y);
_Decimal128x crpowd128x(_Decimal128x x, _Decimal128x y);

_Decimal32x crpowrd32x(_Decimal32x y, _Decimal32x x);
_Decimal64x crpowrd64x(_Decimal64x y, _Decimal64x x);
_Decimal128x crpowrd128x(_Decimal128x y, _Decimal128x x);

_Decimal32x crsind32x(_Decimal32x x);
_Decimal64x crsind64x(_Decimal64x x);
_Decimal128x crsind128x(_Decimal128x x);

_Decimal32x crcosd32x(_Decimal32x x);
_Decimal64x crcosd64x(_Decimal64x x);
_Decimal128x crcosd128x(_Decimal128x x);

_Decimal32x crtand32x(_Decimal32x x);
_Decimal64x crtand64x(_Decimal64x x);
_Decimal128x crtand128x(_Decimal128x x);

_Decimal32x crsinpid32x(_Decimal32x x);
_Decimal64x crsinpid64x(_Decimal64x x);
_Decimal128x crsinpid128x(_Decimal128x x);

_Decimal32x crcospid32x(_Decimal32x x);
_Decimal64x crcospid64x(_Decimal64x x);
_Decimal128x crcospid128x(_Decimal128x x);

_Decimal32x crtanpid32x(_Decimal32x x);
_Decimal64x crtanpid64x(_Decimal64x x);
_Decimal128x crtanpid128x(_Decimal128x x);

_Decimal32x crasinpid32x(_Decimal32x x);
_Decimal64x crasinpid64x(_Decimal64x x);
_Decimal128x crasinpid128x(_Decimal128x x);

_Decimal32x cracospid32x(_Decimal32x x);
_Decimal64x cracospid64x(_Decimal64x x);
_Decimal128x cracospid128x(_Decimal128x x);

_Decimal32x cratanpid32x(_Decimal32x x);
_Decimal64x cratanpid64x(_Decimal64x x);
_Decimal128x cratanpid128x(_Decimal128x x);

_Decimal32x cratan2pid32x(_Decimal32x y, _Decimal32x x);
_Decimal64x cratan2pid64x(_Decimal64x y, _Decimal64x x);
_Decimal128x cratan2pid128x(_Decimal128x y, _Decimal128x x);

_Decimal32x crasind32x(_Decimal32x x);
_Decimal64x crasind64x(_Decimal64x x);
_Decimal128x crasind128x(_Decimal128x x);

_Decimal32x cracosd32x(_Decimal32x x);
_Decimal64x cracosd64x(_Decimal64x x);
_Decimal128x cracosd128x(_Decimal128x x);

_Decimal32x cratand32x(_Decimal32x x);
_Decimal64x cratand64x(_Decimal64x x);
_Decimal128x cratand128x(_Decimal128x x);

_Decimal32x cratan2d32x(_Decimal32x y, _Decimal32x x);
_Decimal64x cratan2d64x(_Decimal64x y, _Decimal64x x);
_Decimal128x cratan2d128x(_Decimal128x y, _Decimal128x x);

_Decimal32x crsinhd32x(_Decimal32x x);
_Decimal64x crsinhd64x(_Decimal64x x);
_Decimal128x crsinhd128x(_Decimal128x x);

_Decimal32x crcoshd32x(_Decimal32x x);
_Decimal64x crcoshd64x(_Decimal64x x);
_Decimal128x crcoshd128x(_Decimal128x x);

_Decimal32x crtanhd32x(_Decimal32x x);
_Decimal64x crtanhd64x(_Decimal64x x);
_Decimal128x crtanhd128x(_Decimal128x x);

_Decimal32x crasinhd32x(_Decimal32x x);
_Decimal64x crasinhd64x(_Decimal64x x);
_Decimal128x crasinhd128x(_Decimal128x x);

_Decimal32x cracoshd32x(_Decimal32x x);
_Decimal64x cracoshd64x(_Decimal64x x);
_Decimal128x cracoshd128x(_Decimal128x x);

_Decimal32x cratanhd32x(_Decimal32x x);
_Decimal64x cratanhd64x(_Decimal64x x);
_Decimal128x cratanhd128x(_Decimal128x x);

#endif // end __STDC_IEC_60559_DFP__
#endif  // end __STDC_IEC_60559_FUNCS__
*/
// ISO/IEC 24747 (Extensions to the C Library, to Support Mathematical Special Functions)に規定の関数
// assoc_laguerre functions
double assoc_laguerre(unsigned n, unsigned m, double x);
float assoc_laguerref(unsigned n, unsigned m, float x);
long double assoc_laguerrel(unsigned n, unsigned m, long double x);

// assoc_legendre functions
double assoc_legendre(unsigned l, unsigned m, double x);
float assoc_legendref(unsigned l, unsigned m, float x);
long double assoc_legendrel(unsigned l, unsigned m, long double x);

// beta functions
double beta(double x, double y);
float betaf(float x, float y);
long double betal(long double x, long double y);

// comp_ellint_1 functions
double comp_ellint_1(double k);
float comp_ellint_1f(float k);
long double comp_ellint_1l(long double k);

// comp_ellint_2 functions
double comp_ellint_2(double k);
float comp_ellint_2f(float k);
long double comp_ellint_2l(long double k);

// comp_ellint_3 functions
double comp_ellint_3(double k, double nu);
float comp_ellint_3f(float k, float nu);
long double comp_ellint_3l(long double k, long double nu);

// cyl_bessel_i functions
double cyl_bessel_i(double nu, double x);
float cyl_bessel_if(float nu, float x);
long double cyl_bessel_il(long double nu, long double x);

// cyl_bessel_j functions
double cyl_bessel_j(double nu, double x);
float cyl_bessel_jf(float nu, float x);
long double cyl_bessel_jl(long double nu, long double x);

// cyl_bessel_k functions
double cyl_bessel_k(double nu, double x);
float cyl_bessel_kf(float nu, float x);
long double cyl_bessel_kl(long double nu, long double x);

// cyl_neumann functions
double cyl_neumann(double nu, double x);
float cyl_neumannf(float nu, float x);
long double cyl_neumannl(long double nu, long double x);

// ellint_1 functions
double ellint_1(double k, double phi);
float ellint_1f(float k, float phi);
long double ellint_1l(long double k, long double phi);

// ellint_2 functions
double ellint_2(double k, double phi);
float ellint_2f(float k, float phi);
long double ellint_2l(long double k, long double phi);

// ellint_3 functions
double ellint_3(double k, double nu, double phi);
float ellint_3f(float k, float nu, float phi);
long double ellint_3l(long double k, long double nu, long double phi);

// expint functions
double expint(double x);
float expintf(float x);
long double expintl(long double x);

// hermite functions
double hermite(unsigned n, double x);
float hermitef(unsigned n, float x);
long double hermitel(unsigned n, long double x);

// laguerre functions
double laguerre(unsigned n, double x);
float laguerref(unsigned n, float x);
long double laguerrel(unsigned n, long double x);

// legendre functions
double legendre(unsigned l, double x);
float legendref(unsigned l, float x);
long double legendrel(unsigned l, long double x);

// riemann_zeta functions
double riemann_zeta(double);
float riemann_zetaf(float);
long double riemann_zetal(long double);

// sph_bessel functions
double sph_bessel(unsigned n, double x);
float sph_besself(unsigned n, float x);
long double sph_bessell(unsigned n, long double x);

// sph_legendre functions
double sph_legendre(unsigned l, unsigned m, double theta);
float sph_legendref(unsigned l, unsigned m, float theta);
long double sph_legendrel(unsigned l, unsigned m, long double theta);

// sph_neumann functions
double sph_neumann(unsigned n, double x);
float sph_neumannf(unsigned n, float x);
long double sph_neumannl(unsigned n, long double x);

#endif // end MATH_H