#ifndef ADT_H
#define ADT_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct frame{
    char SOH;
    int SeqNum;
    int DataLength;
    char* Data;
    char CheckSum;
};

struct ACK{
    char ACK;
    int NextSeqNum;
    char CheckSum;
};
struct sendpacket{
    time_t time;
    struct frame packet;
};

struct frame initialize_frame(int SequentialNumber, int Length, char* buff);

char* stringToBinary(char* s);

struct ACK initialize_ack(char ack, int NextSequentialNumber);

void printcharbin(char a);

void printbinary(struct ACK a);

unsigned char checksum(char* x, int length);

int checksumvalid(struct ACK a);

#endif
