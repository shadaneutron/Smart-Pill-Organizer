# 💊 Smart Pill Organizer

An intelligent automated medication dispensing system designed to improve medication management for elderly patients and individuals with chronic illnesses.

🏆 **1st Place Winner — Arab AI Olympiad**

---

# 📌 Overview

Medication management is one of the biggest healthcare challenges worldwide.

* Nearly 50% of patients fail to take medications on time.
* Medication errors contribute to thousands of deaths annually.
* Hospitals spend significant time distributing medications manually.

The **Smart Pill Organizer** was developed as an innovative automation solution that minimizes human error, improves medication adherence, and assists healthcare providers.

---

# 🚀 Features

✅ Automated medication scheduling
✅ Smart pill dispensing mechanism
✅ Rotating medicine storage system
✅ Vacuum-based pill pickup system
✅ LCD user interface
✅ Keypad interaction system
✅ Audio alerts using buzzer
✅ IR sensor confirmation for medication intake
✅ Automatic medicine delivery door
✅ Smooth robotic arm movement using servo motors
✅ NEMA 17 stepper motor controlled using L298N driver

---

# ⚙️ System Components

## Hardware

* Arduino Uno
* NEMA 17 Stepper Motor
* L298N Motor Driver
* 3 Servo Motors
* Vacuum Pump
* Relay Module
* LCD I2C Display
* 4x4 Keypad
* IR Sensor
* Buzzer
* External Power Supply

## Software

* Arduino IDE
* Arduino C++
* AccelStepper Library
* Servo Library
* LiquidCrystal_I2C Library
* Keypad Library

---

# 🧠 System Workflow

1. The user starts the system using the keypad.
2. The LCD displays medication status and instructions.
3. The NEMA 17 stepper motor rotates the medication tray.
4. The robotic arm moves toward the selected pill.
5. The vacuum pump picks up the pill accurately.
6. The arm transfers the pill to the delivery compartment.
7. The vacuum system releases the pill.
8. The system alerts the patient using sound notifications.
9. The IR sensor checks whether the patient has taken the medication.
10. The delivery door opens automatically.

---

# 🔌 Circuit Connections (Schematic)

## NEMA 17 + L298N Driver

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| IN1       | D2          |
| IN2       | D3          |
| IN3       | D4          |
| IN4       | D5          |
| ENA       | D8          |
| ENB       | D9          |

---

## Servo Motors

| Servo      | Arduino Pin |
| ---------- | ----------- |
| Servo Arm  | D10         |
| Servo Lift | D11         |
| Servo Door | D12         |

---

## Relay Module

| Relay Pin | Arduino Pin |
| --------- | ----------- |
| IN        | D7          |

---

## IR Sensor

| IR Sensor Pin | Arduino Pin |
| ------------- | ----------- |
| OUT           | D13         |

---

## Buzzer

| Buzzer Pin | Arduino Pin |
| ---------- | ----------- |
| +          | D6          |

---

## LCD I2C

| LCD Pin | Arduino Pin |
| ------- | ----------- |
| SDA     | A4          |
| SCL     | A5          |

---

## Keypad

| Keypad Pin | Arduino Pin |
| ---------- | ----------- |
| R1         | A0          |
| R2         | A1          |
| R3         | A2          |
| R4         | A3          |
| C1         | 0           |
| C2         | 1           |
| C3         | 6           |
| C4         | 7           |

---

# 📷 Project Images

## Hardware Prototype

<img width="4032" height="3024" alt="IMG_6918" src="https://github.com/user-attachments/assets/e91eb955-3412-4671-83c0-fa1e5bb95fe1" />

## Mechanical Design
<img width="1271" height="824" alt="7ab67a13-375c-4f4b-9ca4-4c189931af12" src="https://github.com/user-attachments/assets/1f9ce5c5-b49a-499d-9d8a-e35fedd7c69e" />

<img width="1280" height="781" alt="02974b2d-9672-44a5-8abc-ec8d3a284b95" src="https://github.com/user-attachments/assets/ad7f3ea6-70de-4f17-bc57-e38e4f44cd31" />
<img width="1271" height="824" alt="913426db-8fb0-44bf-be45-50515524c66e" src="https://github.com/user-attachments/assets/ed2a5827-0fad-453b-8ac2-81b9c5fb5cbc" />

---

# 🛠️ Future Improvements

* IoT integration for remote monitoring
* Mobile application support
* AI-based medication scheduling
* Voice assistant support
* Cloud database integration
* Emergency notifications
* Real-time patient monitoring

---

# 🙏 Special Thanks

Special thanks to:

* Eng. Omar El Hefny — Mechanical Design
* Eng. Eyad Ahmed — Technical Support
* Eng. Ahmed Assal — Project Assistance

---

# 📄 License

This project is developed for educational and healthcare innovation purposes.
