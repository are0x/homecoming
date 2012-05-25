//
//  ActionFileLoader.h
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

class ActionFileLoader {

#define MAP_CHILDREN(s, plist) { for(int i = 1; i < (int)(s).child.size(); i++) mapper((s).child[i], (plist)); }
#define MAP_INTVAL(s, plist, var) { (plist).var = atoi((s).child[1].value.c_str()); }
#define MAP_FLOATVAL(s, plist, var) { (plist).var = atof((s).child[1].value.c_str()); }
#define MAP_STRVAL(s, plist, var) { (plist).var = (s).child[1].value; }
// #define MAP_STAGE(s, plist, var) { (plist).var =  }  
  
private:
  
  // S式 -> Actionクラス への変換
  // 各要素ごとに再帰的にメンバ変数へのマッピングを行う
  void mapper(const S& es_tree, Action& act) {
    
    static bool in_cond = false;
    static bool in_hist = false;
    
    // アクションの設定ファイルの仕様から、式の第一要素はかならずアトム
    assert(es_tree.child[0].is_atom);
    
    switch (es_tree.child[0].value) {
      case "Action":
        in_cond = in_hist = false;
        MAP_CHILDREN(es_tree, act);
        break;
      case "name":        
        if (in_hist) {
          act.history.push_back(es_tree.child[1].value);
        } else {
          MAP_STRVAL(es_tree, act, name);
        }
        break;
      case "spend":
        MAP_INTVAL(es_tree, act, consume_actpow);
        break;
      case "params":
        MAP_CHILDREN(es_tree, act);
        break;
      case "param":
        (in_cond ? act.rest : act).getParam(es_tree[1].value)
            = RangeNumber(atoi(es_tree[2].value), atoi(es_tree[3].value));
        break;
      case "description":
        MAP_STRVAL(es_tree, act, description);
        break;
      case "cond":
        in_cond = true;
        MAP_CHILDREN(es_tree, act);
        in_cond = false;
        break;
      case "steady":
        act.rest.steady = true;
        break;
      case "phase":
        break;
      case "prob":
        MAP_FLOATVAL(es_tree, act.rest, prob);
        break;
      case "attrs":
        MAP_CHILDREN(es_tree, act);
        break;
      case "attr":
        act.rest.attrs.push_back(es_tree[1].value);
        break;
      case "history":
        in_hist = true;
        MAP_CHILDREN(es_tree, act);
        in_hist = false;
        break;
      default:
        throw "invalid file format";
    }
  }
  
public:
  
  static std::vector<Action> load(const char* path) {
    
    std::ifstream ifs(path);
    std::vector<ES> s_tree = choro3::ES::load(ifs);
    
    std::vector<Action> res;
    for(int i = 0; i < (int)s_tree.size(); i++) {      
      Action act;
      mapper(s_tree[i], act);
      res.push_back(act);
    }
    
    return res;
  }
};

#endif
