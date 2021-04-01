//
//  EkoCommunityNotificationsManager.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 10/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EkoChat/EkoCommunityNotification.h>

NS_ASSUME_NONNULL_BEGIN

@interface EkoCommunityNotificationsManager : NSObject

typedef void (^EkoCommunityNotificationCompletion)(EkoCommunityNotification * _Nullable notificationModel, NSError * _Nullable error);

/**
 @abstract The completion block type.
 @discussion As these push notifications settings are per community and not per device,
 any request will go through the backend.
 
 @param success The outcome of the callback.
 @param error (optional) The error from the backend.
 */
typedef void (^EkoRequestCompletion)(BOOL success, NSError * _Nullable error);

/**
 @abstract Enable the community level push notification setting.
 @note This setting will take effect on particular community.
 
 @param events An array of events that each of them contains push notification for each community event.
 @param completion A block executed when the request has completed.
 */
- (void)enableSettingWithEvents:(nullable NSArray<EkoCommunityNotificationEvent *> *)events
                     completion:(nullable EkoRequestCompletion)completion;

/**
 @abstract Disable the community level push notification setting.
 @note This setting will take effect on particular community.
 
 @param completion A block executed when the request has completed.
 */
- (void)disableSettingWithCompletion:(nullable EkoRequestCompletion)completion;

/**
 @abstract Retrieve the community level push notification state.
 @note This setting will take effect on particular community.
 
 @param completion A block executed when the request has completed.
 */
- (void)getPushNotificationSettingWithCompletion:(nullable EkoCommunityNotificationCompletion)completion;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
