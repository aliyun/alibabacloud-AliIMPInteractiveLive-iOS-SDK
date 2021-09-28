//
//  AIRBRoomSceneLiveProtocol.h
//  AliInteractiveRoomBundle
//
//  Created by fernando on 2021/9/15.
//  Copyright © 2021 AliYun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AIRBRoomSceneLiveProtocol <NSObject>
- (void) createLiveWithTitle:(NSString*)title
                      notice:(NSString*)notice
                    coverUrl:(NSString*)url
                  anchorNick:(NSString*)nick
                   extension:(NSDictionary*)extension
                   onSuccess:(void(^)(NSDictionary* response))onSuccess
                   onFailure:(void(^)(NSString* error))onFailure;

- (void) stopLiveWithLiveID:(NSString*)liveID
                  onSuccess:(void(^)(void))onSuccess
                  onFailure:(void(^)(NSString* error))onFailure;

- (void) getLiveDetailWithLiveID:(NSString*)liveID
                       onSuccess:(void(^)(NSDictionary* response))onSuccess
                       onFailure:(void(^)(NSString* error))onFailure;

- (void) getLiveListWithStatus:(int32_t)status
                       pageNum:(int32_t)pageNum
                      pageSize:(int32_t)pageSize
                     onSuccess:(void(^)(NSDictionary* response))onSuccess
                     onFailure:(void(^)(NSString* error))onFailure;
@end

NS_ASSUME_NONNULL_END
