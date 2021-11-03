//
//  ASLRBLiveRoomAnchorProtocol.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/11/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveInitConfig;

@protocol ASLRBLiveRoomAnchorProtocol <NSObject>
/**
 * 主播端：手动开播，移除livePrestartCustomizedViewHolder，展示开播后的UI界面;
 * @param config 本场直播相关的配置
 */
- (void) startLiveAndUpdateConfig:(ASLRBLiveInitConfig*)config;

/**
 * 更新直播相关信息；仅开播后在主播侧调用有效；
 * @param config 具体见ASLRBLiveInitConfig
 */
- (void) updateLiveConfig:(ASLRBLiveInitConfig*)config
                onSuccess:(void (^)(void))onSuccess
                onFailure:(void (^)(NSString* errorMessage))onFailure;

/**
 * 切换前后摄像头，主播端调用;
 */
- (void) switchCamera;

/**
 * 展示/收起美颜面板（已经内部定义好的一个ViewController），主播端调用，建议高度200;
 */
- (void) showBeautyPanel;

/**
 * 切换麦克风状态（关闭/开启），默认为开启，主播端调用;
 */
- (void) toggleMutedMicrophone;

/**
 * 开启/关闭直播画面镜像（包括本地画面预览和观众看到的直播画面），默认为关闭，主播端调用;
 * @param mirror 是否开启摄像头画面镜像，为YES则开启，为NO则关闭
 */
- (void) mirrorLiveVideo:(BOOL)mirror;

/**
 * 暂停/恢复直播推流，默认为推流状态，主播端调用
 * @param pause 是否暂停直播推流，为YES则暂停，为NO则恢复推流
 */
- (void) pauseLiveStreaming:(BOOL)pause;
@end

NS_ASSUME_NONNULL_END
