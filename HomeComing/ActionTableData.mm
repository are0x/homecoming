//
//  ActionTableData.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ActionTableData.h"
#import "Utility.h"

@implementation ActionTableData
@synthesize display_name;

-(id)initWithAction:(Action)act
{
  data = act;
  display_name = StringToNSString(data.name);
  return self;
}

@end
