//
//  ConfigFileLoader.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/25.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_ConfigFileLoader_h
#define HomeComing_ConfigFileLoader_h

#include <vector>
#include <string>
#include <fstream>

#include "ES.hpp"

class ConfigFileLoader {  
public:
  
  struct S {
    std::string value;
    std::vector<S*> child;
    S(): value(""){};
  };
  
  std::ifstream input;
  
  ConfigFileLoader(const char* path);
  
  std::string get_token();
  S* parse();
  
  static void _pretty(S* es_tree, int depth);
  
public:
  // 
  static ConfigFileLoader* load(const char* path);
  static void prettify(S* es_tree);
};

#endif
