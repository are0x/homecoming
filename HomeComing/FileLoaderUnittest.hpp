//
//  FileLoaderUnittest.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/25.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_FileLoaderUnittest_h
#define HomeComing_FileLoaderUnittest_h

#include "ConfigFileLoader.h"

class FileLoaderUnittest {
private:
public:
  bool run() {
    ConfigFileLoader* loader = ConfigFileLoader::load("../../../../../dat/sample");
    ConfigFileLoader::prettify(loader->parse());
    return true;
  }
};

#endif
