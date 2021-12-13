//
//  ASCRBTeacherViewController4PadProtocol.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/26.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

#pragma mark - ASCRBTeacherViewController4PadProtocolDelegate Interface
@protocol ASCRBTeacherViewController4PadProtocolDelegate <NSObject>

- (void) onASCRBTeacherViewController4Pad:(id<ASCRBTeacherViewController4PadProtocol>)classroomVC classroomEvent:(ASCRBClassroomEvent)classroomEvent info:(NSDictionary*)info;
- (void) onASCRBTeacherViewController4Pad:(id<ASCRBTeacherViewController4PadProtocol>)classroomVC classroomError:(ASCRBClassroomError)classroomError withErrorMessage:(NSString*)errorMessage;

@end

@protocol ASCRBTeacherViewController4PadProtocol <NSObject>

/**
 * 用来接收事件和错误通知，必传
 */
@property (weak, nonatomic) id<ASCRBTeacherViewController4PadProtocolDelegate> delegate;

/**
 * 用来做进入课堂页面前的准备工作
 * @note 如果成功，会收到ASCRBClassroomEventSetupSucceed事件，注意在收到成功事件之后才可以push当前vc；如果失败，会收到ASCRBTeacherErrorFailedToSetup错误
 */
- (void) setup;


@end

NS_ASSUME_NONNULL_END
