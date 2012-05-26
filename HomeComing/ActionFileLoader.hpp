//
//  ActionFileLoader.hpp
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/25.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_ActionFileLoader_h
#define HomeComing_ActionFileLoader_h

#include "ES.hpp"
#include "Action.h"
#include "Utility.h"
#include <cassert>

// アクションの設定ファイルを読み込む

class ConfigFileLoader {};

class ActionFileLoader : ConfigFileLoader {

#define MAP_CHILDREN(s, plist) { for(int i = 1; i < (int)(s).length(); i++) mapper((s)[i], (plist)); }
#define MAP_INTVAL(s, plist, var) { (plist).var = atoi((s)[1].value().c_str()); }
#define MAP_FLOATVAL(s, plist, var) { (plist).var = atof((s)[1].value().c_str()); }
#define MAP_STRVAL(s, plist, var) { (plist).var = (s)[1].value(); }
// #define MAP_STAGE(s, plist, var) { (plist).var =  }  
  
private:
  
  // S式 -> Actionクラス への変換
  // 各要素ごとに再帰的にメンバ変数へのマッピングを行う
  static void mapper(choro3::ES& es_tree, Action& act) {
    
    static bool in_cond = false;
    static bool in_hist = false;
    
    // アクションの設定ファイルの仕様から、式の第一要素はかならずアトム
    assert(es_tree[0].atom());
    
    const std::string tag = es_tree[0].value();
    
    if (tag == "Action") {
      in_cond = in_hist = false;
      MAP_CHILDREN(es_tree, act);      
    } else if (tag == "name") {
      if (in_hist) {
        act.rest.hist.push_back(es_tree[1].value());
      } else {
        MAP_STRVAL(es_tree, act, name);
      }
    } else if (tag == "spend") {      
      MAP_INTVAL(es_tree, act, consume_actpow);
    } else if (tag == "params") {
      MAP_CHILDREN(es_tree, act);
    } else if (tag == "param") {
      RangeNumber rng = RangeNumber(atoi(es_tree[2].value().c_str()), atoi(es_tree[3].value().c_str()));
      if (in_cond) {
        act.rest.setParam(es_tree[1].value(),rng);
      } else {
        act.setParam(es_tree[1].value(),rng);
      }
    } else if(tag == "description") {
      MAP_STRVAL(es_tree, act, description);
    } else if (tag == "cond") {
        in_cond = true;
        MAP_CHILDREN(es_tree, act);
        in_cond = false;      
    } else if (tag == "steady") {
      act.rest.steady = true;
    } else if (tag == "phase") {
      act.rest.enableAge(toStage(es_tree[1].value()));
    } else if (tag == "prob") {
      MAP_FLOATVAL(es_tree, act.rest, prob);
    } else if (tag == "attrs") {
      MAP_CHILDREN(es_tree, act);
    } else if (tag == "attr") {
      act.rest.attrs.push_back(es_tree[1].value());
    } else if (tag == "history") {
      in_hist = true;
        MAP_CHILDREN(es_tree, act);
      in_hist = false;
    } else {
      
    }

  }
  
public:
  
  static std::vector<Action> load(const char* path) {
    
    std::ifstream ifs(path);
    std::vector<choro3::ES> s_tree = choro3::ES::load(ifs);        
    
    //printf("%d\n", (int)s_tree.size());
    
    std::vector<Action> res;
    for(int i = 0; i < (int)s_tree.size(); i++) {
      
      choro3::ES::prettify(s_tree[i]);
      
      // todo: be sure the field "rest.age" is equal to zero initially
      Action act; // act.rest.age = NO_STAGE;
      ActionFileLoader::mapper(s_tree[i], act);
      if (act.rest.age == NO_STAGE) { act.rest.age = STAGE_ALL; }
      
      res.push_back(act);
    }
    
    return res;
  }
};

#endif
