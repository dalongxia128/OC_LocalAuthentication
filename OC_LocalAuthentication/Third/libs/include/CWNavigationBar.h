//
//  CWNavigationBar.h
//  CloudwalkFaceSDKDemo
//
//  Created by 马辉 on 2020/12/24.
//  Copyright © 2020 DengWuPing. All rights reserved.
//

#import <UIKit/UIKit.h>




NS_ASSUME_NONNULL_BEGIN



@interface CWNavigationBar : UIView


@property (nonatomic, copy) void(^backBtnBlcock)(void);

@end

NS_ASSUME_NONNULL_END
