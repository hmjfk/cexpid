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
#if !defined(STDLIB_H)
#define STDLIB_H
#include <stdlib.h>

#if defined(__STDC_WANT_IEC_60559_TYPES_EXT__)
#if defined(__STDC_IEC_60559_BFP__)

// note : AI auto genereted code
int strfromf16(char* restrict s, size_t n, const char* restrict format, _Float16 fp);
int strfromf32(char* restrict s, size_t n, const char* restrict format, _Float32 fp);
int strfromf64(char* restrict s, size_t n, const char* restrict format, _Float64 fp);
int strfromf128(char* restrict s, size_t n, const char* restrict format, _Float128 fp);
_Float16 strtof16(const char* restrict nptr, char** restrict endptr);
_Float32 strtof32(const char* restrict nptr, char** restrict endptr);
_Float64 strtof64(const char* restrict nptr, char** restrict endptr);
_Float128 strtof128(const char* restrict nptr, char** restrict endptr);
_Float16 wcstof16(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float32 wcstof32(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float64 wcstof64(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float128 wcstof128(const wchar_t* restrict nptr, wchar_t** restrict endptr);

int strfromf16x(char* restrict s, size_t n, const char* restrict format, _Float16x fp);
int strfromf32x(char* restrict s, size_t n, const char* restrict format, _Float32x fp);
int strfromf64x(char* restrict s, size_t n, const char* restrict format, _Float64x fp);
int strfromf128x(char* restrict s, size_t n, const char* restrict format, _Float128x fp);
_Float16x strtof16x(const char* restrict nptr, char** restrict endptr);
_Float32x strtof32x(const char* restrict nptr, char** restrict endptr);
_Float64x strtof64x(const char* restrict nptr, char** restrict endptr);
_Float128x strtof128x(const char* restrict nptr, char** restrict endptr);
_Float16x wcstof16x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float32x wcstof32x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float64x wcstof64x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Float128x wcstof128x(const wchar_t* restrict nptr, wchar_t** restrict endptr);

#endif // end __STDC_IEC_60559_BFP__
#if define(__STDC_IEC_60559_DFP__)

int strfromd16(char* restrict s, size_t n, const char* restrict format, _Decimal16 fp);
int strfromd32(char* restrict s, size_t n, const char* restrict format, _Decimal32 fp);
int strfromd64(char* restrict s, size_t n, const char* restrict format, _Decimal64 fp);
int strfromd128(char* restrict s, size_t n, const char* restrict format, _Decimal128 fp);
int strfromd16x(char* restrict s, size_t n, const char* restrict format, _Decimal16x fp);
int strfromd32x(char* restrict s, size_t n, const char* restrict format, _Decimal32x fp);
int strfromd64x(char* restrict s, size_t n, const char* restrict format, _Decimal64x fp);
int strfromd128x(char* restrict s, size_t n, const char* restrict format, _Decimal128x fp);

_Decimal16 strtod16(const char* restrict nptr, char** restrict endptr);
_Decimal32 strtod32(const char* restrict nptr, char** restrict endptr);
_Decimal64 strtod64(const char* restrict nptr, char** restrict endptr);
_Decimal128 strtod128(const char* restrict nptr, char** restrict endptr);
_Decimal16x strtod16x(const char* restrict nptr, char** restrict endptr);
_Decimal32x strtod32x(const char* restrict nptr, char** restrict endptr);
_Decimal64x strtod64x(const char* restrict nptr, char** restrict endptr);
_Decimal128x strtod128x(const char* restrict nptr, char** restrict endptr);

_Decimal16 wcstod16(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal32 wcstod32(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal64 wcstod64(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal128 wcstod128(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal16x wcstod16x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal32x wcstod32x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal64x wcstod64x(const wchar_t* restrict nptr, wchar_t** restrict endptr);
_Decimal128x wcstod128x(const wchar_t* restrict nptr, wchar_t** restrict endptr);

#endif // end __STDC_IEC_60559_DFP__

int strfromencf16(  char* restrict s,
                    size_t n,
                    const char* restrict format,
                    const unsigned char encptr[restrict static 16/8]);
int strfromencf32(  char* restrict s,
                    size_t n,
                    const char* restrict format,
                    const unsigned char encptr[restrict static 32/8]);
int strfromencf64(  char* restrict s,
                    size_t n,
                    const char* restrict format,
                    const unsigned char encptr[restrict static 64/8]);
int strfromencf128( char* restrict s,
                    size_t n,
                    const char* restrict format,
                    const unsigned char encptr[restrict static 128/8]);

int strfromencdecd16(   char* restrict s, size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 16/8]);
int strfromencdecd32(   char* restrict s, size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 32/8]);
int strfromencdecd64(   char* restrict s, size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 64/8]);
int strfromencdecd128(  char* restrict s, size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 128/8]);

int strfromencbind16(   char* restrict s,
                        size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 16/8]);
int strfromencbind32(   char* restrict s,
                        size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 32/8]);
int strfromencbind64(   char* restrict s,
                        size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 64/8]);
int strfromencbind128(  char* restrict s,
                        size_t n,
                        const char* restrict format,
                        const unsigned char encptr[restrict static 128/8]);

void strtoencf16(   unsigned char encptr[restrict static 16/8],
                    const char* restrict nptr,
                    char** restrict endptr);
void strtoencf32(   unsigned char encptr[restrict static 32/8],
                    const char* restrict nptr,
                    char** restrict endptr);
void strtoencf64(   unsigned char encptr[restrict static 64/8],
                    const char* restrict nptr,
                    char** restrict endptr);
void strtoencf128(  unsigned char encptr[restrict static 128/8],
                    const char* restrict nptr,
                    char** restrict endptr);
// end genereted code

#endif // end __STDC_WANT_IEC_60559_TYPES_EXT__
#endif // end STDLIB_H