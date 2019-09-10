#include "bit.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <algorithm>
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

TEST(NextPermutationTest, AlignedWords1) {
  auto seq = std::vector<unsigned char>{0b0000'0000, 0b1111'1111};

  bit::bit_iterator<decltype(seq.begin())> begin(seq.begin());
  bit::bit_iterator<decltype(seq.end())> end(seq.end());

  std::vector<unsigned char> bits(begin, end);

  ASSERT_TRUE(std::next_permutation(begin, end));

  EXPECT_THAT(bits, testing::ElementsAre(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST(NextPermutationTest, AlignedWords2) {

}

TEST(NextPermutationTest, UnalignedWords) {

}

TEST(PrevPermutationTest, AlignedWords1) {

}

TEST(PrevPermutationTest, AlignedWords2) {

}

TEST(PrevPermutationTest, UnalignedWords) {

}
