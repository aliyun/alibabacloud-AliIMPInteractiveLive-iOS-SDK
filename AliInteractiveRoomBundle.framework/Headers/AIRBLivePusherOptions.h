//
//  AIRBLivePusherOptions.h
//  AliInteractiveRoomBundle
//
//  Created by fernando on 2021/5/10.
//  Copyright © 2021 AliYun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AIRBCommonDefines.h"


NS_ASSUME_NONNULL_BEGIN

@interface AIRBLivePusherLiveBusinessOptions : NSObject
@property (copy, nonatomic) NSString* liveTitle;
@property (copy, nonatomic) NSString* liveCoverUrl;
@property (copy, nonatomic) NSString* liveIntroduction;
@property (assign, nonatomic) int64_t liveStartTime;
@property (assign, nonatomic) int64_t liveEndTime;
@property (copy, nonatomic) NSString* extension;
@end

@interface AIRBLivePusherMediaStreamingOptions : NSObject

/**
 * 是否进行仅视频推流（不录制音频），默认NO
 */
@property (assign, nonatomic) BOOL onlyVideo;

/**
 * 视频的帧率，默认20，不建议外部调节
 */
@property (assign, nonatomic) int16_t videoFrameRate;

/**
 * 视频的码率，单位 kbps，范围[400, 5000)，默认 1500，不建议外部调节
 */
@property (assign, nonatomic) int32_t videoBitrate;

/**
 * 视频帧最大关键帧间隔，单位秒，默认4秒，不建议外部调节
 */
@property (assign, nonatomic) int16_t maxVideoKeyFrameInterval;

/**
 * 摄像头的默认类型，默认为前置摄像头
 */
@property (assign, nonatomic) AIRBLivePusherCameraType cameraDefaultType;

/**
 * 是否进行仅音频推流（不录制视频）
 */
@property (assign, nonatomic) BOOL onlyAudio;
@end

@interface AIRBLivePusherBeautyOptions : NSObject

/**
 * 基础美颜，默认打开;
 * 包括 [@"磨皮",@"美白",@"锐化",@"瘦脸",@"脸长",@"削脸",@"瘦颧骨",@"下颌骨",@"下巴",@"下巴拉长",@"大眼",@"眼睑下至",@"眼距",@"瘦鼻",@"鼻长",@"鼻翼",@"鼻头长",@"嘴型",@"嘴唇厚度",@"人中"]
 */


/**
 * 美妆，默认NO;
 * 包括 [@"高光",@"美瞳",@"口红",@"眼妆"]
 * 注意：暂未开放，设置无效；
 */
@property (assign, nonatomic) BOOL enableMakeupBeauty;

/**
 * 滤镜，默认NO; 待开放；
 * 包括 [@"超脱",@"纯真",@"怀旧",@"蓝调",@"清新",@"元气",@"美白",@"初恋",@"清爽",@"非凡",@"动人",@"萌系",@"日系",@"年华",@"单纯",@"蔷薇",@"安静",@"严肃",@"日光"]
 * 注意：暂未开放，设置无效；
 */
@property (assign, nonatomic) BOOL enableFilter;

/**
 * 贴纸，默认NO; 待开放；
 * 包括[@"白羊",@"八字胡",@"布偶",@"小黄脸",@"猴子",@"胡须",@"猫耳朵",@"射手座",@"手绘胡子",@"兔子"]
 * 注意：暂未开放，设置无效；
 */
@property (assign, nonatomic) BOOL enableStickers;

/**
 * 腮红，默认NO; 待开放；
 * 包括 [@"黛紫",@"蜜橘",@"嫩粉",@"桃红",@"樱桃"]
 * 注意：暂未开放，设置无效；
 */
@property (assign, nonatomic) BOOL enableFaceBlush;

/**
 * 整妆，默认NO; 待开放；
 * 包括 [@"活力",@"基础",@"梅子",@"魅惑",@"蜜桃",@"奶橘",@"杏粉",@"优雅",@"元气少女"];
 * 注意：暂未开放，设置无效；
 */
@property (assign, nonatomic) BOOL enableCompleteMakeup;
@end

@interface AIRBLivePusherOptions : NSObject
@property (strong, nonatomic) AIRBLivePusherLiveBusinessOptions* businessOptions;
@property (strong, nonatomic) AIRBLivePusherMediaStreamingOptions* mediaStreamingOptions;
@property (strong, nonatomic) AIRBLivePusherBeautyOptions* beautyOptions;

+ (instancetype) defaultOptions;
@end

NS_ASSUME_NONNULL_END
