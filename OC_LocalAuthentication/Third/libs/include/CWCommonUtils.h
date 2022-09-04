//
//  CWCommonUtils.h
//  CloudwalkFaceSDK
//
//  Created by 密码0000 on 2021/11/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CWCommonUtils : NSObject

+ (NSString *)getRandomCode:(NSInteger)count;

+ (void)writeDataToPath:(NSData *)data fileName:(NSString *)fileName;

@end

NS_ASSUME_NONNULL_END
