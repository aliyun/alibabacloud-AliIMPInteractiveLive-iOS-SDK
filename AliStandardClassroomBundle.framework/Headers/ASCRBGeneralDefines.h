//
//  ASCRBGeneralDefines.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ASCRBUserRole)
{
    ASCRBUserRoleTeacher = 0,
    ASCRBUserRoleStudent
};

typedef NS_ENUM(NSInteger, ASCRBClassroomEvent)
{
    /*
     vc设置成功，跟随当前事件的info信息如下，
     {
        @"classID":xxxxx,      //课程ID
     }
     */
    ASCRBClassroomEventSetupSucceed = 0,
    
    /*
     离开教室，跟随当前事件的info信息为空
     */
    ASCRBClassroomEventLeaveClassroom,
};

typedef NS_ENUM(NSInteger, ASCRBClassroomError)
{
    ASCRBClassroomErrorFailedToSetup = 0,
};
