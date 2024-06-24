#ifndef __WIFI_DATA_H__
#define __WIFI_DATA_H__

/*
 *  Project 01-MQTT-HolaMundo
 *
 *  wifi_data.h
 *      Data configuration for WiFi connection
 */

#if (WIFI==0)                   //  Home settings
    #define MY_SSID "Dolores 2.4GHz"
    #define MY_PASS "00424655227"
#elif (WIFI==1)                 //  University settings
    #define MY_SSID "UA-Alumnos"
    #define MY_PASS "41umn05WLC"
#elif (WIFI==2)                 //  Other place settings
    #define MY_SSID "UA-Alumnos"
    #define MY_PASS "41umn05WLC"
#else
    #error  "WIFI symbol out of range"
#endif

//  wifi_data.h ends
#endif

