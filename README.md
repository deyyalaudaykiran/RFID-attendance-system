# 🚀 RFID Attendance System using LPC2129 and Linux Serial Monitoring

An Embedded-Based **RFID Attendance Management System** developed using the **LPC2129 ARM7 Microcontroller**, **RFID Reader**, **DS1307 RTC Module**, **16x2 LCD Display**, and **UART Serial Communication**.

This project records employee attendance using RFID cards and displays login/logout details on a Linux terminal through serial communication using a **DB9 cable**.

---

# ✨ Features

## 🪪 RFID Based Attendance System

* Employees mark attendance using RFID cards
* Each employee has a unique RFID tag
* Automatically detects valid and invalid cards

---

## ⏰ Real-Time Clock (RTC)

* DS1307 RTC module used for:

  * Current Time
  * Date
  * Day
* Attendance is recorded with timestamp

---

## 🖥️ LCD Display

16x2 LCD displays:

* Employee Name
* Login Status
* Logout Status
* Time and Date

---

## 🔌 UART Serial Communication

* LPC2129 communicates with Linux PC using UART0
* Attendance data transmitted through DB9 serial cable


---

## 🐧 Linux Terminal Monitoring

* `linux.c` receives attendance data
* Displays employee login/logout information in terminal

---

## 💾 Attendance Logging

* Login and logout times stored automatically
* Employee database maintained using RFID IDs

---

# 🛠️ Technologies Used

* Embedded C
* LPC2129 ARM7 Microcontroller
* Keil uVision IDE
* Flash Magic
* UART Communication
* I2C Communication
* RFID Technology
* RTC DS1307
* Linux System Programming
* Serial Communication
* Interrupt Programming

---

# 📂 Project Structure

```bash id="1p5tr4"
.
├── main.c
├── uart0_driver.c
├── uart0_interrupt.c
├── i2c_driver.c
├── lcd4bit_driver.c
├── linux.c
├── delay.c
├── header.h
├── data
└── README.md
```

---

# 📌 Working Principle

## Step-by-Step Workflow

### 1️⃣ RFID Card Scan

Employee places RFID card near RFID reader.

---

### 2️⃣ UART Interrupt Triggered

RFID data received through UART interrupt.

File used:

```bash id="r7l7ye"
uart0_interrupt.c
```

---

### 3️⃣ LPC2129 Reads RFID ID

Microcontroller stores RFID number.

Example:

```text id="d2h4qf"
4900C9C08FCF
```

---

### 4️⃣ RTC Provides Time & Date

DS1307 RTC module provides:

* Hours
* Minutes
* Seconds
* Date
* Day

Using I2C protocol.

---

### 5️⃣ LCD Displays Attendance

LCD shows:

```text id="4v1kq9"
uday
login
```

or

```text id="5h0r9n"
sachin
logout
```

---

### 6️⃣ Attendance Sent to Linux PC

Attendance data transmitted through UART serial communication.

---

### 7️⃣ Linux Program Receives Data

`linux.c` continuously monitors serial port:

```bash id="e2tr3a"
/dev/ttyUSB0
```

---

### 8️⃣ Attendance Displayed in Terminal

Example:

```text id="9m8h0z"
ID=4900C9C08FCF
NAME=uday
IN-TIME 10:30:22 10/03/26 MON
```

---

# 🔥 Hardware Components Required

| Component                 | Purpose                   |
| ------------------------- | ------------------------- |
| LPC2129 Development Board | Main Controller           |
| RFID Reader               | Reads RFID Tags           |
| RFID Tags/Cards           | Employee Identification   |
| DS1307 RTC Module         | Time & Date               |
| 16x2 LCD Display          | Output Display            |
| MAX232 IC                 | Serial Voltage Conversion |
| DB9 Serial Cable          | PC Communication          |
| Linux PC                  | Attendance Monitoring     |
| Power Supply              | Circuit Power             |

---

# 🔌 Hardware Connections

# 🪪 RFID Reader Connections

| RFID Reader | LPC2129 |
| ----------- | ------- |
| TX          | RXD0    |
| GND         | GND     |
| VCC         | 5V      |

---

# ⏰ DS1307 RTC Connections

| DS1307 | LPC2129 |
| ------ | ------- |
| SDA    | P0.3    |
| SCL    | P0.2    |
| VCC    | 5V      |
| GND    | GND     |

---

# 🖥️ LCD Connections

LCD connected in:

* 4-bit mode

LCD pins connected to LPC2129 GPIO pins.

---

# 🔌 Serial Communication Connections

```text id="m8z4sa"
LPC2129 ↔ MAX232 ↔ DB9 Cable ↔ Linux PC
```

---

# 🛠️ Software Requirements

## ✅ Embedded Software Tools

### Keil uVision IDE

Used for:

* Writing Embedded C code
* Compiling source files
* Creating HEX file

Download:

* https://www.keil.com/download/

---

## ✅ Flash Magic

Used for:

* Uploading HEX file into LPC2129

