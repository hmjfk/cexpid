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
#if !defined(COMPLEX_H)
#define COMPLEX_H
#include <complex.h>

// 附属書H (ISO/IEC 60559 interchange and extended types)に規定の関数群
#if defined (__STDC_IEC_60559_TYPES__) && defined (__STDC_WANT_IEC_60559_TYPES_EXT__)

// note : AI auto genereted code
_Float16 _Complex cacosf16(_Float16 _Complex z);
_Float16x _Complex cacosf16x(_Float16x _Complex z);
_Float32 _Complex cacosf32(_Float32 _Complex z);
_Float32x _Complex cacosf32x(_Float32x _Complex z);
_Float64 _Complex cacosf64(_Float64 _Complex z);
_Float64x _Complex cacosf64x(_Float64x _Complex z);
_Float128 _Complex cacosf128(_Float128 _Complex z);
_Float128x _Complex cacosf128x(_Float128x _Complex z);

_Float16 _Complex casinf16(_Float16 _Complex z);
_Float16x _Complex casinf16x(_Float16x _Complex z);
_Float32 _Complex casinf32(_Float32 _Complex z);
_Float32x _Complex casinf32x(_Float32x _Complex z);
_Float64 _Complex casinf64(_Float64 _Complex z);
_Float64x _Complex casinf64x(_Float64x _Complex z);
_Float128 _Complex casinf128(_Float128 _Complex z);
_Float128x _Complex casinf128x(_Float128x _Complex z);

_Float16 _Complex catanf16(_Float16 _Complex z);
_Float16x _Complex catanf16x(_Float16x _Complex z);
_Float32 _Complex catanf32(_Float32 _Complex z);
_Float32x _Complex catanf32x(_Float32x _Complex z);
_Float64 _Complex catanf64(_Float64 _Complex z);
_Float64x _Complex catanf64x(_Float64x _Complex z);
_Float128 _Complex catanf128(_Float128 _Complex z);
_Float128x _Complex catanf128x(_Float128x _Complex z);

_Float16 _Complex ccosf16(_Float16 _Complex z);
_Float16x _Complex ccosf16x(_Float16x _Complex z);
_Float32 _Complex ccosf32(_Float32 _Complex z);
_Float32x _Complex ccosf32x(_Float32x _Complex z);
_Float64 _Complex ccosf64(_Float64 _Complex z);
_Float64x _Complex ccosf64x(_Float64x _Complex z);
_Float128 _Complex ccosf128(_Float128 _Complex z);
_Float128x _Complex ccosf128x(_Float128x _Complex z);

_Float16 _Complex csinf16(_Float16 _Complex z);
_Float16x _Complex csinf16x(_Float16x _Complex z);
_Float32 _Complex csinf32(_Float32 _Complex z);
_Float32x _Complex csinf32x(_Float32x _Complex z);
_Float64 _Complex csinf64(_Float64 _Complex z);
_Float64x _Complex csinf64x(_Float64x _Complex z);
_Float128 _Complex csinf128(_Float128 _Complex z);
_Float128x _Complex csinf128x(_Float128x _Complex z);

_Float16 _Complex ctanf16(_Float16 _Complex z);
_Float16x _Complex ctanf16x(_Float16x _Complex z);
_Float32 _Complex ctanf32(_Float32 _Complex z);
_Float32x _Complex ctanf32x(_Float32x _Complex z);
_Float64 _Complex ctanf64(_Float64 _Complex z);
_Float64x _Complex ctanf64x(_Float64x _Complex z);
_Float128 _Complex ctanf128(_Float128 _Complex z);
_Float128x _Complex ctanf128x(_Float128x _Complex z);

_Float16 _Complex cacoshf16(_Float16 _Complex z);
_Float16x _Complex cacoshf16x(_Float16x _Complex z);
_Float32 _Complex cacoshf32(_Float32 _Complex z);
_Float32x _Complex cacoshf32x(_Float32x _Complex z);
_Float64 _Complex cacoshf64(_Float64 _Complex z);
_Float64x _Complex cacoshf64x(_Float64x _Complex z);
_Float128 _Complex cacoshf128(_Float128 _Complex z);
_Float128x _Complex cacoshf128x(_Float128x _Complex z);

_Float16 _Complex casinhf16(_Float16 _Complex z);
_Float16x _Complex casinhf16x(_Float16x _Complex z);
_Float32 _Complex casinhf32(_Float32 _Complex z);
_Float32x _Complex casinhf32x(_Float32x _Complex z);
_Float64 _Complex casinhf64(_Float64 _Complex z);
_Float64x _Complex casinhf64x(_Float64x _Complex z);
_Float128 _Complex casinhf128(_Float128 _Complex z);
_Float128x _Complex casinhf128x(_Float128x _Complex z);

