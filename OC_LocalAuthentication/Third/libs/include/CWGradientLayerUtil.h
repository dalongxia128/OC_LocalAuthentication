//
//  CWGradientLayerUtil.h
//  CloudWalkSDKProject
//
//  Created by 密码0000 on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CWGradientLayerUtil : NSObject


+ (CAGradientLayer *)createGradientLayer:(UIColor *)startColor
                                endColor:(UIColor *)endColor
                              startPoint:(CGPoint)startPoint
                                endPoint:(CGPoint)endPoint;

@end

NS_ASSUME_NONNULL_END
