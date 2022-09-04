//
//  CWLivessGuideView.h
//  CloudWalkSDKDemo
//
//  Created by Noctis on 2020/5/9.
//  Copyright © 2020 Cloudwalk. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWGuideView : UIView

@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UIButton *startButton;
@property (nonatomic, copy) void(^startLivessBlock)(void);
@property (nonatomic, copy) void(^cancelLivessBlock)(void);

@end

NS_ASSUME_NONNULL_END
