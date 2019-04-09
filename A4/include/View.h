#ifndef A4_VIEW_H_
#define A4_VIEW_H_

#include "CellTypes.h"
#include <string>
#include <vector>

class View {
 private:
 	cellT** B;
 	std::vector<std::vector<int>> B2;
  //array
  //std::vector<int> m_t;
  //std::vector<CardStackT> m_f;
  //CardStackT m_d;
  //CardStackT m_w;

 public:
   View();
  // void read(std::string fname);
   void print(BoardT b) const;
   


  //bool is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1) const;
  //void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);
  //CardStackT get_tab(unsigned i) const;
};

#endif

//using a GridT, which is an array



