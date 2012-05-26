//
//  ExaminationWindowController.m
//  HomeComing
//
//  Created by arai takahiro on 12/05/26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ExaminationWindowController.h"
#include "Utility.h"
#include "SchoolTableData.h"

using namespace std;

@implementation ExaminationWindowController

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
  return self;
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

-(void)initTextField:(Hero)hero
{
  [SchoolExplanationTextField setStringValue:@""];
  [MessageTextField setStringValue:@""];
  [HeroTextField setStringValue:StringToNSString( hero.ToStr())];  
}
-(void)initEnableTable:(vector<School>)schools
{
  int n = (int)schools.size();
  NSMutableArray *tableData = [[[NSMutableArray alloc] initWithCapacity: 0] retain];
  for(int i=0;i<n;i++){
    SchoolTableData *obj = [[SchoolTableData alloc] init];
    [obj setData:StringToNSString(schools[i].name)
            data:schools[i]];
    [tableData addObject: obj];
  }
  [execution_arraycontroller addObjects: tableData];
  [execution_arraycontroller setSelectionIndex:0]; 
}

-(IBAction)ExecutionButton:(id)sender
{
  
}

-(IBAction)TakeExamButton:(id)sender
{
  
}
-(IBAction)UndoTakeExamButton:(id)sender
{
  
}

@end
