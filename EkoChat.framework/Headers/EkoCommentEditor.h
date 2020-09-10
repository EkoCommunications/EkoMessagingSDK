//
//  EkoCommentEditor.h
//  EkoChat
//
//  Created by Michael Abadi on 04/06/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "EkoClient.h"
#import "EkoCollection.h"
#import "EkoObject.h"

@class EkoMessage;

/**
   A editor encapsulates methods for managing comment.
 */
@interface EkoCommentEditor : NSObject

/**
   The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) EkoClient *client;

/**
   The comment identifier associated with the instance.
 */
@property (nonnull, strong, readonly, nonatomic) NSString *commentId;

/**
   Designated intializer.
   @param client A valid context instance.
   @param commentId comment identifier for the selected comment..
 */
- (nonnull instancetype)initWithClient:(nonnull EkoClient *)client
                             commentId:(nonnull NSString *)commentId NS_DESIGNATED_INITIALIZER;

/**
   Edits the text message.
   @param text The new text
   @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
      completion:(EkoRequestCompletion _Nullable)completion;


/**
   Deletes the comment.
   @param completion  A block executed when the request has completed.
 */
- (void)deleteWithCompletion:(nullable EkoRequestCompletion)completion;

/**
   Block call of `init` and `new` because this object cannot be created directly.
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

