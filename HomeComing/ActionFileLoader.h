//
//  ActionFileLoader.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/25.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_ActionFileLoader_h
#define HomeComing_ActionFileLoader_h

#include "ConfigFileLoader.h"
#include "Action.h"

class ActionFileLoader : ConfigFileLoader {
private:
  void mapper(S* es_tree, Action& act) {
    
    static bool in_cond = false;
    static bool in_hist = false;
    
    switch (es_tree->child[0].value) {
      case "Action":
        for(int i = 1; i < es_tree->child.size(); i++)
          mapper(es_tree->child[i], act);
        break;
      case "name":        
        if (in_hist) {
          act.history.push_back(es_tree->child[1].value);
        } else {
          act.name = es_tree->child[1].value;
        }
        break;
      case "spend":
        act.consume_actpow = atoi(es_tree->child[1].value.c_str());
        break;
      case "params":
        
        break;
      case "param":
        break;
      case "description":
        break;
      case "cond":        
        break;
      case "steady":
        break;
      case "phase":
        break;
      case "prob":
        break;
      case "attrs":
        break;
      case "attr":
        break;
      case "history":
        break;
      default:
        throw "invalid file format";
    }
  }
public:
  static std::vector<Action> load(const char* path) {
    loader = ActionFileLoader(path);
    std::vector<Action> res;
    while (input) { 
      Action act;
      mapper(parse(), act);
      res.push_back(act);
    }
  }
};

#endif
