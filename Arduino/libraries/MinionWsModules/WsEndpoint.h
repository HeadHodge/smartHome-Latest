#ifndef WSENPOINT_H
#define WSENPOINT_H

namespace WsEndpoint {
    //typedef char* (*callBack)(unsigned char*);
    #define CURRENT_TIME millis()
    
    enum connectOptions {
        CONNECT_SSID, CONNECT_PASSWORD, CONNECT_ADDRESS, CONNECT_PORT, CONNECT_PATH
    };

    static char* _defaultConnectInfo[] = {
        "NOSSID",
        "NOPASSWORD",
        "NOADDRESS",
        "NOPORT",
        "NOPATH"
    };
  
    bool sendReplyPkg(const char *pPkg);
    bool sendControlPkg(const char *pPkg);    
    bool sendControlPkg(DynamicJsonDocument& pPkg);
    char** getConnectInfo();
    void refresh();
    bool isWifiConnected();
    
    bool awaitEndpoint(
        char* pConnectInfo[] = _defaultConnectInfo,
        void (*pOnPkgInput)(DynamicJsonDocument& pPkgObj) = nullptr
    );
    
    bool connectEndpoint(
        char* pConnectInfo[] = _defaultConnectInfo,
        char* pEndpointInfo[] = _defaultConnectInfo,
        void (*pOnPkgInput)(DynamicJsonDocument& pPkgObj) = nullptr
    );
} //namespace WsEndpoint

#endif