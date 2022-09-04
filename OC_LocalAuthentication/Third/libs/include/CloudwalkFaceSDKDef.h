//
//  CloudwalkFaceSDKLivessDef.h
//  CloudwalkFaceSDK
//
//  Created by DengWuPing on 17/1/10.
//  Copyright © 2017年 DengWuPing. All rights reserved.
//

#ifndef CloudwalkFaceSDKLivessDef_h
#define CloudwalkFaceSDKLivessDef_h
#import <AVFoundation/AVFoundation.h>

#if defined(__cplusplus)
#define CWF_EXPORT extern "C"
#else
#define CWF_EXPORT extern
#endif

//活体检测动作
typedef NSString *CWLiveActionType NS_STRING_ENUM;
    CWF_EXPORT CWLiveActionType const CWLiveActionHeadLeft;                         // 左转头
    CWF_EXPORT CWLiveActionType const CWLiveActionHeadRight;                        // 右转头
    CWF_EXPORT CWLiveActionType const CWLiveActionOpenMouth;                        // 张嘴
    CWF_EXPORT CWLiveActionType const CWLiveActionBlink;                            // 眨眼
    CWF_EXPORT CWLiveActionType const CWLiveActionLight;                            // 闪光

//人脸信息字典key
typedef NSString *CWLiveActionFaceInfoKey NS_STRING_ENUM;
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceKeyptScoreKey;                   // 关键点评分
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFacePointKey;                        // 关键点
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceRectKey;                         // 人脸框坐标
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceTrackIdKey;                      // 跟踪ID

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceHeadPitchKey;                    // 是否抬头、低头
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceHeadYawKey;                      // 是否左右转头
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceMouthOpenKey;                    // 是否张嘴
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceBlinkKey;                        // 是否眨眼

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceQualityScoreKey;                 // 人脸质量分数
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceClarityKey;                      // 人脸清晰度
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceBrightnessKey;                   // 亮度
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceFaceImageKey;                    // 人脸图片

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceHeadYawDegreeKey;                // 转头的角度 左转为正
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceHeadPitchDegreeKey;              // 抬头、低头的角度 抬头为正
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceHeadRollDegreeKey;               // 歪头角度 顺时针为正

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceMouthOpeningKey;                 // 张嘴分数， 越大表示越可能张嘴，推荐范围0.0-0.5
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceLeftEyeOpeningKey;               // 左眼睁眼分数， 越大表示左眼越可能是睁眼，推荐范围0.5-1.0
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceRightEyeOpeningKey;              // 右眼睁眼分数， 越大表示右眼越可能是睁眼，推荐范围0.5-1.0
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceBlackFrameGlassKey;              // 戴黑框眼镜置信度，越大表示戴黑框眼镜的可能性越大，推荐范围0.0-0.5
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceSunglassKey;                     // 戴墨镜的置信分，越大表示戴墨镜的可能性越大，推荐范围0.0-0.5
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceSkinScoreKey;                    // 肤色分

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceProceduremaskKey;                // 口罩
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceOcclusionScoreKey;               // 遮挡分

    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceFaceltKey;                        // 防脸优 flag  返回1开始活体检测
    CWF_EXPORT CWLiveActionFaceInfoKey const CWFaceLivessAttackKey;                  // 活体检测攻击码

//活体等级
typedef NS_ENUM(NSInteger,CWLiveDetectlLevel){
    CWLiveDetectLow=0,       // 活体检测难度低
    CWLiveDetectStandard,    // 活体检测难度中等    转头区分左右、上下  检测出当前动作则为通过
    CWLiveDetectLevelHigh    // 活体检测难度高      严格动作控制、检测出与当前提示不同的动作则为失败
};

//活体检测动作定义
typedef NS_ENUM(NSInteger,CWLiveDetectType) {
    CWLivePrepare,              // 准备阶段,
    CWLiveLiveLight,            //光线阶段
    CWLiveHeadTurnLeft,         // 向左转头
    CWLiveHeadTurnRight,        // 向右转头
    CWLiveHeadRise,             // 向上抬头
    CWLiveHeadDown,             // 向下低头
    CWLiveOpenMouth,            // 张嘴
    CWLiveBlink,                // 眨眼
};

