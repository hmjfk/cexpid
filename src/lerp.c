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
/// source: https://raw.githubusercontent.com/llvm/llvm-project/refs/heads/main/libcxx/include/cmath

double lerp(double a, double b, double t) [[unsequenced]]
{
    if ((a <= 0 && b >= 0) || (a >= 0 && b <= 0))
        return t * b + (1 - t) * a;

    if (t == 1)
        return b;

    auto x = a + t * (b - a);
    if ((t > 1) == (b > a))
        return b < x ? x : b;
    else
        return x < b ? x : b;
}