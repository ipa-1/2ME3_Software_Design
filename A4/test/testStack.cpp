#include <stdexcept>
#include <vector>

#include "catch.h"
#include "CardTypes.h"
#include "Stack.h"

std::vector<CardT> new_deck() {
  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }

  return d;
}

TEST_CASE("tests for Stack", "[Stack]") {

  SECTION("constructor accepts a vector") {
    Stack<CardT> stack(new_deck());
    REQUIRE(stack.size() == 104);
  }

  SECTION("push yields new stack, does not modify old stack") {
    Stack<CardT> stack(new_deck());
    size_t old_size = stack.size();
    CardT c = { Spades, 1 };
    Stack<CardT> next = stack.push(c);
    REQUIRE(next.size() == stack.size() + 1);
    REQUIRE(stack.size() == old_size);
  }

  SECTION("pop yields new stack, does not modify old stack") {
    Stack<CardT> stack(new_deck());
    size_t old_size = stack.size();
    Stack<CardT> next = stack.pop();
    REQUIRE(next.size() == stack.size() - 1);
    REQUIRE(stack.size() == old_size);
  }

  SECTION("push/pop/top respect FILO order") {
    Stack<CardT> stack(new_deck());
    CardT a = { Spades, 1 };
    CardT b = { Clubs, 2 };
    stack = stack.push(a);
    REQUIRE(stack.top().s == Spades);
    REQUIRE(stack.top().r == 1);

    stack = stack.push(b);
    REQUIRE(stack.top().s == Clubs);
    REQUIRE(stack.top().r == 2);

    stack = stack.pop();
    REQUIRE(stack.top().s == Spades);
    REQUIRE(stack.top().r == 1);
  }

  SECTION("stack isn't artifically bounded") {
    Stack<CardT> stack(new_deck());
    CardT a = { Spades, 1 };
    for (unsigned int i = 0; i < 1000; i++) {
      stack = stack.push(a);
    }
    REQUIRE(stack.size() == 1000 + new_deck().size());
  }

  SECTION("pop throws out_of_range") {
    std::vector<CardT> s;
    Stack<CardT> stack(s);
    REQUIRE_THROWS_AS(
      stack.pop(),
      std::out_of_range
    );
  }

  SECTION("top throws out_of_range") {
    std::vector<CardT> s;
    Stack<CardT> stack(s);
    REQUIRE_THROWS_AS(
      stack.top(),
      std::out_of_range
    );
  }

  SECTION("toSeq has correct order") {
    std::vector<CardT> s = new_deck();
    Stack<CardT> stack(s);
    stack = stack.pop();
    s.pop_back();
    std::vector<CardT> vec = stack.toSeq();
    REQUIRE(vec.size() == s.size());
    bool isCorrect = true;
    for (unsigned int i = 0; i < s.size(); i++) {
      if (!(vec[i].r == s[i].r && vec[i].s == s[i].s)) {
        isCorrect = false;
        break;
      }
    }
    REQUIRE(isCorrect);
  }

}
