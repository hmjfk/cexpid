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
#if !defined(EXTSTDLIB_H)
#define EXTSTDLIB_H

size_t strmove(char* stro, const char* stri, size_t n);
/*
strmove関数

striからn個の文字列をstroに複製する。
文字列の由来は重複していてもよく、stroには終端文字が挿入されなければならない。
stroとstriのいずれかが文字列を指していない（空指示定数を含む）若しくは
striのn個目の要素に終端文字が含まれていない場合、arrcpy関数を呼び出して複製する。
n個を満たないのにstri若しくはstroが終端文字に達したときは、
その時点で複製を終了し複製が終了した位置を返す。また、 n > SIZE_MAXの場合は複製を行わずにSIZE_MAXを返す。
stroは0で初期化することはなく、この関数をそのままの値になる。

*/

size_t arrcpy(void* stro, size_t n_o, const char* stri, size_t n);
/*
関数

striからn個の配列をintmax型の配列としてstroに複製する。終端文字は考慮されない。要素の由来は重複していてもよい。
stroとstriのどちらかが有効な指示を指さない場合（空指示定数を含む）はSIZE_MAX-1を返し,
n_o > SIZE_MAX か、 n > SIZE_MAX、またはn_o < n の場合は、SIZE_MAXを返す。
stroは0で初期化することはなく、そのままの値になる。stroが持つ実際の要素数とn_oが一致しない場合は、
未定義の動作となる。
*/

int cmdarg(char** argv);
/*
引数
argv - main関数の第二引数に同じ。ただし、指示を介してcommand line引数への指示が渡される。

戻り値
main関数の第一引数に同じ。

機能
command line引数をmain関数の引数に代わって取得し、実装のruntimeを起動する。
これは、独立環境などにおいてruntimeの処理開始点を設けることができない状況のために存在する。
argvがnullptrの場合、command line引数は返されず、戻り値は0となる。
*/

// つぎの４つの関数について、詳しくはlibc_ext.mdを参照のこと。
// 引数が積上・可変領域のどちらを指しているか調べる。
bool alloctype(void* ptr);

// 領域が割り当てられているか調べる。（積上・可変の区別はない）
bool isalloced(void* ptr);

// 実行時に配列の要素数を調べる。
size_t rtlentghof(void* ptr);

// 未定義動作を引き起こすことなく安全に動的配列を開放する。
void strfree_s(void* ptr);

// 未定義動作を引き起こすことなく安全に動的領域を開放する。
void free_s(void* ptr);

// max function
int max(int a, int b)[[reproducible]];

// min function
int min(int a, int b) [[reproducible]];

// swap function
void swap(int* const a, int* const b);

// strtoi function
// strtolの戻り値をint型にした関数
int strtoi(const char * restrict nptr, char ** restrict endptr, int base);

/*
function poiner encrypt/decrypt function
See below: https://www.open-std.org/JTC1/SC22/WG14/www/docs/n1332.pdf
*/
void* encfptr(void* fptr); // from encode_pointer
void* decfptr(void* fptr); // from decode_pointer
#endif // end EXTSTDLIB_H