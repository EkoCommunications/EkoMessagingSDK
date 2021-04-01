//
//  EkoCommunityNotificationEventModel.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 3/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <EkoChat/EkoRoleFilter.h>

typedef NS_ENUM(NSUInteger, EkoCommunityNotificationEventType) {
    EkoCommunityNotificationEventTypePostCreated = 1,
    EkoCommunityNotificationEventTypePostReacted,
    EkoCommunityNotificationEventTypeCommentCreated,
    EkoCommunityNotificationEventTypeCommentReplied,
    EkoCommunityNotificationEventTypeCommentReacted
};

NS_ASSUME_NONNULL_BEGIN

@interface EkoCommunityNotificationEvent : NSObject

@property (nonatomic, strong) NSString *eventName;
@property (nonatomic, assign) EkoCommunityNotificationEventType eventType;
@property (nonatomic, assign) BOOL isNetworkEnabled;
@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) EkoRoleFilter * _Nullable roleFilter;

- (instancetype)initWithEventType:(EkoCommunityNotificationEventType)eventType
                        isEnabled:(BOOL)isEnabled
                       roleFilter:(nullable EkoRoleFilter *)roleFilter;

@end

NS_ASSUME_NONNULL_END
