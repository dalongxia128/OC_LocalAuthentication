//
//  CWLanguageConfig.h
//  CWLanguageManager
//
//  Created by Laziest on 2019/9/3.
//  Copyright © 2019 CloudWalkTechnology. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CWLanguageType) {
    en,//英語
    zhHans,//簡體中文
    zhHant//繁體
};


@interface CWLanguageConfig : NSObject

/**
 用戶自定義使用的語言， en 英語  zhHans 中文簡體 zh-Hant 繁体
 */
@property (class, nonatomic, assign) CWLanguageType userLanguage;
/**
 重置系統語言
 */
+ (void)resetSystemLanguage;


+ (NSString *)getLanguageName:(CWLanguageType)type;
@end

NS_ASSUME_NONNULL_END

