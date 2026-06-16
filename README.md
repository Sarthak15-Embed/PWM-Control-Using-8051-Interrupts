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

## 📐 8051 Timer Delay Calculations & PWM Waveforms

### Timer Register Calculations (Mode 1 - 16 Bit Timer)

The project uses an **11.0592 MHz crystal oscillator** and Timer0 operating in **Mode 1 (16-bit Timer Mode)**.

#### Machine Cycle Calculation

```text
Crystal Frequency = 11.0592 MHz

1 Machine Cycle = 12 / 11.0592 MHz
                = 1.085 µs
```

#### Timer Count Formula

```text
Count = Target Delay / 1.085 µs

Timer Value = 65536 - Count
```

### Timer Register Values

| Target Delay | Decimal Count | Timer Value (Hex) | TH0 (High Byte) | TL0 (Low Byte) |
| ------------ | ------------- | ----------------- | --------------- | -------------- |
| 5 ms         | 4608          | 0xEE00            | 0xEE            | 0x00           |
| 10 ms        | 9216          | 0xDC00            | 0xDC            | 0x00           |
| 15 ms        | 13824         | 0xCA00            | 0xCA            | 0x00           |
| 20 ms        | 18433         | 0xB7FF            | 0xB7            | 0xFF           |

---

## ⚡ PWM Duty Cycle Waveforms

The PWM signal is generated using Timer0 delays. Different ON and OFF timings create different motor speeds.

### 25% Duty Cycle

```text
5 ms ON + 15 ms OFF = 20 ms Period

PWM:
_____|‾‾‾‾|_______________

Duty Cycle = 25%
```

| ON Time | OFF Time | Duty Cycle |
| ------- | -------- | ---------- |
| 5 ms    | 15 ms    | 25%        |

---

### 50% Duty Cycle

```text
10 ms ON + 10 ms OFF = 20 ms Period

PWM:
_____|‾‾‾‾‾‾‾‾|__________

Duty Cycle = 50%
```

| ON Time | OFF Time | Duty Cycle |
| ------- | -------- | ---------- |
| 10 ms   | 10 ms    | 50%        |

---

### 75% Duty Cycle

```text
15 ms ON + 5 ms OFF = 20 ms Period

PWM:
_____|‾‾‾‾‾‾‾‾‾‾‾‾|____

Duty Cycle = 75%
```

| ON Time | OFF Time | Duty Cycle |
| ------- | -------- | ---------- |
| 15 ms   | 5 ms     | 75%        |

---

### 100% Duty Cycle

```text
Continuous HIGH

PWM:
________________________________
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

Duty Cycle = 100%
```

| ON Time | OFF Time | Duty Cycle |
| ------- | -------- | ---------- |
| 20 ms   | 0 ms     | 100%       |

---

## 📷 Technical Infographic

Add the infographic image generated for this project in the Images folder:

```text
Images/8051_Timer_PWM_Infographic.png
```

Display it in README using:

```markdown
## Technical Documentation Graphic

![8051 Timer Delay and PWM Generation](Images/8051_Timer_PWM_Infographic.png)
```

This infographic summarizes:

* 8051 Timer0 calculations
* Machine cycle mathematics
* TH0/TL0 register values
* PWM duty cycle generation
* Motor speed control logic


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

**Sarthak Pampattiwar**

Embedded Systems Enthusiast  
Skills: Embedded C | 8051 | LPC2148 | UART | SPI | I2C | PWM | ADC

---

⭐ If you like this project, consider giving it a star!
