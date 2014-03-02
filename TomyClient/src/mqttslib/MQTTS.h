/*
 * MQTTS.h
 *
 *                               The MIT License (MIT)
 *
 *               Copyright (c) 2013 Tomoaki YAMAGUCHI  All rights reserved.
 *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.*
 *
 *
 *  Created on: 2013/06/23
 *    Modofied: 2013/12/12
 *      Author: Tomoaki YAMAGUCHI
 *     Version: 1.0.0
 *
 */

#ifndef MQTTS_H_
#define MQTTS_H_

#ifndef ARDUINO
        #include "MQTTS_Defines.h"
#endif

#if defined(ARDUINO) && ARDUINO >= 100
        #include "Arduino.h"
        #include <inttypes.h>
        #include <ZBeeStack.h>
#endif

#if defined(ARDUINO) && ARDUINO < 100
        #include "WProgram.h"
        #include <inttypes.h>
        #include <ZBeeStack.h>
#endif

#ifdef LINUX
        #include <sys/time.h>
        #include <iostream>
        #include "ZBeeStack.h"
#endif

#ifdef MBED
        #include "mbed.h"
        #include "ZBeeStack.h"
#endif

                              /* [sec] */
#define MQTTS_DEFAULT_KEEPALIVE 3600     // 1H
#define MQTTS_DEFAULT_DURATION   900     // 15min
#define MQTTS_TIME_SEARCHGW        3
#define MQTTS_TIME_RETRY          10
#define MQTTS_TIME_WAIT          300     //  5min


#define MQTTS_MAX_TOPICS         10
#define MQTTS_MAX_PACKET_LENGTH  60

#define MQTTS_TYPE_ADVERTISE     0x00
#define MQTTS_TYPE_SEARCHGW      0x01
#define MQTTS_TYPE_GWINFO        0x02
#define MQTTS_TYPE_CONNECT       0x04
#define MQTTS_TYPE_CONNACK       0x05
#define MQTTS_TYPE_WILLTOPICREQ  0x06
#define MQTTS_TYPE_WILLTOPIC     0x07
#define MQTTS_TYPE_WILLMSGREQ    0x08
#define MQTTS_TYPE_WILLMSG       0x09
#define MQTTS_TYPE_REGISTER      0x0A
#define MQTTS_TYPE_REGACK        0x0B
#define MQTTS_TYPE_PUBLISH       0x0C
#define MQTTS_TYPE_PUBACK        0x0D
#define MQTTS_TYPE_PUBCOMP       0x0E
#define MQTTS_TYPE_PUBREC        0x0F
#define MQTTS_TYPE_PUBREL        0x10
#define MQTTS_TYPE_SUBSCRIBE     0x12
#define MQTTS_TYPE_SUBACK        0x13
#define MQTTS_TYPE_UNSUBSCRIBE   0x14
#define MQTTS_TYPE_UNSUBACK      0x15
#define MQTTS_TYPE_PINGREQ       0x16
#define MQTTS_TYPE_PINGRESP      0x17
#define MQTTS_TYPE_DISCONNECT    0x18
#define MQTTS_TYPE_WILLTOPICUPD  0x1A
#define MQTTS_TYPE_WILLTOPICRESP 0x1B
#define MQTTS_TYPE_WILLMSGUPD    0x1C
#define MQTTS_TYPE_WILLMSGRESP   0x1D

#define MQTTS_TOPIC_TYPE_NORMAL     0x00
#define MQTTS_TOPIC_TYPE_PREDEFINED 0x01
#define MQTTS_TOPIC_TYPE_SHORT      0x02
#define MQTTS_TOPIC_TYPE            0x03

#define MQTTS_FLAG_DUP     0x80
#define MQTTS_FLAG_QOS_0   0x0
#define MQTTS_FLAG_QOS_1   0x20
#define MQTTS_FLAG_QOS_2   0x40
#define MQTTS_FLAG_QOS_N1  0xc0
#define MQTTS_FLAG_RETAIN  0x10
#define MQTTS_FLAG_WILL    0x08
#define MQTTS_FLAG_CLEAN   0x04

#define MQTTS_PROTOCOL_ID  0x01
#define MQTTS_HEADER_SIZE  2

#define MQTTS_RC_ACCEPTED                  0x00
#define MQTTS_RC_REJECTED_CONGESTION       0x01
#define MQTTS_RC_REJECTED_INVALID_TOPIC_ID 0x02
#define MQTTS_RC_REJECTED_NOT_SUPPORTED    0x03

