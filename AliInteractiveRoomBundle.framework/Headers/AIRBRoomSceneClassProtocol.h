//
//  AIRBRoomSceneClassProtocol.h
//  AliInteractiveRoomBundle
//
//  Created by fernando on 2021/9/15.
//  Copyright © 2021 AliYun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AIRBRoomSceneClassProtocol <NSObject>

-(void)createClassWithTitle:(NSString*)title
                   nickName:(NSString*)nickName
                  onSuccess:(void(^)(NSDictionary* response))onSuccess
                  onFailure:(void(^)(NSString* error))onFailure;

-(void)getClassDetailWithClassID:(NSString*)classID
                          onSuccess:(void(^)(NSDictionary* response))onSuccess
                          onFailure:(void(^)(NSString* error))onFailure;

-(void)startClassWithClassID:(NSString*)classID
                   onSuccess:(void(^)(void))onSuccess
                   onFailure:(void(^)(NSString* error))onFailure;

-(void)stopClassWithClassID:(NSString*)classID
                  OnSuccess:(void(^)(void))onSuccess
                  onFailure:(void(^)(NSString* error))onFailure;

@end

NS_ASSUME_NONNULL_END
