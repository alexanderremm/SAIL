#include <gtest/gtest.h>

#include <sail/version.hpp>

TEST(Version, SemanticVersion) {
    ASSERT_EQ("0.1.0", sail::version::get_version());
}

TEST(Version, MajorVersion) {
    ASSERT_EQ("0", sail::version::get_major_version());
}

TEST(Version, MinorVersion) {
    ASSERT_EQ("1", sail::version::get_minor_version());
}

TEST(Version, PatchVersion) {
    ASSERT_EQ("0", sail::version::get_patch_version());
}