//
//  Action.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#ifndef HomeComing_Action_h
#define HomeComing_Action_h

#include "Utility.h"
#include <string>
#include <vector>
#include "Game.h"

struct ParameterList {
  //変動の範囲
  RangeNumber visual,intel,human,property;
  RangeNumber actpow,lifepow,mindpow,technicpow,luck,fatalpow;
  RangeNumber toku;
  // パラメータ名とメンバ変数の対応を取る
  // ex:   act.getParam("知性") = RangeNumber(1, 2);  // act.intel に (1, 2) を設定
  void setParam(const std::string  &param,const RangeNumber &val);
  const RangeNumber &getParam(const std::string &param)const;
};

struct Action : ParameterList {
  
  // 制約条件
  struct Restriction : ParameterList {

    bool steady;
    std::vector<std::string> attrs, hist;
    double prob;
    
    int age;
    inline void enableAge(Stage a) { age |= a; }
    inline void disableAge(Stage a) { age &= ~a; }
    inline bool satisfyAge(Stage a) { return (bool)(age & a); }
  };
  
  std::string name;
  int consume_actpow;//必要行動力
  std::string description;
  //
  Restriction rest;
  // 
  static std::vector<Action> loadActions(const char* path);
  
  bool IsEnable(Stage s,Game *game);
  bool operator<(const Action &act)const;
  
  
};

static void print_act(const Action& a) {
  std::cout << "Action: " << a.name << std::endl;
  std::cout << "  cost " << a.consume_actpow << "pt." << std::endl;
  std::cout << "  parameters:" << std::endl;
  std::cout << "    intelligence [" << a.intel.low << "-" << a.intel.up << "] " << std::endl;
  std::cout << "          visual [" << a.visual.low << "-" << a.visual.up << "] " << std::endl;
  std::cout << "            life [" << a.lifepow.low << "-" << a.lifepow.up << "] " << std::endl;
  std::cout << "            mind [" << a.mindpow.low << "-" << a.mindpow.up << "] " << std::endl;
  std::cout << "         technic [" << a.technicpow.low << "-" << a.technicpow.up << "] " << std::endl;
  std::cout << "        humanity [" << a.human.low << "-" << a.human.up << "] " << std::endl;
  std::cout << "           stock [" << a.property.low << "-" << a.property.up << "] " << std::endl;
  std::cout << "            luck [" << a.luck.low << "-" << a.luck.up << "] " << std::endl;
  std::cout << "        activity [" << a.actpow.low << "-" << a.actpow.up << "] " << std::endl;
  
}

#endif
