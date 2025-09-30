#ifndef MOCK_HAL_COMMS_H
#define MOCK_HAL_COMMS_H

#ifdef __cplusplus
extern "C" {
#endif

// Mock control functions for testing
void mock_hal_set_receive_data(const char* data, int len);
void mock_hal_set_device_ready(int ready);
char* mock_hal_get_sent_data(void);
int mock_hal_get_sent_length(void);
void mock_hal_reset(void);

#ifdef __cplusplus
}
#endif

#endif // MOCK_HAL_COMMS_H