//
//  ASCRBCommonDefines.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ASCRBClassRoomViewControllerType)
{
    ASCRBClassRoomViewControllerTypeTeacher4Pad = 0,
    ASCRBClassRoomViewControllerTypeStudent4Pad,
    ASCRBClassRoomViewControllerTypeStudent4Phone
};


typedef NS_ENUM(NSInteger, ASCRBUserRole)
{
    ASCRBUserRoleTeacher = 0,
    ASCRBUserRoleStudent
};
