//
//  ASLRBLiveRoomAudienceProtocol.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/11/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ASLRBLiveRoomAudienceProtocol <NSObject>
/**
 * 直播观看时画面的伸缩模式，目前仅支持三种，即UIViewContentModeScaleToFill, UIViewContentModeScaleAspectFit和UIViewContentModeScaleAspectFill
 * 默认为UIViewContentModeScaleAspectFit；
 */
@property (assign, nonatomic) UIViewContentMode playerViewContentMode;

/**
 * 在不退出当前直播间的情况下重新加载视频播放
 * 仅观众端调用有效；
 */
- (void) refreshPlayer;

/**
 * 切换观众，主播侧调用无效；
 * @param userID 新的用户ID
 * @param nick     新的用户昵称
 */
- (void) switchAudience:(NSString*)userID nick:(NSString*)nick;
@end

NS_ASSUME_NONNULL_END
