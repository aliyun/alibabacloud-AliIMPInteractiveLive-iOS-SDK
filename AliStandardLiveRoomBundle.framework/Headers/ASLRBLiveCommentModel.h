//
//  ASLRBLiveCommentModel.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/12/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASLRBLiveCommentModel : NSObject
@property (copy, nonatomic) NSString* senderNick;
@property (strong, nonatomic) UIColor*  senderNickColor;
@property (copy, nonatomic) NSString* senderID;
@property (copy, nonatomic) NSString* sentContent;
@property (strong, nonatomic) UIColor*  sentContentColor;
@end

NS_ASSUME_NONNULL_END
