//
//  AppDelegate.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (void)dealloc
{
  [super dealloc];
  delete game;
}
	
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
  // Insert code here to initialize your application
  srand((unsigned int)time(NULL));
  game = new Game();
  command_menu_controller	= [[CommandMenuController alloc] initWithDelegate:self];
  [command_menu_controller showWindow:self];
  // [[[StoryWindowController alloc] initWithDelegate:self] showWindow:self];
  // [[[StoryWindowController alloc] initWithWindowNibName: @"StoryWindowController"] showWindow:self];
}
-(void)NextState
{
  game->NextState();
}
-(void)CalcExecution
{
}
-(void)RunExecution
{
  //結果を計算
  [self CalcExecution];
  //結果を表示するwindowに切り替える
}
-(void)DisplayResultEnd
{
  [self NextState];
  //[command_menu_controller initActionList:game->enable_actions];
  //[command_menu_controller initMeetList:game->enable_heroines];
  [command_menu_controller showWindow:self];
}
-(void)didCommandMenu
{
  [command_menu_controller initMeetList:game->enable_heroines];
  [command_menu_controller initActionList:game->enable_actions];
  [command_menu_controller initTextField:game->cur_hero];
}
@end
