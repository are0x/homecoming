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
#include "Hero.h"

@class AppDelegate;

@interface CommandMenuController : NSWindowController{
  IBOutlet NSArrayController *action_array_controller;
  IBOutlet NSArrayController *execution_array_controller;
  IBOutlet NSArrayController *meet_array_controller;
  IBOutlet NSArrayController *attack_array_controller;
  
  IBOutlet NSTextField *meetHeroinrTextfield;
  
  IBOutlet NSTextField *attackHeroinTextfield;
  
  IBOutlet NSTextField *heroTextfield;
  
  IBOutlet NSTableView *meetTableView;
  
  IBOutlet NSTableView *attackTableView;
  AppDelegate *appdelegate;
}
-(id)initWithDelegate:(AppDelegate *)app;
-(void)initActionList:(std::vector<Action>)actions;
-(void)initMeetList:(std::vector<Heroine>)heroines;
-(void)initTextField:(Hero)hero;
-(IBAction)attackButton :(id)sender;
-(IBAction)undoAttackButton:(id)sender;
-(IBAction)executionButton:(id)sender;
@end
