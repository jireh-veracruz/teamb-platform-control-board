# Team B Platform Control Board

A comprehensive embedded systems platform designed for industrial monitoring and connectivity applications. This repository contains firmware for multiple target platforms including STM32MP1 (Cortex-A7/CM4), STM32H7, and various development boards with connectivity, control, and oil monitoring system (OilMS) capabilities.

## Overview

The Team B Platform Control Board is an embedded systems framework that provides:

- **Multi-platform Support**: STM32MP1 (dual-core), STM32H7, Arduino, ESP-IDF, nRF Connect SDK, PIC32, and Code Composer Studio
- **Connectivity Solutions**: WiFi, MQTT, CAN bus, RS485, XBee, and Zigbee communication protocols  
- **Industrial Applications**: Oil monitoring systems with sensor integration and data logging
- **Modular Architecture**: Separated BSP (Board Support Package), application layer, and utility drivers
- **Cloud Integration**: MQTT-based cloud connectivity with local data storage fallback

## Project Structure

```
├── APP/                    # Application layer
│   ├── projects/          
│   │   ├── connectivity/   # WiFi/MQTT connectivity board firmware
│   │   ├── controlBoard/   # Main control board application
│   │   └── oilMs/         # Oil monitoring system
├── BSP/                   # Board Support Packages
│   ├── stm32/            # STM32 family (MP1, H7)
│   ├── arduino/          # Arduino platforms
│   ├── esp_idf/          # Espressif ESP32 framework
│   ├── nrfconnect/       # Nordic nRF Connect SDK
│   ├── pic32/            # Microchip PIC32
│   └── codecomposer/     # TI Code Composer Studio
├── CUSTOM/               # Custom application modules
│   ├── dev_status/       # Device status monitoring
│   ├── factory_reset/    # Factory reset functionality
│   ├── log_service/      # Logging service
│   ├── ota_update/       # Over-the-air updates
│   └── wired_update/     # Wired firmware updates
├── UTIL_DRVR/           # Utility drivers and libraries
│   ├── can/             # CAN bus communication
│   ├── rs485/           # RS485 serial communication
│   ├── lib_teamb_handshake/  # Team B handshake protocol
│   ├── xbee/            # XBee wireless modules
│   ├── zigbee/          # Zigbee mesh networking
│   ├── thermoc/         # Thermocouple sensors
│   ├── rtc/             # Real-time clock
│   └── logger/          # Data logging utilities
├── EXAMPLE_APP/         # Example applications and demos
└── Dockerfile           # Container for development environment
```

## Supported Platforms

### Primary Targets
- **STM32MP1**: Dual-core (Cortex-A7 + Cortex-M4) with Linux/RTOS capability
- **STM32H7**: High-performance Cortex-M7 microcontroller

### Additional Platforms
- Arduino (various boards)
- ESP32 (via ESP-IDF)
- Nordic nRF series (via nRF Connect SDK)
- Microchip PIC32
- Texas Instruments (via Code Composer Studio)

## Key Features

### Connectivity Board
The connectivity board application (`APP/projects/connectivity/`) provides:
- WiFi network connectivity
- MQTT client for cloud communication
- CAN bus and RS485 protocol support
- Data aggregation from multiple sensors
- Local storage fallback (SD card/EEPROM) when cloud connectivity fails

### Oil Monitoring System (OilMS)
Industrial oil monitoring with:
- Multi-sensor data collection
- Temperature monitoring via thermocouples
- Real-time data logging
- Configurable alert thresholds
- Remote monitoring capabilities

### Communication Protocols
- **CAN Bus**: Industrial-grade vehicle/machinery communication
- **RS485**: Robust serial communication for industrial environments  
- **XBee/Zigbee**: Wireless mesh networking
- **MQTT**: Cloud connectivity and IoT integration
- **Team B Handshake**: Custom inter-device communication protocol

## Build Requirements

### For STM32 Targets (Main Platform)
- ARM GNU Toolchain (`arm-none-eabi-gcc`)
- CMake 3.13+
- Ninja build system

### For Example Applications
- Standard GCC compiler
- CMake 3.10+

### Using Docker (Recommended)
```bash
docker build -t teamb-platform .
docker run -it --rm -v $(pwd):/workspace teamb-platform
```

## Building the Project

### Main Firmware (STM32)
```bash
# Make build script executable
chmod +x build.sh

# Build all targets
./build.sh
```

**Note**: The main build requires ARM cross-compilation tools. Install the ARM GNU Toolchain:
```bash
# Ubuntu/Debian
sudo apt-get install gcc-arm-none-eabi libnewlib-arm-none-eabi

# Or use the provided Docker environment
```

### Example Applications
```bash
cd EXAMPLE_APP/lib_teamb_handshake
chmod +x build_sample_app.sh
./build_sample_app.sh
```

This builds and runs a demonstration of the Team B handshake protocol.

## Configuration Files

The repository includes configuration files for different target setups:
- `connect01.cfg/.dts/.sh` - Connectivity board configuration
- `connect02.cfg` - Alternative connectivity setup  
- `oilms_base.cfg/.dts/.sh` - Base oil monitoring system
- `oilms_mini.cfg/.dts/.sh` - Minimal oil monitoring configuration

## Development Environment

### Using Docker
The included Dockerfile provides a complete development environment with:
- Ubuntu 22.04 base
- ARM cross-compilation toolchain
- CMake and Ninja build tools
- Python development tools

### Manual Setup
Install required dependencies:
```bash
# Build tools
sudo apt-get install build-essential cmake ninja-build git

# ARM toolchain for STM32
sudo apt-get install gcc-arm-none-eabi libnewlib-arm-none-eabi

# Optional: Python tools
sudo apt-get install python3 python3-pip
```

## Usage Examples

### Running the Handshake Example
```bash
cd EXAMPLE_APP/lib_teamb_handshake
./build_sample_app.sh
# Output: "Calling init_handshake() function"
```

### Building for Specific Platforms
The CMake build system automatically selects the appropriate toolchain based on the target platform specified in the BSP configuration.

## Contributing

When contributing to this project:
1. Follow the existing directory structure
2. Add new platforms to the `BSP/` directory
3. Implement platform-specific drivers in `UTIL_DRVR/`
4. Use the existing build system patterns
5. Test on relevant hardware platforms

## Hardware Support

This firmware is designed for:
- Industrial monitoring systems
- IoT connectivity solutions  
- Multi-protocol communication gateways
- Oil and fluid monitoring applications
- Sensor data aggregation systems

## License

[License information to be added]

## Authors

[Author information to be added]
