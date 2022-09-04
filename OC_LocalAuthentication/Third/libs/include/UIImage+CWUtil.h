//
//  UIImage+CWUtil.h
//  CloudwalkFaceSDK
//
//  Created by Ethan.Luo on 2018/12/18.
//  Copyright © 2018 DengWuPing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (CWUtil)
/**
 获取视频帧图像数据
 * param sampleBuffer 视频帧
 * param bufferType   视频帧格式 (see detail in CWCardAliginBufferType)
 * param block        结果返回
 block param:
        frameData      帧图片数据
        width          图片宽
        height         图片高
        bytesPerRow    每一行的数据  宽*4
 */
+ (void)cw_getFrameFromSampleBuffer:(CMSampleBufferRef)sampleBuffer bufferType:(NSUInteger)bufferType completionBlock:(void(^)(unsigned char * frameData,int width,int height,size_t bytesPerRow))block;

#pragma mark
#pragma mark -----------getImageFromBGRA BGRA转uiimage
/**
 *  @brief BGRA转uiimage
 *
 *  * param sampleBuffer BGRA视频流
 *  * param bufferType   视频帧格式 (see detail in CWCardAliginBufferType)
 *  @return UIImage
 */

+ (UIImage *)cw_getImageFromBGRA:(CMSampleBufferRef)sampleBuffer bufferType:(NSUInteger)bufferType;

/**
 *  @brief BGRA转uiimage
 *
 *  * param sampleBuffer BGRA视频流
 *
 *  @return UIImage
 */
+ (UIImage *)cw_getImageFromBGRA:(UInt8 *)imageAddress width:(size_t)width height:(size_t)height bytesPerRow:(size_t)bytesPerRow;


//+ (unsigned char *)convertUIImageToBitmapRGBA8:(UIImage *)image;

/**
 BGR转成UIImage
 
 * param buffer BGR图像数据
 * param width  图像宽
 * param height 图像高
 
 @return 返回转换后的UIImage
 */
+ (UIImage *)cw_convertBitmapRGBA8ToUIImage:(unsigned char *) buffer  withWidth:(int) width withHeight:(int) height isBGRA:(BOOL)isBGRA;

/**
 *  图片裁剪
 *
 *  * param superImage   原始图片
 *  * param subImageRect 裁剪的区域
 *
 *  @return 裁剪之后的图片
 */

+ (UIImage *)cw_cutImage:(UIImage*)superImage subImageRect:(CGRect)subImageRect;

//递归缩放图片
+ (UIImage *)cw_recureScaleImage:(UIImage *)oldImage;

+ (UIImage *)cw_fixOrientation:(UIImage *)aImage;

+ (NSData *)getBGRWithImage:(UIImage *)image;
+ (UIImage*)cw_scaleImageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;

@end

NS_ASSUME_NONNULL_END
