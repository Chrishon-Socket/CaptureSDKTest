#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SktCapture.h"
#import "SktCaptureDataSource.h"
#import "SktCaptureErrors.h"
#import "SktCaptureEvent.h"
#import "SktCaptureProperty.h"
#import "SktCapturePropertyIds.h"
#import "SktCaptureVersion.h"

FOUNDATION_EXPORT double SKTCaptureVersionNumber;
FOUNDATION_EXPORT const unsigned char SKTCaptureVersionString[];

