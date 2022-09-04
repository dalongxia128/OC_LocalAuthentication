//
//  CWDeviceStatusManager.h
//  CloudWalkSDKDemo
//
//  Created by 马辉 on 2021/1/21.
//  Copyright © 2021 Cloudwalk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CWDeviceStatusManager : NSObject

+ (instancetype)defaultManager;
/**
 判断设备是否越狱
 */
+ (BOOL)isDeviceEscape;
/*!
 @method
 @abstract 逐步设置亮度
 */
+ (void)graduallySetBrightness:(CGFloat)value MainBrightness:(CGFloat)mainBrightness;

/*!
 @method
 @abstract 逐步恢复亮度
 */
+ (void)graduallyResumeBrightness;



+ (NSString *)cw_getUUID;

@end

NS_ASSUME_NONNULL_END