Download:

* https://www.flashmagictool.com/

---

## ✅ Linux Environment

Used for:

* Running serial monitoring program

Supported:

* Ubuntu
* Debian
* Kali Linux
* Fedora

---

# ⚙️ Installation & Setup Guide

# 📥 Step 1: Clone the Repository

```bash id="cv3wyu"
git clone https://github.com/deyyalaudaykiran/RFID-attendance-system.git
```

---

# 📂 Step 2: Open Project Folder

```bash id="d3xy2o"
cd RFID-Attendance-System
```

---

# 🛠️ Step 3: Open Project in Keil

1. Open **Keil uVision**
2. Create new project
3. Select device:

```text id="1jlwm1"
NXP → LPC2129
```

4. Add source files:

   * main.c
   * uart0_driver.c
   * uart0_interrupt.c
   * i2c_driver.c
   * lcd4bit_driver.c
   * header.h
   * delay.c

---

# ⚙️ Step 4: Build the Project

## Click:

```text id="qz5r8g"
Project → Build Target
```

OR press:

```text id="b5m9az"
F7
```

---

# 📦 Step 5: HEX File Generation

After successful compilation:

```bash id="v0f7q3"
project.hex
```

will be generated.

---

# ⚡ Step 6: Flash HEX File into LPC2129

## Open Flash Magic

### Configure Settings

| Setting   | Value           |
| --------- | --------------- |
| Device    | LPC2129         |
| COM Port  | Select COM Port |
| Baud Rate | 9600            |
| Interface | None (ISP)      |

---

## Select HEX File

```bash id="1apxzr"
project.hex
```

---

## Click:

```text id="v70x6j"
Start
```

HEX file will be uploaded into LPC2129.

---

# 🔌 Step 7: Connect Hardware

Connect:

* RFID Reader
* RTC Module
* LCD
* MAX232
* DB9 Cable

Power ON the LPC2129 board.

---

# 🐧 Step 8: Compile Linux Program

## Install GCC Compiler

### Ubuntu/Debian

```bash id="ow0f1k"
sudo apt update
sudo apt install build-essential
```

---

# ⚙️ Compile linux.c

```bash id="i8ml3e"
gcc linux.c -o linux
```

---

# ▶️ Step 9: Run Linux Attendance Monitor

```bash id="b3q0mx"
./linux
```

---

# 📁 Step 10: Create Employee Database File

Create file:

```bash id="5nqg3f"
data
```

---

## Example Data File


4900C9C08FCF Uday

4900C8EC3855 Sachin

0200105B3C75 Anuradha

4900C8E53F5V Parti

00201068BE891 Kavya

```

---

# 💬 Example Output

## LCD Display

uday

login
```

---

## Linux Terminal Output

ID=4900C9C08FCF

NAME=uday

IN-TIME 10:30:22 10/03/26 MON


# 📚 Source File Explanation

| File Name         | Purpose                 |
| ----------------- | ----------------------- |
| main.c            | Main application logic  |
| uart0_driver.c    | UART communication      |
| uart0_interrupt.c | RFID interrupt handling |
| i2c_driver.c      | RTC communication       |
| lcd4bit_driver.c  | LCD interfacing         |
| linux.c           | Linux serial monitoring |
| header.h          | Function declarations   |

---

# 🔥 Key Concepts Demonstrated

✔️ Embedded C Programming

✔️ ARM7 LPC2129 Programming

✔️ UART Communication

✔️ I2C Communication

✔️ RTC Interfacing

✔️ RFID Interfacing

✔️ Interrupt Handling

✔️ Linux Serial Programming

✔️ Attendance Automation

---

# 🚀 Future Enhancements

* Fingerprint Authentication
* WiFi Attendance Monitoring
* GSM SMS Alerts
* Cloud Database Integration
* Web Dashboard
* Mobile App Integration
* Face Recognition

---

# ⚠️ Important Notes

* Server/Linux PC must detect serial device:

```bash id="tcfjlwm"
/dev/ttyUSB0
```

* RFID IDs must match entries in `data` file
* HEX file must be flashed before running Linux program
* MAX232 required for DB9 communication

---

# 🧹 Troubleshooting

## Check USB Serial Device

```bash id="7kkm4g"
ls /dev/ttyUSB*
```

---

## Give Serial Port Permission

```bash id="0w5j5u"
sudo chmod 777 /dev/ttyUSB0
```

---

## Check Serial Communication

```bash id="6a9gtt"
dmesg | grep tty
```

---

# 👨‍💻 Learning Outcomes

This project helps understand:

* ARM7 Embedded Programming
* LPC2129 Peripheral Interfacing
* UART Communication
* I2C Protocol
* RFID Systems
* RTC Integration
* Linux Serial Communication
* Interrupt Driven Programming
* Real-Time Embedded Systems

---

# ⭐ Support

If you found this project useful:

⭐ Star the repository

🍴 Fork the project

🛠️ Contribute improvements

---
