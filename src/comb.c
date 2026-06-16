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
original code is CC0
https://github.com/okumuralab/algo-c
*/
unsigned long comb(const unsigned int n, unsigned int r)
{
    typeof(unsigned long[17]) a;

    if (n - r < r)  r = n - r;
    
    if (r == 0)          return 1;
    else if (r == 1)     return n;
    else if (r > 17)     return 0; // error
    
    for (auto i = 1u; i < r; i++) 
        a[i] = i + 2;
    
    for (auto i = 3u; i <= n - r + 1; i++)
    {
        a[0] = i;
        for (auto j = 1u; j < r; j++) 
            a[j] += a[j - 1];
    }
    return a[r - 1];
}