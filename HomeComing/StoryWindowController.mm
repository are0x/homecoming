//
//  StoryWindowController.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryWindowController.h"

@implementation StoryWindowController
@synthesize view;
@synthesize textfield;
@synthesize image;

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

- (void)windowDidLoad
{
  [super windowDidLoad];
    
  // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
  
  // [view setAction:@selector(turnOverPages:)];
  // view = [[StoryView alloc] initWithFrame:[[self window] frame]];
  // assert([[self window] makeFirstResponder:[self view]]);
  // assert([[self view] becomeFirstResponder]);
  
  NSLog(@"%s\n", [[self window] firstResponder] == view ? "YES" : "NO");
}

- (void)turnOverPages:(id)sender {
  NSLog(@"caught the message\n");
}

@end
