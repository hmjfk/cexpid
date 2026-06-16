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
/*
original code is CC0
https://github.com/okumuralab/algo-c
*/
#include <math.h>

double riemann_zeta(double x)
{
  constexpr auto n = 8u;
  static constexpr double coef[20] = 
    {
      8.333333333333333333333333333e-2,  /*  1/12 */
      -1.388888888888888888888888889e-3, /* -1/720 */
      3.306878306878306878306878307e-5,  /*  1/30240 */
      -8.267195767195767195767195767e-7, /* -1/1209600 */
      2.087675698786809897921009032e-8,  /*  1/47900160 */
      -5.284190138687493184847682202e-10,
      1.338253653068467883282698098e-11,
      -3.389680296322582866830195391e-13,
      8.586062056277844564135905450e-15,
      -2.174868698558061873041516424e-16,
      5.509002828360229515202652609e-18,
      -1.395446468581252334070768626e-19,
      3.534707039629467471693229977e-21,
      -8.953517427037546850402611251e-23,
      2.267952452337683060310950058e-24,
      -5.744790668872202445263829503e-26,
      1.455172475614864901866244572e-27,
      -3.685994940665310178130050728e-29,
      9.336734257095044668660153106e-31,
      -2.365022415700629886484029550e-32
    };

  double z = 1.0, zprev = {};

  for (auto i = 2u; i < n; i++)
  {
    zprev = z;
    z += exp(-x * log((double)i));
    if (z == zprev)
        return z;
  }

  auto const powNx = exp(x * log((double)n));
  double w = x / (n * powNx);

  z += 0.5 / powNx + n / ((x - 1) * powNx) + coef[0] * w;

  for (auto i = 1u; i < 20 && z != zprev; i++)
  {
    w *= fma((x + 2.0 * (double)i - 1.0) * (x + 2.0 * (double)i), 1.0 / ( (double)n * (double) n ), w);
    zprev = z;
    z += coef[i] * w;
  }
  return z;
}
