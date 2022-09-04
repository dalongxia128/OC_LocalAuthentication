//
//  NSBundle+CWLocalization.h
//  CWFaceSDK
//
//  Created by Ethan on 2018/12/11.
//  Copyright © 2018 DengWuPing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (CWLocalization)
+ (instancetype)cw_shareBundle;

+ (UIImage *)cw_imageWithNamed:(NSString *)imageName;

+ (NSString *)cw_audioWithNamed:(NSString *)audioName;

+ (NSString *)cw_localizedStringForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
