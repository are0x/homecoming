//
//  AppDelegate.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Game.h"
#import <cstdlib>
#import "CommandMenuController.h"
#import "StoryWindowController.h"

@class CommandMenuController;

@interface AppDelegate : NSObject <NSApplicationDelegate>{
  Game *game;
  CommandMenuController *command_menu_controller;
}
-(void)NextState;
-(void)CalcExecution;
-(void)RunExecution;
-(void)DisplayResultEnd;
@end
