//
//  CWDataProcessUtil.h
//  CloudwalkFaceSDK
//
//  Created by 马辉 on 2021/9/6.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger,CWEncryptionStyle){
    CWEncryptionStyleDefaut = 0, // 不加密
    CWEncryptionStyleAES, //AES
    CWEncryptionStyleSM4, //SM4
    CWEncryptionStyleHX, //HX

};

NS_ASSUME_NONNULL_BEGIN

@interface CWDataProcessUtil : NSObject

+ (NSString *)cw_aes_encodeContent:(NSString *)content forKey:(NSString *)key;
+ (NSString *)cw_aes_decodeContent:(NSString *)content forKey:(NSString *)key;


+ (NSString *)cw_sm4_encodeContent:(NSString *)content forKey:(NSString *)key;
+ (NSString *)cw_sm4_decodeContent:(NSString *)content forKey:(NSString *)key;

+ (NSData *)cw_sm4_decodeData:(NSData *)data forKey:(unsigned char *)key;

/**
 对字符串进行sm4加密
 @param content 原始字符串
 @param key 密钥
 @return 加密后的sm4字符串
 */
+ (NSString *)cw_sm4_encode:(NSString *)content byKey:(unsigned char *)key;

/**
 对字符串进行md_5加密
 @param content 原始字符串
 @return 加密后的MD_5字符串
 */
+ (NSString *)cw_mdEncode:(NSString *)content;


+ (NSString *)getHackStringWith_UUIDTimeString:(NSString *)hackString;
// base64解码
+ (NSData *)cw_decodeBase64ForData:(NSString *)string;
// base64编码
+ (NSString *)cw_encodeBase64ForData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
