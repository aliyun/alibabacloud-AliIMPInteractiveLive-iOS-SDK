//
//  ASLRBLiveCommentViewProtocol.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/10/27.
//

#import <Foundation/Foundation.h>
#import <AliStandardLiveRoomBundle/ASLRBLiveCommentModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ASLRBLiveCommentViewDelegate <NSObject>
- (void) onASLRBLiveCommentJustAboutToPresent:(ASLRBLiveCommentModel*)comment;
@end

@protocol ASLRBLiveCommentViewProtocol <NSObject>

/**
 * 直播评论区的各种事件回调
 */
@property (weak, nonatomic) id<ASLRBLiveCommentViewDelegate> delegate;

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
 * 插入直播系统消息
 * @param message 消息内容
 * @param seconds 消息停留的秒数
 */
- (void)insertLiveSystemMessage:(NSString*)message duration:(float)seconds;

@end

NS_ASSUME_NONNULL_END
