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
#if !defined (STDIO_H)
#define STDIO_H
#include <stdio.h>

#define __STDC_ALLOC_LIB__ 200906L

#if defined(__STDC_WANT_LIB_EXT2__)

int asprintf(char** restrict ptr, const char * restrict format,  ...);
int vasprintf(char** restrict ptr, const char * restrict format,  va_list arg);
int aswprintf(wchar_t** restrict ptr, const wchar_t * restrict format,  ...);
int vaswprintf(wchar_t** restrict ptr, const wchar_t * restrict format,  va_list arg);

FILE* fmemopen(void * restrict buf, size_t size,  const char * restrict mode);

FILE* open_memstream(char** restrict bufp, size_t * restrict sizep);
FILE* open_wmemstream(wchar_t** bufp,  size_t * sizep);

ssize_t getdelim(char** restrict lineptr, size_t * restrict n, int delimiter,  FILE * stream);
ssize_t getwdelim(wchar_t** restrict lineptr, size_t * restrict n, wint_t delimiter,  FILE * stream);
ssize_t getline(char** lineptr, size_t * n, FILE * stream);
ssize_t getwline(wchar_t** lineptr, size_t * n, FILE * stream);

#endif // end __STDC_WANT_LIB_EXT2__
#endif // end STDIO_H