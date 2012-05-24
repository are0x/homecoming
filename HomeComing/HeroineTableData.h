//
//  HeroinTableData.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "Heroine.h"

@interface HeroineTableData : NSObject{
  NSString *display_name;
  Heroine data;
};
-(id)initWithHeroine:(Heroine)heroine;
- (void) setData: (NSString*) n data: (Heroine) d;
- (NSString *)display_name;
- (Heroine)data;
@end
