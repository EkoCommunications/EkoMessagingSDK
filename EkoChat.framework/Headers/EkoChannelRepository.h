//
//  EkoChannelRepository.h
//  EkoChat
//
//  Created by eko on 1/25/18.
//  Copyright © 2018 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "EkoChannel.h"
#import "EkoChannelNotificationsManager.h"
#import "EkoClient.h"
#import "EkoCollection.h"
#import "EkoChannelQueryBuilder.h"

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access channel and collections of channels
 */
@interface EkoChannelRepository : NSObject

@property (strong, readonly, nonatomic) EkoClient *client;
@property (readonly, nonatomic) NSUInteger totalUnreadCount;

/**
 * Designated intializer
 * @param client A valid context instance
 */
- (instancetype)initWithClient:(EkoClient *)client NS_DESIGNATED_INITIALIZER;

/**
 * Returns a collection of all channels where the user is in, filtered by the specific mode
 *
 * @param filter Indicates whether we want channels where the user is member, not member, or both
 *
 * @return Collection instance
 */
- (nonnull EkoCollection<EkoChannel *> *)channelsForFilter:(EkoChannelQueryFilter)filter DEPRECATED_MSG_ATTRIBUTE("Deprecated start from 3.0, this no longer be supported in the long term, please use channel collection with builder instead.");

/**
 * Create a channel
 *
 * @param channelId A channel Identifier
 * @param displayName The Channel display name (this can be changed later)
 * @param type The channel type
 * @param metadata Your custom metadata to associate with the channel
 * @param userIds An array of user Ids
 */
- (EkoObject<EkoChannel *> *)createChannel:(nullable NSString *)channelId
                               displayName:(nullable NSString *)displayName
                                      type:(EkoChannelCreateType)type
                                  metadata:(nonnull NSDictionary<NSString *, id> *)metadata
                                     users:(nonnull NSArray<NSString *> *)userIds;

/**
 * Create a channel
 * Convenience method with the few required parameters:
 * in this case an empty dictionary to metadata, and the channel displayName is not set at all (nil)
 *
 * @param channelId A channel Identifier
 * @param type The channel type
 * @param userIds An array of user Ids
 */
- (EkoObject<EkoChannel *> *)createChannel:(nullable NSString *)channelId
                                      type:(EkoChannelCreateType)type
                                     users:(nonnull NSArray<NSString *> *)userIds;

/**
 * Create a channel
 *
 * @param channelId A channel Identifier
 * @param displayName The Channel display name (this can be changed later)
 * @param type The channel type
 * @param metadata Your custom metadata to associate with the channel
 * @param tags Your custom tags to associate with the channel
 * @param userIds An array of user Ids
 */
- (nonnull EkoObject<EkoChannel *> *)createChannel:(nullable NSString *)channelId
                                       displayName:(nullable NSString *)displayName
                                              type:(EkoChannelCreateType)type
                                          metadata:(nonnull NSDictionary<NSString *, id> *)metadata
                                              tags:(nonnull NSArray<NSString *> *)tags
                                             users:(nonnull NSArray<NSString *> *)userIds;

/**
 * Joins a channel by channel Id, if you are already in this channel, it will fetch the existing channel. **Note:** Starting from SDK version 3.0, this method doesnot creates a new channel, if the channel doesnot exists.
 * @param channelId A valid Channel Id
 * @return A Proxy Object for the channel
 */
- (EkoObject<EkoChannel *> *)joinChannel:(nonnull NSString *)channelId type:(EkoChannelType)type;


/**
 * Gets an existing channel by channel Id
 */
- (EkoObject<EkoChannel *> *)getChannel:(nonnull NSString *)channelId;

/**
   Sets the metadata for the channel
   @param channelId  A valid Channel Id
   @param data A dictionary containing metadata
 */
- (void)setMetadataForChannel:(nonnull NSString *)channelId
                         data:(nullable NSDictionary<NSString *, id> *)data
                   completion:(nullable EkoRequestCompletion)completion;

/**
   Sets the display name for the channel
   @param channelId  A valid Channel Id
   @param displayName a display name for the channel
 */
- (void)setDisplayNameForChannel:(nonnull NSString *)channelId
                     displayName:(nonnull NSString *)displayName
                      completion:(nullable EkoRequestCompletion)completion;

/**
   Sets the tags for the given channel
   @param channelId  A valid Channel Id
   @param tags An array of tags
 */
- (void)setTagsForChannel:(nonnull NSString *)channelId
                     tags:(nullable NSArray<NSString *> *)tags
               completion:(nullable EkoRequestCompletion)completion;


/**
   Sets the tags for the given channel
   @param channelId  A valid Channel Id
   @param image An image. Put nil if you want to remove the avatar
 */
- (void)setAvatarForChannel:(nonnull NSString *)channelId
                     avatar:(nullable UIImage *)image
                 completion:(nullable EkoRequestCompletion)completion;


/**
   @abstract Returns a collection of all channels, filtered by the specific filter and tags
   @note A channel is matched when it contains ANY tag listed in includingTags, and contains NONE of the tags listed in excludingTags

   @param filter Indicates whether we want channels where the user is member, not member, or both
   @param includingTags The list of required channel tags, pass an empty array to ignore this requirement
   @param excludingTags The list of tags required not to be set in the channels, pass an empty array to ignore this requirement
   @return Collection instance
 */
- (nonnull EkoCollection<EkoChannel *> *)channelsForFilter:(EkoChannelQueryFilter)filter
                                             includingTags:(nonnull NSArray<NSString *> *)includingTags
                                             excludingTags:(nonnull NSArray<NSString *> *)excludingTags DEPRECATED_MSG_ATTRIBUTE("Deprecated start from 3.0, this no longer be supported in the long term, please use channel collection with builder instead.");

/**
 * Create a conversation channel
 *
 * @param userId An user Identifier that we want to chat with
 * @param displayName The Channel display name (this can be changed later)
 * @param metadata Your custom metadata to associate with the channel
 * @param tags Your custom tags to associate with the channel
 */
- (nonnull EkoObject<EkoChannel *> *)createConversation:(nonnull NSString *)userId
                                            displayName:(nullable NSString *)displayName
                                               metadata:(nonnull NSDictionary<NSString *, id> *)metadata
                                                   tags:(nonnull NSArray<NSString *> *)tags;

/**
   Create a new channel query builder in order to get specific channel types
   @note Hence client must specify the channel types with declarative ways in order get the correct  designated builder
   @return ChannelQueryBuilder instance
 */
- (nonnull EkoChannelQueryBuilder *)channelCollection;

/**
   @abstract Channel Level Push Notifications Management object.
 */
- (nonnull EkoChannelNotificationsManager *)notificationManagerForChannelId:(nonnull NSString *)channelId;

/**
   Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
