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
/*
Original work info
Source: https://cpprefjp.github.io/reference/cmath/lerp.html
License: CC BY 4.0 https://creativecommons.org/licenses/by/4.0/deed.ja
change: 原版からC言語へ翻訳する変更を行った。
*/
#include <extc/math.h>
#include <stdio.h>

int main()
{
    // 開始点0.0から、目標点10.0まで、10% (時間0.1) ずつ値を進める
    auto start = 0.0;
    auto target = 10.0;
    auto t = 0.0;

    for (auto i = 0u; i <= 10; ++i)
        {
            auto r = lerp(start, target, t);
            printf("%g\n", r);
            t += 0.1;
        }
    return 0;
}