//视频流格式
typedef NS_ENUM(NSInteger,CWFaceBufferType) {
    CWFaceBufferBGRA=1,         // 视频流格式 BGRA    kCVPixelFormatType_32BGRA
    CWFaceBufferYUV420,         // 视频流格式 YUV420  kCVPixelFormatType_420YpCbCr8BiPlanarFullRange
};

#pragma mark----------- 屏幕方向
/******************屏幕方向*******************/
typedef NS_ENUM(NSInteger,CWScreenDirection) {
    CWScreenDirectionPortrait=1,            //  竖直
    CWScreenDirectionPortraitUpsideDown,    //  倒置
    CWScreenDirectionLeft,                  //  横屏向左
    CWScreenDirectionRight,                 //  横屏向右
};

#pragma mark----------- 活体检测准备阶段状态码
/******************活体检测准备阶段状态码*******************/
typedef NS_ENUM(NSInteger,CW_PrepareFaceInfo){
    CW_FACE_PREPARE_WAITTING = 0,           // 等待
    CW_FACE_PREPARE_TOOFAR = 2,             // 人脸距离摄像头太远
    CW_FACE_PREPARE_TOOCLOSE = 3,           // 人脸距离摄像头太近
    CW_FACE_PREPARE_FRONTAL = 4,            // 人脸没有正对屏幕
    CW_FACE_PREPARE_STABLE = 5,             // 人脸晃动
    CW_FACE_PREPARE_TOODARK = 6,            // 光线太暗
    CW_FACE_PREPARE_BRIGHT = 7,             // 光线太亮
    CW_FACE_PREPARE_NOTCENTER = 8,          // 人脸不居中
    CW_FACE_PREPARE_NOFACE = 9,             // 检测不到人脸
    CW_FACE_PREPARE_FACECOVER = 10,         // 人脸被遮挡
    CW_FACE_PREPARE_SUNGLASSES = 15,        // 检测到戴墨镜
    CW_FACE_PREPARE_PROCEDUREMASK = 16,     // 检测到戴口罩
    CW_FACE_PREPARE_MULTIPLE_FACE = 17,     //检测到多个人脸
};

#pragma mark----------- 活体检测返回码

/******************活体检测返回码*******************/
typedef NS_ENUM(NSInteger,CwLiveCode){
    
    CW_FACE_LIVENESS_OPENMOUTH = 600,     // 检测到张嘴
    CW_FACE_LIVENESS_BLINK,               // 检测到眨眼
    CW_FACE_LIVENESS_HEADPITCH,           // 检测到抬头
    CW_FACE_LIVENESS_HEADDOWN,            // 检测到点头
    CW_FACE_LIVENESS_HEADLEFT,            // 检测到左转
    CW_FACE_LIVENESS_HEADRIGHT,           // 检测到右转
    CW_FACE_LIVENESS_LIGHT,           // 光线检测

    
    //活体检测代码返回
    CwLiveCode_SUCCESS = 618,         // 活体验证成功
    CwLiveCode_NO_FACE = 700,         // 没有检测到人脸
    CwLiveCode_MULTIPLE_FACE = 701,         // 检测到多个人（未体现）
    CwLiveCode_CHANGE_FACE = 702,           // 检测到换人
    CwLiveCode_TIME_OUT = 703,              // 检测超时
    CwLiveCode_ACTION_NOT_STANDARD = 704,   // 检测到做了要求以外的其他动作
    
    CwLiveCode_RESTART_LIVE = 705,          // 检测过程中锁屏或退出后台
    CwLiveCode_FAIL = 706,                  // 活体验证失败
    CwLiveCode_HIJACK = 707,                // 检测到劫持
    
    CwLiveCode_OTHER_ATTACK = 708,          // 其他攻击
    CwLiveCode_UNSAFE_ENVIRONMENT = 709,    //设备存在安全隐患 越狱
    CwLiveCode_NOT_CAMERA_PERMISSION = 710, //没有相机权限
    CwLiveCode_LIVE_START_CANCEL = 711,     //用户主动取消检测
    CwLiveCode_LIVE_CANCEL = 712,           //活体页面用户主动取消检测
    CwLiveCode_NETWORK_ERR = 713,           //网络请求错误（未体现）
    CwLiveCode_INIT_FAIL = 714,             // SDK初始化失败_授权失败
    CwLiveCode_LIVE_INIT_MODEL_FAIL = 715 , //SDK初始化失败_模型文件加载失败
    CwLiveCode_LIVE_INIT_OTHER_FAIL = 716,   //SDK初始化失败_其他失败
    CwLiveCode_UI_NOT_SUPPORT = 717,        //UI不被支持（未体现）
    CwLiveCode_PACKAGE_NAME_NOT_SUPPORT = 718, //bundleID不被支持（未体现）
    CwLiveCode_FACE_ATTACK = 719, // 检测到攻击 - 安卓
    CwLiveCode_FAIL_RESULT_PAGE_RESTART = 720,//失败页面重试
    CwLiveCode_FAIL_RESULT_PAGE_EXIT = 721,// 失败页面退出
    CwLiveCode_SUCCESS_RESULT_PAGE_EXIT = 722,// 成功页面退出
    CwLiveCode_FACE_STAGE_SMALL = 723, //人脸太小
    CwLiveCode_FACE_STAGE_BIG = 724, //人脸太大
    CwLiveCode_FACE_STAGE_LEFT = 725, // 人脸偏左
    CwLiveCode_FACE_STAGE_TOP = 726, //  人脸偏上
    CwLiveCode_FACE_STAGE_RIGHT = 727, //  人脸偏右
    CwLiveCode_FACE_STAGE_BOTTOM = 728, //  人脸偏下
    CwLiveCode_FACE_STAGE_SHAKE = 729, //  人脸晃动
    CwLiveCode_FACE_STAGE_CENTER = 730, //  人脸已经居中
    CwLiveCode_FACE_STAGE_NO_CENTER = 731, //  人脸不居中对应算法值8
    CwLiveCode_FACE_STAGE_FRONTAL = 732, //  人脸不正对屏幕 4
    CwLiveCode_NOT_AUDIO_RECOD_PERMISSION = 733, //  没有录音权限(安卓使用)
    CwLiveCode_HAS_FACE = 734, //   检测到人脸(安卓使用)
    CwLiveCode_FACE_STANDARD_MOUTH = 735,       //动作不一致做出张嘴动作
    CwLiveCode_FACE_STANDARD_HEAD_LEFT = 736,       //动作不一致做出左转动作
    CwLiveCode_FACE_STANDARD_HEAD_RIGHT = 737,       //动作不一致做出右转动作
    CwLiveCode_CW_MESSAGE_ERR = 738,                 // 报文生成失败
};



