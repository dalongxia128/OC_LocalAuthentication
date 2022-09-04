//
//  CWURLParam.h
//  CloudwalkFaceSDK
//
//  Created by 马辉 on 2021/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWURLParam : NSObject

@property (nonatomic, strong) NSString *tempAuth;     // String    是否必须：否    临时授权进行二次验证【非空表示二次验证】
@property (nonatomic, strong) NSString *userId;       // String    是否必须：否    用户ID
@property (nonatomic, strong) NSString *deviceId;     // String    是否必须：否    设备ID
@property (nonatomic, strong) NSString *deviceType;   // String    是否必须：是    设备型号
@property (nonatomic, strong) NSNumber *phone;        // Long      是否必须：否    手机号
@property (nonatomic, strong) NSString *ip;           // String    是否必须：否    设备IP
@property (nonatomic, strong) NSNumber *lon;          // Number    是否必须：否    经度
@property (nonatomic, strong) NSNumber *lat;          // Number    是否必须：否    纬度
@property (nonatomic, strong) NSString *address;      // String    是否必须：否    登录地
@property (nonatomic, strong) NSNumber *root;         // Boolean   是否必须：否    是否root权限
@property (nonatomic, strong) NSNumber *timeStamp;    // Long      是否必须: 是    请求时间戳
@property (nonatomic, strong) NSString *nonceStr;     // String    是否必须：是    请求随机字符串；
@property (nonatomic, strong) NSString *eventNo;      // String    是否必须：是    事件编码
@property (nonatomic, strong) NSString *sceneNo;      // String    是否必须：是    场景编码
@property (nonatomic, strong) NSString *param;        // String    是否必须：是    待识别图片的base64编码【动作活体特征值】
@property (nonatomic, strong) NSString *actions;      // String    是否必须：是    活体顺序

@property (nonatomic, strong) NSNumber *filterType;   // number    是否必须：否    图片质量过滤掩码（打开多个过滤功能，filterType为各过滤数值相加，如打开口罩、遮挡和墨镜过滤，filterType=2+4+8=14）1:人行人脸识别质量标准过滤2:戴口罩过滤4:遮挡过滤8:墨镜过滤16:confidence 0.35过滤32:best_score 0.3过滤64:质量分过滤

- (void)cwSetACtions:(NSArray *)actions;

@end

NS_ASSUME_NONNULL_END
