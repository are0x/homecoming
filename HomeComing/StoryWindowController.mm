//
//  StoryWindowController.m
//  HomeComing
//
//  Created by 翔真 石原 on 12/05/23.
//  Copyright (c) 2012年 東京工業大学. All rights reserved.
//

#import "StoryWindowController.h"
#import "Game.h"

#import <vector>

@implementation StoryWindowController
@synthesize view;
@synthesize textfield;
@synthesize image;
@synthesize param_field;

- (id)initWithWindow:(NSWindow *)window
{
  self = [super initWithWindow:window];
  if (self) {
    // Initialization code here.    
  }
  return self;
}

-(id)initWithDelegate:(AppDelegate *)app
{
  appdelegate = app;
  if ( ! (self = [super initWithWindowNibName: @"StoryWindowController"]) ) {
    return nil;
  } // end if
  return self;
}

- (BOOL)loadStory:(std::vector<Action>) actions Heroines:(std::vector<Heroine>) heroines {

  NSLog(@"[loadStory]");
  
  story = Story(actions, heroines);
  story_idx = 0;
  
  return true;
}

- (void)windowDidLoad
{
  [super windowDidLoad];
    
  // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    
  [textfield setStringValue:@"-- 第N世代 HOGE時代 --"];
  [self print_param:appdelegate->game->cur_hero];
}

// todo:
//   アクションに従って主人公のステータスを更新する
//   更新時: 天運が高いほどいい値
//   告白の成功・失敗の判定
//   

- (void) update_param:(Hero)hero action:(Action) act {
  [textfield setStringValue:StringToNSString(act.name)];
  
  hero.update(act);
  
  [self print_param:hero];
}

- (void) print_param:(Hero)hero {
  [param_field setStringValue:StringToNSString(hero.ToStr())];
}

- (bool) propose:(Hero)hero heroine:(Heroine) heroine {
  // std::string params[] = {"知性", "資産", "人間性", "", "", "", "", "", ""};
  bool success = uni(RangeNumber(0, 1)) > 0.7;
  if (success) {
    [textfield setStringValue: [[NSString alloc] initWithFormat:@"%sへのアタックが成功しました！やったね！", 
                                StringToNSString(heroine.name)]];
  } else {
    [textfield setStringValue: [[NSString alloc] initWithFormat:@"%sへのアタックは失敗しました(　☣_ゝ☣)ﾟ",
                                StringToNSString(heroine.name)]];
  }
  // hoge
  return success;
}

- (bool) execute_actions {
  static int idx = 0;
  static int INSTRACTION_SIZE = 2 + (int)story.acts.size() + 1;
  static std::string pre_exec[] = {"-- 第N世代 HOGE時代 --", "行動を開始します。"};
  if(idx < 2) {
    [textfield setStringValue:StringToNSString(pre_exec[idx])];
  } else if( idx < 2 + (int) story.acts.size() ) { 
    [self update_param:appdelegate->game->cur_hero action:story.acts[idx - 2]];
  } else if(idx < INSTRACTION_SIZE) {
    [textfield setStringValue:@"すべての行動が終了しました。"];
  } else {
    return true;
  }
  idx++;
  return false;  
}

// 返り値はおわったかどうか
- (bool) propose_heroines {
  static int idx = 0;
  static int INSTRACTION_SIZE = 1 + (int)story.heroines.size() + 1;
  static std::string pre_exec[] = {"〜,〜' ~ あたっくちゃーんす！！ ~〜〜＊〜"};
  static std::vector<std::string> failure_heroines;
  if(idx < 1) {
    [textfield setStringValue:StringToNSString(pre_exec[idx])];
  } else if( idx < 1 + (int) story.heroines.size() ) { 
    bool success = [self propose:appdelegate->game->cur_hero heroine:story.heroines[idx - 1]];
    if (!success) {
      failure_heroines.push_back(story.heroines[idx - 1].name);
    }
  } else if(idx < INSTRACTION_SIZE) {
    [textfield setStringValue:@"アタックが終了しました。"];
    // しっぱいしたやつをけす
    for(int i = 0; i < failure_heroines.size(); i++) {
      for(int j = 0; j < story.heroines.size(); j++) {
        if (failure_heroines[i] == story.heroines[j].name) {
          story.heroines.erase(story.heroines.begin() + j);
          break;
        }
      }
    }
    appdelegate->game->cur_heroines = story.heroines;
  } else {
    return true;
  }
  idx++;
  return false;  
}

- (IBAction)turnOverPages:(id)sender {
  
  printf("turnOverPages:\n");
  
  if ([self execute_actions]) {
    if([self propose_heroines]) {
      [self closeStory];
    }
  }
  
  /*
  if (story_idx < (int)story.acts.size()) {
    [self update_param: appdelegate->game->cur_hero action:story.acts[story_idx++]];
  } else {
    printf("close\n");
    for(int i = 0; i < (int)story.heroines.size(); i++) {
      
    }
    // closeStory();
  }  
  */  
  
  // NSLog(@"caught the message\n");
}

- (void)closeStory {
  printf("ばいばい\n");
}

@end
