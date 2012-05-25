//
//  Action.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "Utility.h"
#include <string>
#include <vector>

#ifndef HomeComing_Action_h
#define HomeComing_Action_h

struct ParameterList {
  RangeNumber visual,intel,human,property;
  RangeNumber actpow,lifepow,mindpow,technicpow,luck;  
  // パラメータ名とメンバ変数の対応を取る
  // ex:   act.getParam("知性") = RangeNumber(1, 2);  // act.intel に (1, 2) を設定
  RangeNumber& getParam(std::string param);
};

class Action : ParameterList {
public:
  
  // 制約条件
  struct Restriction : ParameterList {

    enum Stage {ELM1, ELM2, JHS, HS, UNV1, UNV2, WOK1, WOK2, WOK3, WOK4, WOK5};

    bool steady;
    std::vector<std::string> attrs, hist;
    double prob;
    Stage age;
  };
  
  std::string name;
  int consume_actpow;//必要行動力
  //変動の範囲
  RangeNumber visual,intel,human,property;
  RangeNumber actpow,lifepow,mindpow,technicpow,luck;
  std::string description;
  //
  Restriction rest;
  // 
  static std::vector<Action> loadActions(const char* path);
};

#endif
