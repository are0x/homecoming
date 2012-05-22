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
  Heroine data;
  NSString display_name;
};
@property (retain) NSString *display_name;
-(id)initWithHeroine:(Heroine)heroine;
@end
