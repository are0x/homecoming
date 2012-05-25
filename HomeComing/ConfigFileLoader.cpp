//
//  ConfigFileLoader.cpp
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/25.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#include <iostream>

#include "ConfigFileLoader.h"

ConfigFileLoader::ConfigFileLoader(const char* path)
  :input(path) {
    if (!input.is_open()) throw "cannot open file";
}

std::string ConfigFileLoader::get_token() {
  std::string s;
  input >> s;
  return s;
}

ConfigFileLoader::S* ConfigFileLoader::parse() {

  input.clear(); input.ignore();

  char c;
  S* res = new S();    
  
  if (input >> c && c != '(') {  // atom
    input.putback(c);    
    res->value = get_token();    
    return res;    
  } else {    // list
    while (true) {
      if (input >> c && c == ')') {
        return res;
      } else {
        res->child.push_back(parse());
      }
    }
  }
}

void ConfigFileLoader::_pretty(ConfigFileLoader::S *es_tree, int depth) {
  if (es_tree->child.size() == 0) {
    for(int i = 0; i < depth; i++) printf("  ");
    printf("%s\n", es_tree->value.c_str());
  } else {
    for(int i = 0; i < depth; i++) printf("  ");
    printf("(\n");
    for(int i = 0; i < es_tree->child.size(); i++) _pretty(es_tree->child[i], depth + 1);
    printf(")");
  }
}

void ConfigFileLoader::prettify(ConfigFileLoader::S *es_tree) {
  ConfigFileLoader::_pretty(es_tree, 0);
}


