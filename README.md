# cexpid
POSIX指向のC言語汎用部品集
## 概要
C言語標準部品集を強化した総合的な部品集であり、各種規格準拠とUNIX哲学、安全性に重点をおいて設計している。
## 特長的な機能
他の言語で標準的に整備されている算法等の便利な関数を収録！
また、C言語標準部品集に統合されることを想定して設計した拡張関数も実装されている。
### 各種標準関数の実装
ISO CやPOSIXなどの標準規格で規定があるものの、一般的でないか任意実装とされたもののほぼ完全な実装
- ISO/IEC 9899:2024 附属書F, 附属書H
- ISO/IEC TS 18661-4:2015
- ISO/IEC TR 24731-2:2010
- ISO/IEC 24747

このうち、ISO/IEC 9899:2024 附属書Kに規定の関数は、[Safelib](https://github.com/rurban/safeclib)や[slibc](https://github.com/sbaresearch/slibc)などの先行実装が存在するため、本部品集では実装していない。これについて詳しくは[libc_ext.md](docs/libc_ext.md)にて説明している。
### 言語機能
C言語の言語機能を補強する関数もある。
- switch文で便利な実行時範囲切り出し([rangeif.h](include/rangeif.h))
## 利用許諾
source codeは、GNU GPL 3.0以降、その他文章はCC BY-SA 4.0以降でその利用を許諾する。