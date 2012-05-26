//
//  StoryWindowController.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryWindowController.h"

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
  
  
  
  return true;
}

- (void)windowDidLoad
{
  [super windowDidLoad];
    
  // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
  
  [view setAction:@selector(turnOverPages:)];
  [view setTarget:self];
  // view = [[StoryView alloc] initWithFrame:[[self window] frame]];
  // assert([[self window] makeFirstResponder:[self view]]);
  // assert([[self view] becomeFirstResponder]);  
  
  NSLog(@"%s\n", [[self window] firstResponder] == view ? "YES" : "NO");
  [[self window] setNextResponder:(NSResponder *)self];
  // assert([[self window] nextResponder] == self);

}

- (IBAction)turnOverPages:(id)sender {
  // NSLog(@"caught the message\n");
}

- (void)closeStory {
}

@end
