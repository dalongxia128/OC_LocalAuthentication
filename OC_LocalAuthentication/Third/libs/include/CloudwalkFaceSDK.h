//
//  CloudwalkFaceSDK.h
//  CloudwalkFaceSDK
//
//  Created by DengWuPing on 16/5/10.
//  Copyright © 2016年 DengWuPing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "CloudwalkFaceSDKDef.h"
#import "CloudwalkSampleFaceDetectResultModel.h"


//人脸检测和活体检测的代理方法
@protocol CloudwalkFaceSDKDelegate <NSObject>

@optional
/**
 活体检测代理方法
 @param contextType 活体动作通过与否的编码
 @param imageData 活体通过时的人脸图片数据 JPG格式的
 @param message 当前动作通过与否的提示信息
 */
-(void)cwLivessInfoCallBack:(CwLiveCode)contextType
                  liveImage:(NSData  * _Nullable)imageData
                    message:(NSString * _Nullable)message;

/**
 人脸信息返回代理方法
 @param personsArry 人脸信息字典
 */
-(void)cwFaceInfoCallBack:(NSArray *_Nullable)personsArry;

@end


@interface CloudwalkFaceSDK : NSObject

@property(nonatomic, weak) id <CloudwalkFaceSDKDelegate> _Nullable delegate;
@property(nonatomic, assign) BOOL isTrack;
@property(nonatomic, assign) CGFloat faceMissingInterval;
//设备是否安全。安全传入0, 风险设备传入1
@property(nonatomic, assign) CGFloat riskDevice;

//禁止多人检测
@property(nonatomic, assign) BOOL isForbidMultipleFaceDetect;

//活体数据压缩率
@property(nonatomic,assign) CGFloat imageCompressionRatio;

//最大报文限制，默认为500k。 最小设置值为300k，若设置小于300k则会设置失败。
@property(nonatomic,assign) CGFloat maxMessageSize ;

/**
 单例方法
 @return 返回CloudwalkFaceSDK的一个单例
 */
+ (instancetype _Nonnull)shareInstance;

/**
 人脸SDK初始化
 @param AuthCodeStr 授权码
 @return 0成功 非0失败 错误码
 */
- (NSInteger)cwInit:(NSString * _Nonnull)AuthCodeStr;

/**
 算法参数设置
 @param maxFaceNumber 设置最大检测人脸个数
 @param minSize 检测的最小人脸框在视频帧中的像素数 默认设置为160 单位像素 视频帧中的像素数
 @param maxSize 检测的最小人脸框在视频帧中的像素数 默认设置为260 单位像素 视频帧中的像素数
 @param perfmonLevel 效率等级1-6，默认值为6
 @return 0成功，非0错误码
 */
- (NSInteger)cwSetParamMaxFaceNumber:(int)maxFaceNumber
                         minFaceSize:(int)minSize
                         maxFaceSize:(int)maxSize
                        perfmonLevel:(int)perfmonLevel; //建议使用默认参数


/// 当前人脸信息中是否拥有人脸图片的标记位 默认为NO
//@property (nonatomic, assign, readonly) BOOL makeFaceImageForFaceInfo;

/// 人脸信息回调中添加人脸图片信息
- (void)cwAddFaceImageToFaceInfo;

/// 人脸信息移除人脸图片信息
- (void)cwRemoveFaceImageToFaceInfo;

/**
 启动活体检测
 @param detectType 传入活体动作的类型
 @return 0 成功
 */
- (NSInteger)cwStartLivess:(CWLiveDetectType)detectType;

/**
 停止活体检测
 */
- (void)cwStoptLivess;

/**
 push摄像头获取的每一帧图片数据
 @param bufferType 视频流格式 CWFaceBufferBGRA,// BGRA    kCVPixelFormatType_32BGRA
 @param direction 视频流数据
 @param sampleBuffer 屏幕方向
 @return 返回0成功
 */
- (NSInteger)cwPushFrame:(CWFaceBufferType)bufferType
         screenDirection:(CWScreenDirection)direction
             frameBuffer:(_Nonnull CMSampleBufferRef)sampleBuffer;


