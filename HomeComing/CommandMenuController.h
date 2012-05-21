//
//  CommandMenuController.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"

@class AppDelegate;

@interface CommandMenuController : NSWindowController{
  AppDelegate *appdelegate;
}
-(id)initWithDelegate:(AppDelegate *)app;
@end