_Float16 _Complex catanhf16(_Float16 _Complex z);
_Float16x _Complex catanhf16x(_Float16x _Complex z);
_Float32 _Complex catanhf32(_Float32 _Complex z);
_Float32x _Complex catanhf32x(_Float32x _Complex z);
_Float64 _Complex catanhf64(_Float64 _Complex z);
_Float64x _Complex catanhf64x(_Float64x _Complex z);
_Float128 _Complex catanhf128(_Float128 _Complex z);
_Float128x _Complex catanhf128x(_Float128x _Complex z);

_Float16 _Complex ccoshf16(_Float16 _Complex z);
_Float16x _Complex ccoshf16x(_Float16x _Complex z);
_Float32 _Complex ccoshf32(_Float32 _Complex z);
_Float32x _Complex ccoshf32x(_Float32x _Complex z);
_Float64 _Complex ccoshf64(_Float64 _Complex z);
_Float64x _Complex ccoshf64x(_Float64x _Complex z);
_Float128 _Complex ccoshf128(_Float128 _Complex z);
_Float128x _Complex ccoshf128x(_Float128x _Complex z);

_Float16 _Complex csinhf16(_Float16 _Complex z);
_Float16x _Complex csinhf16x(_Float16x _Complex z);
_Float32 _Complex csinhf32(_Float32 _Complex z);
_Float32x _Complex csinhf32x(_Float32x _Complex z);
_Float64 _Complex csinhf64(_Float64 _Complex z);
_Float64x _Complex csinhf64x(_Float64x _Complex z);
_Float128 _Complex csinhf128(_Float128 _Complex z);
_Float128x _Complex csinhf128x(_Float128x _Complex z);

_Float16 _Complex ctanhf16(_Float16 _Complex z);
_Float16x _Complex ctanhf16x(_Float16x _Complex z);
_Float32 _Complex ctanhf32(_Float32 _Complex z);
_Float32x _Complex ctanhf32x(_Float32x _Complex z);
_Float64 _Complex ctanhf64(_Float64 _Complex z);
_Float64x _Complex ctanhf64x(_Float64x _Complex z);
_Float128 _Complex ctanhf128(_Float128 _Complex z);
_Float128x _Complex ctanhf128x(_Float128x _Complex z);

_Float16 _Complex cexpf16(_Float16 _Complex z);
_Float16x _Complex cexpf16x(_Float16x _Complex z);
_Float32 _Complex cexpf32(_Float32 _Complex z);
_Float32x _Complex cexpf32x(_Float32x _Complex z);
_Float64 _Complex cexpf64(_Float64 _Complex z);
_Float64x _Complex cexpf64x(_Float64x _Complex z);
_Float128 _Complex cexpf128(_Float128 _Complex z);
_Float128x _Complex cexpf128x(_Float128x _Complex z);

_Float16 _Complex clogf16(_Float16 _Complex z);
_Float16x _Complex clogf16x(_Float16x _Complex z);
_Float32 _Complex clogf32(_Float32 _Complex z);
_Float32x _Complex clogf32x(_Float32x _Complex z);
_Float64 _Complex clogf64(_Float64 _Complex z);
_Float64x _Complex clogf64x(_Float64x _Complex z);
_Float128 _Complex clogf128(_Float128 _Complex z);
_Float128x _Complex clogf128x(_Float128x _Complex z);

_Float16 cabsf16(_Float16 _Complex z);
_Float16x cabsf16x(_Float16x _Complex z);
_Float32 cabsf32(_Float32 _Complex z);
_Float32x cabsf32x(_Float32x _Complex z);
_Float64 cabsf64(_Float64 _Complex z);
_Float64x cabsf64x(_Float64x _Complex z);
_Float128 cabsf128(_Float128 _Complex z);
_Float128x cabsf128x(_Float128x _Complex z);

_Float16 _Complex cpowf16(_Float16 _Complex x, _Float16 _Complex y);
_Float16x _Complex cpowf16x(_Float16x _Complex x, _Float16x _Complex y);
_Float32 _Complex cpowf32(_Float32 _Complex x, _Float32 _Complex y);
_Float32x _Complex cpowf32x(_Float32x _Complex x, _Float32x _Complex y);
_Float64 _Complex cpowf64(_Float64 _Complex x, _Float64 _Complex y);
_Float64x _Complex cpowf64x(_Float64x _Complex x, _Float64x _Complex y);
_Float128 _Complex cpowf128(_Float128 _Complex x, _Float128 _Complex y);
_Float128x _Complex cpowf128x(_Float128x _Complex x, _Float128x _Complex y);

