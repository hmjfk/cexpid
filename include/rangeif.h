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
#ifndef RANGEIF
#define RANGEIF
/**
 @brief 範囲指定できるswitch文を書きやすくする関数
 @param cmpval 比較対象の整数値。
 @param qty 比較条件の個数。
 @param condi 比較条件の一覧。各値は小さい順に範囲の区間となる数値。
 @return
 cmpval以上で該当するcondiの要素番号。cmpvalがcondi[0]の値未満の場合、-1を返す。
*/

// 比較条件cmpmode指定用。
enum {less, under, more};

int range_if [[reproducible]](const int cmpval,unsigned int qty,const int* condi, const unsigned char cmpmode);

#endif // end rangeif header