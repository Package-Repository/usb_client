#include "usb_protocol_client.h"
#include "usb_device_handle.h"

#define STARTER_BYTES 5

int sys_kill()
{
    byte_t message[SML_MSG_SIZE] =      {
                                            INIT_BYTE,   EMPTY_MSG,   SYSTEM,      SYSTEM_KILL,
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD,
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, 
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD,
                                        };
    send_message(message, SML_MSG_SIZE);
}

int move_motors(const byte_t* thrusts)
{
    byte_t message[SML_MSG_SIZE] =      {
                                            INIT_BYTE,   SMALL_MSG,   MOTORS,      MOTOR_MOVE,
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD,
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, 
                                            EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD,
                                        };
    memcpy(message+STARTER_BYTES, thrusts, SML_MSG_SIZE-NON_DATA_BYTES);
    send_message(message, SML_MSG_SIZE);
}