#define MQTTS_MSG_REQUEST     1
#define MQTTS_MSG_RESEND_REQ  2
#define MQTTS_MSG_WAIT_ACK    3
#define MQTTS_MSG_COMPLETE    4
#define MQTTS_MSG_REJECTED    5
#define MQTTS_MSG_REBOOT_REQ  6


#define MQTTS_GW_INIT         0
#define MQTTS_GW_SEARCHING    1
#define MQTTS_GW_FOUND        2
#define MQTTS_GW_CONNECTED    3
#define MQTTS_GW_DISCONNECTED 4
#define MQTTS_GW_LOST         5

#define MQTTS_ERR_NO_ERROR            0
#define MQTTS_ERR_NOT_CONNECTED      -1
#define MQTTS_ERR_RETRY_OVER         -2
#define MQTTS_ERR_GATEWAY_LOST       -3
#define MQTTS_ERR_CANNOT_ADD_REQUEST -4
#define MQTTS_ERR_NO_TOPICID         -5
#define MQTTS_ERR_REJECTED           -6
#define MQTTS_ERR_WAIT_GWINFO        -7
#define MQTTS_ERR_OUT_OF_MEMORY      -8
#define MQTTS_ERR_PING_REQUIRED      -9
#define MQTTS_ERR_ACK_TIMEOUT       -10
#define MQTTS_ERR_PINGRESP_TIMEOUT  -11
#define MQTTS_ERR_INVALID_TOPICID   -12
#define MQTTS_ERR_NO_DATA           -13
#define MQTTS_ERR_REBOOT_REQUIRED   -14

#define MQTTS_TOPIC_MULTI_WILDCARD   '#'
#define MQTTS_TOPIC_SINGLE_WILDCARD  '+'

#define MQTTS_TOPICID_NORMAL 256
#define MQTTS_TOPICID_PREDEFINED_TIME   0x0001
#define MQTTS_TOPIC_PREDEFINED_TIME     ("$GW/01")

extern uint16_t getUint16(uint8_t* pos);
extern void setUint16(uint8_t* pos, uint16_t val);

using namespace tomyClient;

/*=====================================
        Class MQString
 =====================================*/
class MQString{
public:
    MQString();
    MQString(const char*);
    MQString(char*);
    ~MQString();
    uint8_t getCharLength();
    int     comp(MQString* str);
    int     comp(const char* str);
    int     ncomp(MQString* str, long n);
    void    copy(MQString* str);
    void    copy(const char* str);
    void    copy(char* str);
    void    copy(uint8_t* str, uint8_t len);
    MQString* create();
    void    writeBuf(uint8_t* buf);
    void    readBuf(uint8_t* buf);
    uint8_t getChar(uint8_t index);
    char*  getStr();
    const char* getConstStr();
    bool    isConst();
    bool operator==(MQString&);
    bool operator!=(MQString&);
private:
    void    freeStr();
    char*    _str;
    const char* _constStr;
};

/*=====================================
        Class MqttsMessage
  =====================================*/
class MqttsMessage {
public:
    MqttsMessage();
    ~MqttsMessage();
    void  setLength(uint8_t length);
    void  setType(uint8_t type);
    bool  setBody(uint8_t* body);
    bool  allocateBody();
    void  setStatus(uint8_t stat);
    void  setDup();
    uint8_t getLength();
    uint8_t getType();
    uint8_t getStatus();
    uint8_t* getBody();
    uint8_t getBodyLength();
    uint8_t* getMsgBuff();
    uint8_t getFrameLength();
    bool  copy(MqttsMessage* src);
    void  reset();
    void  setMsgBuff(uint8_t* buff);
    const char* getMsgTypeName();
protected:
    uint8_t* _msgBuff;
private:
    uint8_t  _status; // 1:request 2:sending 3:resending 4:waitingAck  5:complite
    uint8_t  _length;
    uint8_t  _type;
};

/*=====================================
        Class MqttsAdvertize
 ======================================*/
class MqttsAdvertise : public MqttsMessage {
public:
  MqttsAdvertise();
  ~MqttsAdvertise();
  void setGwId(uint8_t id);
  void setDuration(uint16_t duration);
  uint8_t getGwId();
  uint16_t getDuration();

private:
};

/*=====================================
        Class MqttsSearchGw
 ======================================*/
class MqttsSearchGw : public MqttsMessage {
public:
    MqttsSearchGw();
  ~MqttsSearchGw();
  void setRadius(uint8_t radius);
  uint8_t getRadius();

private:
};

