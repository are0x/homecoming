//
//  CommandMenuController.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"
#include "Action.h"

@class AppDelegate;

@interface CommandMenuController : NSWindowController{
  IBOutlet NSArrayController *action_array_controller;
  IBOutlet NSArrayController *execution_array_controller;
  IBOutlet NSArrayController *meet_array_controller;
  IBOutlet NSArrayController *attack_array_controller;
  AppDelegate *appdelegate;
}
-(id)initWithDelegate:(AppDelegate *)app;
-(void)initActionList:(std::vector<Action>)actions;
-(void)initMeetList:(std::vector<Heroine>)heroines;
-(IBAction)attackButton :(id)sender;
-(IBAction)undoAttackButton:(id)sender;
@end
