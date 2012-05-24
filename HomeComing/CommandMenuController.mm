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
#include <iostream>

using namespace std;

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
  [appdelegate didCommandMenu];
}
-(void)initActionList:(std::vector<Action>)actions{
  int n = (int)actions.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    ActionTableData *obj = [[ActionTableData alloc] initWithAction:actions[i]];
    [tableData addObject: obj];
  }
  [action_array_controller addObjects: tableData];
  //[action_array_controller setSelectionIndex:0];
  
}
-(void)initMeetList:(std::vector<Heroine>)heroines{
  int n = (int)heroines.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    HeroineTableData *obj = [[HeroineTableData alloc] init];
    [obj setData:StringToNSString(heroines[i].name)
            data:heroines[i]];
    [tableData addObject: obj];
    NSLog(obj.display_name);
  }
  [meet_array_controller addObjects: tableData];
  [meet_array_controller setSelectionIndex:0];
}
-(void)tableViewSelectionDidChange:(NSNotification *)aNotification{
 [aNotification object];
  NSLog(@"tableViewSelectionDidChange");
}
-(IBAction)attackButton:(id)sender
{
  NSArray *ta = [meet_array_controller selectedObjects];
  HeroineTableData *obj = [ta objectAtIndex:0];
  [attack_array_controller addObject:obj];
  [meet_array_controller removeObject:obj];
}
-(IBAction)undoAttackButton:(id)sender
{
  NSArray *ta = [attack_array_controller selectedObjects];
  HeroineTableData *obj = [ta objectAtIndex:0];
  [meet_array_controller addObject:obj];
  [attack_array_controller removeObject:obj];
}

@end