/*=====================================
        Class MqttsGwinfo
 ======================================*/
class MqttsGwInfo : public MqttsMessage {
public:
  MqttsGwInfo();
  ~MqttsGwInfo();
  void setGwId(uint8_t id);
  uint8_t getGwId();

private:
};

/*=====================================
         Class MqttsConnect
  ======================================*/
class MqttsConnect : public MqttsMessage {
public:
    MqttsConnect(MQString* id);
    ~MqttsConnect();
    void setFlags(uint8_t flg);
    void setDuration(uint16_t msec);
    void setClientId(MQString* id);
    uint8_t* getClientId();
    uint8_t getFlags();
    uint16_t getDuration();
    void setFrame(uint8_t* data, uint8_t len);
private:
 };

/*=====================================
        Class MqttsConnack
 ======================================*/
class MqttsConnack : public MqttsMessage  {
public:
    MqttsConnack();
    ~MqttsConnack();
    void setReturnCode(uint8_t rc);
    uint8_t getReturnCode();

private:

};

/*=====================================
         Class MqttsWillTopicReq
  ======================================*/
class MqttsWillTopicReq : public MqttsMessage  {
public:
    MqttsWillTopicReq();
    ~MqttsWillTopicReq();

private:

 };

/*=====================================
         Class MqttsWillTopic
  ======================================*/
class MqttsWillTopic : public MqttsMessage  {
public:
    MqttsWillTopic();
    ~MqttsWillTopic();
    void setFlags(uint8_t flags);
    void setWillTopic(MQString* topic);
    MQString* getWillTopic();
    uint8_t getQos();
    bool isWillRequired();

private:
    uint8_t _flags;
    MQString _ustring;
 };

/*=====================================
         Class MqttsWillMsgReq
  ======================================*/
class MqttsWillMsgReq : public MqttsMessage  {
public:
    MqttsWillMsgReq();
    ~MqttsWillMsgReq();

private:

 };

/*=====================================
         Class MqttsWillMsg
  ======================================*/
class MqttsWillMsg : public MqttsMessage  {
public:
    MqttsWillMsg();
    ~MqttsWillMsg();
    void setWillMsg(MQString* msg);
    char* getWillMsg();

private:

 };

/*=====================================
         Class MqttsRegister
  ======================================*/
class MqttsRegister : public MqttsMessage  {
public:
    MqttsRegister();
    ~MqttsRegister();
    void setTopicId(uint16_t topicId);
    uint16_t getTopicId();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();
    void setTopicName(MQString* topicName);
    void setFrame(uint8_t* data, uint8_t len);
    void setFrame(ZBResponse* resp);
    MQString* getTopicName();

private:
    uint16_t _topicId;
    uint16_t _msgId;
    MQString _ustring;

 };

/*=====================================
         Class MqttsRegAck
  ======================================*/
class MqttsRegAck : public MqttsMessage  {
public:
    MqttsRegAck();
    ~MqttsRegAck();
    void setTopicId(uint16_t topicId);
    uint16_t getTopicId();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();
    void setReturnCode(uint8_t rc);
    uint8_t getReturnCode();

private:

 };

 /*=====================================
         Class MqttsPublish
  ======================================*/
class MqttsPublish : public MqttsMessage  {
public:
    MqttsPublish();
    ~MqttsPublish();
    void setFlags(uint8_t flags);
    uint8_t getFlags();
    void setTopicId(uint16_t id);
    void setTopic(MQString* topic);
    MQString* getTopic(MQString* topic);
    uint16_t getTopicId();
    uint8_t  getTopicType();
    uint8_t  getQos();
    bool isRetain();
    void setMsgId(uint16_t msgId);
    void setDup();
    uint16_t getMsgId();
    void setData(uint8_t* data, uint8_t len);
    void setData(MQString* str);
    void setFrame(uint8_t* data, uint8_t len);
    void setFrame(ZBResponse* resp);
    uint8_t* getData();

private:
    uint8_t _flags;
    uint16_t _topicId;
    uint16_t _msgId;
    MQString* _topic;
 };

/*=====================================
         Class MqttsPubAck
  ======================================*/
class MqttsPubAck : public MqttsMessage  {
public:
    MqttsPubAck();
    ~MqttsPubAck();
    void setTopicId(uint16_t id);
    uint16_t getTopicId();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();
    void setReturnCode(uint8_t rc);
    uint8_t getReturnCode();


private:

 };
 /*=====================================
         Class MqttsSubscribe
  ======================================*/
