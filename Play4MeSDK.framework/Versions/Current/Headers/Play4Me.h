//
//  Play4Me.h
//  Play4Me SDK
//
//  Copyright (c) 2014 SK Planet. All rights reserved..
//
#ifndef _PLAY4ME_H
#define _PLAY4ME_H


#define UNITY_TOUCH_BEGIN                       0
#define UNITY_TOUCH_ENDED                       1
#define UNITY_TOUCH_CANCELED                    2
#define UNITY_TOUCH_MOVED                       3
#define UNITY_PAUSE                             4

#define DISPLAY_DATA_SIZE_LIMIT                 30

#define OFFLINE_PLAY_VIDEO_QUALITY_LOW          0
#define OFFLINE_PLAY_VIDEO_QUALITY_MEDIUM       1
#define OFFLINE_PLAY_VIDEO_QUALITY_HIGH         2
#define OFFLINE_PLAY_VIDEO_QUALITY_MAX          3

typedef bool (*p4m_start_offline_play_callback) (const void* p_sync_data, int n_data_size);
typedef bool (*p4m_input_result_data_callback) (const void* p_result_data, int n_data_size);
typedef bool (*p4m_stop_offlieplay_callback) (void);
typedef bool (*p4m_error_callback) (int n_error_code);

#if defined __cplusplus
extern "C" {
#endif
    /*!
     The Play4Me aims at implementing a realtime game recording and a peer-to peer remote game playing software on iOS. 
     The software is complete especially remote playing.

     The Play4Me is developed for game developers to experiment with new ideas. 
     It is written in Objective C language. It is licensed under alternate commercial license.
     */
    /***************************************************************************
     Interface for XCode Internal
     ***************************************************************************/
    //-----------------------------------------------------------------------------
    /*
     these api will be used in Unity XCode project automatically.
     If you want to use this API manually, Please check reference code with CARE.
     */
    void p4m_ios_prepare_start();
    void p4m_ios_set_target_resolution(int width, int height);
    void p4m_ios_prepare_render_loop();
    void p4m_ios_prepare_present_render_buffer();
    void p4m_ios_prepare_surface();
    bool p4m_ios_send_url(NSURL *url, void (^block)(NSError *error));
    
    bool p4m_ios_is_ui_running();
    bool p4m_ios_is_ui_running_on_ios7();
    bool p4m_ios_set_unity_interface(int type, void *pFn);
    
    /***************************************************************************
     Interface for Unity C# script
     ***************************************************************************/
    //-----------------------------------------------------------------------------
    /*!
     @function   p4m_cs_auth_info
     @abstract   pass authentication info to SDK.
                you have to pass authenication info in Dev Center.
                If you don't, API will not work.
                So, you have to call this function in early stage.
     
     @param      p_app_key
                Application Key in UUID format.
                (dash has to be included. ex> 69e22d3a-8780-3450-b751-b4c9f818b7db)
                You can check this value in "APP Information" tab at dev center.
     @param      p_client_id
                Client ID in UUID format.
                (dash has to be included. ex> 69e22d3a-8780-3450-b751-b4c9f818b7db)
                You can check this value in "APP Information" tab at dev center.
     @param      p_client_secret
                Client Secret in UUID format.
                (dash has to be included. ex> 69e22d3a-8780-3450-b751-b4c9f818b7db)
                You can check this value in "APP Information" tab at dev center.
     @param      p_game_id
                Game ID in Integer string.
                (null terminated value. ex> "10000169")
                You can check this value in "Service Setting" tab at dev center.
     @result     An bool result status.
     */
    bool p4m_cs_auth_info(char* p_app_key, char* p_client_id, char* p_client_secret, char* p_game_id);
    
    /*!
     @function   p4m_cs_get_last_error
     @abstract   when play4me API return false, 
                you can check error code with this function.
     
     @result     An error code .
     */
    int p4m_cs_get_last_error(void);
    
    /*!
     @function   p4m_cs_initialize
     @abstract   register callback function in Unity(C#) to play offline mode.
     
     @param      start_fn
                callback funtion to start offline play.
                Meta data will be passed to this function.
     @param      stop_fn
                callback function to stop offline play.
                "p4m_cs_stop_offline_play" has to be called in this function with Meta data.
     @param      input_fn
                callback function to get Meta data for offline play result.
                When user select offline play in play list, this function will be called.
     @param      error_fn
                callback function to get internal error code.
                In unexpected error or abnormal case , this function will be called.
                
     @result     An bool result status.
                If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_initialize(p4m_start_offline_play_callback start_fn,
                           p4m_stop_offlieplay_callback stop_fn,
                           p4m_input_result_data_callback input_fn,
                           p4m_error_callback error_fn);
    
    /*!
     @function   p4m_cs_show_me_in_app
     @abstract   show Play4Me In-app to user.
                All the requests for help will be shown in In-app.
                Also, game video and text, comment will be shown too.
                Once this function is called, Unity engine will be suspended until user exit In-app.
     
     @result     An bool result status.
                If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_show_me_in_app(void);
    
    /*!
     @function   p4m_cs_show_me_in_app
     @abstract   show Play4Me In-app to user.
     All the requests for help will be shown in In-app.
     Also, game video and text, comment will be shown too.
     Once this function is called, Unity engine will be suspended until user exit In-app.
     
     @param      p_search_data
                Search data to be used in search.
                Play4Me will search "p_search_data" in display data you passed before.
     @param      n_data_size
                size of "p_search_data"
     
     @result     An bool result status.
     If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_show_me_in_app_search(void* p_search_data, int n_data_size);
    
    /*!
     @function   p4m_cs_send_request
     @abstract   send Play4Me request.
                As Play4Me scenario, online request turns into offline request after 60 secs.
                So, you have to pass Meta data to sync status. (even though online request)
     
     @param      p_sync_data
                Meta data to sync start status.
                Data format is not limited.
                You can pass whatever you want.
     @param      n_data_size
                size of "p_sync_data"
     @param      p_display_data
                This data will be displayed in Play4Me In-app.
                You can pass text data whatever you want to display.
                (Score, Level, Point will be OK)
                Size is available up to 30 bytes.
                If passed string is larger than 30 bytes, SDK will cut the rest.
     @param      n_display_data_size
                size of "p_display_data"
     @result     An bool result status.
                If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_send_request(void* p_sync_data, int n_data_size,
                             char* p_display_data, int n_display_data_size);
    
    /*!
     @function   p4m_cs_stop_offline_play
     @abstract   finish offline play.
                You can call this function to finish offline play whenever you want.
     
     @param      p_result_data
                Meta data to sync result status after play.
     @param      n_data_size
                size of "p_result_data"
     @param      p_display_data
                This data will be displayed in Play4Me In-app.
                You can pass text data whatever you want to display.
                (Score, Level, Point will be OK)
                Size is available up to 30 bytes.
                If passed string is larger than 30 bytes, SDK will cut the rest.
     @param      n_display_data_size
                size of "p_display_data"
     @result     An bool result status.
                If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_stop_offline_play(void* p_result_data, int n_data_size,
                                  char* p_display_data, int n_display_data_size);
    
    /*!
     @function   p4m_cs_set_offline_play_record_quality
     @abstract   Set recorded video quality during offline play.
                If you don't set video quality, SDK use OFFLINE_PLAY_VIDEO_QUALITY_MAX as default.
     @param      level
                Level of quality.
                This value can be OFFLINE_PLAY_VIDEO_QUALITY value.
                Best quality makes larger video file.
                    OFFLINE_PLAY_VIDEO_QUALITY_LOW          : 400K
                    OFFLINE_PLAY_VIDEO_QUALITY_MEDIUM       : 600K
                    OFFLINE_PLAY_VIDEO_QUALITY_HIGH         : 800K
                    OFFLINE_PLAY_VIDEO_QUALITY_MAX          : 960K
     
     @result     An bool result status.
     If false is returned, please check error code with "p4m_cs_get_last_error".
     */
    bool p4m_cs_set_offline_play_record_quality(int level);
    
#if defined __cplusplus
};
#endif

#ifdef __OBJC__
    #import "PlagaWindow.h"
    #import "PlagaApplication.h"
    #import "PlagaDefines.h"
#else
#endif

#endif//_PLAY4ME_H
