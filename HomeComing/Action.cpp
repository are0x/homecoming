//
//  Action.cpp
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/24.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#include <iostream>
#include "Action.h"
#include <fstream>
#include <map>

std::vector<Action> Action::loadActions(const char* path) {
  
  std::ifstream ifs(path);
  if(!ifs.is_open()) throw "cannot open file";  
  
  std::vector<Action> res;
  while (ifs) {
    
    Action act;
    
    std::string name;
    int point, param_size;
    ifs >> name >> point >> param_size;
    act.name = name;
    act.consume_actpow = point;
    
    for(int i = 0; i < param_size; i++) {
      std::string param_name;
      int lb, ub;
      ifs >> param_name >> lb >> ub;
      act.getParam(param_name) = RangeNumber(lb, ub);      
    }
    
    std::string description(""), tmp;
    while (std::getline(ifs, tmp) && tmp != "") description += tmp;
    act.description = description;
    
    res.push_back(act);
  }
  
  return res;
}

RangeNumber& ParameterList::getParam(std::string param) {
  if(param == "知性" || param == "intel") {
    return intel;
  } else if(param == "容姿" || param == "visual") {    
    return visual;
  } else if(param == "生命力" || param == "lifepow") {
    return lifepow;
  } else if(param == "精神力" || param == "mindpow") {
    return mindpow;
  } else if(param == "技術" || param == "technicpow") {
    return technicpow;
  } else if(param == "人間性" || param == "human") {
    return human;
  } else if(param == "資産" || param == "property") {
    return property;
  } else if(param == "天運" || param == "luck") {
    return luck;
  } else if(param == "行動力" || param == "actpow") {
    return actpow;
  } else if(param == "運命力") {
    ;
  } else {
    throw "No such member variable";
  }
}