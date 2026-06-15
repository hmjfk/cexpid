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
#if !defined(FENV_H) && defined(__STDC_IEC_60559_DFP__)
#define FENV_H
#include <fenv.h>

// #define FE_SNANS_ALWAYS_SIGNAL 1
int fe_dec_getround(void);
int fe_dec_setround(int rnd);

#endif // end FENV_H
