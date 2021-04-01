//
//  EkoNotificationModule.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 10/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <EkoChat/EkoRoleFilter.h>

typedef NS_ENUM(NSUInteger, EkoNotificationModuleType) {
    EkoNotificationModuleTypeChat = 1,
    EkoNotificationModuleTypeVideoStreaming,
    EkoNotificationModuleTypeSocial
};

NS_ASSUME_NONNULL_BEGIN

@interface EkoUserNotificationModule : NSObject

@property (nonatomic, assign) EkoNotificationModuleType moduleType;
@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) EkoRoleFilter * _Nullable roleFilter;

/**
 Initializes module for push notification settings.
 
 @param isEnabled Whether or not the user would like to receive push notifications on the particular module.
 @param roleFilter (optional) A filter for determining which user role that the user would like to receive notification from. If nil provided, skip updating roles.
 */
- (instancetype)initWithModuleType:(EkoNotificationModuleType)moduleType
                         isEnabled:(BOOL)isEnabled
                        roleFilter:(nullable EkoRoleFilter *)roleFilter;

@end

NS_ASSUME_NONNULL_END
