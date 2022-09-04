//
//  CWLivessFinishedView.h
//  CloudWalkSDKDemo
//
//  Created by Noctis on 2020/5/9.
//  Copyright © 2020 Cloudwalk. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    CWLivessFinishedViewStatusSuccess,
    CWLivessFinishedViewStatusFailed,
} CWLivessFinishedViewStatus;


@interface CWLivessFinishedView : UIView

@property (nonatomic, copy) void(^ _Nullable cancelLivessAction)(void);
@property (nonatomic, copy) void(^ _Nullable retryLivessAction)(void);


@property (nonatomic, strong) UIButton * _Nullable closeButton;
@property (nonatomic, strong) UIButton * _Nullable retryButton;
@property (nonatomic, strong) UIButton * _Nullable confirmButton;

-(instancetype _Nonnull )initWithFrame: (CGRect)frame
                             andStatus: (CWLivessFinishedViewStatus) status
                             faceImage: (UIImage * _Nullable)faceImage
                               message:(NSString *)message;

@end
