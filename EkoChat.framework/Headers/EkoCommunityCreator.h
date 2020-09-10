//
//  EkoCommunityCreator.h
//  EkoChat
//
//  Created by Michael Abadi on 07/07/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EkoClient.h"
#import "EkoBuilder.h"

@class EkoCommunity;

/**
   A editor encapsulates methods for managing community transaction process
 */
@interface EkoCommunityCreator : NSObject

/**
   The context used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) EkoClient *client;

/**
   Designated intializer
   @param client A valid context instance
 */
- (nonnull instancetype)initWithClient:(nonnull EkoClient *)client NS_DESIGNATED_INITIALIZER;

/**
  Create the which need a text represented by string value
  @param builder: A type of EkoCommunityBuilder object.
*/
- (void)createCommunity:(nonnull id<EkoCommunityBuilder>)builder
             completion:(EkoRequestCompletion _Nullable)completion;


/**
  Update specific community with the updated data
  @param communityId A community id represent the group object
  @param builder: A type of EkoCommunityBuilder object. You can use EkoCommunityDataBuilder to update community data.
*/
- (void)updateCommunityWithCommunityId:(nonnull NSString *)communityId
                       builder:(nonnull id<EkoCommunityBuilder>)builder
                    completion:(EkoRequestCompletion _Nullable)completion NS_SWIFT_NAME(updateCommunity(withId:builder:completion:));

/**
   Delete the specific community
   @param communityId A community id represent the community object
 */
- (void)deleteCommunityWithCommunityId:(nonnull NSString *)communityId
                    completion:(EkoRequestCompletion _Nullable)completion;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

