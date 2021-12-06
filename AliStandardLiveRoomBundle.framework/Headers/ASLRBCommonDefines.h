//
//  ASLRBCommonDefines.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/7/20.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ASLRBUserRole)
{
    ASLRBUserRoleAnchor = 0,  // 直播中的主播身份，进行推流（发起直播）
    ASLRBUserRoleAudience     // 直播中的观众身份，进行拉流（观看直播）
};

typedef NS_ENUM(NSInteger, ASLRBLiveRoomType)
{
    ASLRBLiveRoomTypeNone = 0,
    ASLRBLiveRoomTypeLivePushing,      // 主播正在进行推流的直播间
    ASLRBLiveRoomTypeLivePlaying,      // 直播正在进行拉流的直播间
    ASLRBLiveRoomTypeLivePlayback      // 直播回放观看的直播间
};

typedef NS_ENUM(NSInteger, ASLRBEvent)
{
    ASLRBAnchorEventLivePusherStarted = 0,    // 主播端：直播开始（推流开始）事件，info字段会携带liveID
    ASLRBAnchorEventLivePusherStreamingPoorNetworkStart, //主播端推流遭遇弱网
    ASLRBAnchorEventLivePusherStreamingPoorNetworkEnd, //主播端推流从弱网状态恢复
    ASLRBAnchorEventLivePusherStreamingReconnectStart, //主播端推流网络开始重连
    ASLRBAnchorEventLivePusherStreamingReconnectSuccess, //主播端推流网络重连成功
    ASLRBAnchorEventLivePusherStreamingNetworkConnectionLost, //主播端推流网络断开
    ASLRBAnchorEventLivePusherStopped,        // 主播端：直播结束（推流结束）事件
    
    ASLRBAudienceEventLivePlayerStartPlaying, // 观众端的直播开始播放
    ASLRBAudienceEventLivePlayerStartLoading, // 观众端观看直播过程中出现卡顿
    ASLRBAudienceEventLivePlayerEndLoading, // 观众端观看直播过程中卡顿结束
    ASLRBAudienceEventLiveNotExit,          // 观众端收到了直播不存在的消息
    ASLRBAudienceEventLiveNotStarted,        // 观众端收到了直播已创建但未开始的消息
    ASLRBAudienceEventLiveEnded,              // 观众端收到了直播被结束或进入后直播已结束的消息
    ASLRBAudienceEventSwitchAudienceSucceeded,  // 切换观众成功
    
    ASLRBCommonEventExitButtonDidClicked,     // 退出按钮点击事件
    ASLRBCommonEventShareButtonDidClicked,    // 分享按钮点击事件
    ASLRBCommonEventCustomMessageReceived,    // 收到自定义消息，info字段会携带自定义消息内容
    ASLRBCommonEventLiveDataUpdated,          // 直播数据（在线人数、点赞数）更新，info字段会携带更新后数据
    ASLRBCommonEventYourCommentsBannedOrNot,    // 个人禁言/取消禁言，info字段携带是否禁言的标志布尔值
    ASLRBCommonEventAllCommentsBannedOrNot,    // 全员禁言/取消禁言，info字段携带是否禁言的标志布尔值
    ASLRBCommonEventViewWillAppear,           // 视图控制器的viewWillAppear
    ASLRBCommonEventViewWillDisappear,        // 视图控制器的viewWillDisappear
    ASLRBCommonEventViewDidAppear,           // 视图控制器的viewDidAppear
    ASLRBCommonEventViewDidDisappear,        // 视图控制器的viewDidDisappear
};

typedef NS_ENUM(NSInteger, ASLRBLiveRoomError)
{
    ASLRBLiveRoomErrorUpdateTitleFailure = 0x000,   // 更新标题失败
    ASLRBLiceRoomErrorLivePusherError,          // 主播端：推流错误
    ASLRBLiceRoomErrorLivePlayerError,          // 观众端：播放错误
    ASLRBLiveRoomErrorOthers,                   // 其他错误
    
    ASLRBLiveRoomCommentSentInnerError = 0x700, // 发送弹幕内部错误
    ASLRBLiveRoomCommentSentInvalidChatID, // 无效chatID
    ASLRBLiveRoomCommentSentFrequencyExceedsLimit, // 发送弹幕过于频繁
    ASLRBLiveRoomCommentLengthExceedsLimit,  // 发送弹幕长度超限
};
