//
//  SchoolTableData.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SchoolTableData.h"

@implementation SchoolTableData

-(void)setData:(NSString *)name data:(School)sc{
  display_name = name;
  data = sc;
}
-(NSString *)display_name{
  return display_name;
}
-(School)data{
  return data;
}

@end
