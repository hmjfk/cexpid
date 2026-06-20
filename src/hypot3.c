/*
    cexpid - POSIX指向のC言語汎用部品集
    Copyright (C) 1997-2026 Free Software Foundation, Inc.
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
// This function translated libstdc++ std::hypot to C.
// Original Source: https://gcc.gnu.org/cgit/gcc/plain/libstdc++-v3/include/c_global/cmath
#include <math.h>


double hypot3(double x, double y, double z) [[reproducible]]
{
    x = fabs(x);
    y = fabs(y);
    z = fabs(z);

    if (const double a = x < y ? /* true */(y < z ? z : y ) : /* false */(x < z ? z : x))

	    return a * sqrt((x / a) * (x / a) + (y / a) * (y / a) + (z / a) * (z / a));
    else
	    return (constexpr double){};
}