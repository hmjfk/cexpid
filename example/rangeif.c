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
#include <stdio.h>
#include <rangeif.h>

int main()
{
  int b = 0;

  scanf("%d", &b);
  switch (range_if(b, 3, (const int[3]){-3, 6, 8}), more)
  {
  case 0:
    puts("-5以上");
    break;
  case 1:
    puts("6以上");
    break;
  case 2:
    puts("8以上");
    break;
  default:
    break;
  }
  return 0;
}