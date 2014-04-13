//
//  FobosImage.h
//  SpaceAppIpad
//
//  Created by Luis Fernando Bustos Ramírez on 12/04/14.
//  Copyright (c) 2014 Luis Fernando Bustos Ramírez. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Parse/Parse.h>
#import <AVFoundation/AVFoundation.h>

@interface FobosImage : UIImageView{
    NSTimer *contadorTimer;
    NSDate *timeNow;
    NSDate *timeParse;
    int i;
    AVAudioPlayer *sound;
    
}

- (void)comienza:(NSTimer *) elContador;
- (void)empezar;
- (void) setImageByParse;
@end
