//
//  AttributeFileLoader.hpp
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/27.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_AttributeFileLoader_h
#define HomeComing_AttributeFileLoader_h

#include "Attribute.hpp"
#include <fstream>

static std::vector<Attribute> loadAttributes(const char* path) {
  std::ifstream ifs(path);
  if (!ifs.is_open()) throw "cannot open file";
  
  std::vector<Attribute> res;
  while (true) { // each row

    Attribute attr;
    
    if (ifs >> attr.name) {
      ifs >> attr.dialogue_failure >> attr.dialogue_success;
      ifs >> attr.category >> attr.priority;
      res.push_back(attr);
    } else {
      break;
    }
  }
  
  return res;
}

#endif
