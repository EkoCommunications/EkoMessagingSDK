//
//  EkoFileRepository.h
//  EkoChat
//
//  Created by Nishan Niraula on 7/8/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EkoClient.h"
#import "EkoMessage.h"
#import "EkoImageData.h"
#import "EkoFileData.h"

@class UIImage;
@class UploadableFile;

typedef void (^EkoFileUploadCompletion)(NSArray<EkoFileData *> * _Nonnull fileIds, NSArray<UploadableFile *> * _Nonnull failedUploads);
typedef void (^EkoImageUploadCompletion)(NSArray<EkoImageData *> * _Nonnull fileIds, NSArray<UIImage *> * _Nonnull failedUploads);

NS_ASSUME_NONNULL_BEGIN

@interface EkoFileRepository : NSObject

@property (strong, readonly, nonatomic) EkoClient *client;

/**
   Designated intializer
   @param client A valid context instance
 */
- (instancetype)initWithClient:(EkoClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Uploads images to File Service. Use this api in conjunction to another api such as create post etc
 @param images: Array of images to be uploaded. **Note** The max limit is 10.
 @param completionBlock: Returns the array of uploaded ImageData & array of failed uploads if any.
 */
- (void)uploadImages:(NSArray<UIImage *> *)images completion: (EkoImageUploadCompletion)completionBlock;

/**
 Uploads Files to FileService. Use this api in conjunction to another api such as create post etc.
 @param files: Array of files to be uploaded. *Note* The max limit is 10.
 @param completionBlock: Returns the array of uploaded FileData & array of failed uploads if any.
 */
- (void)uploadFiles:(NSArray<UploadableFile *> *)files completion: (EkoFileUploadCompletion)completionBlock;

/**
 Downloads the images from file service. Image is downloaded asynchronously.
 @param fileId : The file id for the image to be downloaded
 @param size : The size in which image is to be downloaded.
 @param completion Returns the downloaded image if success. Else returns error.
*/
- (void)downloadImage:(NSString *)fileId size:(EkoMediaSize)size completion:(void (^)(UIImage * _Nullable image, EkoMediaSize size, NSError * _Nullable error))completion;

/**
 Downloads the file from FileService. File is downloaded asynchronously
 @param fileId : Id of the file to be downloaded
 @param completion Returns the downloaded file if success. Else returns error
 */
- (void)downloadFile:(NSString *)fileId completion:(void (^)(NSData * _Nullable file, NSError * _Nullable error))completion;

/**
 Cancels the download of file from FileService
 
 @param fileId: Id of the file
 */
- (void)cancelFileDownload:(NSString *)fileId;

/**
 Cancels the download of images from File Service
 
 @param fileId: Id of the image file
 @param size: Size of image
 */
- (void)cancelImageDownload:(NSString *)fileId size:(EkoMediaSize)size;

/**
 Prevent direct initialization of this class.
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
