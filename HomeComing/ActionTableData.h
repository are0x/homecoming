//
//  ActionTableData.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/22.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Action.h"

@interface ActionTableData : NSObject{
  Action data;
  NSString *display_name;
}
-(id)initWithAction:(Action)act;
@property (retain) NSString *display_name;


@end
