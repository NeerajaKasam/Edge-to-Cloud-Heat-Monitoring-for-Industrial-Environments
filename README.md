# Edge-to-Cloud Heat Monitoring for Industrial Environments
## 📌 Overview
The Edge-to-Cloud Heat Monitoring for Industrial Environments project is an IoT-based industrial monitoring system developed using the LPC2148 ARM7 Microcontroller. The system continuously monitors temperature and gas/smoke levels in an industrial environment and uploads real-time data to the cloud using the ESP01 (ESP8266) Wi-Fi Module.  

Temperature data from the LM35 sensor is periodically uploaded to ThingSpeak Cloud, while gas/smoke alerts detected by the MQ-2 sensor are immediately reported. The system also provides local alerts through a buzzer and displays live information on a 16x2 LCD.

This project demonstrates the integration of Embedded Systems, IoT, Cloud Computing, Sensors, UART Communication, ADC, and RTC in a real-world industrial monitoring application.  

---

# 🎯 Project Objectives

* Monitor industrial temperature in real time.
* Detect gas/smoke leakage and generate alerts.
* Upload sensor data to the cloud platform.
* Maintain historical records using ThingSpeak.
* Provide local alerts using buzzer indication.
* Display current system status on LCD.
* Use RTC for periodic cloud updates.
* Enable remote monitoring from anywhere.

---

# 🏗️ System Architecture

```text
                 +------------------+
                 |      LM35        |
                 | Temperature      |
                 +--------+---------+
                          |
                          v
                    ADC (LPC2148)
                          |
+-----------+      +------+-------+      +-----------+
|   MQ-2    |----->|   LPC2148    |----->|   LCD     |
| GasSensor |      | ARM7 MCU     |      | Display   |
+-----------+      +------+-------+      +-----------+
                          |
                          |
                     UART0
                          |
                          v
                   +-------------+
                   | ESP01 WiFi  |
                   +------+------+
                          |
                          v
                    ThingSpeak
                       Cloud
                          |
                          v
                 Mobile / Laptop
```

---

# ✨ Features

### Temperature Monitoring

* LM35 continuously measures temperature.
* ADC converts analog sensor output to digital value.
* Temperature displayed on LCD.
* Data uploaded to cloud every 3 minutes.

### Gas/Smoke Detection

* MQ-2 sensor monitors smoke and gas concentration.
* Immediate alert generation when threshold exceeds limit.
* Buzzer activated during hazardous conditions.
* Alert status uploaded to cloud instantly.

### Cloud Connectivity

* ESP01 Wi-Fi module provides internet access.
* ThingSpeak stores and visualizes sensor data.
* Historical temperature analysis available remotely.

### Real-Time Clock Support

* RTC maintains accurate time tracking.
* Controls periodic cloud updates.
* Reduces unnecessary network traffic.

---

# 🛠 Hardware Requirements

| Component          | Description                |
| ------------------ | -------------------------- |
| LPC2148            | ARM7TDMI-S Microcontroller |
| LM35               | Temperature Sensor         |
| MQ-2               | Gas/Smoke Sensor           |
| ESP01              | Wi-Fi Module (ESP8266)     |
| 16x2 LCD           | Display Unit               |
| Buzzer             | Alert Indication           |
| USB-UART Converter | Programming & Debugging    |
| Power Supply       | 5V Regulated               |

---

# 💻 Software Requirements

* Keil µVision
* Embedded C
* Flash Magic
* ThingSpeak Cloud Platform
* Serial Terminal

---

# 📂 Project Structure

```text
Project/
│
├── main.c
│
├── lcd.c
├── lcd.h
├── lcd_defines.h
│
├── adc.c
├── adc.h
├── adc_defines.h
│
├── uart0.c
├── uart0.h
│
├── esp01.c
├── esp01.h
│
├── rtc.c
├── rtc.h
├── rtc_defines.h
│
├── delay.c
├── delay.h
│
├── defines.h
├── types.h
│
└── README.md
```

---

# 📁 Module Description

## main.c

Main application file responsible for:

* Initialization of peripherals
* Reading sensor values
* LCD updates
* Cloud communication
* Alarm generation
* System control flow

---

## ADC Module

### Files

```text
adc.c
adc.h
adc_defines.h
```

### Function

* Configures ADC channel
* Reads LM35 temperature value
* Converts analog voltage into digital data

---

## LCD Module

### Files

```text
lcd.c
lcd.h
lcd_defines.h
```

### Function

* LCD initialization
* Display strings
* Display sensor readings
* User status indication

---

## UART Module

### Files

```text
uart0.c
uart0.h
```

### Function

* UART initialization
* Serial communication
* ESP01 communication

---

## ESP01 Driver

### Files

```text
esp01.c
esp01.h
```

### Function

* Send AT commands
* Connect to Wi-Fi
* Send HTTP GET requests
* Upload data to ThingSpeak

---

## RTC Module

### Files

```text
rtc.c
rtc.h
rtc_defines.h
```

### Function

* Real-time clock configuration
* Periodic timing control
* 3-minute cloud upload scheduling

---

## Delay Module

### Files

```text
delay.c
delay.h
```

### Function

* Software delay generation
* LCD timing support
* Sensor stabilization delays

---

# 🔄 Project Workflow

### Step 1

Initialize:

* LCD
* ADC
* UART
* RTC
* ESP01

### Step 2

Read LM35 temperature.

### Step 3

Display temperature on LCD.

### Step 4

Check MQ-2 sensor status.

### Step 5

If gas detected:

* Activate buzzer
* Display warning
* Send alert to cloud

### Step 6

RTC checks 3-minute interval.

### Step 7

Upload temperature data to ThingSpeak.

### Step 8

Repeat forever.

---

# ☁️ ThingSpeak Data Fields

| Field   | Description      |
| ------- | ---------------- |
| Field 1 | Temperature (°C) |
| Field 2 | Gas Alert Status |

---

# 📡 ESP01 AT Commands Used

## Disable Echo

```text
ATE0
```

## Check Module

```text
AT
```

## Set Wi-Fi Mode

```text
AT+CWMODE=1
```

## Connect to Wi-Fi

```text
AT+CWJAP="SSID","PASSWORD"
```

## Start TCP Connection

```text
AT+CIPSTART="TCP","api.thingspeak.com",80
```

## Send Data

```text
AT+CIPSEND=<length>
```

## Close Connection

```text
AT+CIPCLOSE
```

---

# 🚨 Alert Conditions

## Normal Condition

```text
Temperature within limit
Gas not detected
Buzzer OFF
```

## Warning Condition

```text
Gas detected
Buzzer ON
Alert uploaded
```

---

# 🔍 Applications

* Industrial Heat Monitoring
* Factory Safety Systems
* Boiler Monitoring
* Chemical Industries
* Warehouse Monitoring
* Manufacturing Plants
* Smart Industry 4.0 Solutions

---

# 🚀 Future Enhancements

* Mobile Application Integration
* Email Alert System
* SMS Notifications
* MQTT Cloud Integration
* AWS IoT Integration
* Data Analytics Dashboard
* Multiple Sensor Support
* Predictive Maintenance Features

---

# 🎓 Learning Outcomes

This project helps in understanding:

* ARM7 LPC2148 Programming
* Embedded C Development
* ADC Interfacing
* UART Communication
* ESP8266 Wi-Fi Communication
* ThingSpeak Cloud Integration
* RTC Programming
* Sensor Interfacing
* Industrial IoT Concepts
* Edge Computing Fundamentals

---

# 👨‍💻 Author

**Neeraja Kasam**

Electronics & communication Engineering
Embedded Systems | ARM | Embedded C | IoT
