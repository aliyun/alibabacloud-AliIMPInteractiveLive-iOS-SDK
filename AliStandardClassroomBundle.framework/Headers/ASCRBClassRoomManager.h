//
//  ASCRBClassRoomManager.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ASCRBCommonDefines.h"

NS_ASSUME_NONNULL_BEGIN


@class ASCRBAppInitConfig, ASCRBClassInitConfig, ASCRBClassRoomViewController;
@protocol ASCRBTeacherViewController4PadProtocol;
@protocol ASCRBStudentViewController4PadProtocol;

@interface ASCRBClassRoomManager : NSObject
/**
 * 获取ClassRoomManager全局单例对象
 */
+ (ASCRBClassRoomManager*)sharedInstance;

- (id<ASCRBTeacherViewController4PadProtocol>) createTeacherVC4PadWithAppInitConfig:(ASCRBAppInitConfig*)appInitConifg
                                                                    classInitConfig:(ASCRBClassInitConfig*)classInitConfig;

- (id<ASCRBStudentViewController4PadProtocol>) createStudentVC4PadWithAppInitConfig:(ASCRBAppInitConfig*)appInitConifg
                                                                    classInitConfig:(ASCRBClassInitConfig*)classInitConfig;
@end

NS_ASSUME_NONNULL_END
