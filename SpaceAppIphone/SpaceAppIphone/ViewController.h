//
//  ViewController.h
//  SpaceAppIphone
//
//  Created by Luis Fernando Bustos Ramírez on 12/04/14.
//  Copyright (c) 2014 Luis Fernando Bustos Ramírez. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <Parse/Parse.h>
#import "AVCamPreviewView.h"

@interface ViewController : UIViewController <AVCaptureFileOutputRecordingDelegate, CLLocationManagerDelegate>{
    NSTimer *contadorTimer;
    int i;
    AVAudioPlayer *sound;
    
}

// Elementos para los beacons
@property (strong, nonatomic) CLBeaconRegion *beaconRegion;
@property (strong, nonatomic) CLLocationManager *locationManager;

// For use in the storyboards.
@property (nonatomic, weak) IBOutlet AVCamPreviewView *previewView;

- (void)comienza:(NSTimer *) elContador;
- (void)empezar;
// Session management.
@property (nonatomic) dispatch_queue_t sessionQueue; // Communicate with the session and other session objects on this queue.
@property (nonatomic) AVCaptureSession *session;
@property (nonatomic) AVCaptureDeviceInput *videoDeviceInput;
@property (nonatomic) AVCaptureMovieFileOutput *movieFileOutput;
@property (nonatomic) AVCaptureStillImageOutput *stillImageOutput;

// Utilities.
@property (nonatomic) UIBackgroundTaskIdentifier backgroundRecordingID;
@property (nonatomic, getter = isDeviceAuthorized) BOOL deviceAuthorized;
@property (nonatomic, readonly, getter = isSessionRunningAndDeviceAuthorized) BOOL sessionRunningAndDeviceAuthorized;
@property (nonatomic) BOOL lockInterfaceRotation;
@property (nonatomic) id runtimeErrorHandlingObserver;



@end
