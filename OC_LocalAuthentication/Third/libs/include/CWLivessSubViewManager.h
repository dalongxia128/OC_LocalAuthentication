//
//  CWlicessSubViewManager.h
//  CloudwalkFaceSDKDemo
//
//  Created by 马辉 on 2021/1/26.
//  Copyright © 2021 DengWuPing. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AVFoundation/AVFoundation.h>
#import "CWLivessViewManager.h"
#import "CWNavigationBar.h"
#import "CWGuideView.h"
#import "CWLivessCameraView.h"
#import "CWLivessFinishedView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CWLivessSubViewManager : CWLivessViewManager

@property (nonatomic, strong) CWNavigationBar     *navigationBar;   // 导航栏
@property (nonatomic, strong) CWGuideView         *guideView;       // 活体引导页面
@property (nonatomic, strong) CWLivessCameraView  *cameraView;      // 活体检测页面
@property (nonatomic, strong) CWLivessFinishedView      *finishView;      // 成功失败页面
@property (nonatomic, assign) BOOL isShowGuideView;//是否显示引导页
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

@end

NS_ASSUME_NONNULL_END
