#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "CardTypes.h"
#include "GameBoard.h"
#include "Stack.h"

std::vector<CardStackT> init_seq(unsigned int n) {
  return std::vector<CardStackT>(n);
}

void cnt_cards_stack(const CardStackT s, unsigned short int (&count)[13][4]) {
  for (CardT card : s.toSeq()) {
    count[card.r - 1][card.s]++;
  }
}

bool two_decks(
    const std::vector<CardStackT> t,
    const std::vector<CardStackT> f,
    const CardStackT d,
    const CardStackT w) {
  unsigned short int count[13][4];
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      count[rank - 1][suit] = 0;
    }
  }

  for (auto &stack : t) {
    cnt_cards_stack(stack, count);
  }
  for (auto &stack : f) {
    cnt_cards_stack(stack, count);
  }
  cnt_cards_stack(d, count);
  cnt_cards_stack(w, count);

  for (RankT rank = ACE; rank < KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      if (count[rank][suit] != 2) {
        return false;
      }
    }
  }

  return true;
}

std::vector<CardStackT> tab_deck(std::vector<CardT>::const_iterator begin) {
  std::vector<CardStackT> tabs(10);
  for (unsigned int i = 0; i < 10; i++) {
    for (unsigned int j = 0; j < 4; j++) {
      tabs[i] = tabs[i].push(*begin);
      begin++;
    }
  }

  return tabs;
}

BoardT::BoardT(const std::vector<CardT> deck)
: m_t(tab_deck(deck.cbegin()))
, m_f(init_seq(8))
, m_d(CardStackT(std::vector<CardT>(deck.cbegin() + 40, deck.cend())))
, m_w() {
  if (!two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT())) {
    throw std::invalid_argument("Invalid deck.");
  }

  // It's a good idea to check that we initialized the BoardT correctly, not
  // just that we received a valid deck.
  assert(two_decks(m_t, m_f, m_d, m_w));
}

bool tab_placeable(CardT c, CardT d) {
  return c.s == d.s && c.r == d.r - 1;
}

bool foundation_placeable(CardT c, CardT d) {
  return c.s == d.s && c.r == d.r + 1;
}

bool is_valid_pos(CategoryT c, unsigned int n) {
  switch (c) {
    case Deck:
    case Waste:
      return true;
    case Tableau:
      return n >= 0 && n <= 9;
    case Foundation:
      return n >= 0 && n <= 7;
    default:
      return false;
  }
}

bool BoardT::valid_tab_tab(unsigned int n0, unsigned int n1) const {
  if (m_t[n0].size() == 0) {
    return false;
  }

  if (m_t[n1].size() == 0) {
    return true;
  }

  return tab_placeable(m_t[n0].top(), m_t[n1].top());
}

bool BoardT::valid_tab_foundation(unsigned int n0, unsigned int n1) const {
  if (m_t[n0].size() == 0) {
    return false;
  }

  if (m_f[n1].size() == 0) {
    return m_t[n0].top().r == ACE;
  }

  return foundation_placeable(m_t[n0].top(), m_f[n1].top());
}

bool BoardT::valid_waste_tab(unsigned int n) const {
  return m_t[n].size() == 0 || tab_placeable(m_w.top(), m_t[n].top());
}

bool BoardT::valid_waste_foundation(unsigned int n) const {
  if (m_f[n].size() == 0) {
    return m_w.top().r == ACE;
  }

  return foundation_placeable(m_w.top(), m_f[n].top());
}

