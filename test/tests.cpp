// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
#include <iostream>

TEST(TextGeneratorTests, GeneratePrefx) {
    std::string s = "a b c d e f g f g k";
    textgen gen(s);
    std::map<textgen::prefix, std::vector<std::string>> ans = {
        {{"a", "b"} , {"c"}},
        {{"b", "c"}, {"d"}},
        {{"c", "d"}, {"e"}},
        {{"d", "e"}, {"f"}},
        {{"e", "f"}, {"g"}},
        {{"f", "g"}, {"f", "k"}},
        {{"g", "f"}, {"g"}},
        {{"g", "k"}, {}},
    };
    ASSERT_EQ(ans, gen.get_prefixs());
}

TEST(TextGeneratorTests, GenerateText) {
    std::string s = "a b c d e f g k";
    textgen gen(s);
    textgen::prefix pref = {"a", "b"};
    std::string ans = gen.generate_from(pref);
    ASSERT_EQ(s, ans);
}