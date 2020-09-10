//
//  EkoCommentRepository.h
//  EkoChat
//
//  Created by Michael Abadi Santoso on 5/20/20.
//  Copyright © 2020 eko. All rights reserved.
//

@import Foundation;
#import "EkoEnums.h"
#import "EkoObject.h"
#import "EkoCollection.h"

@class EkoComment;
@class EkoClient;

/**
 Repository provides access messages and collections.
 */
@interface EkoCommentRepository : NSObject

/**
 The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) EkoClient *client;

/**
 Designated intializer.

 @param client A valid context instance.
 */
- (nonnull instancetype)initWithClient:(nonnull EkoClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a new comment. Comments are created locally and then synced with server. You can observe
 the `syncState` property of `EkoComment` to determine if server sync was successful or not. 
 
 @param referenceId: The unique identifiers of id.
 @param referenceType: ReferenceType for comment
 @param parentId: The unique identifiers of the parent of the comment.
 @param text: The comment text.
 @return The EkoComment live object.
 */
- (nonnull EkoObject<EkoComment *> *)createCommentWithReferenceId:(nonnull NSString *)referenceId
                                                    referenceType:(EkoCommentReferenceType)type
                                                         parentId:(nullable NSString *)parentId
                                                             text:(nonnull NSString *)text;
/**
 Get a collection of all comment by reference id.
 
 @param referenceId The reference id of the commented object.
 @param filterByParentId If want to be filtered by the parent id.
 @param parentId The reference of which comment we are interested in.
 @param reverse Whether we'd like the collection in opposite order.
 @return The messages collection.
 */
- (nonnull EkoCollection<EkoComment *> *)commentsWithReferenceId:(nonnull NSString *)referenceId
                                                      referenceType:(EkoCommentReferenceType)type
                                                   filterByParentId:(BOOL)filterByParentId
                                                           parentId:(nullable NSString *)parentId
                                                            reverse:(BOOL)reverse;


/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
