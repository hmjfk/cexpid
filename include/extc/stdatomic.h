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
#if !defined(EXTSTDATOMIC_H)
#define EXTSTDATOMIC_H
/**
Summary:
  Check the state without changing atomic_flag.
returns:
  Same as atomic_flag_test_and_set.
*/
bool atmftst(volatile atomic_flag* flag);
#endif // end EXTSTDATOMIC_H
