//
//  ASLRBLiveInitConfig.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/8/17.
//

#import <Foundation/Foundation.h>

#import "ASLRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN

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
 *本场直播的标题，非必传，只有主播侧设置有效
 */
@property (nonatomic, copy) NSString* liveTitle;

/**
 *本场直播的封面图地址，非必传，只有主播侧设置有效
 */
@property (nonatomic, copy) NSString* liveCoverURL;

/**
 *本场直播的自定义数据，非必传，只有主播侧设置有效
 */
@property (nonatomic, copy) NSString* liveCustomData;

/**
 *本场直播弹幕的最大字符个数（即[NSString length]），默认为50，支持外部设置0~50之间的值；
 *所发送弹幕长度超过maxLiveCommentLength时会报错ASLRBLiveRoomCommentLengthExceedsLimit；
 */
@property (nonatomic, assign) int8_t maxCommentLength;

/**
 * 本场直播拉流是否开启RTS低延迟观看，默认为NO，只有观众侧设置有效；
 * 注意，需要增加Rts.framework和ArtcSource.framework后使用；
 */
@property (nonatomic, assign) BOOL lowDelayLivePlaying;

@end

NS_ASSUME_NONNULL_END