#pragma mark----------- 算法返回错误码
/******************算法返回错误码*******************/
typedef NS_ENUM(NSInteger, CW_FaceDETCode) { // 算法SDK错误码返回
    
    CW_FACE_DET_OK = 0,                         // 成功 or 合法
    
    CW_FACE_EMPTY_FRAME = 20000,                // 空图像 20000
    CW_FACE_UNSUPPORTFRAME,                     // 图像格式不支持 20001
    CW_FACE_DETECTED_NOFACE,                    // 没有人脸 20002
    
    CW_FACE_SETROI_FAILED,                      // ROI设置失败 20003
    CW_FACE_SETMINMAX_FAILED,                   // 最小最大人脸设置失败 20004
    CW_FACE_OUTOF_RANGEERR,                     // 数据范围错误 20005
    CW_FACE_METHOD_INVALID,                     // 方法无效 20006
    
    CW_FACE_UNAUTHORIZED,                       // 未授权 20007
    CW_FACE_UNINITIALIZED,                      // 尚未初始化 20008
    CW_FACE_DETMODEL_FAILED,                    // 加载检测模型失败 20009
    CW_FACE_KEYPTMODEL_FAILED,                  // 加载关键点模型失败 20010
    CW_FACE_QUALITYMODEL_FAILED,                // 加载质量评估模型失败 20011
    CW_FACE_LIVENESSMODEL_FAILED,               // 加载活体检测模型失败 20012
    
    CW_FACE_DET_FAILED,                         // 检测失败 20013
    CW_FACE_KEYPT_FAILED,                       // 提取关键点失败 20014
    CW_FACE_ALIGN_FAILED,                       // 对齐人脸失败 20015
    CW_FACE_QUALITY_FAILED,                     // 质量评估失败 20016
    CW_FACE_LIVENESS_DETERR                     // 活体检测错 20017
};

typedef NS_ENUM(NSInteger, CW_BeautyFaceCode) {
    
    CW_BEAUTY_SUCCESS = 26160000,
    CW_BEAUTY_NOT_AUTHORIZE_ERROR
};




#endif /* CloudwalkFaceSDKLivessDef_h */
