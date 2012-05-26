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
#import "ExaminationWindowController.h"
#include <vector>

@class CommandMenuController;
@class StoryWindowController;

@interface AppDelegate : NSObject <NSApplicationDelegate>{
  @public
  Game *game;
  CommandMenuController *command_menu_controller;
  StoryWindowController *story_window_controller;
  ExaminationWindowController * examination_window_controller;
}
-(void)NextState;
-(void)RunExecution:(std::vector<Action>)actions Heroines:(std::vector<Heroine>)heroines;
-(void)DisplayResultEnd;
-(void)didCommandMenu;
@end
