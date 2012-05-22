//
//  CommandMenuController.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/21.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "CommandMenuController.h"
#import "ActionTableData.h"
#import "HeroineTableData.h"

@implementation CommandMenuController

-(id)initWithDelegate:(AppDelegate *)app{
  appdelegate = app;
  if ( ! (self = [super initWithWindowNibName: @"CommandMenu"]) ) {
		return nil;
	} // end if
	return self;
}


- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}
-(void)initActionList:(std::vector<Action>)actions{
  int n = (int)actions.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    ActionTableData *obj = [[ActionTableData alloc] initWithAction:actions[i]];
    [tableData addObject: obj];
  }
  [action_array_controller addObjects: tableData];
  [action_array_controller setSelectionIndex:0];
  
}
-(void)initMeetList:(std::vector<Heroine>)heroines{
  int n = (int)heroines.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    HeroineTableData *obj = [[HeroineTableData alloc] initWithHeroine:heroines[i]];
    [tableData addObject: obj];
  }
  [action_array_controller addObjects: tableData];
  [action_array_controller setSelectionIndex:0];
}
@end
