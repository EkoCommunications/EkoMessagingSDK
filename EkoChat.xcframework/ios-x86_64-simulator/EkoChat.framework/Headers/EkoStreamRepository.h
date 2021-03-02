//
//  EkoStreamRepository.h
//  EkoChat
//
//  Created by Nutchaphon Rewik on 22/9/2563 BE.
//  Copyright © 2563 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <EkoChat/EkoObject.h>
#import <EkoChat/EkoCollection.h>

@class EkoStream;
@class EkoObject;
@class EkoClient;
@class EkoCollection;
@class EkoLiveStreamURLInfo;
@class EkoStreamNotificationsManager;

NS_ASSUME_NONNULL_BEGIN

@class EkoStreamCollectionQuery;

/// EkoStreamRepository manages stream objects
@interface EkoStreamRepository : NSObject

#pragma mark - Initializer

/// The context used to create the instance.
@property (nonnull, strong, readonly, nonatomic) EkoClient *client;

/// Designated intializer.
/// @param client A valid context instance.
- (nonnull instancetype)initWithClient:(nonnull EkoClient *)client NS_DESIGNATED_INITIALIZER;

#pragma mark - Query

/// Get the collection of streams for the specified statuses..
- (EkoCollection<EkoStream *> *)getStreamsCollectionFormQuery:(EkoStreamCollectionQuery *)query NS_SWIFT_NAME(getStreamsCollection(from:));

/// Get a live object of stream, by id.
/// @param streamId The unique identifer of stream
- (EkoObject<EkoStream *> *)getStreamById:(nullable NSString *)streamId;

/// Create a new video stream.
- (void)createVideoStreamWithTitle:(nonnull NSString *)title
                       description:(nullable NSString *)description
                        completion:(void (^_Nonnull)(EkoStream * _Nullable, NSError * _Nullable))completion;

/// Send the request to update streaming status to ".ended", and dispose streaming url.
- (void)disposeStreamWithId:(NSString *)streamId
                 completion:(void (^_Nonnull)(EkoStream * _Nullable, NSError * _Nullable))completion;

/* Not used in this version.
/// @abstract User Level Notification Management object.
@property (nonnull, readonly, nonatomic) EkoStreamNotificationsManager *notificationManager;
 */

#pragma mark - Prevent default initializer

/// Block call of `init` and `new` because this object cannot be created directly
- (instancetype)init NS_UNAVAILABLE;

/// Block call of `init` and `new` because this object cannot be created directly
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
