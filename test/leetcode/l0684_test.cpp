//
// Created by 张俭 on 2021/8/10.
//

#include "gtest/gtest.h"
#include "../../src/leetcode/l0684.cpp"

namespace {
    TEST(l0684, case1) {
        L10684 *aux = new L10684();
        std::vector<vector<int>> src = {{1, 2},
                                        {1, 3},
                                        {2, 3}};
        const vector<int> &result = aux->findRedundantConnection(src);
        const vector<int> excepted = {2, 3};
        EXPECT_EQ(result, excepted);
    }
}
