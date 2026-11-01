# 🚗 V8 Engine with Alcohol Detection and Engine Locking System

A simple Arduino-based safety prototype that detects alcohol near the driver and automatically locks the engine of a V8 engine model when the alcohol level crosses a set limit.

---

## 📌 Overview

Drunk driving is a major cause of road accidents. This project shows how a low-cost alcohol sensor and a microcontroller can stop an engine from running when alcohol is detected.

The **MQ-3 sensor** measures alcohol vapour. The **Arduino** reads the value, compares it with a threshold, and controls a **relay** that switches the engine motor ON or OFF. A **buzzer** warns when alcohol is detected.

---

## ✨ Features

- Real-time alcohol detection using the MQ-3 sensor
- Automatic engine locking using a relay
- Buzzer alert when alcohol is detected
- 60-second sensor warm-up for stable readings
- Live sensor values on the Serial Monitor
- Simple, beginner-friendly Arduino code

---

## 🔄 How It Works

1. The Arduino powers up and waits **60 seconds** for the MQ-3 heater to stabilise.
2. It reads the sensor value on pin **A0** (range 0 to 1023).
3. It compares the value with the threshold (**400**).
4. **Value ≤ 400 (safe):** buzzer OFF, relay OFF, the engine motor runs.
5. **Value > 400 (alcohol detected):** buzzer ON, relay ON, the motor is cut and the engine is locked.
6. It repeats every 0.5 seconds, so the engine runs again once the alcohol level falls back to the safe range.

```text
Start
  │
  ▼
Warm up sensor (60 s)
  │
  ▼
Read MQ-3 value (A0)
  │
  ▼
Value > 400 ? ──── NO ───► Buzzer OFF, Relay OFF → Engine runs
  │
 YES
  │
  ▼
Buzzer ON, Relay ON → Engine locked
  │
  └──────► Repeat
```

---

## 🧰 Hardware Components

| Component                 | Purpose                                  |
| ------------------------- | ---------------------------------------- |
| Arduino Uno               | Reads the sensor and controls the system |
| MQ-3 Alcohol Sensor       | Detects alcohol vapour                   |
| Relay Module              | Switches the engine motor ON/OFF         |
| DC Motor (V8 model)       | Represents the engine                    |
| Buzzer                    | Warning alert                            |
| External Battery          | Powers the motor                         |
| Connecting Wires          | Electrical connections                   |

---

## 🔌 Pin Connections

| Component               | Arduino Pin |
| ----------------------- | ----------- |
| MQ-3 analog output (AO) | A0          |
| Relay input (IN)        | D7          |
| Buzzer                  | D8          |
| MQ-3 VCC / GND          | 5V / GND    |

The motor is connected through the relay's **normally closed (NC)** contact. When the relay turns ON, the NC line opens and the motor stops. The motor runs from the external battery, so the Arduino is not loaded by it.

---

## 💻 Software

- Arduino IDE
- Embedded C/C++ (Arduino framework)

### Run it

1. Open `V8_Simple.ino` in the Arduino IDE.
2. Select **Board: Arduino Uno** and the correct COM port.
3. Upload the code.
4. Open the Serial Monitor at **9600 baud**.
5. Wait 60 seconds for warm-up, then test with an alcohol-based vapour source (for example, hand sanitiser) held near the sensor.

---

## ⚙️ Key Settings

| Setting           | Value                        |
| ----------------- | ---------------------------- |
| Alcohol threshold | 400 (on the 0 to 1023 scale) |
| Warm-up time      | 60 seconds                   |
| Reading interval  | 500 ms                       |
| Serial baud rate  | 9600                         |

If your relay module is active-LOW, swap the HIGH and LOW values for the relay in the code. Change the threshold after testing in your own environment.

---

## ⚠️ Limitations

- The MQ-3 is affected by temperature, humidity and other gases.
- It needs calibration; the threshold of 400 is a tuned value, not a legal alcohol-limit measurement.
- It is not a certified breath analyser.
- This is a prototype; a real vehicle needs automotive-grade parts and extensive testing.

---

## 🚀 Future Improvements

- Average several readings to reduce noise
- Add an LED status indicator and an LCD display
- Use `millis()` instead of `delay()` for non-blocking timing
- GSM/GPS alert to an emergency contact
- IoT dashboard and event logging (for example, with ESP32)

---

## 🙏 Acknowledgements

Inspired by an ESP32-based alcohol detection and engine locking expo project by a friend. This version was rebuilt on Arduino.

---

## 👤 Author

**Muthupandi K**
Final-year B.E. Electronics and Communication Engineering, V.S.B Engineering College, Karur

---

## 📄 License

Developed for educational and demonstration purposes.
