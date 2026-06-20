#   cexpid - POSIX指向のC言語汎用部品集
#   Copyright (C) 2025 - Denkousi
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.

CC=gcc
DC=dmd
CFLAGS=-std=c2y
DFLAGS=-betterC -preview=dip1021 -w -O -release -inline -boundscheck=off
INCDIR=-I../include
OFLAGS=-flto -O2
WFLAGS=-pedantic-errors -fanalyzer -Werror -Wall -Wextra -Wconversion -Wno-error=sign-conversion -Wformat=2 -Wpacked -Wshadow -Wundef -Wunsafe-loop-optimizations -Wuseless-cast -Wzero-as-null-pointer-constant -Wswitch-default -Wpadded -Wno-error=padded -Wdouble-promotion -Wno-error=cpp -Wno-error=double-promotion -Wswitch-enum -Wno-error=switch-enum -Wjump-misses-init -Wc++-compat -Wstrict-prototypes

DSRC=

all: compile lib

compile:
	$(CC) -c *.c $(INCDIR) $(CFLAGS) $(WFLAGS) $(OFLAGS) && $(DC) -c $(DSRC) $(DFLAGS)

lib:
	ar r libcexpid.a *.o

install:

clean:
	rm *.o *.a