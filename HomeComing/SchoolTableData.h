//
//  SchoolTableData.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "School.h"

@interface SchoolTableData : NSObject
{
  NSString *display_name;
  School data;
}
-(void)setData:(NSString *)name data:(School) sc;
-(NSString *)display_name;
-(School)data;
@end
