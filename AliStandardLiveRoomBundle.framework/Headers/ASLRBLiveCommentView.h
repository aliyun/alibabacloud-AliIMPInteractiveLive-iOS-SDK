//
//  ASLRBLiveCommentView.h
//  AliStandardLiveRoomBundle
//
//  Created by fernando on 2021/10/25.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASLRBLiveCommentView : UIView
@property (assign, nonatomic) BOOL showComment; //默认为NO;
@property (assign, nonatomic) BOOL showLiveSystemMessage; //默认为NO;

- (void)insertNewComment:(NSString*) comment;
- (void)insertNewCommentCompulsorily:(NSString*)comment;

- (void)insertLiveSystemMessage:(NSString*)message duration:(float)seconds;
@end

NS_ASSUME_NONNULL_END
