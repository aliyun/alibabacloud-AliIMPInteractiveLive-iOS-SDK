//
//  ASLRBLiveSystemMessageModel.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/10/15.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ASLRBLiveSystemMessageLevel)
{
    ASLRBLiveSystemMessageLevelNomal = 0,  //普通级别，累积较多时可能会丢弃
};

NS_ASSUME_NONNULL_BEGIN

@interface ASLRBLiveSystemMessageModel : NSObject
@property (strong, nonatomic) NSMutableAttributedString* message;
@property (assign, nonatomic) ASLRBLiveSystemMessageLevel level;
@end

NS_ASSUME_NONNULL_END
