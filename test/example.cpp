#include "bit_iterator.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <cstddef>
#include <vector>

template <typename... Ts>
std::vector<std::byte> make_bytes(Ts &&... args) noexcept {
  return {std::byte(std::forward<Ts>(args))...};
}

TEST(IsPermutationTest, Simple) {
  auto seq1 = make_bytes(0b0000'0000, 0b1111'1111);
  auto seq2 = make_bytes(0b0101'0101, 0b0101'0101);

  bit::bit_iterator it1(seq1);
  bit::bit_iterator it2(seq2);

  EXPECT_TRUE(std::is_permutation(seq1.begin(), seq1.end(), seq2.begin()));
}
