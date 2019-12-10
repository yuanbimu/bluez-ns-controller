#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)

typedef struct MacAddress
{
    uint8_t _0;
    uint8_t _1;
    uint8_t _2;
    uint8_t _3;
    uint8_t _4;
    uint8_t _5;
} MacAddress_t;

typedef struct Alias
{
    char raw[20];
} Alias_t;

#pragma pack()

#define mac_address_le(address) ({MacAddress_t mac = {};sscanf(address, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx", &mac._5, &mac._4, &mac._3, &mac._2, &mac._1, &mac._0);mac; })
#define mac_address_be(address) ({MacAddress_t mac = {};sscanf(address, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx", &mac._0, &mac._1, &mac._2, &mac._3, &mac._4, &mac._5);mac; })
#define alias(str) ({Alias_t a = {};strcpy(a.raw,str);a; })

typedef enum DeviceRole
{
    CONSOLE,
    CONTROLLER,
} DeviceRole_t;

typedef struct Device
{
    const DeviceRole_t role;
    const char *name;
    const char *mac_address;
    const char *serial_number;
} Device_t;

static Device_t SwitchConsole = {
    .role = CONSOLE,
    .name = "Nintendo Switch",
    .mac_address = "DC:68:EB:15:9A:62",
    .serial_number = "XAJ70017696541",
};
#endif //  _DEVICE_H_
