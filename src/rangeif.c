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
#include "rangeif.h"

int range_if [[reproducible]](const int cmpval,unsigned int qty,const int* condi, const unsigned char cmpmode)
{
  switch(cmpmode)
  {
    // 以上
    case more:
        if(cmpval < condi[0])
        {
            return -1;
        }
        while (cmpval < condi[--qty]){}

        break;
    // 以下
    case under:
        for(auto i = 0u; i < qty; i++)
        {
            if (cmpval <= condi[i])
            {
                qty = i;
            }
        }
    break;
    // 未満
    case less:
        for(auto i = 0u; i < qty; i++)
        {
            if (cmpval < condi[i])
            {
                qty = i;
            }
        }
        break;
    default:
        return -2;
  }
  return qty;
}