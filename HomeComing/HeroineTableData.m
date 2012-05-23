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
@synthesize display_name;
-(id)initWithHeroine:(Heroine)heroine{
  data = heroine;
  display_name = StringToNSString(heroine.name);
  return self;
}
@end
