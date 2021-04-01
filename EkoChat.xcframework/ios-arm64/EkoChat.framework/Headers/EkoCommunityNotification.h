//
//  EkoCommunityNotificationEventModel.h
//  EkoChat
//
//  Created by Nontapat Siengsanor on 3/3/2564 BE.
//  Copyright © 2564 BE eko. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EkoChat/EkoCommunityNotificationEvent.h>

NS_ASSUME_NONNULL_BEGIN

@interface EkoCommunityNotification : NSObject

@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, assign) BOOL isUserEnabled;
@property (nonatomic, strong) NSArray<EkoCommunityNotificationEvent *> *events;

- (instancetype)initWithResponse:(NSDictionary<NSString *, id> *)response;

@end

NS_ASSUME_NONNULL_END
