//
//  CWLivessInfo.h
//  CloudwalkFaceSDK
//
//  Created by 密码0000 on 2021/11/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWLivessInfo : NSObject


//最佳人脸图
@property (nonatomic,strong) NSData *bestFaceOriginData;

//最佳人脸图加密字符串
@property (nonatomic,strong) NSString *bestFaceOriginStr;

//后端防hack字符串
@property (nonatomic,strong) NSString *backendHackData;

//裁剪图
@property (nonatomic,strong) NSData *bestFaceCropData;

//录制的视频数据
@property (nonatomic,strong) NSData *videoData;

//截屏数据
@property (nonatomic,strong) UIImage *screenImage;

//录制的声纹数据
@property (nonatomic,strong) NSData *audioData;
//产生8位随机数
@property (nonatomic,strong) NSString *randomNum;


@end

NS_ASSUME_NONNULL_END
