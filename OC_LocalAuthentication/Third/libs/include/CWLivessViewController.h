//
//  LiveDetectViewController.h
//  CloudwalkFaceSDKDemo
//
//  Created by DengWuPing on 16/5/12.
//  Copyright © 2016年 DengWuPing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CWLivessViewControllerDelegate.h"
#import "CWLivessViewManager.h"
#import "CWCamera.h"
#import "CloudwalkFaceSDKDef.h"
#import "CWDataProcessUtil.h"
//#import "CWURLParam.h"

#define CWHackResultNotifacation @"CWHackResultNotifacation" // 后端防hack通知名称

typedef NS_ENUM(NSInteger,CWHackDetectLevel){
    CWHackDetectBankend=0, //后端(在线)方式
    CWHackDetectFront = 1, //前端(离线/本地)方式
    CWHackDetectNone=2     //不做防hack操作
};

typedef NS_ENUM(NSInteger,CWErrorTipsStyle){
    CWErrorTipsAlertStyle = 0, //弹窗提示
    CWErrorTipsViewStyle  = 1, //页面提示
};

@interface CWLivessViewController : UIViewController


@property (nonatomic, weak) id <CWLivessViewControllerDelegate> _Nullable delegate;
/**
 管理View和事件的中间类
 */
@property (nonatomic, strong) CWLivessViewManager * _Nonnull viewManager ;

/**
 云从科技获取的授权码
 */
@property (nonatomic, strong) NSString *  _Nonnull authCodeString;
/**
 云从科技获取的加密之后的bundleID
 */
@property (nonatomic, strong) NSString *  _Nonnull encryptPackageName;

/**
 活体动作数组，默认设置为 (张嘴  眨眼  左转头 右转头)
 @[CWLiveActionBlink,
 CWLiveActionOpenMouth,
 CWLiveActionHeadLeft,
 CWLiveActionHeadRight]
 */
@property (nonatomic, strong) NSArray<CWLiveActionType>  * _Nullable allActionArry;

/**
 活体动作检测超时时间  默认设置为8秒  设置为0的时候不显示倒计时
 */
@property (nonatomic, assign) NSInteger livessTime;

/**
活体动作准备阶段超时时间 设置为0的时候不显示倒计时
*/
@property (nonatomic, assign) NSInteger prepareTime;

/**
 活体检测动作个数 默认设置为3个( 0 <= livessNumber   <= allActionArry.count )
 */
@property (nonatomic, assign) NSInteger livessNumber;
/**
 是否播放提示语音  默认为YES
 */
@property (nonatomic, assign) BOOL  isPlayAudio;
/**
 是否显示活体检测引导页面  默认为YES
 */
@property (nonatomic, assign) BOOL isShowGuideView;
/**
 是否显示活体检测结果页面 (检测失败的View )  默认为YES
 */
@property (nonatomic, assign) BOOL isShowFailResultView;
/**
 是否显示活体检测结果页面 (检测成功的View )  默认为YES
 */
@property (nonatomic, assign) BOOL isShowSuccessResultView;

/**
 是否使用后置摄像头 默认为NO,使用前置摄像头
 */
@property (nonatomic, assign) BOOL isUserBackCamera;

/**
 选择防hacker的方式 默认CWHackDetectBankend
 */
@property (nonatomic, assign) CWHackDetectLevel hackerDetectType;

/**
 是否打开log，默认关闭
 备注：  发版需关闭log
 */
@property (nonatomic, assign) BOOL isOpenLog;

@property (nonatomic, assign) UIStatusBarStyle  statusBarStyle; //顶部状态栏颜色
/**
 是否按照指定动作顺序
 */
@property (nonatomic, assign) BOOL  isRandomActions;


/**
 错误提示方式
 */
@property (nonatomic, assign) CWErrorTipsStyle errorTipsStyle;


/**
 是否开启截屏
 */
@property (nonatomic, assign) BOOL  isOpenSnapScreenImage;

/**
 越狱情况下是否立即终止活检
 */
@property (nonatomic, assign) BOOL  isRootStopLivess;

@property (nonatomic,assign) BOOL isRecord;//是否在活体检测的过程中录制视频  默认为NO
@property (nonatomic,strong) NSString * _Nullable videoPath;//视频存储地址 默认地址为  "~/Documents/cwLivessDetect.mp4"

/**
 连续(faceMissingInterval)毫秒内检测不到人脸，报人脸丢失。默认值为100ms
 */
@property(nonatomic, assign) CGFloat faceMissingInterval;

// 允许失败的次数
@property(nonatomic,assign) NSInteger retryCount;

//背景颜色
@property(nonatomic,strong) NSArray * _Nullable backgroundColorList;
//闪烁的总时长
@property(nonatomic,assign) CGFloat twinkInterval;
//是否开启光线活体模式
@property(nonatomic,assign) BOOL openLightLivessMode;

/**
 如果需要重写UI，继承CWLivessViewManager类，并把新的类名传进来，部分重写继承CWLivessSubViewManager
*/
@property(nonatomic,strong) NSString * _Nullable customUIClassName;

/**
 加密方式
*/
@property(nonatomic,assign) CWEncryptionStyle  encryptionStyle;
/**
 加密key
*/
@property(nonatomic,strong) NSString  * _Nullable  encryptionKey;

@property(nonatomic,assign) BOOL isAIAntifraud; // 是否反欺诈

//@property(nonatomic,strong) CWURLParam * _Nonnull antifraudRequestParma; // 反欺诈借口参数

//是否禁止多人检测
@property(nonatomic,assign) BOOL isForbidMultipleFaceDetect;

/**
 是否在摄像框显示动作提示
 */
@property(nonatomic,assign) BOOL showActionInCameraArea;
//活体数据压缩率
@property(nonatomic,assign) CGFloat imageCompressionRatio;

//是否默认有眨眼动作
@property(nonatomic,assign) BOOL isAddBlinkAction;

//3个及以上的动作是否有默认有张嘴和眨眼动作
@property(nonatomic,assign) BOOL defaultMouthAndBlinkAction;


//最大报文限制，默认为500k。 最小设置值为300k，若设置小于300k则会设置失败。
@property(nonatomic,assign) CGFloat maxMessageSize ;

/**
 是否显示切换相机前后置按钮  默认为NO
 */
@property (nonatomic,assign) BOOL isShowSwitchCamera;

/**
 获取SDK版本号方法
 */
+ (NSString * _Nonnull)cwGetSDKVersion;


@end
