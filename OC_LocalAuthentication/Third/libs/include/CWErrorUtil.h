//
//  CWErrorUtil.h
//  CloudwalkFaceSDK
//
//  Created by 马辉 on 2021/10/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWErrorUtil : NSObject

@property (nonatomic, assign) NSInteger errorCode; // code
@property (nonatomic, strong) NSString *errorDes; // 描述
@property (nonatomic, strong) NSData *errorVedioData; // 视频(开启视频录制才会生效)
@property (nonatomic, assign) BOOL isRecordVoiceStage; //是否是录音阶段


@end

NS_ASSUME_NONNULL_END