/**
 push摄像头获取的每一帧图片数据
 @param bufferType 视频流格式 CWFaceBufferBGRA,// BGRA    kCVPixelFormatType_32BGRA
 @param direction 视频流数据
 @param screenRGB 屏幕RGB
 @param sampleBuffer 屏幕方向
 @return 返回0成功
 */
- (NSInteger)cwPushFrame:(CWFaceBufferType)bufferType
         screenDirection:(CWScreenDirection)direction
               screenRGB:(NSArray *)screenRGB
             frameBuffer:(_Nonnull CMSampleBufferRef)sampleBuffer;


/**
 获取最佳人脸
 @param block 获取数据的block
 block param
 bestFaceData 最佳人脸裁剪图片
 originalData 最佳人脸原始图片
 nextImageData 最佳人脸下一帧图片
 hackStrng 防hack拼接字符串
 sdkCode SDK转换码
 */
- (void)cwGetBestFaceImage:(void(^_Nullable)(NSData *_Nullable bestFaceData,
                                             NSData *_Nullable originalData,
                                             NSData *_Nullable nextImageData,
                                             NSString *_Nullable hackStrng,NSInteger sdkCode))block;

/**
 获取最佳人脸下一帧 以及关键点角度 用作后端防攻击 （需要在cwGetBestFaceImage之后调用）
 @param block 获取数据的block
 block param
 originalData 最佳人脸原始图片
 bestFaceData 最佳人脸裁剪图片
 keyPointArray 最佳人脸原始图片关键点数组
 headPoseArray 最佳人脸图片头部角度数组、pitch俯仰角、yaw水平角度 roll偏转角度
 */
- (void)cwGetBestFaceNextFrame:(void(^_Nullable)(NSData * _Nullable originalData,
                                                 NSData *_Nullable bestFaceData,
                                                 NSArray * _Nullable keyPointArray,
                                                 NSArray * _Nullable headPoseArray))block;

/**
 最佳人脸图片防攻击检测
 @return 0活体  非0 攻击
 */
-(NSInteger)cwGetHackerInfoByBestImage;

/**
 动作通过后防攻击检测
 @return 0活体  非0 攻击
 */
-(NSInteger)cwVerifyFaceConhlist;

/**
 图片检测
 @param faceImage 人脸图片JPG
 @param block 图片质量检测结果返回block
 block param
 score 图片质量分数
 idImage 抠取的人脸图像
 */
- (void)cwFaceImageQuality:(UIImage * _Nonnull)faceImage
                completion:(void(^_Nullable)(double score,
                                             UIImage *  _Nullable idImage,
                                             CGRect  rect))block;

/**
 释放资源（在退出页面时调用销毁，和cwinit配套使用）
 */
- (void)cwDestroy;

/**
 获取SDK版本信息
 @return 返回算法SDK版本信息
 */
- (NSString * _Nullable)cwGetVersion;


/**
 开启算法日志，正式版一定要删掉非常耗性能

 */
- (void)cwGetLogAndSaveImageInfo;

/**
 是否严格要求动作一致性
 */
- (void)setMaxQualityAction:(BOOL)maxQualityAction;

/**
 图片检测
 @param detectImage 人脸图片
 @param maxFaceCount 最大检测出的人脸数,最大值为5
 @param block 检测完成回调
 faces 检测到的人脸数组 将会返回所有检测到的人脸和其信息, 图片人脸数量超过最大人脸数时, 优先返回图片中的最大人脸
 人脸分数推荐可用范围0.65-1.0
 */
-(void)cwDetectFacesForImage:(UIImage *_Nonnull)detectImage
            withMaxFaceCount: (int) maxFaceCount
               andCompletion:(void (^_Nullable)(NSArray<CloudwalkSampleFaceDetectResultModel *> * _Nonnull))block;
/**
 转换错误码到对应的文字
 */
- (NSString *_Nullable)cwSwitcErrorCodeToMessage: (CwLiveCode)statusCode;
/**
 验证包名是否符合
 */
- (BOOL)verifyPackageName:(NSString *_Nullable)encryptPackageName;

//检测阶段重置检测状态
- (void)resetSampleBufferStatusWithActionName:(NSString *_Nullable)actionName;
@end

