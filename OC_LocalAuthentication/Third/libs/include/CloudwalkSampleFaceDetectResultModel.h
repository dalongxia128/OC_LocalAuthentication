//
//  CloudwalkSampleFaceDetectResultModel.h
//  CloudwalkFaceSDK
//
//  Created by Noctis on 2020/5/15.
//  Copyright © 2020 Cloudwalk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CloudwalkSampleFaceDetectResultModel : NSObject

@property (nonatomic, assign) double score;
@property (nonatomic, assign) CGRect rect;
@property (nonatomic, strong) UIImage *faceImage;

@end

