//
//  StoryView.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

//
// Class StoryView:
//
// 

#import <Cocoa/Cocoa.h>
#import <vector>
#import <string>

class Story;

@interface StoryView : NSView

{
  int _storyIndex;
  Story* story;
}

@property int storyIndex;

- (void) turnOverPages:(NSEvent *)theEvent;

@end
