//
//  StoryWindowController.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryWindowController.h"
#import "Game.h"

#import <vector>

@implementation StoryWindowController
@synthesize view;
@synthesize textfield;
@synthesize image;
@synthesize param_field;

- (id)initWithWindow:(NSWindow *)window
{
  self = [super initWithWindow:window];
  if (self) {
    // Initialization code here.    
  }
  return self;
}

-(id)initWithDelegate:(AppDelegate *)app
{
  appdelegate = app;
  if ( ! (self = [super initWithWindowNibName: @"StoryWindowController"]) ) {
    return nil;
  } // end if
  return self;
}

- (BOOL)loadStory:(std::vector<Action>) actions Heroines:(std::vector<Heroine>) heroines {

  NSLog(@"[loadStory]");
  
  story = Story(actions, heroines);
  story_idx = 0;
  
  return true;
}

- (void)windowDidLoad
{
  [super windowDidLoad];
    
  // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.  
}

- (void) update_param:(Hero)hero action:(Action) act {

  [textfield setStringValue:StringToNSString(act.name)];  
  
}

- (IBAction)turnOverPages:(id)sender {
  
  printf("turnOverPages:\n");
  
  if (story_idx < (int)story.acts.size()) {
    [self update_param: appdelegate->game->cur_hero action:story.acts[story_idx++]];
  } else {
    printf("close\n");
    for(int i = 0; i < (int)story.heroines.size(); i++) {
      
    }
    // closeStory();
  }  
  
  // NSLog(@"caught the message\n");
}

- (void)closeStory {
  
}

@end
