//
//  EkoCommunityParticipation.h
//  EkoChat
//
//  Created by Nishan Niraula on 10/7/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EkoChat/EkoClient.h>
#import <EkoChat/EkoCollection.h>
#import <EkoChat/EkoCommunityMembership.h>

NS_ASSUME_NONNULL_BEGIN

@interface EkoCommunityParticipation : NSObject

/**
 The client used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) EkoClient *client;

/**
 The channel Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *communityId;

/**
 Designated intializer
 @param client A valid client instance
 @param channelId The Id of the channel to update
 */
- (nonnull instancetype)initWithClient:(nonnull EkoClient *)client
                        andCommunityId:(nonnull NSString *)communityId NS_DESIGNATED_INITIALIZER;

/**
 Adds users to the community
 
 @param userIds An array of users Ids to add
 @param completion A block executed when the request has completed
 */
- (void)addUsers:(nonnull NSArray<NSString *> *)userIds completion:(EkoRequestCompletion _Nullable)completion;

/**
 Removes users from the channel
 
 @param userIds An array of users Ids to remove
 @param completion A block executed when the request has completed
 */
- (void)removeUsers:(nonnull NSArray<NSString *> *)userIds completion:(EkoRequestCompletion _Nullable)completion;

/**
 Get membership information of this community
 
 @param communityId The id for the community
 @param membership The membership option that user wish to select
 @param roles The list of roles to filter. If you don't want to filter by roles, set empty array instead.
 @param sortBy The sort option that user wish to select
 */
- (nonnull EkoCollection<EkoCommunityMembership *> *)getMemberships:(EkoCommunityMembershipFilter)filter roles:(NSArray<NSString *> *)roles sortBy:(EkoCommunityMembershipSortOption)sortBy;

/**
 Get membership information for particular user
 
 @param userId: The id of the user
 @return: Returns EkoCommunityMembership object
 */
- (nullable EkoCommunityMembership *)getMembership:(NSString *)userId;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
