//
//  ASCRBClassroomManager.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ASCRBGeneralDefines.h"

NS_ASSUME_NONNULL_BEGIN


@class ASCRBAppInitConfig, ASCRBClassInitConfig, ASCRBClassroomVCBaseFunction;
@protocol ASCRBTeacherViewController4PadProtocol;
@protocol ASCRBStudentViewController4PadProtocol;

@interface ASCRBClassroomManager : NSObject
/**
 * 获取ClassRoomManager全局单例对象
 */
+ (ASCRBClassroomManager*)sharedInstance;

/**
 * 接收内部日志用的block；注意避免block强引用外部对象；
 * 注意：必须要在globalInitOnceWithConfig之前设置；
 */
@property (strong, nonatomic) void(^onLogMessage)(NSString* log);

- (id<ASCRBTeacherViewController4PadProtocol>) createTeacherVC4PadWithAppInitConfig:(ASCRBAppInitConfig*)appInitConifg
                                                                    classInitConfig:(ASCRBClassInitConfig*)classInitConfig;

- (id<ASCRBStudentViewController4PadProtocol>) createStudentVC4PadWithAppInitConfig:(ASCRBAppInitConfig*)appInitConifg
                                                                    classInitConfig:(ASCRBClassInitConfig*)classInitConfig;
@end

NS_ASSUME_NONNULL_END
