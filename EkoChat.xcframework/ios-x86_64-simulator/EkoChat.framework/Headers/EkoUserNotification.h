//
//  EkoNotifiableModule.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 10/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EkoChat/EkoUserNotificationModule.h>

NS_ASSUME_NONNULL_BEGIN

@interface EkoUserNotification : NSObject

@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) NSArray<EkoUserNotificationModule *> *modules;

@end

NS_ASSUME_NONNULL_END
