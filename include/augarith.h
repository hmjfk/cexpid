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
#if !defined (AUGARITH_H)
#define AUGARITH_H

#define __STDC_IEC_60559_FUNCS_AUGMENTED_ARITHMETIC__ 202401L

#if defined(__STDC_IEC_60559_BFP__)

struct daug_t       { double h;      double t;       };
struct faug_t       { float h;       float t;        };
struct ldaug_t      { long double h; long double t;  };

struct _f16aug_t    { _Float16 h;    _Float16 t;     };
struct _f32aug_t    { _Float32 h;    _Float32 t;     };
struct _f64aug_t    { _Float64 h;    _Float64 t;     };
struct _f128aug_t   { _Float128 h;   _Float128 t;    };

struct _f16xaug_t   { _Float16x h;   _Float16x t;    };
struct _f32xaug_t   { _Float32x h;   _Float32x t;    };
struct _f64xaug_t   { _Float64x h;   _Float64x t;    };
struct _f128xaug_t  { _Float128x h;  _Float128x t;   };

// aug_add functions
struct daug_t aug_add(double x, double y);
struct faug_t aug_addf(float x, float y);
struct ldaug_t aug_addl(long double x, long double y);

struct _f16aug_t aug_addf16(_Float16 x, _Float16 y);
struct _f32aug_t aug_addf32(_Float32 x, _Float32 y);
struct _f64aug_t aug_addf64(_Float64 x, _Float64 y);
struct _f128aug_t aug_addf128(_Float128 x, _Float128 y);

struct _f16xaug_t aug_addf16x(_Float16x x, _Float16x y);
struct _f32xaug_t aug_addf32x(_Float32x x, _Float32x y);
struct _f64xaug_t aug_addf64x(_Float64x x, _Float64x y);
struct _f128xaug_t aug_addf128x(_Float128x x, _Float128x y);

// aug_sub functions
struct daug_t aug_sub(double x, double y);
struct faug_t aug_subf(float x, float y);
struct ldaug_t aug_subl(long double x, long double y);

struct _f16aug_t aug_subf16(_Float16 x, _Float16 y);
struct _f32aug_t aug_subf32(_Float32 x, _Float32 y);
struct _f64aug_t aug_subf64(_Float64 x, _Float64 y);
struct _f128aug_t aug_subf128(_Float128 x, _Float128 y);

struct _f16xaug_t aug_subf16x(_Float16x x, _Float16x y);
struct _f32xaug_t aug_subf32x(_Float32x x, _Float32x y);
struct _f64xaug_t aug_subf64x(_Float64x x, _Float64x y);
struct _f128xaug_t aug_subf128x(_Float128x x, _Float128x y);

// aug_mul functions
struct daug_t aug_mul(double x, double y);
struct faug_t aug_mulf(float x, float y);
struct ldaug_t aug_mull(long double x, long double y);

struct _f16aug_t aug_mulf16(_Float16 x, _Float16 y);
struct _f32aug_t aug_mulf32(_Float32 x, _Float32 y);
struct _f64aug_t aug_mulf64(_Float64 x, _Float64 y);
struct _f128aug_t aug_mulf128(_Float128 x, _Float128 y);

struct _f16xaug_t aug_mulf16x(_Float16x x, _Float16x y);
struct _f32xaug_t aug_mulf32x(_Float32x x, _Float32x y);
struct _f64xaug_t aug_mulf64x(_Float64x x, _Float64x y);
struct _f128xaug_t aug_mulf128x(_Float128x x, _Float128x y);

#endif // end  __STDC_IEC_60559_BFP__
#endif // end AUGARITH_H