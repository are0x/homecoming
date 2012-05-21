//
//  CommandMenuController.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "CommandMenuController.h"

@implementation CommandMenuController

- (id)initWithWindow:(NSWindow *)window
{
    self = [super initWithWindow:window];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}
-(id)initWithDelegate:(AppDelegate *)app{
  appdelegate = app;
  if ( ! (self = [super initWithWindowNibName: @"ゲーム"]) ) {
		return nil;
	} // end if
	return self;
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

@end
