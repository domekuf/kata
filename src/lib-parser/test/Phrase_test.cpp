#include <Phrase.hpp>
using ddi::kata::Phrase;

#include <CppUTest/TestHarness.h>

TEST_GROUP(PhraseGroup)
{
};

TEST(PhraseGroup, post)
{
    Phrase p("Alice -> I love the weather today");
    CHECK_EQUAL("Alice", p.subject());
    CHECK_EQUAL(Phrase::POST, p.predicate());
    CHECK(p.object()?true:false);
    CHECK_EQUAL("I love the weather today", p.object().get());
}

TEST(PhraseGroup, read)
{
    Phrase p("Bob");
    CHECK_EQUAL("Bob", p.subject());
    CHECK_EQUAL(Phrase::READ, p.predicate());
    CHECK_FALSE(p.object()?true:false);
}

TEST(PhraseGroup, follow)
{
    Phrase p("Bob follows Alice");
    CHECK_EQUAL("Bob", p.subject());
    CHECK_EQUAL(Phrase::FOLLOW, p.predicate());
    CHECK(p.object()?true:false);
    CHECK("Alice");
}

TEST(PhraseGroup, wall)
{
    Phrase p("Charlie wall");
    CHECK_EQUAL("Charlie", p.subject());
    CHECK_EQUAL(Phrase::WALL, p.predicate());
    CHECK_FALSE(p.object()?true:false);
}