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
#if !defined(EXTSTDBIT_H)
#define EXTSTDBIT_H

// このheaderは、C2yの<stdbit.h>に存在しない関数を補足するものである。header only

// 範囲なし操作
/**
 @brief bit列をずらす。この関数は、組み込みのshft演算子の動作が処理系定義となっている問題を解決するものである。
 @param value 対象のbit列
 @param direction ずらす方向、右で、true、左でfalse
 @param mode trueで算術、falseで論理
 @return ずらした後のbit列 
*/
uint8_t bit_shift(uint8_t value , bool direction, bool mode) [[unsequenced]];

/**
 @brief 特定bitの状態を調べる。
 @param value 対象のbit列
 @param bit LSBから数えて、設定するbitの桁数
 @return 指定されたbitの状態 
 */
bool leading_bit(uint8_t value, uint8_t bit) [[unsequenced]];

/** 
 @brief 特定bitに値を設定する。
 @param value 設定対象のbit列
 @param bit LSBから数えて、設定するbitの桁数
 @param flag 設定する値
 @return 設定後の値
*/
uint8_t setting_bit(uint8_t value, uint8_t bit, bool flag) [[unsequenced]];

/** 
 @brief 特定bitの値を反転する。
 @param value 反転対象のbit列
 @param bit LSBから数えて、設定するbitの桁数
 @return 反転後の値
*/
inline uint8_t bit_not(uint8_t value, uint8_t bit) [[unsequenced]];
/**
 @brief bit列を結合する。
 @param a 結合元
 @param b 結合元
 @return 結合後のbit列
 */
uint8_t cat_bits(uint8_t a, uint8_t b) [[unsequenced]];


/** 
 @brief 複数のbitでflagを削除する。これは、Go言語の&^演算子と等価である。
 @param value 設定対象のbit列
 @param bit LSBから数えて、設定するbitの桁数
 @return  a & ~b
*/
inline uint8_t flag_clear(uint8_t a, uint8_t b) [[unsequenced]]
{
    return a & ~b;
}

/** 
 @brief 複数のbitでflagを設定する。Go言語の&^演算子と逆の動作をする。
 @param value 設定対象
 @param bit LSBから数えて、設定するbitの桁数
 @return  a & ~b
*/
inline uint8_t flag_set(uint8_t a, uint8_t b) [[unsequenced]]
{
    return a & b;
}

/*
範囲付き操作
本部品集を使えば、直感的な操作でbit操作が可能となる。これで、かなり面倒だったbitmaskは不要となる。
*/
/*
<stdbit.h>の範囲拡張

これらは、<stdbit.h>の関数群を拡張し、bit範囲を指定して操作できるようにしたものである。
ただし、<stdbit.h>の範囲版として本headerで提供する関数は、関数名の接尾辞stdc_を外し、_rという接尾辞がついたものである。
この際、既存の引数の後ろに`uint8_t lbit, uint8_t ubit`が追加される。

- stdc_leading_zeros
- stdc_leading_ones
- stdc_trailing_zeros
- stdc_trailing_ones
- stdc_first_leading_zero
- stdc_first_leading_one
- stdc_first_trailing_zero
- stdc_count_zeros
- stdc_count_ones
- stdc_has_single_bit
- stdc_bit_floor
- stdc_bit_ceil
- stdc_rotate_left
- stdc_rotate_right
*/

uint8_t leading_zeros_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t leading_ones_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t trailing_zeros_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t trailing_ones_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t first_leading_zero_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t first_leading_one_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t first_trailing_zero_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t count_zeros_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t count_ones_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t has_single_bit_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t bit_floor_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t bit_ceil_r(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];
uint8_t rotate_left_r(uint8_t value, uint8_t count, uint8_t lbit, uint8_t ubit);
uint8_t rotate_right_r(uint8_t value, uint8_t count, uint8_t lbit, uint8_t ubit);


/**
 @brief 範囲内のbit列を切り出す。
 @param value 対象bit列
 @param lbit 切り出し範囲の下限bit
 @param ubit 切り出し範囲の上限bit
 @return 切り出し後のbit列
 */
uint8_t clipping_bits(uint8_t value, uint8_t lbit, uint8_t ubit) [[unsequenced]];

/**
 @brief bit列の途中に割り込んで挿入する。
 @param value 対象bit列
 @param insert_v 挿入元bit列
 @param count  LSBから数えた挿入開始bit
 @return 挿入後のbit列
 */
uint8_t insert_bits(uint8_t value, uint8_t insert_v, uint8_t count) [[unsequenced]];

/**
 @brief bit列を範囲内で上書きする。flagsの桁数と上書き範囲が異なる場合、上書き範囲が優先される。
 @param value 対象bit列。
 @param flags 上書き元bit
 @param lbit  上書き開始bit
 @param ubit  上書き終了bit
 @param flag flagの種類
 @return 上書き後のbit列
 */
uint8_t overwrite_bits(uint8_t value, uint8_t flags, uint8_t lbit, uint8_t ubit) [[unsequenced]];

// bitmask作成
/**
 @brief 全bitが1のbitmaskを作成する。
 @param count bitmaskの桁数
 @return 指定したbitmaskを返す。
 */
inline uint8_t bitmask(uint8_t count)[[reproducible]];
inline uint8_t bitmask(uint8_t count)[[reproducible]]
{
    return (1u << count) - 1u;
}
/**
 @brief 先頭だけが1で、それ以外が0のbitmask(単一bitmask)を作成する。
 @param count bitmaskの桁数
 @return 指定したbitmaskを返す。
 */
inline uint8_t bitmask_single(uint8_t count)[[reproducible]];
inline uint8_t bitmask_single(uint8_t count)[[reproducible]]
{
    return 1u << count;
}

/**
 @brief 偶数bitが1, 奇数bitが0のbitmaskを作成する。
 @param count bitmaskの桁数
 @return 指定したbitmaskを返す。
 */
uint8_t bitmask_even(uint8_t count)[[reproducible]];

/**
 @brief 偶数bitが0, 奇数bitが1のbitmaskを作成する。
 @param count bitmaskの桁数
 @return 指定したbitmaskを返す。
 */
uint8_t bitmask_odd(uint8_t count)[[reproducible]];

/**
 @brief 特定octedがすべて1のbitmaskを作成する。
 @param count LSBから数えたoctedの位置
 @return 指定したbitmaskを返す。
 */
uint8_t bitmask_octed(uint8_t octed)[[reproducible]];
#endif // end EXTMATH_H