bool BoardT::is_valid_tab_mv(
    CategoryT c,
    unsigned int n0,
    unsigned int n1) const {
  switch (c) {
    case Deck:
    case Waste:
      return false;

    case Tableau:
      if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Tableau, n1))) {
        throw std::out_of_range("Invalid Tableau -> Tableau move.");
      }
      return valid_tab_tab(n0, n1);

    case Foundation:
      if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Foundation, n1))) {
        throw std::out_of_range("Invalid Tableau -> Foundation move.");
      }
      return valid_tab_foundation(n0, n1);

    default:
      return false;
  }
}

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n) const {
  if (m_w.size() == 0) {
    throw std::invalid_argument("Waste stack is empty.");
  }

  switch (c) {
    case Deck:
    case Waste:
      return false;

    case Tableau:
      if (!is_valid_pos(Tableau, n)) {
        throw std::out_of_range("Invalid Waste -> Tableau move.");
      }
      return valid_waste_tab(n);

    case Foundation:
      if (!is_valid_pos(Foundation, n)) {
        throw std::out_of_range("Invalid Waste -> Foundation move.");
      }
      return valid_waste_foundation(n);

    default:
      return false;
  }
}

bool BoardT::is_valid_deck_mv() const {
  return m_d.size() > 0;
}

void BoardT::tab_mv(CategoryT c, unsigned int n0, unsigned int n1) {
  if (!is_valid_tab_mv(c, n0, n1)) {
    throw std::invalid_argument("Invalid move from tableau.");
  }

  CardT source = m_t[n0].top();
  m_t[n0] = m_t[n0].pop();
  if (c == Tableau) {
    m_t[n1] = m_t[n1].push(source);
  } else if (c == Foundation) {
    m_f[n1] = m_f[n1].push(source);
  }
}

void BoardT::waste_mv(CategoryT c, unsigned int n) {
  if (!is_valid_waste_mv(c, n)) {
    throw std::invalid_argument("Invalid move from waste.");
  }

  if (c == Tableau) {
    m_t[n] = m_t[n].push(m_w.top());
  } else if (c == Foundation) {
    m_f[n] = m_f[n].push(m_w.top());
  }
  m_w = m_w.pop();
}

void BoardT::deck_mv() {
  if (!is_valid_deck_mv()) {
    throw std::invalid_argument("Invalid move from deck.");
  }

  m_w = m_w.push(m_d.top());
  m_d = m_d.pop();
}

CardStackT BoardT::get_tab(unsigned i) const {
  if (!is_valid_pos(Tableau, i)) {
    throw std::out_of_range("Invalid Tableau index.");
  }

  return m_t[i];
}

CardStackT BoardT::get_foundation(unsigned i) const {
  if (!is_valid_pos(Foundation, i)) {
    throw std::out_of_range("Invalid Foundation index.");
  }

  return m_f[i];
}

CardStackT BoardT::get_deck() const {
  return m_d;
}

CardStackT BoardT::get_waste() const {
  return m_w;
}

bool BoardT::valid_tab_mv() const {
  for (unsigned int tab0 = 0; tab0 < 10; tab0++) {
    for (unsigned int tab1 = tab0 + 1; tab1 < 10; tab1++) {
      if (!is_valid_tab_mv(Tableau, tab0, tab1)) {
        return false;
      }
    }
  }

  for (unsigned int tab = 0; tab < 10; tab++) {
    for (unsigned int foundation = 0; foundation < 8; foundation++) {
      if (!is_valid_tab_mv(Foundation, tab, foundation)) {
        return false;
      }
    }
  }

  return true;
}

bool BoardT::valid_waste_mv() const {
  if (m_w.size() == 0) {
    return false;
  }

  for (unsigned int tab = 0; tab < 10; tab++) {
    if (!is_valid_waste_mv(Tableau, tab)) {
      return false;
    }
  }

  for (unsigned int foundation = 0; foundation < 8; foundation++) {
    if (!is_valid_waste_mv(Foundation, foundation)) {
      return false;
    }
  }

  return true;
}

bool BoardT::valid_mv_exists() const {
  return (
    valid_tab_mv() ||
    valid_waste_mv() ||
    is_valid_deck_mv());
}

bool BoardT::is_win_state() const {
  return std::all_of(
    m_f.cbegin(),
    m_f.cend(),
    [](CardStackT s) { return s.size() > 0 && s.top().r == KING; });
}
