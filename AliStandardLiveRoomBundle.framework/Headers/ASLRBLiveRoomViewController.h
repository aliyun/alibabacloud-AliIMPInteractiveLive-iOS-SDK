//
//  ASLRBLiveRoomViewController.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/7/20.
//

#import <UIKit/UIKit.h>
#import "ASLRBCommonDefines.h"
#import "ASLRBLiveCommentViewProtocol.h"
#import "ASLRBLiveRoomAnchorProtocol.h"
#import "ASLRBLiveRoomAudienceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveRoomViewController,ASLRBLiveInitConfig,ASLRBLiveCommentView;


#pragma mark - ASLRBLiveRoomViewControllerDelegate Interface
@protocol ASLRBLiveRoomViewControllerDelegate <NSObject>
- (void) onASLRBLiveRoomEventInViewController:(ASLRBLiveRoomViewController *)liveRoomVC liveRoomEvent:(ASLRBEvent)liveRoomEvent info:(NSDictionary*)info;


- (void) onASLRBLiveRoomErrorInViewController:(ASLRBLiveRoomViewController *)liveRoomVC liveRoomError:(ASLRBLiveRoomError)liveRoomError withErrorMessage:(NSString*)errorMessage;
@end

@interface ASLRBLiveRoomViewController : UIViewController<ASLRBLiveRoomAnchorProtocol, ASLRBLiveRoomAudienceProtocol>

/**
 *用来接收事件和错误通知，必传
 */
@property (weak, nonatomic) id<ASLRBLiveRoomViewControllerDelegate> delegate;

/** **********************************此部分各种Holder是用来承载业务方自定义的各种UI控件的背景view ************************************ */

/**
 * 主播端：这是一层覆盖在本VC.view上的透明的开播预览层，可以添加预览页的UI，在调用startLive后会被内部自动移除;
 */
@property(nonatomic, strong) UIView* _Nullable livePrestartCustomizedViewHolder;

/**
 * 位于屏幕左上位置的用户自定义区域，便于在上面添加自定义控件，比如主播头像等
 */
@property (strong, nonatomic) UIView* upperLeftCustomizedViewHolder;

/**
 * 位于屏幕右上位置（跟upperLeftCustomizedViewHolder保持水平）的用户自定义区域，便于在上面添加自定义控件，比如退出直播按钮等
 */
@property (strong, nonatomic) UIView* upperRightCustomizedViewHolder;

/**
 * 位于中间位置的用户自定义区域，便于在上面添加自定义控件
 */
@property (strong, nonatomic) UIView* middleCustomizedViewHolder;

/**
 * 位于底部位置的用户自定义区域，便于在上面添加自定义控件，比如弹幕输入框、点赞按钮等
 */
@property (strong, nonatomic) UIView* bottomCustomizedViewHolder;

/** **********************************此部分各种Holder是用来承载业务方自定义的各种UI控件的背景view ************************************ */


/** **********************************此部分是内部已经定义好的UI控件 ************************************ */

/**
 * 展示评论的view，目前不支持外部定义；注意外部更改commentView的frame时需要使用Masonry的mas_remakeConstraints接口；
 */
@property (strong, nonatomic) UIView<ASLRBLiveCommentViewProtocol>* liveCommentView;

/** **********************************此部分是内部已经定义好的UI控件 ************************************ */

/** **********************************此部分是主播端和观众端共同使用的接口 ************************************ */

/**
 *直播间背景图，不传时则使用内部默认图；
 */
@property (nonatomic, strong) UIImage* backgroundImage;

/**
 * 在push当前vc之前调用，用来做进入直播页面前的准备工作；注意在onSuccess之后才可以push当前vc；
 * @param onSuccess  setup成功时回调，如果之前没有传入live-id，此时会回传创建直播成功后的live-id；注意避免block内强引用外部对象造成循环引用
 * @param onFailure  setup失败时回调，会有具体的错误信息；注意避免block内强引用外部对象造成循环引用;
 */
- (void) setupOnSuccess:(void(^)(NSString* liveID))onSuccess
              onFailure:(void(^)(NSString* errorMessage))onFailure;

/**
 * 主播端调用的效果：结束当前直播，退出直播间;
 * 观众端调用的效果：退出直播间;
 */
- (void) exitLiveRoom;

/**
 * 弹幕区发送消息;
 * @param message 要发送的消息内容
 * @param onSuccess 成功的回调
 * @param onFailure 失败的回调
 */
- (void) sendComment:(NSString *)message
           onSuccess:(void (^)(void))onSuccess
           onFailure:(void (^)(ASLRBLiveRoomError code, NSString * errorMessage))onFailure;

/**
 * 弹幕区发送消息;
 * @param message 要发送的消息内容
 * @param extension 自定义扩展字段
 * @param onSuccess 成功的回调
 * @param onFailure 失败的回调
 */
- (void) sendComment:(NSString *)message
           extension:(NSDictionary<NSString *,NSString *> *)extension
           onSuccess:(void (^)(void))onSuccess
           onFailure:(void (^)(ASLRBLiveRoomError code, NSString * errorMessage))onFailure;

/**
 * 开启/关闭全员禁言，主播端调用
 * @param ban 是否开启禁言全员禁言，为YES则开启，为NO则关闭
 */
- (void) banAllComments:(BOOL)ban;

/**
 * 点赞，一次一个，内部会对短时间内的多次点赞进行聚合;
 */
- (void) sendLike;

/**
 * 发送自定义消息给特定用户，仅主播侧调用有效
 */
- (void) sendCustomMessage:(NSString*)message toUsers:(NSArray<NSString*>*)userIDs onSuccess:(void (^)(void))onSuccess onFailure:(void (^)(NSString* errorMessage))onFailure;

/**
 * 发送自定义消息给直播间内的所有用户，仅主播侧调用有效
 */
- (void) sendCustomMessageToAll:(NSString*)message
                      onSuccess:(void (^)(void))onSuccess
                      onFailure:(void (^)(NSString* errorMessage))onFailure;

@end

NS_ASSUME_NONNULL_END
