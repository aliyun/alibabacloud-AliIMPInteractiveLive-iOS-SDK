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

/**
 * 是否禁止录屏，非必传，默认为否
 */
@property (nonatomic, assign) BOOL screenSecure;

/**
 * 直播视频画面的水印图片URL，非必传
 * @note 学生端生效，铺满播放器画面
 */
@property (nonatomic, copy) NSString* videoWatermarkUrl;

@end

NS_ASSUME_NONNULL_END
