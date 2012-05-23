//
//  StoryView.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryView.h"

@implementation StoryView

@synthesize storyIndex = _storyIndex;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Drawing code here.
}

- (void) mouseDown:(NSEvent *)theEvent {
  [self turnOverPages: theEvent];
}

- (void) keyDown:(NSEvent *)theEvent {
  [self turnOverPages: theEvent];
}

- (void) turnOverPages:(NSEvent *)theEvent {
  printf("turn over the page!\n");
  _storyIndex++;
}

@end
