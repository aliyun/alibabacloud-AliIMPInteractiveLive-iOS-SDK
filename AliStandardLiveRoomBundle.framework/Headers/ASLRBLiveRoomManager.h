//
//  ASLRBLiveRoomManager.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ASLRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN


@class ASLRBAppInitConfig, ASLRBLiveInitConfig, ASLRBLiveRoomViewController;

@interface ASLRBLiveRoomManager : NSObject
/**
 * 获取RoomEngine全局单例对象
 */
+ (ASLRBLiveRoomManager*)sharedInstance;

/**
 * 全局初始化，只需要调用一次；收到onSuccess后再进行下一步；
 * @param config 初始化需要的配置信息，具体见ASLRBAppInitConfig
 * @param onSuccess  初始化成功后回调；注意避免block内强引用外部对象造成循环引用
 * @param onFailure  初始化失败时回调，会有具体的错误信息；注意避免block内强引用外部对象造成循环引用
 */
- (void) globalInitOnceWithConfig:(ASLRBAppInitConfig*)config
                        onSuccess:(void(^)(void))onSuccess
                        onFailure:(void(^)(NSString* errorMessage))onFailure;


- (ASLRBLiveRoomViewController*) createLiveRoomVCWithConfig:(ASLRBLiveInitConfig*)config;
@end

NS_ASSUME_NONNULL_END
