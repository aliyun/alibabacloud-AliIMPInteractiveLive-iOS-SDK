
//
//  AIRBRTCConfig.h
//  AliInteractiveRoomBundle
//
//  Created by 刘再勇 on 2021/8/19.
//  Copyright © 2021 AliYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AIRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface AIRBRTCConfig : NSObject

/**
 * 高分辨率视频流（大流）的编码分辨率，默认为640x480
 */
@property (nonatomic, assign) CGSize videoStreamTypeHighDimensions;

/**
 * 是否同时推送低分辨率视频流（小流），默认开启（小流的分辨率无法修改）
 */
@property (nonatomic, assign) BOOL videoStreamTypeLowPublished;

/**
 * 旁路推流分辨率类型，默认值为AIRBRTCBypassLiveResolutionType_1280x720
 */
@property (nonatomic, assign) AIRBRTCBypassLiveResolutionType bypassLiveResolutionType;

@end

NS_ASSUME_NONNULL_END
