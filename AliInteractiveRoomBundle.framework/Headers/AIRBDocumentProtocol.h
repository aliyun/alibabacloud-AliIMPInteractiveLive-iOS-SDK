//
//  AIRBDocumentProtocol.h
//  AliInteractiveRoomBundle
//
//  Created by fernando on 2021/9/3.
//  Copyright © 2021 AliYun. All rights reserved.
//

#ifndef AIRBDocumentProtocol_h
#define AIRBDocumentProtocol_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AIRBDocumentTargetConversionFormat)
{
    AIRBDocumentTargetConversionFormatJPG = 0,
    AIRBDocumentTargetConversionFormatPNG,
    AIRBDocumentTargetConversionFormatPDF
};

@protocol AIRBDocumentProtocol <NSObject>

/**
 * @brief 上传文档，会获得一个documentID作为这个文档的标记
 * @param documentURL 文档地址（文档本地地址或者网络链接都可以）
 */
- (void) uploadDocument:(NSString*)documentURL
              onSuccess:(void(^)(NSString* documentID))onSuccess
              onFailure:(void(^)(NSString* errorMessage))onFailure;

/**
 * @brief 分段下载文档，onSuccess会不断被触发，每次都会返回一段内容，当下载完毕时complete为YES且同时data为nil
 * @param documentID 要下载的文档对应的ID
 */
- (void) downloadDocument:(NSString*)documentID
                onSuccess:(void(^)(NSData* data, BOOL complete))onSuccess
                onFailure:(void(^)(NSString* errorMessage))onFailure;
              
/**
 * @brief 文档格式转换
 * @param sourceDocumentID 要转换的源文档ID
 * @param targetType 要转的目标格式，目前仅支持三种，具体见AIRBDocumentTargetConversionFormat
 */
- (void) convertDocumentFormat:(NSString*)sourceDocumentID
                        toType:(AIRBDocumentTargetConversionFormat)targetType
                     onSuccess:(void(^)(NSString* targetDocumentID, NSArray<NSString*>* documentURLs))onSuccess
                     onFailure:(void(^)(NSString* errorMessage))onFailure;

/**
 * @brief 使用文档ID获取文档的存储地址链接
 * @param documentID 要获取链接的文档ID
 */
- (void) getDocumentURLs:(NSString*)documentID
               onSuccess:(void(^)(NSArray<NSString*>* documentURLs))onSuccess
               onFailure:(void(^)(NSString* errorMessage))onFailure;
@end


#endif /* AIRBDocumentProtocol_h */
