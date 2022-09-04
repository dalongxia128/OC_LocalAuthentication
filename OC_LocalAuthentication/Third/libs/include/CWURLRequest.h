//
//  CWURLRequest.h
//  CloudwalkFaceSDK
//
//  Created by 马辉 on 2021/10/21.
//

#import <Foundation/Foundation.h>
#import "CWURLParam.h"
#import "CWResponseUtil.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  @brief 网络请求block回调
 *
 *  @param data  请求结果数据
 *  @param error 错误信息
 */
typedef void(^NSurlSessionFinishedBlock)(NSData * __nonnull data,NSError * __nonnull error);

@interface CWURLRequest : NSObject<NSURLSessionDataDelegate>

{
    NSMutableURLRequest  * request;
    NSURLSession     * mainSession;
}

+ (__nonnull instancetype)sharedClient;

#pragma mark--
#pragma mark  cancelRequest 取消请求
-(void)cancelRequest;

- (void)cw_hackWithParam:(CWURLParam *)param result:(void(^)(CWResponseUtil *util))result;


@end

NS_ASSUME_NONNULL_END
