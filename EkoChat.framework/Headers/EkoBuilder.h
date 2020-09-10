//
//  EkoBuilder.h
//  EkoChat
//
//  Created by Nishan Niraula on 6/15/20.
//  Copyright © 2020 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol EkoPostBuilder <NSObject>

/**
 Returns the JSON representation of the data object needed for post
 */
- (NSDictionary<NSString *, id> *)build;

@end

@protocol EkoCommunityBuilder <NSObject>

/**
 Returns the JSON representation of the data object needed for group
 */
- (NSDictionary<NSString *, id> *)build;

@end

