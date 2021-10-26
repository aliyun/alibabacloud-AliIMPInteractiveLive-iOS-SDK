//
//  ASLRBLiveRoomViewController.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/7/20.
//

#import <UIKit/UIKit.h>
#import "ASLRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class ASLRBLiveRoomViewController,ASLRBLiveInitConfig,ASLRBLiveCommentView;


#pragma mark - ASLRBLiveRoomViewControllerDelegate Interface
@protocol ASLRBLiveRoomViewControllerDelegate <NSObject>
- (void) onASLRBLiveRoomEventInViewController:(ASLRBLiveRoomViewController *)liveRoomVC liveRoomEvent:(ASLRBEvent)liveRoomEvent info:(NSDictionary*)info;


- (void) onASLRBLiveRoomErrorInViewController:(ASLRBLiveRoomViewController *)liveRoomVC liveRoomError:(ASLRBLiveRoomError)liveRoomError withErrorMessage:(NSString*)errorMessage;
@end

@interface ASLRBLiveRoomViewController : UIViewController

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
@property (strong, nonatomic) ASLRBLiveCommentView* liveCommentView;

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

/** **********************************此部分是主播端和观众端共同使用的接口 ************************************ */

/** **********************************此部分是仅主播端使用的接口 ************************************ */
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

/** **********************************此部分是仅主播端使用的接口 ************************************ */

/** **********************************此部分是仅观众端使用的接口 ************************************ */

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

/** **********************************此部分是仅观众端使用的接口 ************************************ */

@end

NS_ASSUME_NONNULL_END