class MqttsSubscribe : public MqttsMessage  {
public:
    MqttsSubscribe();
    ~MqttsSubscribe();
    void setFlags(uint8_t flags);
    void setDup();
    uint8_t getFlags();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();
    uint16_t getTopicId();
        uint8_t  getQos();
    void setTopicName(MQString* topicName);
    MQString* getTopicName();
    void setTopicId(uint16_t predefinedId);
        void setFrame(uint8_t* data, uint8_t len);
        void setFrame(ZBResponse* resp);
protected:
    uint16_t _topicId;
    uint8_t  _flags;
    uint16_t _msgId;
    MQString _ustring;
 };

/*=====================================
         Class MqttsSubAck
  ======================================*/
class MqttsSubAck : public MqttsMessage  {
public:
    MqttsSubAck();
    ~MqttsSubAck();
    void setFlags(uint8_t flags);
    uint8_t getFlags();
    uint8_t getQos();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();
    void setTopicId(uint16_t topicId);
    uint16_t getTopicId();
    void setReturnCode(uint8_t rc);
    uint8_t getReturnCode();

private:

 };

 /*=====================================
         Class MqttsUnsubscribe
  ======================================*/
class MqttsUnsubscribe : public MqttsSubscribe  {
public:
    MqttsUnsubscribe();
    ~MqttsUnsubscribe();
    void setFlags(uint8_t flags);
    void setTopicName(MQString* data);
private:

 };

/*=====================================
         Class MqttsUnSubAck
  ======================================*/
class MqttsUnSubAck : public MqttsMessage  {
public:
    MqttsUnSubAck();
    ~MqttsUnSubAck();
    void setMsgId(uint16_t msgId);
    uint16_t getMsgId();

private:

 };

/*=====================================
        Class MqttsPingReq
 ======================================*/
class MqttsPingReq : public MqttsMessage  {
public:
    MqttsPingReq(MQString* id);
    ~MqttsPingReq();
    //void setClientId(MQString* id);
    char* getClientId();
private:

};

/*=====================================
        Class MqttsPingResp
 ======================================*/
class MqttsPingResp : public MqttsMessage  {
public:
    MqttsPingResp();
    ~MqttsPingResp();
private:

};

 /*=====================================
         Class MqttsDisconnect
  ======================================*/
class MqttsDisconnect : public MqttsMessage  {
public:
    MqttsDisconnect();
    ~MqttsDisconnect();
    void setDuration(uint16_t duration);
    uint16_t getDuration();
private:

 };

/*=====================================
        Class Topic
 ======================================*/
typedef int (*TopicCallback)(MqttsPublish*);

class Topic {
public:
    Topic();
    ~Topic();
    uint8_t   getStatus();
    uint16_t  getTopicId();
    MQString*  getTopicName();
    uint8_t   getTopicLength();
    uint8_t   getTopicType();
    TopicCallback getCallback();
    void     setTopicId(uint16_t id);
    void     setTopicName(MQString* topic);
    void     setStatus(uint8_t stat);
    int      execCallback(MqttsPublish* msg);
    void     copy(Topic* src);
    void     setCallback(TopicCallback callback);
    uint8_t   isWildCard();
    bool     isMatch(Topic* wildCard);
private:
    uint16_t  _topicId;
    uint8_t   _status;
    MQString*  _topicStr;
    TopicCallback  _callback;
};

/*=====================================
        Class Topics
 ======================================*/
class Topics {
public:
      Topics();
      ~Topics();
      bool     allocate(uint8_t topicsSize);
      uint16_t  getTopicId(MQString* topic);
      Topic*    getTopic(MQString* topic);
      Topic*    getTopic(uint16_t topicId);
      bool     setTopicId(MQString* topic, uint16_t id);
      bool     setCallback(MQString* topic, TopicCallback callback);
      bool     setCallback(uint16_t topicId, TopicCallback callback);
      int      execCallback(uint16_t  topicId, MqttsPublish* msg);
      int      execCallback(MQString* topic, MqttsPublish* msg);
      void     addTopic(MQString* topic);
      Topic*    match(MQString* topic);
      void     setSize(uint8_t size);

private:

    uint8_t   _sizeMax;
    uint8_t   _elmCnt;
    Topic*  _topics;

};


/*=====================================
        Class Publish Handler
 ======================================*/
class PublishHandller {
public:
    PublishHandller();
    ~PublishHandller();
    int exec(MqttsPublish* msg, Topics* topics);

};


#endif  /* MQTTS_H_ */
