//
//  PlagaDefines.h
//  Play4Me SDK
//
//  Copyright (c) 2014 SK Planet. All rights reserved..
//
#import <UIKit/UIKit.h>

/**---------------------------------------------------------------------------------------
 * @name this enum value uses under "Error Handling"
 *  ---------------------------------------------------------------------------------------
 */

typedef enum : NSInteger {
    PlagaErrorCodeRecorder                  = -101,
    PlagaErrorCodeCameraAssetWriter,
    PlagaErrorCodeSurfaceAssetWriter,
    PlagaErrorCodeAssetLibrary,
    PlagaErrorCodeCameraCapturer,
    PlagaErrorCodeCoreAudioCapturer,
    PlagaErrorCodeGLESCapturer,
    PlagaErrorCodeCameraController,
    PlagaErrorCodeSyncController,
    PlagaErrorCodeRecordMenuView,
    PlagaErrorCodeUIEvent,
    PlagaErrorCodeURLScheme,
    
    PlagaErrorCodeOAuth,
    PlagaErrorCodeCommHubOpenAPI,
    PlagaErrorCodeP4MOpenAPI,
} PlagaErrorCode;

extern NSString *const PlagaErrorDomain;
extern NSString *const PlagaException;

@interface PlagaError : NSObject

+ (NSString *)getErrorType:(PlagaErrorCode) type;

@end

