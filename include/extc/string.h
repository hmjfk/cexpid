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
#if !defined(EXTSTRING_H)
#define EXTSTRING_H
char* arabic(char* str);
char* asctoKana(char* str);

const char* bathtext(int value);// 戻り値は動的確保された領域

/*
cleanchar関数：配列の終端文字を除く、
文字化けもしくはlocelによって表示できない文字、制御文字を削除する。
*/
char* clean_char(char* str);
char16_t* currency_symbol(float vlaue, unsigned int dp); // DOLLAR関数
float dollerde(float numerator, unsigned int denominator);
const char* encode_url(const char* url);
const char* filter_xml(const char* doc, const char* xml_exp);
char* fixed(float value, unsigned int dp,  bool delimiter);
/*
wcstrtocstr();
left
leftb
lower
mid
midb
numbervalue
proper
replace
replaceb
rept
right
rightb
char* roman(char* str);
rot13
search
searchb
substitute
textjoin
trim
unichar
unicode
upper
*/
char16_t* phonetic(char16_t* str); // for excel
char16_t* numberstr(int value, unsigned int type);// NUMBERSTRING() for excel
#endif // end EXTSTRING_H