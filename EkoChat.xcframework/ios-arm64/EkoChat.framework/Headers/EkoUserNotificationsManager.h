//
//  EkoUserNotificationsManager.h
//  EkoChat
//
//  Created by Federico Zanetello on 6/5/19.
//  Copyright © 2019 eko. All rights reserved.
//

#import <EkoChat/EkoUserNotification.h>

/**
   @abstract Responsible to manage the user level push notification settings.
 */
@interface EkoUserNotificationsManager : NSObject

typedef void (^EkoUserNotificationCompletion)(EkoUserNotification * _Nullable notificationModel, NSError * _Nullable error);

/**
   @abstract The completion block type.
   @discussion As these push notifications settings are per user and not per device,
   any request will go through the backend.

   @param success The outcome of the callback.
   @param error (optional) The error from the backend.
 */
    typedef void (^EkoRequestCompletion)(BOOL success,
     NSError * _Nullable error);

/**
   @abstract Updates the user level push notification setting.
   @note This setting will take effect on every device used by the user.
   If the user wishes to stop receiving notifications only on this device,
   then unregister push notifications with this device instead.

   @param isAllowed Whether or not the user would like to receive any push notifications.
   @param completion A block executed when the request has completed.
 */
- (void)setIsAllowed:(BOOL)isAllowed
          completion:(nullable EkoRequestCompletion)completion DEPRECATED_MSG_ATTRIBUTE("Deprecated from 4.8, this method is no longer be supported and will be removed. Please use `enableSettingWithModules(_:)` or `disableSettingWithCompletion(_:)` method instead.");

/**
   @abstract Retrieve the current user level push notification state.
   @note This setting is per user, not per device.

   @param completion A block executed when the request has completed.
 */
- (void)isAllowedWithCompletion:(void(^ _Nonnull)(BOOL isAllowed, NSError * _Nullable))completion DEPRECATED_MSG_ATTRIBUTE("Deprecated from 4.8, this method is no longer be supported and will be removed. Please use `getSettingsWithCompletion(_:)` method instead.");

/**
 @abstract Enable the user level push notification setting.
 @note This setting will take effect on every device used by the user.
 
 @param modules An array of modules that consishts of `chat`, `social` and `video-streaming`.
 @param completion A block executed when the request has completed.
 */
- (void)enableSettingWithModules:(nullable NSArray<EkoUserNotificationModule *> *)modules
                      completion:(nullable EkoRequestCompletion)completion;

/**
 @abstract Disable the user level push notification setting.
 @note This setting will take effect on every device used by the user.
 
 @param completion A block executed when the request has completed.
 */
- (void)disableSettingWithCompletion:(nullable EkoRequestCompletion)completion;

/**
 @abstract Retrieve the user level push notification state.
 @note This setting is per user, not per device.
 
 @param completion A block executed when the request has completed.
 */
- (void)getSettingsWithCompletion:(nullable EkoUserNotificationCompletion)completion;

/**
   Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end
