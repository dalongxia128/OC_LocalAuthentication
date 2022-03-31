//
//  NSObject+LocalAuthentication.m
//  OC_Test
//
//  Created by OC_LYL on 2022/3/31.
//

#import "NSObject+LocalAuthentication.h"

#import<LocalAuthentication/LocalAuthentication.h>

@implementation NSObject (LocalAuthentication)

- (void)getLocalAuthentication {
    
    LAContext *context = [[LAContext alloc] init];
    NSError*error =nil;
    if (@available(iOS 11.0, *)) {
        LABiometryType type = context.biometryType;
        NSLog(@"进入前： %ld", (long)type); // 这里一直是 0， 具体原因未知
    }
    // 判断设备是否支持指纹识别 （如果iPhone支持并设置了面容/指纹，canEvaluatePolicy:会判断成功，进入内部逻辑，否则执行else语句，输出打印error）
    if ([context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error]) {
        
        if (@available(iOS 11.0, *)) {
            LABiometryType type = context.biometryType;
            NSLog(@"已进入：%ld", (long)type);
            
        }
        //支持 localizedReason为alert弹框的message内容
        [context evaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics localizedReason:@"请验证已有指纹" reply:^(BOOL success, NSError * _Nullable error) {
            if(success) {
                NSLog(@"面容/指纹验证通过");
                //在这里登录操作
            }else{
                NSLog(@"验证失败:%@",error.description);
                switch(error.code) {
                    case LAErrorSystemCancel:
                    {
                        NSLog(@"系统取消授权，如其他APP切入");
                        break;
                    }
                    case LAErrorUserCancel:
                    {
                        NSLog(@"用户取消验证Touch ID");
                    }
                    case LAErrorAuthenticationFailed:
                    {
                        NSLog(@"授权失败");
                        break;
                    }
                    case LAErrorPasscodeNotSet:
                    {
                        NSLog(@"系统未设置密码");
                        break;
                    }
                    case LAErrorBiometryNotAvailable:
                    {
                        NSLog(@"设备Touch ID不可用，例如未打开");
                        break;
                    }
                    case LAErrorBiometryNotEnrolled:
                    {
                        NSLog(@"设备Touch ID不可用，用户未录入");
                        break;
                    }
                    case LAErrorUserFallback:
                    {
                        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                            NSLog(@"用户选择输入密码，切换主线程处理");
                        }];
                        break;
                    }
                    default:
                    {
                        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                        NSLog(@"其他情况，切换主线程处理");
                        }];
                    break;
                    }
                }
            }
        }];
    }else{
        if (@available(iOS 11.0, *)) {
            LABiometryType type = context.biometryType;
            NSLog(@"未设置面容/指纹： %ld", (long)type); // 无指纹/面容 0  指纹 1 面容 2
        }
        NSLog(@"error : %@",error.description);
    }
  
}

@end
