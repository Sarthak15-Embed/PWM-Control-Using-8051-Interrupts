# ⚙️ 8051 PWM Generation using Interrupts for DC Motor Control

![C Language](https://img.shields.io/badge/Language-C-blue)
![8051 Microcontroller](https://img.shields.io/badge/Microcontroller-8051-orange)
![Embedded Systems](https://img.shields.io/badge/Domain-Embedded%20Systems-green)

---

## 📌 Project Overview

This project demonstrates **PWM (Pulse Width Modulation) generation using Timer0 interrupts** on the **8051 microcontroller** for controlling a DC motor.

The system uses **software PWM** to control motor speed and direction through an **L293D motor driver**. The design is implemented in **Embedded C** and simulated using **Proteus**.

---

## ✨ Features

- PWM generation using Timer0
- Software-based PWM control
- DC Motor speed control
- Motor direction control
- Proteus simulation support
- Embedded C implementation
- Interrupt-based control logic

---

## 🧠 Working Principle

The microcontroller generates PWM by switching the output pin ON and OFF based on timer overflow.

- HIGH time → Motor ON
- LOW time → Motor OFF

By changing ON/OFF ratio, motor speed is controlled.

Direction is controlled using L293D input pins.

---

## 🔌 Hardware / Simulation Setup

| Component | Description |
|-----------|-------------|
| Microcontroller | 8051 (AT89C51 / AT89S52) |
| Motor Driver | L293D |
| DC Motor | Load |
| Crystal | 11.0592 MHz |
| Power Supply | 5V |
| Simulation Tool | Proteus |

---

## 🔗 Pin Configuration

| 8051 Pin | Function |
|----------|----------|
| P0.0 | IN1 (Motor Direction) |
| P0.1 | IN2 (Motor Direction) |
| P0.2 | PWM Output (Enable Pin) |

---

## 📊 PWM Concept

Duty cycle controls motor speed:

| Duty Cycle | Speed |
|------------|------|
| 25% | Low Speed |
| 50% | Medium Speed |
| 75% | High Speed |
| 100% | Full Speed |

---

## ⚙️ Working Flow

1. Initialize Timer0
2. Generate interrupt-based delay
3. Create PWM signal using ON/OFF switching
4. Apply PWM to L293D Enable pin
5. Control motor speed
6. Change direction using input pins

---

## 🧾 Code Explanation

### 🔹 main()

- Initializes ports
- Configures Timer0
- Runs infinite loop
- Controls PWM output

---

### 🔹 ISR (Interrupt Routine)

- Handles timer overflow
- Toggles PWM signal
- Maintains duty cycle timing

---

### 🔹 timer_delay()

- Generates precise delay using Timer0
- Controls PWM ON time

---

### 🔹 delay()

- Simple software delay function
- Used for timing adjustment and stability

---

## 📁 Project Structure

```
8051-PWM-Interrupt-Based-Motor-Control
│
├── README.md
├── Source_Code
│   └── Pwm_Interrupt.c
│
├── Proteus_Simulation
│   ├── L2935_DC_Motor.pdsprj
│   └── connection_diagram.png
│
├── Startup_Code
│   └── STARTUP.A51
│
└── Images
    └── output.png
```

---

## 🚀 How to Run

### Step 1
Open project in **Keil uVision**

### Step 2
Build project and generate HEX file

### Step 3
Open **Proteus**

### Step 4
Load HEX file into 8051

### Step 5
Run simulation

### Step 6
Observe:
- Motor speed variation (PWM effect)
- Direction control via L293D

---

## 🖼 Simulation

👉 Add your Proteus connection image here:

```
Images/connection_diagram.png
```

---

## 📈 Expected Output

- Smooth motor speed variation using PWM
- Proper direction control via L293D
- Stable interrupt-based timing behavior

---

## 🔮 Future Improvements

- UART-based motor control
- LCD display for speed level
- Closed-loop speed control
- Encoder feedback system
- IoT-based motor control

---

## ⚠️ Note

This project uses **software PWM**, not hardware PWM, making it ideal for learning embedded fundamentals on 8051.

---

## 👨‍💻 Author

**Lovely Kumar**

Embedded Systems Enthusiast  
Skills: Embedded C | 8051 | LPC2148 | UART | SPI | I2C | PWM | ADC

---

⭐ If you like this project, consider giving it a star!
