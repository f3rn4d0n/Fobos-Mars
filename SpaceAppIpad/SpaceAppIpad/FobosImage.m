//
//  FobosImage.m
//  SpaceAppIpad
//
//  Created by Luis Fernando Bustos Ramírez on 12/04/14.
//  Copyright (c) 2014 Luis Fernando Bustos Ramírez. All rights reserved.
//

#import "FobosImage.h"

@implementation FobosImage

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

- (void) setImageByParse{
}


-(void)comienza:(NSTimer *) elContador {
    i++;
    //Beacons
    if (i%3 == 0) {
        PFQuery *query = [PFQuery queryWithClassName:@"Beacon"];
        NSArray *ids = @[@1,@2,@3];
        [query whereKey:@"flag" containedIn:ids];
        [query findObjectsInBackgroundWithBlock:^(NSArray *objects, NSError *error) {
            if (!error) {
                NSDateFormatter *timeFormatter = [[NSDateFormatter alloc]init];
                timeFormatter.dateFormat = @"mm:ss";
                PFObject *object = objects.lastObject;
                timeParse = object.updatedAt;
                NSString *dateParse = [timeFormatter stringFromDate: timeParse];
                NSLog(@"Parse %@",dateParse);
                
                NSTimeInterval seconds = [timeParse timeIntervalSinceNow];
                NSInteger time = seconds;
                
                if (abs(time)<=2) {
                    NSNumber *flag = object[@"flag"];
                    int flagData = [flag intValue];
                    NSLog(@"Id %i", flagData);
                }
                
            } else {
                NSLog(@"Error: %@ %@", error, [error userInfo]);
            }
        }];
    }
    
    
    //Image
    if (i%3 == 0) {
        //Image
        PFQuery *photoQuery = [PFQuery queryWithClassName:@"Image"];
        PFObject *photo = [photoQuery getFirstObject];
        PFFile *imageFile = [photo objectForKey:@"picture"];
        [imageFile getDataInBackgroundWithBlock:^(NSData *result, NSError *error) {
            if (!error) {
                NSLog(@"abemus image");
                NSLog(@"Id %@", photo.updatedAt);
                UIImage *image = [UIImage imageWithData:result];
                [self setImage:image];
            }else{
                NSLog(@"Error: %@",error);
            }
        }];
    }
}

- (void)empezar{
    contadorTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(comienza:) userInfo:nil repeats:YES];
}



@end
