//
//  School.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <string>

#ifndef HomeComing_School_h
#define HomeComing_School_h

class School{
public:
  std::string name;
  //関係するパラメーターリスト
  std::vector<std::string> paramaters;
  //そのパラメータの平均値、標準偏差
  std::vector<double> nyus;
  std::vector<double> sigmas;
};

#endif
