//
//  PlagaWindow.h
//  Play4Me SDK
//
//  Copyright (c) 2014 SK Planet. All rights reserved..
//
#import <UIKit/UIKit.h>

/** This class implementes a plaga menu
    You must replace your UIWindow to PlagaWindow.
 */

@interface PlagaWindow : UIWindow

/**---------------------------------------------------------------------------------------
 * @name this method uses under "PlagaWindow"
 *  ---------------------------------------------------------------------------------------
 */

/** This is class method for PlagaWindow
 
 You can get current window instance.

 @result instance if returned successfully, nil otherwise
 */
+ (PlagaWindow *)window;

@end

