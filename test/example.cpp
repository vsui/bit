#include "bit.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <cstddef>
#include <vector>

TEST(IsPermutationTest, Simple) {
  auto seq1 = std::vector<unsigned char>{0b0000'0000, 0b1111'1111};
  auto seq2 = std::vector<unsigned char>{0b0101'0101, 0b0101'0101};

  bit::bit_iterator<decltype(seq1.begin())> begin1(seq1.begin());
  bit::bit_iterator<decltype(seq1.end())> end1(seq1.end());
  bit::bit_iterator<decltype(seq2.begin())> begin2(seq2.begin());

  EXPECT_TRUE(std::is_permutation(begin1, end1, begin2));
}

TEST(IsPermutationTest, UnalignedWords) {
  auto seq1 = std::vector<unsigned char>{0b0000'0000, 0b1111'1111};
  auto seq2 = std::vector<unsigned char>{0b0101'0101, 0b0101'0101};

  bit::bit_iterator<decltype(seq1.begin())> begin1(seq1.begin());
  bit::bit_iterator<decltype(seq1.end())> end1(seq1.end());
  bit::bit_iterator<decltype(seq2.begin())> begin2(seq2.begin());

  EXPECT_TRUE(std::is_permutation(begin1 + 1, end1 - 1, begin2 + 2));
}
