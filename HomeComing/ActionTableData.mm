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
-(id)initWithAction:(Action)act
{
  data = act;
  display_name = StringToNSString(data.name);
  return self;
}
-(void)setData:(NSString *)n data:(Action)d
{
  display_name = [n retain];
  data = d;
}
-(NSString *)display_name{
  return display_name;
}
-(Action)data{
  return data;
}

@end
