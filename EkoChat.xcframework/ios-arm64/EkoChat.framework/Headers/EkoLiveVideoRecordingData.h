//
//  EkoLiveVideoRecordingData.h
//  EkoChat
//
//  Created by Nutchaphon Rewik on 21/12/2563 BE.
//  Copyright © 2563 eko. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EkoLiveVideoRecordingFileFormat) {
    EkoLiveVideoRecordingFileFormatMP4 = 0,
    EkoLiveVideoRecordingFileFormatFLV = 1,
    EkoLiveVideoRecordingFileFormatM3U8 = 2
};

@interface EkoLiveVideoRecordingData : NSObject

/* We will expose this soon in the future.
 
@property (nullable, strong, nonatomic) NSDate *startTime;

@property (nullable, strong, nonatomic) NSDate *stopTime;

@property (assign, nonatomic) NSTimeInterval duration;
 */

- (nullable NSURL *)urlForFileFormat:(EkoLiveVideoRecordingFileFormat)format;

@end

NS_ASSUME_NONNULL_END
