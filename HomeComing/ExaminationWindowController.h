//
//  ExaminationWindowController.h
//  HomeComing
//
//  Created by arai takahiro on 12/05/26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "Hero.h"
#include "School.h"
#include <vector>

@class AppDelegate;
@interface ExaminationWindowController : NSWindowController{
  
  IBOutlet NSTextField *SchoolExplanationTextField;
    
  IBOutlet NSTextField *MessageTextField;
  
  IBOutlet NSTextField *HeroTextField;
  IBOutlet NSArrayController *enable_arraycontroller;
  IBOutlet NSArrayController *execution_arraycontroller;
  AppDelegate *appdelegate;
}
-(id)initWithDelegate:(AppDelegate *)app;
-(void)initTextField:(Hero)hero;
-(void)initEnableTable:(std::vector<School>)schools;
-(IBAction)ExecutionButton:(id)sender;
-(IBAction)TakeExamButton:(id)sender;
-(IBAction)UndoTakeExamButton:(id)sender;

@end
