//
//  CWNormalMacroDefine.h
//  CloudWalkSDKDemo
//
//  Created by 马辉 on 2021/1/19.
//  Copyright © 2021 Cloudwalk. All rights reserved.
//

#ifndef CWNormalMacroDefine_h
#define CWNormalMacroDefine_h
//警告
#define CW_FUNCTION_DEPRECATED(_info) __attribute__((deprecated(_info)))
//禁用
#define CW_FUNCTION_UNAVAILABLE(_info) __attribute__((unavailable(_info)))
//RGB颜色
#define CW_ColorFromRGB(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define CW_ColorFromRGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]
#define CW_SystemVersion [[[UIDevice currentDevice] systemVersion] floatValue]

#define CW_ColorFrom16(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define CW_ColorFrom16A(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]
#define CW_IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//屏幕宽
#define CW_SCREEN_WIDTH  [[UIScreen mainScreen] bounds].size.width
//屏幕高
#define CW_SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height
//判断是否是ipad
//判断是否是iPhone X系列
#define CW_IS_IPHONEX_S \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

#define CWErrorLog(fmt, ...) NSLog((@"CloudwalkFaceSDK Error: %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define CWKeyInfoLog(...) NSLog(__VA_ARGS__);

//比例适配
#define CW_SIZE(a) (CW_IS_IPAD?a * 1.6 : a / 375. * CW_SCREEN_WIDTH)
#ifdef DEBUG
# define CWLog(fmt, ...) NSLog((@"\n文件名->%s\n" "函数名->%s\n" "行号->%d \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
# define HanLog(...);
#endif

#endif /* CWNormalMacroDefine_h */
