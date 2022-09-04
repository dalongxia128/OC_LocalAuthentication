//
//  CWResponseUtil.h
//  CloudwalkFaceSDK
//
//  Created by 马辉 on 2021/10/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWResponseUtil : NSObject

@property (nonatomic, strong) NSString *riskLevel;    //String    否    风险级别：高high、中medium、低low、安全safe
@property (nonatomic, strong) NSString *strategy;   // String    否    命中策略
@property (nonatomic, strong) NSString *decision;   // String    否    决策结果：通过 pass，不通过 fail，存疑 doubt
//String    否    操作指令：(决策结果为存疑则会存在操作指令)二次验证A12345(1眨眼 2张嘴 3左转 4右转 5炫光) 转人工 B00000 短信验证C00000
@property (nonatomic, strong) NSString *instruct;
@property (nonatomic, strong) NSString *tempAuth;    //String    否    临时授权进行二次验证（有效时间3分钟）
/*Integer
 是
 活体判断结果: 0:无法判断; 1:判断为活体; 2:判断为扣眼攻击; 3:判断为扣嘴攻击; 4:判断为半张脸攻击; 5:判断为视频回放攻击; 6:判断为黑白图片; 7:判断为纸面攻击; 8:判断为边框（包括纸面、手机等边框); 9:判断为摩尔纹攻击; 10:判断为脸优攻击; 11:判断为纸面攻击(光流) ; 12：判断为面具攻击; 13：判断为证卡攻击; 14:判断为3D面具攻击; 16:动作活体未检测到动作; 20:判断为不满足人行人脸识别图片质量要求； 21:判断为戴口罩/遮挡或者墨镜； 22:判断为未检测到人脸； 23:人脸检测或质量分或活体分模块运行异常; 30: 动作活体判定为换人，提示请不要剧烈晃动屏幕; 31 动作活体判定为环境光太暗，提示增加环境光; 32:动作活体判定为环境光太亮，提示降低环境光 33 动作活体判定没有正对屏幕，提示需要正对屏幕; 34:动作活体判定清晰度不够，提示确保光线自然，无晃动屏幕; 35: 动作活体未检测到动作; 50:判断为合成图像攻击; 51:判断为合成图像攻击; 52: 判断为黑产软件攻击; 53: 判断为T型面具攻击; 54: 判断为黑白照片; 55:判断为模糊图片; 56:补充攻击模型1; 57: 补充攻击模型2;
     58:补充攻击模型3;59: 补充攻击模型4;
 */
@property (nonatomic, strong) NSNumber *code;
@property (nonatomic, strong) NSNumber *result;   // Integer    是    非0表示错误码
@property (nonatomic, strong) NSString *extInfo;   // String    否    活体判断结果
@property (nonatomic, strong) NSNumber *confidence;   // double    否    真人置信分0-1
@property (nonatomic, strong) UIImage *image;       //人脸图片


@end

NS_ASSUME_NONNULL_END
