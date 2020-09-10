//
//  EkoCommunityRepository.h
//  EkoChat
//
//  Created by Michael Abadi on 03/07/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EkoClient.h"
#import "EkoCollection.h"
#import "EkoEnums.h"
#import "EkoCommunityCategory.h"

@class EkoCommunityCreator;
@class EkoCommunity;
@class EkoCommunityMembership;

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access to community and collections of communities
 */
@interface EkoCommunityRepository : NSObject

@property (strong, readonly, nonatomic) EkoClient *client;

/**
 Designated intializer
 @param client A valid context instance
 */
- (instancetype)initWithClient:(EkoClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a new Community Manager (convenience class for handling Community).
 
 @return The EkoCommunityCreator  object.
 
 @note This manager will handle all CUD operation of the Community Object
 */

- (nonnull EkoCommunityCreator *)communityCreatorManager;

/**
 Get the collection of communities.
 
 @param keyword: The keyword of display name that want to be searched
 @param filter: The filter option that user wish to select
 @param sortBy: The sort option that user wish to select
 @param categoryId: Category id for the community. This value is optional.
 
 @return The EkoCollection of EkoCommunity  object. Observe the changes for getting the result.
 */
- (nonnull EkoCollection<EkoCommunity *> *)getCommunitiesWithKeyword:(nonnull NSString *)keyword
                                                              filter:(EkoCommunityQueryFilter)filter
                                                              sortBy:(EkoCommunitySortOption)sortBy
                                                          categoryId:(nullable NSString *)categoryId;

/**
 Retrieves community for particular community id
 
 @param communityId The id for the community
 */
- (nonnull EkoObject<EkoCommunity *> *)getCommunityForCommunityId:(nonnull NSString *)communityId;

/**
 Fetches all the categories for community.
 */
- (nonnull EkoCollection<EkoCommunityCategory *> *)getAllCategories:(EkoCommunityCategoriesSortOption)sortBy;

/**
 Join community for particular community id
 
 @param communityId The id for the community
 */
- (void)joinCommunityWithCommunityId:(nonnull NSString *)communityId
                          completion:(EkoRequestCompletion _Nullable)completion;

/**
 Leave community for particular community id
 
 @param communityId The id for the community
 */
- (void)leaveCommunityWithCommunityId:(nonnull NSString *)communityId
                           completion:(EkoRequestCompletion _Nullable)completion;


/**
 Get membership information of this community
 
 @param communityId The id for the community
 @param membership The membership option that user wish to select
 @param sortBy The sort option that user wish to select
 */
- (nonnull EkoCollection<EkoCommunityMembership *> *)getMembershipsWithCommunityId:(nonnull NSString *)communityId
                                                                        membership:(EkoCommunityMembershipFilter)membership
                                                                            sortBy:(EkoCommunitySortOption)sortBy
                                                                        completion:(EkoRequestCompletion _Nullable)completion;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

