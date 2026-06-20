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
module cexpid.macros;

/// 総称型関数からCの関数を自動生成するmixin
mixin template cFuncGen(alias funcname, T)
{
private:
    static if(is(T == float))
    {  const prefix = 'f';  }
    else static if(is(T ==  real))
    {  const prefix = 'd';  }
    else static if(is(T ==  double))
    {  const prefix = ' ';  }
    else
        static assert(false, "error: T is not floting point");


public:
    mixin(prefix ~ __traits(identifier, funcname) ~ );
}