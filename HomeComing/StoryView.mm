//
//  StoryView.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryView.h"

@implementation StoryView

@synthesize action;
@synthesize target;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
      // Initialization code here.
      printf("Im View\n");
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Drawing code here.
}

- (void) mouseDown:(NSEvent *)theEvent {
  [self _turnOverPages: theEvent];
}

- (void) keyDown:(NSEvent *)theEvent {
  [self _turnOverPages: theEvent];
}

- (void) _turnOverPages:(NSEvent *)theEvent {
  
  if ([theEvent type] == NSKeyDown) {
    NSLog(@"%d\n", [theEvent keyCode]);
  } else {
    NSLog(@"Mouse\n");
  }
    
  printf("send=%d\n", [NSApp sendAction:@selector(turnOverPages:) to:target from:self]);
}

- (BOOL) acceptsFirstResponder {
  // printf("accepts\n");
  return YES;
}

- (BOOL) becomeFirstResponder {
  return YES;
}

@end
