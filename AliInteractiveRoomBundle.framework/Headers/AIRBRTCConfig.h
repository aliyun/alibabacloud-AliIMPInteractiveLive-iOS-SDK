
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
 * 是否开启纯音频模式，默认为NO（关闭）
 * - YES: 只有音频推流和拉流（纯音频）
 * - NO: 音视频都支持
 * @note 需要在joinChannel之前配置
 */
@property (nonatomic, assign) BOOL audioOnlyModeEnabled;

/**
 * 高分辨率视频流（大流）的编码分辨率，默认为640x480
 */
@property (nonatomic, assign) CGSize videoStreamTypeHighDimensions;

/**
 * 是否同时推送低分辨率视频流（小流），默认开启（小流的分辨率无法修改）
 */
@property (nonatomic, assign) BOOL videoStreamTypeLowPublished;

//******** 已废弃，请通过开启旁路推流接口startPublishingBypassLive:进行设置 ********//
///**
// * 旁路直播分辨率类型，默认值为AIRBRTCBypassLiveResolutionType_1280x720
// * @note 非必需，只有开启旁路直播的房主设置才会生效
// */
//@property (nonatomic, assign) AIRBRTCBypassLiveResolutionType bypassLiveResolutionType;

@end

NS_ASSUME_NONNULL_END
