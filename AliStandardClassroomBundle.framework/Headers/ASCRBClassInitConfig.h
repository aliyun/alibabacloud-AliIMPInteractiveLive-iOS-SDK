//
//  ASCRBClassInitConfig.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/14.
//

#import <Foundation/Foundation.h>

#import "ASCRBGeneralDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ASCRBClassInitConfig : NSObject

/**
 * 本堂课程的用户角色，老师或学生，必传
 */
@property (nonatomic, assign) ASCRBUserRole role;

/**
 * 本堂课程的ID，老师侧非必传，观众侧必传
 * @note 老师侧classID为空则会创建课程
 */
@property (nonatomic, copy) NSString* classID;

/**
 * 本堂课程的标题，非必传
 */
@property (nonatomic, copy) NSString* classTitle;

@end

NS_ASSUME_NONNULL_END
