//
//  CWLivessTimeoutAlert.h
//  CloudWalkSDKDemo
//
//  Created by Noctis on 2020/5/11.
//  Copyright © 2020 Cloudwalk. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWLivessTimeoutAlert : UIView

- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message;
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message leftBtnTitle:(NSString *)leftBtnTitle rightBtnTitle:(NSString *)rightBtnTitle;


@property (nonatomic, copy) void(^onCancel)(void);
//重试
@property (nonatomic, copy) void(^onRetry)(void);
//相机设置
@property (nonatomic, copy) void(^goSetting)(void);


@end

NS_ASSUME_NONNULL_END
