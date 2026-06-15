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

// 主にlibreofficeの関数を参考とした。

// sum function
int tsum (unsigned int n, typeof(int[n]) a);
double ftsum(unsigned int n, typeof(double[n]) a);

// average function
double average(unsigned int n, typeof(int[n]) a);
double faverage(unsigned int n, typeof(double[n]) a);

double median(unsigned int n, typeof(int[n]) a);

double trimmean(unsigned int n, typeof(double[n]) a, float p);

double geomean(unsigned int n, typeof(double[n]) a);

double harmean(unsigned int n, typeof(double[n]) a);

double mode(unsigned int n, typeof(double[n]) a);

double large(unsigned int n, typeof(double[n]) a, unsigned int rank);

double small(unsigned int n, typeof(double[n]) a, unsigned int rank);

double rank(int value, unsigned int n, typeof(double[n]) a, bool r);

double rankavg(int value, unsigned int n, typeof(double[n]) a, bool r);
/*
avedev
betadist
betainv
binomdist
binomdistrange
binominv
chisqdist
chisqdistrt
chisqinv
chisqinvrt
chisqtest
confidencenorm
confidencet
correl
countblank
covariancep
covariances
devsq
expondist
fdistrt
finv
finvrt
ftest
fisher
fisherinv
forecastets
forecastetsconfint
forecastetsseasonality
forecastetsstat
forecastlinear
gammadist
gammainv
gammaln
gammalnprecise
gauss
geomean
growth
harmean
hypgeomdist
intercept
kurt
large
linest
logest
lognormdist
lognorminv
modemult
modesngl
negbinomdist
normdist
norminv
normsdist
normsinv
pearson
percentileexc
percentileinc
percentrankexc
percentrankinc
permut
permutationa
phi
poissondist
prob
quartileexc
quartileinc
rankavg
rankeq
rsq
skew
skewp
slope
standardize
stdevp
stdevs
stdeva
stdevpa
steyx
tdist
tdist2t
tdistrt
tinv
tinv2t
ttest
trend
varp
vars
weibulldist
ztest
*/