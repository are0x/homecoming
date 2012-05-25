//
//  StoryWindowController.h
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "StoryView.h"
#import "AppDelegate.h"

@class AppDelegate;

@interface StoryWindowController : NSWindowController

{
  AppDelegate* appdelegate;
}

@property (assign) IBOutlet StoryView *view;
@property (assign) IBOutlet NSTextField *textfield;
@property (assign) IBOutlet NSImageView *image;

- (id)initWithDelegate: (AppDelegate *)app;
- (void)turnOverPages:(id)sender;

@end