_Float16 _Complex csqrtf16(_Float16 _Complex z);
_Float16x _Complex csqrtf16x(_Float16x _Complex z);
_Float32 _Complex csqrtf32(_Float32 _Complex z);
_Float32x _Complex csqrtf32x(_Float32x _Complex z);
_Float64 _Complex csqrtf64(_Float64 _Complex z);
_Float64x _Complex csqrtf64x(_Float64x _Complex z);
_Float128 _Complex csqrtf128(_Float128 _Complex z);
_Float128x _Complex csqrtf128x(_Float128x _Complex z);

_Float16 cargf16(_Float16 _Complex z);
_Float16x cargf16x(_Float16x _Complex z);
_Float32 cargf32(_Float32 _Complex z);
_Float32x cargf32x(_Float32x _Complex z);
_Float64 cargf64(_Float64 _Complex z);
_Float64x cargf64x(_Float64x _Complex z);
_Float128 cargf128(_Float128 _Complex z);
_Float128x cargf128x(_Float128x _Complex z);

_Float16 cimagf16(_Float16 _Complex z);
_Float16x cimagf16x(_Float16x _Complex z);
_Float32 cimagf32(_Float32 _Complex z);
_Float32x cimagf32x(_Float32x _Complex z);
_Float64 cimagf64(_Float64 _Complex z);
_Float64x cimagf64x(_Float64x _Complex z);
_Float128 cimagf128(_Float128 _Complex z);
_Float128x cimagf128x(_Float128x _Complex z);

_Float16 _Complex CMPLXF16(_Float16 x, _Float16 y);
_Float16x _Complex CMPLXF16x(_Float16x x, _Float16x y);
_Float32 _Complex CMPLXF32(_Float32 x, _Float32 y);
_Float32x _Complex CMPLXF32x(_Float32x x, _Float32x y);
_Float64 _Complex CMPLXF64(_Float64 x, _Float64 y);
_Float64x _Complex CMPLXF64x(_Float64x x, _Float64x y);
_Float128 _Complex CMPLXF128(_Float128 x, _Float128 y);
_Float128x _Complex CMPLXF128x(_Float128x x, _Float128x y);

_Float16 _Complex conjf16(_Float16 _Complex z);
_Float16x _Complex conjf16x(_Float16x _Complex z);
_Float32 _Complex conjf32(_Float32 _Complex z);
_Float32x _Complex conjf32x(_Float32x _Complex z);
_Float64 _Complex conjf64(_Float64 _Complex z);
_Float64x _Complex conjf64x(_Float64x _Complex z);
_Float128 _Complex conjf128(_Float128 _Complex z);
_Float128x _Complex conjf128x(_Float128x _Complex z);

_Float16 _Complex cprojf16(_Float16 _Complex z);
_Float16x _Complex cprojf16x(_Float16x _Complex z);
_Float32 _Complex cprojf32(_Float32 _Complex z);
_Float32x _Complex cprojf32x(_Float32x _Complex z);
_Float64 _Complex cprojf64(_Float64 _Complex z);
_Float64x _Complex cprojf64x(_Float64x _Complex z);
_Float128 _Complex cprojf128(_Float128 _Complex z);
_Float128x _Complex cprojf128x(_Float128x _Complex z);

_Float16 crealf16(_Float16 _Complex z);
_Float16x crealf16x(_Float16x _Complex z);
_Float32 crealf32(_Float32 _Complex z);
_Float32x crealf32x(_Float32x _Complex z);
_Float64 crealf64(_Float64 _Complex z);
_Float64x crealf64x(_Float64x _Complex z);
_Float128 crealf128(_Float128 _Complex z);
_Float128x crealf128x(_Float128x _Complex z);
// end genereted code

#endif // end __STDC_IEC_60559_TYPES__ && __STDC_WANT_IEC_60559_TYPES_EXT__
/*
ISO/IEC TS 18661-­ 4:2015 に規定の予約された識別子。現在は未実装
https://en.cppreference.com/w/c/experimental/fpext4.html は、実装任意関数と間違えている。
*/
/*
#if defined(__STDC_IEC_60559_FUNCS__)

#endif
*/
#endif // end COMPLEX_H