//
//  ViewController.m
//  SpaceAppIpad
//
//  Created by Luis Fernando Bustos Ramírez on 12/04/14.
//  Copyright (c) 2014 Luis Fernando Bustos Ramírez. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [_imageParse setImageByParse];
    [_imageParse empezar];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
