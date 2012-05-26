//
//  Attribute.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/27.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#ifndef HomeComing_Attribute_h
#define HomeComing_Attribute_h

#include <string>
#include <vector>
#include <iostream>

class Attribute {
public:  
  std::string name;
  std::string dialogue_success, dialogue_failure;
  std::string category;
  unsigned int priority;
  
  // void prettify(std::ostream& os = std::cout) {  
  void prettify() {
    std::cout << "Attribute: " << name << std::endl;
    std::cout << "  success - [" << dialogue_success << "]" << std::endl;
    std::cout << "  failure - [" << dialogue_failure << "]" << std::endl;
    std::cout << "  category: " << category << std::endl;
    std::cout << "  priority: " << priority << std::endl;
  }
};

#endif
