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
#include "Utility.h"

using namespace std;


bool Action::operator<(const Action &act)const{
  string vs[10]={"知性","容姿","生命力","精神力","技術","人間性","資産","天運","行動力","運命力"};
  for(int i=0;i<10;i++){
    RangeNumber vala = act.getParam(vs[i]);
    RangeNumber val = getParam(vs[i]);
    if(val != vala) return vala < val;
  }
  for(int i=0;i<10;i++){
    RangeNumber vala = act.rest.getParam(vs[i]);
    RangeNumber val = rest.getParam(vs[i]);
    if(val != vala) return vala < val;
  }
  if(act.rest.steady != rest.steady) return act.rest.steady < rest.steady;
  if(act.rest.prob != rest.prob) return act.rest.prob < rest.prob;
  if(act.rest.age != rest.age)return act.rest.age < rest.age;  
  if(act.consume_actpow != consume_actpow) return act.consume_actpow < consume_actpow;
  if(act.name != name) return act.name < name;
  return act.description < description;
}

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
      act.setParam(param_name,RangeNumber(lb, ub));      
    }
    
    std::string description(""), tmp;
    while (std::getline(ifs, tmp) && tmp != "") description += tmp;
    act.description = description;
    
    res.push_back(act);
  }
  
  return res;
}

bool Action::IsEnable(Stage s, Game *game){
  string vs[10]={"知性","容姿","生命力","精神力","技術","人間性","資産","天運","行動力","運命力"};
  if(!rest.satisfyAge(s)) return false;
  if(rest.steady && game->steady.name == "None"){
    return false;
  }
  for(int i=0;i<10;i++){
    RangeNumber rval = rest.getParam(vs[i]);
    int hval = game->cur_hero.GetParamater(vs[i]);
    if( !(rval.low <= hval && hval <= rval.up ) ) return false;
  }
  int n = (int)rest.attrs.size();
  for(int i=0;i<n;i++){
    if(!game->steady.HaveAttr( rest.attrs[i] ) ) return false;
  }
  n = (int)rest.hist.size();
  for(int i=0;i<n;i++){
    if(game->past_actions.find(rest.hist[i]) == game->past_actions.end()) return false;
  }
  return true;
}

string Action::ToStr(){
  string ret= "必要行動力:"+NumToStr(consume_actpow)+"\n";
  ret += description;
  return ret;
}

void ParameterList::setParam(const string &param,const RangeNumber &val) {
  if(param == "知性" || param == "intel") {
    intel = val;
  } else if(param == "容姿" || param == "visual") {    
    visual = val;
  } else if(param == "生命力" || param == "lifepow") {
    lifepow = val;
  } else if(param == "精神力" || param == "mindpow") {
    mindpow = val;
  } else if(param == "技術" || param == "technicpow") {
    technicpow = val;
  } else if(param == "人間性" || param == "human") {
    human = val;
  } else if(param == "資産" || param == "property") {
    property = val;
  } else if(param == "天運" || param == "luck") {
    luck = val;
  } else if(param == "行動力" || param == "actpow") {
    actpow = val;
  } else if(param == "徳" || param == "toku") {
    toku = val;    
  } else if(param == "運命力") {
    fatalpow = val;
  } else {
    std::cerr << "passed invalid parameter identifier " << param << " for the method getParam." << std::endl;
    throw "No such member variable";
  }
}

const RangeNumber& ParameterList::getParam(const std::string& param)const {
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
  } else if(param == "徳" || param == "toku") {
    return toku;
  } else if(param == "運命力") {
    return fatalpow;
  } else {
    std::cerr << "passed invalid parameter identifier " << param << " for the method getParam." << std::endl;
    throw "No such member variable";
  }
}

