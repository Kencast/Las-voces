/**
 * Igual a unordered_map en terminos de API
 * Utiliza 1.5 veces mas memoria
 * 3 veces mas rapido
 */
#include <bits/extc++.h>
struct chash {
	const uint64_t C = lld(4e18 * acos(0)) | 71;
	lld operator()(lld x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<lld,int,chash> h({},{},{},{},{1<<16});
