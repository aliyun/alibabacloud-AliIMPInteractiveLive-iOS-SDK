//
//  ASLRBLiveCommentViewProtocol.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/10/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveCommentModel, ASLRBLiveSystemMessageModel;

@protocol ASLRBLiveCommentViewDelegate <NSObject>
- (void) onASLRBLiveCommentJustAboutToPresent:(ASLRBLiveCommentModel*)comment;
- (void) onASLRBLiveSystmeMessageJustAboutToPresent:(ASLRBLiveSystemMessageModel *)systemMessage;
@end

@protocol ASLRBLiveCommentViewProtocol <NSObject>

/**
 * 直播评论区的各种事件回调
 */
@property (weak, nonatomic) id<ASLRBLiveCommentViewDelegate> delegate;

/**
 * 直播系统消息展示用的label
 */
@property (strong, nonatomic) UILabel* liveSystemMessageLabel;

/**
 * 直播弹幕发送人昵称的文本颜色，值是hex形式，例如@"#8CE7FF"
 * 默认是根据发送人nick hash出的随机颜色
 */
@property (copy, nonatomic) NSString* uniformSenderColor;

/**
 * 直播弹幕内容的文本颜色，值是hex形式，例如@"#8CE7FF"
 * 默认是白色
 */
@property (copy, nonatomic) NSString* uniformContentColor;

/**
 * @brief 插入直播系统消息
 * @param message 消息内容
 */
- (void)insertLiveSystemMessage:(NSString*)message;

/**
 * @brief 插入直播系统消息
 * @param messageModel 消息model
 */
- (void)insertLiveSystemMessageModel:(ASLRBLiveSystemMessageModel*)messageModel;

/**
 * 插入普通直播弹幕
 * @param comment 弹幕model
 * @param presentedCompulsorily 是否强制显示，默认不强制
 */
- (void) insertLiveComment:(ASLRBLiveCommentModel*)comment
     presentedCompulsorily:(BOOL)presentedCompulsorily;

/**
 * 插入普通直播弹幕
 * @param content 弹幕内容
 * @param nick 弹幕发送者昵称
 * @param presentedCompulsorily 是否强制显示，默认不强制
 */
- (void) insertLiveComment:(NSString*)content
         commentSenderNick:(NSString*)nick
     presentedCompulsorily:(BOOL)presentedCompulsorily;

@end

NS_ASSUME_NONNULL_END
