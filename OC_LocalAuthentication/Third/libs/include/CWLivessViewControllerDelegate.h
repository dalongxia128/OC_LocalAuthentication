//
//  CWLivessViewControllerDelegate.h
//  CloudwalkFaceSDKDemo
//
//  Created by 马辉 on 2021/1/26.
//  Copyright © 2021 DengWuPing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CWNormalMacroDefine.h"
#import "CWLivessInfo.h"

NS_ASSUME_NONNULL_BEGIN


@protocol CWLivessViewControllerDelegate <NSObject>

@optional

/**
 检测动作取消
 */
- (void)onLivenessCancel;

/**
 检测退出页面返回对应的错误code码
 */
- (void)onLivenessCancelWithErrorCode:(NSInteger)code;


/**
 活体检测成功

 @param viewController 活体检测 UI Controller
 @param livessInfo 存放活体数据
 */
- (void)viewController:(UIViewController *_Nullable)viewController
            livessInfo:(CWLivessInfo *)livessInfo;


/**
 活体检测成功

 @param viewController 活体检测 UI Controller
 @param bestFaceOriginData 最佳人脸原图的数据
 @param backendHackData 用于后端防hack的数据
 @param resultDataDict 其他的数据  ScreenImage:截屏数据  bestFaceCropData：裁剪图   VideoData：录制的视频数据  AudioData：声纹数据
 */
- (void)viewController:(UIViewController *_Nullable)viewController
    bestFaceOriginData:(NSData *_Nullable)bestFaceOriginData
            resultDataDict:(NSDictionary *)resultDataDict
       backendHackData:(NSString *_Nullable)backendHackData CW_FUNCTION_DEPRECATED("已过时，请及时更换使用新方法 - (void)viewController:(UIViewController *_Nullable)viewController livessInfo:(CWLivessInfo *)livessInfo");;


/**
 活体检测失败

 @param viewController 活体检测 UI Controller
 @param errCode 错误码
 */
- (void)viewController:(UIViewController *_Nullable)viewController
livenessDetectionFailed:(NSInteger)errCode;

@end

NS_ASSUME_NONNULL_END
