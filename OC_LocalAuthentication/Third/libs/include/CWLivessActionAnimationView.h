//
//  CWLivessActionAnimationView.h
//  CloudWalkSDKDemo
//
//  Created by Noctis on 2020/5/8.
//  Copyright © 2020 Cloudwalk All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CloudwalkFaceSDKDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface CWLivessActionAnimationView : UIView

-(void)setActions: (NSArray<CWLiveActionType> *)actionsArray;

-(void)moveToAction: (NSInteger) index;

-(void)startAnimation;

-(void)stopAnimation;

@end

NS_ASSUME_NONNULL_END
