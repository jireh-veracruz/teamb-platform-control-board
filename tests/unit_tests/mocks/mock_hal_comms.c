#include <stddef.h>
#include "hal_comms.h"

// Mock variables for testing
static char mock_receive_buffer[256];
static int mock_receive_length = 0;
static char* mock_send_buffer = NULL;
static int mock_send_length = 0;
static int mock_device_ready_return = 1;

// Mock implementations
void hal_init(void)
{
    // Mock implementation - does nothing
}

void hal_service(void)
{
    // Mock implementation - does nothing
}

void hal_receive_data(char* data, int len)
{
    // Copy mock data to the provided buffer
    if (mock_receive_length > 0) {
        for (int i = 0; i < len && i < mock_receive_length; i++) {
            data[i] = mock_receive_buffer[i];
        }
    }
}

int hal_send_data(char* data, int len)
{
    // Store the sent data for verification
    mock_send_buffer = data;
    mock_send_length = len;
    return 1; // Success
}

int hal_device_ready(void)
{
    return mock_device_ready_return;
}

void hal_deinit(void)
{
    // Mock implementation - does nothing
}

int hal_register_device(void* device)
{
    (void)device; // Suppress unused parameter warning
    return 1; // Success
}

// Mock control functions for testing
void mock_hal_set_receive_data(const char* data, int len)
{
    mock_receive_length = len < 256 ? len : 255;
    for (int i = 0; i < mock_receive_length; i++) {
        mock_receive_buffer[i] = data[i];
    }
}

void mock_hal_set_device_ready(int ready)
{
    mock_device_ready_return = ready;
}

char* mock_hal_get_sent_data(void)
{
    return mock_send_buffer;
}

int mock_hal_get_sent_length(void)
{
    return mock_send_length;
}

void mock_hal_reset(void)
{
    mock_receive_length = 0;
    mock_send_buffer = NULL;
    mock_send_length = 0;
    mock_device_ready_return = 1;
}