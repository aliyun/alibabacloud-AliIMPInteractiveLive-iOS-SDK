//
//  ASLRBLiveRoomAnchorProtocol.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/11/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveInitConfig, ASLRBLiveBusinessInfo;

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
                onFailure:(void (^)(NSString* errorMessage))onFailure DEPRECATED_MSG_ATTRIBUTE("建议使用updateLiveBusinessInfo");

/**
 * @brief 更新直播相关信息；仅开播后在主播侧调用有效；
 * @param info 具体见ASLRBLiveBusinessInfo
 */
- (void) updateLiveBusinessInfo:(ASLRBLiveBusinessInfo*)info
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

/**
 * @brief 开启/关闭某user的禁言
 * @param userID 要开启或关闭禁言的用户id
 * @param banSeconds 要禁言的秒数（注意，取消禁言时可不传入；注意，需要永久禁言时可传入0）
 * @param ban YES即开启禁言，NO即关闭禁言
 */
- (void) banCommentsOfUser:(NSString*)userID bannedSeconds:(int32_t)banSeconds ban:(BOOL)ban;

/**
 * @brief 开启/关闭全员禁言，主播端调用
 * @param ban 是否开启禁言全员禁言，为YES则开启，为NO则关闭
 */
- (void) banAllComments:(BOOL)ban;

/**
 * @brief 主播踢人
 * @param kickedSeconds 踢出时长（踢出后多久才能进）
 */
- (void) kickUser:(NSString*)userID
    kickedSeconds:(int32_t)kickedSeconds
        onSuccess:(void(^)(void))onSuccess
        onFailure:(void(^)(NSString* errorMessage))onFailure;

/**
 * @brief 获取本直播间内人员列表，具体信息在response中的ASLRBLiveRoomUserModel
 * @param pageNum  分页index，从1开始
 * @param pageSize  每页的数量
 */
- (void) getLiveUserListWithPageNum:(int32_t)pageNum
                           pageSize:(int32_t)pageSize
                          onSuccess:(void (^)(NSDictionary* response))onSuccess
                          onFailure:(void (^)(NSString* errorMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
