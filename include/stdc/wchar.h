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
#if !defined(WCHAR_H)
#define WCHAR_H
#include <wchar.h>

#if defined(__STDC_WANT_IEC_60559_TYPES_EXT__)

void wcstoencf32(       unsigned char encptr[restrict static 32/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencf64(       unsigned char encptr[restrict static 64/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencf128(      unsigned char encptr[restrict static 128/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);

void wcstoencdecd32(    unsigned char encptr[restrict static 32/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencdecd64(    unsigned char encptr[restrict static 64/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencdecd128(   unsigned char encptr[restrict static 128/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);

void wcstoencbind32(    unsigned char encptr[restrict static 32/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencbind64(    unsigned char encptr[restrict static 64/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);
void wcstoencbind128(   unsigned char encptr[restrict static 128/8],
                        const wchar_t * restrict nptr,
                        wchar_t ** restrict endptr);

#endif // end __STDC_WANT_IEC_60559_TYPES_EXT__
#endif // end WCHAR_H