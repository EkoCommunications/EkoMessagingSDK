//
//  EkoStreamCollectionQuery.h
//  EkoChat
//
//  Created by Nutchaphon Rewik on 4/2/2564 BE.
//  Copyright © 2564 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EkoStreamStatus);

NS_ASSUME_NONNULL_BEGIN

/// The query predicate for "getStreamsCollection".
@interface EkoStreamCollectionQuery : NSObject

/// Include status as part of stream collection querying.
- (void)includeStatus:(EkoStreamStatus)status NS_SWIFT_NAME(includeStatus(_:));

@end

NS_ASSUME_NONNULL_END
