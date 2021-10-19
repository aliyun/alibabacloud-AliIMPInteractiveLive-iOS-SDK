//
//  ASLRBAppInitConfig.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "ASLRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ASLRBAppInitConfig : NSObject
/**
 *在阿里云互动直播控制台上开通应用后获得，必传
 */
@property (nonatomic, copy) NSString* appKey;

/**
 *在阿里云互动直播控制台上开通应用后获得，必传
 */
@property (nonatomic, copy) NSString* appID;

/**
 *已经部署了互动直播服务的用户服务器地址，必传，例如https://xxx.com
 */
@property (nonatomic, copy) NSString* appServerUrl;

/**
 *在阿里云互动直播控制台上开通应用后获得，必传
 */
@property (nonatomic, copy) NSString* appServerSignSecret;

/**
 *用户id，仅支持英文字母或者阿拉伯数字或者二者的组合，必传
 */
@property (nonatomic, copy) NSString* userID;

/**
 *用户昵称，支持任意字符，必传
 */
@property (nonatomic, copy) NSString* userNick;
@end

NS_ASSUME_NONNULL_END
