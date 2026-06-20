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
// Original License:
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// source https://raw.githubusercontent.com/llvm/llvm-project/refs/heads/main/libcxx/include/__math/special_functions.h

module cexpid.math.hermite;
import cexpid.macros;


pure:
@live:
@nogc:
nothrow:

T hermite(T)(uint n, T x)
{
    // The Hermite polynomial H_n(x).
    // The implementation is based on the recurrence formula: H_{n+1}(x) = 2x H_n(x) - 2n H_{n-1}.
    // Press, William H., et al. Numerical recipes 3rd edition: The art of scientific computing.
    // Cambridge university press, 2007, p. 183.

    // NOLINTBEGIN(readability-identifier-naming)
    if (isnan(x))
        return x;

    T H_0 = 1;
    if (n == 0)
        return H_0;

    T H_n_prev = H_0;
    T H_n = 2 * x;
    for (auto i = 1u; i < n; ++i)
    {
        T H_n_next = 2 * (x * H_n - i * H_n_prev);
        H_n_prev = H_n;
        H_n = H_n_next;
    }

    if (!isfinite(H_n))
    {
        // Overflow occurred. Two possible cases:
        //    n is odd:  return infinity of the same sign as x.
        //    n is even: return +Inf
        T inf = T.infinity;
        return (n & 1) ? copysign(inf, x) : inf;
    }
    return H_n;
    // NOLINTEND(readability-identifier-naming)
}

extern (C):
mixin cFuncGen!(hermite, float);
mixin cFuncGen!(hermite, double);
mixin cFuncGen!(hermite, real);