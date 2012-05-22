//
//  Utility.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/20.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <string>

#ifndef HomeComing_Utility_h
#define HomeComing_Utility_h

struct RangeNumber{
  int low,up;
};

static std::string NSStringToString(NSString *str){
  std::string ret = [str UTF8String];
  return ret;
}

static NSString * StringToNSString(std::string str){
  return [[[NSString alloc] initWithCString:str.c_str() encoding:NSUTF8StringEncoding] autorelease];
}

#endif
