#include <bit>

// ============================== Bit Operations ==============================

#define setcnt(x) (std::popcount(static_cast<unsigned long long>(x)))
#define is_pow2(x) ((x) > 0 && std::has_single_bit(static_cast<unsigned long long>(x)))
#define nxt_pow2(x) (std::bit_ceil(static_cast<unsigned long long>(x)))
#define prv_pow2(x) (std::bit_floor(static_cast<unsigned long long>(x)))
#define msb_idx(x) ((x) == 0 ? -1 : static_cast<int>(std::bit_width(static_cast<unsigned long long>(x))) - 1)
#define lzero(x) (std::countl_zero(static_cast<unsigned long long>(x)))
#define rzero(x) (std::countr_zero(static_cast<unsigned long long>(x)))
#define lone(x) (std::countl_one(static_cast<unsigned long long>(x)))
#define rone(x) (std::countr_one(static_cast<unsigned long long>(x)))
#define rotl(x, s) (std::rotl(static_cast<unsigned long long>(x), s))
#define rotr(x, s) (std::rotr(static_cast<unsigned long long>(x), s))
