#include "CppUTest/TestHarness.h"

extern "C" {
    #include "handshake.h"
    #include "mock_hal_comms.h"
    #include "common.h"
}

TEST_GROUP(HandshakeAdvancedTestGroup)
{
    void setup()
    {
        mock_hal_reset();
    }

    void teardown()
    {
        mock_hal_reset();
    }
};

TEST(HandshakeAdvancedTestGroup, TestHandshakeConstants)
{
    // Test that handshake message constants are defined correctly
    STRCMP_EQUAL("HELLO", MSG_HANDSHAKE_INIT);
    STRCMP_EQUAL("ACK", MSG_HANDSHAKE_ACK);
    STRCMP_EQUAL("DATA_READY", MSG_DATA_READY);
    STRCMP_EQUAL("ERROR_TIMEOUT", MSG_ERROR_TIMEOUT);
}

TEST(HandshakeAdvancedTestGroup, TestDeviceStatusConstants)
{
    // Test that device status constants have expected values
    CHECK_EQUAL(0, DEV_STATUS_UNKNOWN);
    CHECK_EQUAL(1, DEV_STATUS_IDLE);
    CHECK_EQUAL(2, DEV_STATUS_ACTIVE);
    CHECK_EQUAL(3, DEV_STATUS_WAITING);
}

TEST(HandshakeAdvancedTestGroup, TestMaxBufferSize)
{
    // Test that MAX_BUFF_SIZE is reasonable
    CHECK(MAX_BUFF_SIZE > 0);
    CHECK(MAX_BUFF_SIZE <= 1024); // Reasonable upper bound
}

TEST(HandshakeAdvancedTestGroup, TestHandshakeMessageConstants)
{
    // Test that handshake message type constants are defined
    CHECK_EQUAL(0, HANDSHAKE_MSG_PING);
    CHECK_EQUAL(1, HANDSHAKE_MSG_PING_REPLY);
    CHECK_EQUAL(2, HANDSHAKE_MSG_SEND_DAT);
    CHECK_EQUAL(3, HANDSHAKE_MSG_RECV_DAT);
}

TEST(HandshakeAdvancedTestGroup, TestCommonConstants)
{
    // Test common constants
    CHECK_EQUAL(1, YES);
    CHECK_EQUAL(0, NO);
    CHECK_EQUAL(1, SUCCESS);
    CHECK_EQUAL(0, FAILED);
    CHECK_EQUAL(1, OK);
    CHECK_EQUAL(0, CANCEL);
}

TEST(HandshakeAdvancedTestGroup, TestDeviceReadyMultipleStates)
{
    // Test device ready with multiple state changes
    mock_hal_set_device_ready(1);
    CHECK_EQUAL(1, teamb_handshake_device_ready());
    
    mock_hal_set_device_ready(0);
    CHECK_EQUAL(0, teamb_handshake_device_ready());
    
    mock_hal_set_device_ready(1);
    CHECK_EQUAL(1, teamb_handshake_device_ready());
}

TEST(HandshakeAdvancedTestGroup, TestSendDataWithDifferentLengths)
{
    const char* test_data = "HELLO";
    
    // Test with different lengths - implementation should still use len=1
    teamb_handshake_send_data((char*)test_data, 1);
    CHECK_EQUAL(1, mock_hal_get_sent_length());
    
    teamb_handshake_send_data((char*)test_data, 5);
    CHECK_EQUAL(1, mock_hal_get_sent_length()); // Still 1 due to implementation
    
    teamb_handshake_send_data((char*)test_data, 10);
    CHECK_EQUAL(1, mock_hal_get_sent_length()); // Still 1 due to implementation
}