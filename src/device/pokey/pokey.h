#ifndef __POKEY_H
#define __POKEY_H

#include "../../PoKeysLib.h"
#include <uv.h>

#define DEVICE_READ_INTERVAL 100
#define DEVICE_START_DELAY 100
// #define PWM_CLOCK 25000000
#define PWM_CLOCK 12500000
// #define PWM_CLOCK 500000

#define MAX_DEVICES 16
#define MAX_PINS 55
#define MAX_DEVICE_NAME_LENGTH 10

typedef struct{
    char* name;
    int pin;
    int type;
    int defaultValue;
    int valid;
    int value;
    int previousValue;
    int dutyCycle;
} device_port_t;

typedef struct {
    char* serialNumber;
    char* name;
    int uid;
    int hasPokey;
    int dhcp;
    int numberOfPins;
    sPoKeysDevice* pokey;
    device_port_t *pins[MAX_PINS];
    uv_loop_t* loop;
    pthread_t pThread;
} device_t;

int numberOfDevices;
device_t *devices[MAX_DEVICES];
int activeDevices;

/* function prototypes */
void dumpDevices();
void dumpDevice(device_t *device);
int getDeviceBySerialNumber(device_t* device, char *serialNumber);
int syncDeviceName(device_t *device);
int applyConfiguration(device_t *device);
int startDeviceLoop(device_t *device);
int findPinMappingByName(char *name, device_port_t* port);


#endif
