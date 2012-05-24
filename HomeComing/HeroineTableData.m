//
//  HeroinTableData.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "HeroineTableData.h"
#include "Utility.h"

@implementation HeroineTableData
-(id)initWithHeroine:(Heroine)heroine{
  display_name = StringToNSString(heroine.name);
  data = heroine;
  return self;
}
-(void)setData:(NSString *)n data:(Heroine)d
{
  display_name = [n retain];
  data = d;
}
-(NSString *)display_name{
  return display_name;
}
-(Heroine)data{
  return data;
}

@end
