//
//  EkoRoleFilter.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 18/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EkoRoleFilterType) {
    EkoRoleFilterTypeOnly,
    EkoRoleFilterTypeNot,
    EkoRoleFilterTypeAll
};

NS_ASSUME_NONNULL_BEGIN

@interface EkoRoleFilter : NSObject

@property (nonatomic, assign) EkoRoleFilterType filterType;
@property (nonatomic, strong) NSArray<NSString *> * _Nullable roleIds;

/**
 Initializes EkoRoleFilter with EkoRoleFilterTypeOnly
 A filter for receiving the particular user roles.
 
 @param roleIds A set of role id the user would like to receive push notification from.
 */
+ (instancetype)onlyFilterWithRoleIds:(NSArray<NSString *> *)roleIds;

/**
 Initializes EkoRoleFilter with EkoRoleFilterTypeAll
 A filter for receiving any type of user roles.
 */
+ (instancetype)allFilter;

@end


NS_ASSUME_NONNULL_END
