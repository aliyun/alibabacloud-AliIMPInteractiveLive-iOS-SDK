//
//  AIRBLivePusherProtocol.h
//  AliInteractiveRoomBundle
//
//  Created by fernando on 2021/6/22.
//  Copyright © 2021 AliYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <AliInteractiveRoomBundle/AIRBCommonDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class AIRBLivePusherOptions;
@class AIRBLivePusherFaceBeautyOptions;
@class AIRBLivePusherLiveBusinessOptions;

@protocol AIRBLivePusherDelegate <NSObject>
- (void) onAIRBLivePuhserEvent:(AIRBLivePusherEvent)event info:(NSDictionary*)info;
- (void) onAIRBLivePusherError:(AIRBErrorCode)errorCode message:(NSString*)errorMessage;
@end

@protocol AIRBLivePusherProtocol <NSObject>

/**
 * 用来接收推流相关的事件和错误
 */
@property (weak, nonatomic) id<AIRBLivePusherDelegate> delegate;

/**
 * 推流相关的配置，视频默认分辨率720P，具体见AIRBLivePusherOptions的字段说明
 */
@property (strong, nonatomic) AIRBLivePusherOptions* options;

/**
 * 推流时的相机画面预览view
 */
@property (strong, nonatomic) UIView* pusherView;

/**
 * 推流时的相机画面预览view的拉伸模式，具体见AIRBVideoViewContentMode，默认为AIRBVideoViewContentModeAspectFill
 */
@property (assign, nonatomic) AIRBVideoViewContentMode contentMode;

/**
 * 美颜面板，已经实现完毕，外部只需present即可，建议size为CGSizeMake(屏幕宽度，200)；
 */
@property (strong, nonatomic) UIViewController* beautyViewController;

/**
 * 根据配置，打开推流预览画面
 * @param options 推流相关的配置
 */
- (void) startLocalPreviewWithOptions:(AIRBLivePusherOptions*)options;

/**
 * 开始直播推流
 */
- (void) startLiveStreaming;

/**
 * 暂停直播推流
 */
- (void) pauseLiveStreaming;

/**
 * 从暂停状态下恢复直播推流
 */
- (void) resumeLiveStreaming;

/**
 * 停止直播推流
 * @param stopLive YES表示结束直播，NO表示只停止推流不结束直播
 */
- (void) stopLiveStreaming:(BOOL)stopLive;

/**
 * 停止直播推流并结束直播
 * @note 等同于stopLiveStreaming:YES
 */
- (void) stopLiveStreaming;

/**
 * 切换前后摄像头，默认使用前置摄像头
 */
- (void) toggleCamera;

/**
 * 切换推流是否静音（静音后观众侧侧听不到主播侧的声音）
 */
- (void) toggleMuted;

/**
 * 是否开启摄像头预览画面的镜像
 */
- (void) setPreviewMirror:(BOOL)mirror;

/**
 * 是否开启视频流的画面镜像
 */
- (void) setStreamingVideoMirror:(BOOL)mirror;

/**
 * 动态打开或者关闭美颜
 */
- (void) toggleFaceBeauty;

/**
 * 动态更新直播业务信息，具体见AIRBLivePusherLiveBusinessOptions
 */
- (void) updateLiveBusinessOptions:(AIRBLivePusherLiveBusinessOptions*) businessOptions
                         onSuccess:(void (^)(void))onSuccess
                         onFailure:(void (^)(NSString* errorMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
