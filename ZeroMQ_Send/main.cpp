#include <iostream>
#include <stdio.h>
#include <zmq.h>

using namespace std;
//ZeroMQ
int messageSend(){
    void* pCtx = NULL;
    void* pSock = NULL;
    // 使用 tcp协议进行通信，需要连接的目标机器IP地址为192.168.1.113
    //通信使用网络端口7766
    const char* pAddr = "tcp://192.168.1.113:7766";

    //创建context
    if((pCtx = zmq_ctx_new()) == NULL){
        return 0;
    }
    //创建socket
    if((pSock = zmq_socket(pCtx, ZMQ_DEALER)) == NULL){
        zmq_ctx_destroy(pCtx);
        return 0;
    }
    int iSndTimeout = 5000;

    //设置超时时间
    if(zmq_setsockopt(pSock, ZMQ_RCVTIMEO, &iSndTimeout, sizeof(iSndTimeout)) < 0){
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
        return 0;
    }

    //连接目标IP 192.168.1.113  端口7766
    if(zmq_connect(pSock,pAddr) < 0){
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
        return 0;
    }

    //循环发送消息
    while(1){
        static int i = 0;
        char szMsg[1024] = {0};
        snprintf(szMsg, sizeof(szMsg), "hello world:%3d", ++i);
        printf("Enter to send...\n");
        if(zmq_send(pSock, szMsg, sizeof(szMsg), 0) < 0){
            fprintf(stderr, "send message failed\n");
            continue;
        }

        printf("send message : [%s] succeed \n", szMsg);
        getchar();

    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    messageSend();
    return 0;
}