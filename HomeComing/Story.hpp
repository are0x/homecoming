//
//  Story.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_Story_h
#define HomeComing_Story_h

/*
#include <vector>
#include <string>

class Story {
private:
  std::vector<std::string> _text;
  std::vector<std::string> _image;
public:
  static Story load(const char* path);
  // int current();
  // int next();
  // int prev();
  std::string getText(int idx);
  std::string getImagePath(int idx);
};
 */

#include "Heroine.h"
#include "Action.h"
#include <vector>
#include <string>

class Story {
private:
public:
  Story(std::vector<Action> acts, std::vector<Heroine> heroines) {    
  }
  Story(){}
};

#endif
