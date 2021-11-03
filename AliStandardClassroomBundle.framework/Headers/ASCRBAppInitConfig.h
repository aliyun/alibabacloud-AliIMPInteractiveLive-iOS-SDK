//
//  ASCRBAppInitConfig.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>
#import "ASCRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ASCRBAppInitConfig : NSObject
/**
 *在阿里云低代码音视频工厂控制台上开通应用后获得，必传
 */
@property (nonatomic, copy) NSString* appID;

/**
 *在阿里云低代码音视频工厂控制台上开通应用后获得，必传
 */
@property (nonatomic, copy) NSString* appKey;

/**
 *已经部署了低代码音视频工厂服务的用户服务器地址，必传，例如https://xxx.com
 */
@property (nonatomic, copy) NSString* appServerUrl;

/**
 *在阿里云低代码音视频工厂控制台上开通应用后获得，必传
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
