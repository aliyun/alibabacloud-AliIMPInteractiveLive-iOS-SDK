//
//  ASLRBLiveInitConfig.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/8/17.
//

#import <Foundation/Foundation.h>

#import <AliStandardLiveRoomBundle/ASLRBCommonDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveBusinessInfo;

@interface ASLRBLiveInitConfig : NSObject

/**
 *本场直播的用户角色，主播或观众，必传
 */
@property (nonatomic, assign) ASLRBUserRole role;

/**
 *本场直播的ID，主播侧非必传，观众侧必传
 */
@property (nonatomic, copy) NSString* liveID;

/**
 * @brief 本场直播的扩展信息；
  注意：更新此字段不会触发观众端ASLRBCommonEventLiveExtensionUpdated事件上报，只有更新ASLRBLiveBusinessInfo.liveCustomData后才会触发观众端ASLRBCommonEventLiveExtensionUpdated事件上报；
 *
 */
@property (nonatomic, copy) NSString* liveCustomData DEPRECATED_MSG_ATTRIBUTE("建议使用ASLRBLiveBusinessInfo.liveCustomData");

/**
 *本场直播的信息，里面包括直播的title、notice、封面图url以及扩展信息
 */
@property (nonatomic, strong) ASLRBLiveBusinessInfo* liveBusinessInfo;

/**
 * 本场直播弹幕的最大字符个数（即[NSString length]），默认为50，支持外部设置0~50之间的值；
 * 所发送弹幕长度超过maxLiveCommentLength时会报错ASLRBLiveRoomCommentLengthExceedsLimit；
 */
@property (nonatomic, assign) int8_t maxCommentLength;

/**
 * 本场直播拉流是否开启RTS低延迟观看，默认为YES，只有观众侧设置有效；
 * 注意，需要增加Rts.framework和ArtcSource.framework后使用；
 */
@property (nonatomic, assign) BOOL lowDelayLivePlaying;

/**
 * 本场直播的主播侧推流媒体相关的配置，其类型为已依赖库AlivcLivePusher.framework中的AlivcLivePushConfig类；
 * 不设置alivcLivePushConfig时默认使用内部标准配置；
 */
@property (nonatomic, strong) id alivcLivePushConfig;

/**
 * 直播观众侧手机切后台是否继续播放，默认不允许播放
 */
@property (nonatomic, assign) BOOL enableBackgroundLivePlaying;

/**
 * 直播回放逻辑，默认关闭
 */
@property (nonatomic, assign) BOOL enableLivePlayback;

@end

NS_ASSUME_NONNULL_END
