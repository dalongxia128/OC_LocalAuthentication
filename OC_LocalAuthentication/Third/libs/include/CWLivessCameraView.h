//
//  CWLivessCameraView.h
//  CloudwalkFaceSDKDemo
//
//  Created by 马辉 on 2021/2/8.
//  Copyright © 2021 DengWuPing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWLivessCameraView : UIView

@property (nonatomic, strong) UIView *cameraView;
@property (nonatomic, copy) void(^outTimeCallBack)(void);
@property (nonatomic, copy) void(^cancelCallBack)(void);
@property (nonatomic, copy) void(^switchCameraBlock)(void);
/**
 是否在摄像框显示动作提示
 */
@property(nonatomic,assign) BOOL showActionInCameraArea;
@property(nonatomic, assign) NSInteger circleDiameter;//prelayer区域
@property(nonatomic, assign) NSInteger actionViewMargin;//活动图距离圆环的高度

//开始活检外圈动画
- (void)pageStartAnimation;

//动作的动画
- (void)actionsAnimation:(NSArray *)actions;
//切换动作
- (void)actionStepIndex:(NSInteger)index;

- (void)stopAllTimer;
- (void)creatTimerWithTime:(NSInteger)time;

//活检过程提示
- (void)showTipText:(NSString *)text;

- (void)hiddenTipView:(BOOL)hidden;
- (void)stopAnimations;

//动作结束进度条动画
- (void)circleProgressAnimation;

- (void)showHackCheckingLabel;
- (void)showCountDownLabel:(BOOL)show;
- (void)showSwitchCameraButton:(BOOL)show;

- (void)changeErrorTipArea:(NSString *)tipName;
@end

NS_ASSUME_NONNULL_END
