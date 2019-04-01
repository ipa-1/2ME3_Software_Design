#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include <vector>

#include "CardTypes.h"
#include "CardStack.h"

class BoardT {
 private:
  std::vector<CardStackT> m_t;
  std::vector<CardStackT> m_f;
  CardStackT m_d;
  CardStackT m_w;

  bool valid_tab_tab(unsigned int n0, unsigned int n1) const;
  bool valid_tab_foundation(unsigned int n0, unsigned int n1) const;
  bool valid_waste_tab(unsigned int n) const;
  bool valid_waste_foundation(unsigned int n) const;
  bool valid_tab_mv() const;
  bool valid_waste_mv() const;

 public:
  explicit BoardT(const std::vector<CardT> deck);
  bool is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1) const;
  bool is_valid_waste_mv(CategoryT c, unsigned int n) const;
  bool is_valid_deck_mv() const;
  void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);
  void waste_mv(CategoryT c, unsigned int n);
  void deck_mv();
  CardStackT get_tab(unsigned i) const;
  CardStackT get_foundation(unsigned int i) const;
  CardStackT get_deck() const;
  CardStackT get_waste() const;
  bool valid_mv_exists() const;
  bool is_win_state() const;
};

#endif
