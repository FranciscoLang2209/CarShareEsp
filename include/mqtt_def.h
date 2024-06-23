#ifndef __MQTT_DEF_H__
#define __MQTT_DEF_H__
#include <mqtt_actions.h>
#include <cstddef>

/*
 *  mqtt_def.h
 *
 *      This is not a traditional header file
 *      As a matter of fact, it has all the configurations for MQTT in one file
 *      Please, modify it with caution
 */

typedef struct
{
    const char *sub_topic;
    void (*action)( int origin, char *message );
} topic_t;

/*
 *  C1 -> List of topics and actions
 */

static const topic_t topics[] =
{
    {   "start", new_session },
    {   "stop", stop_session },
    {   "weight", setWeight  },
    { NULL }
};

static const char *subs[] =
{
#if (SUB_LIST==0)
    "#",
#elif (SUB_LIST==1)
    "session/#",
    "set/weight",
#else
    #error "Bad SUB_LIST symbol, out of range"
#endif
    NULL
};

#define id_string(buf,brd)      sprintf(buf,"%s_%s_%02d",   MAIN_NAME,SUB_NAME,brd)
#define topic_string(buf,brd)   sprintf(buf,"%s/%s/%02d",   MAIN_NAME,SUB_NAME,brd)
#define subs_string(buf)        sprintf(buf,"%s/%s",        MAIN_NAME,SUB_NAME)

#if (MQTT==0)                                       
    #define BROKER_NAME "ec2-18-232-20-96.compute-1.amazonaws.com"         //  Mosquitto in local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==1)
    #define BROKER_NAME "44.201.113.109"          //  Mosquitto outside local network
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#elif (MQTT==2)
    #define BROKER_NAME "broker.mqtt-dashboard.com"    //  Remote broker by name
    #define BROKER_PORT 1883
    #define BROKER_USER ""
    #define BROKER_PASS ""
#else
    #error "Bad MQTT symbol, broker name out of range"
#endif

#endif      //  ends  __MQTT_DEF_H__
