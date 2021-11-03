//
//  ASCRBTeacherViewController4PadProtocol.h
//  AliStandardClassroomBundle
//
//  Created by 刘再勇 on 2021/10/26.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@protocol ASCRBTeacherViewController4PadProtocol <NSObject>

/**
 * 在push当前vc之前调用，用来做进入课堂页面前的准备工作；注意在onSuccess之后才可以push当前vc；
 * @param onSuccess  setup成功时回调，如果是老师并且之前没有传入class_id，此时会回传创建直播成功后的class_id；注意避免block内强引用外部对象造成循环引用
 * @param onFailure  setup失败时回调，会有具体的错误信息；注意避免block内强引用外部对象造成循环引用;
 */
- (void) setupOnSuccess:(void(^)(NSString* classID))onSuccess
              onFailure:(void(^)(NSString* errorMessage))onFailure;


@end

NS_ASSUME_NONNULL_END
