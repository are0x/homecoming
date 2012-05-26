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
    ActionTableData *obj = [[ActionTableData alloc] init];
    [obj setData: StringToNSString(actions[i].name)
            data: actions[i]];
    [tableData addObject: obj];
  }
  [action_array_controller addObjects: tableData];
  [action_array_controller setSelectionIndex:0];
  NSArray *ta = [action_array_controller selectedObjects];
  ActionTableData *obj = [ta objectAtIndex:0];
  Action t = [obj data];
  [actionTextField setStringValue:StringToNSString(t.ToStr())];
}
-(void)initMeetList:(std::vector<Heroine>)heroines{
  int n = (int)heroines.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    HeroineTableData *obj = [[HeroineTableData alloc] init];
    [obj setData:StringToNSString(heroines[i].name)
            data:heroines[i]];
    [tableData addObject: obj];
  }
  [meet_array_controller addObjects: tableData];
  [meet_array_controller setSelectionIndex:0];
  NSArray *ta = [meet_array_controller selectedObjects];
  HeroineTableData *obj = [ta objectAtIndex:0];
  Heroine t = [obj data];
  [meetHeroinrTextfield setStringValue:StringToNSString(t.ToStr())];
}
-(void)initTextField:(Hero)hero
{
  [meetHeroinrTextfield setStringValue:@""];
  [attackHeroinTextfield setStringValue:@""];
  [heroTextfield setStringValue:StringToNSString(hero.ToStr())];
}
-(void)tableViewSelectionDidChange:(NSNotification *)aNotification{
  id object = [aNotification object];
  if(object == meetTableView){
    NSArray *ta = [meet_array_controller selectedObjects];
    HeroineTableData *obj = [ta objectAtIndex:0];
    Heroine t = [obj data];
    [meetHeroinrTextfield setStringValue:StringToNSString(t.ToStr())];
  }
  else if(object == attackTableView){
    NSArray *ta = [attack_array_controller selectedObjects];
    HeroineTableData *obj = [ta objectAtIndex:0];
    Heroine t = [obj data];
    [attackHeroinTextfield setStringValue:StringToNSString(t.ToStr())];
  }
  else if(object == actionTableView){
    NSArray *ta = [action_array_controller selectedObjects];
    ActionTableData *obj = [ta objectAtIndex:0];
    Action t = [obj data];
    [actionTextField setStringValue:StringToNSString(t.ToStr())];
  }
}
-(IBAction)attackButton:(id)sender
{
  NSArray *ta = [meet_array_controller selectedObjects];
  HeroineTableData *obj = [ta objectAtIndex:0];
  [attack_array_controller addObject:obj];
  [meet_array_controller removeObject:obj];
  ta = [meet_array_controller selectedObjects];
  obj = [ta objectAtIndex:0];
  if(obj != nil){
    [meetHeroinrTextfield setStringValue:StringToNSString([obj data].ToStr())];
  }
}
-(IBAction)undoAttackButton:(id)sender
{
  NSArray *ta = [attack_array_controller selectedObjects];
  HeroineTableData *obj = [ta objectAtIndex:0];
  [meet_array_controller addObject:obj];
  [attack_array_controller removeObject:obj];
  ta = [attack_array_controller selectedObjects];
  obj = [ta objectAtIndex:0];
  if(obj != nil){
    [attackHeroinTextfield setStringValue:StringToNSString([obj data].ToStr())];
  }
}
-(IBAction)executionButton:(id)sender
{
  vector<Heroine> vh;
  for (HeroineTableData *obj in attack_array_controller.arrangedObjects)
  {
    vh.push_back([obj data]);
  }
  vector<Action> va;
  for (ActionTableData *obj in execution_array_controller.arrangedObjects)
  {
    va.push_back([obj data]);
  }
  [appdelegate RunExecution:va Heroines:vh];
}
-(IBAction)actionButton:(id)sender
{
  NSArray *ta = [action_array_controller selectedObjects];
  ActionTableData *obj = [ta objectAtIndex:0];
  [execution_array_controller addObject:obj];
  [action_array_controller removeObject:obj];
  ta = [action_array_controller selectedObjects];
  obj = [ta objectAtIndex:0];
  if(obj != nil){
  [actionTextField setStringValue:StringToNSString([obj data].ToStr())];
  } 
}

-(IBAction)undoActionButton:(id)sender{
  NSArray *ta = [execution_array_controller selectedObjects];
  ActionTableData *obj = [ta objectAtIndex:0];
  [action_array_controller addObject:obj];
  [execution_array_controller removeObject:obj];
  ta = [action_array_controller selectedObjects];
  obj = [ta objectAtIndex:0];
  if(obj != nil){
    [actionTextField setStringValue:StringToNSString([obj data].ToStr())];
  }
}
@end
