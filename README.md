# Computer Architecture Assignments

This repository contains the **Computer Architecture (ECGR 4181/5181) Assignments** completed as part of coursework. Each assignment focuses on different aspects of **processor design, pipeline execution, and event-driven simulations**.

## 📌 Assignments Overview

### 📝 Assignment 1: Master Event Queue (MEQ) Simulation
- Implemented a **Master Event Queue (MEQ)** using **C++ and Vectors**.
- **Generated 20 random events**, each defined as **E = (t, v)** where:
  - `t` is the execution time (taken from system time).
  - `v` is a random integer.
- Events were **sorted-inserted** into the queue.
- A function reads the **earliest event**, prints `v`, generates a new event `E'`, and re-inserts it into the queue.
- The simulation **processed 100 events** before termination.

📂 **File:** `ComputerArchitecture_assignment3.cpp`

---

### 📝 Assignment 2: Pipelined CPU Simulation
- Simulated a **4-stage pipelined CPU** with:
  - **Fetch, Decode, Execute, Store** stages.
- Implemented an **Event-driven simulator** to execute **RISC-V assembly instructions**.
- Printed the **clock cycle progression** and **event list** dynamically.
- **Branch handling included**: Predictively fetched instructions were discarded when the loop completed.
- Used **C++ to simulate the pipeline**, and each stage printed `{stage_name, instruction_name, data, clock cycle number}`.

📂 **File:** `ComputerArchitecture_assignment2.cpp`

---

### 📝 Assignment 3: RISC-V Decoder Implementation
- Designed a **RISC-V Decoder** for a **von Neumann architecture**.
- Implemented **instruction decoding in C++**, supporting:
  - **RV32I, RV32F, and RV32M** instruction subsets.
  - Ignored `double words, ecall, ebreak, fence, and "cs" ops`.
- **Implemented an unpipelined design**.
- **Decoder functions included:**
  - Parsing **R-type, I-type, S-type, SB-type, U-type, and UJ-type instructions**.
  - Printed control signals for each instruction.

📂 **File:** `ComputerArchitecture_assignment3.cpp`

---

## 💻 Technologies Used
- **C++**
- **Event-driven simulation**
- **RISC-V Assembly**
- **CPU Pipeline Modeling**
- **Data Structures (Vectors for Queues)**

---

## 📢 Contributors
👤 **Poojitha Rajapuram**  
👤 **Indhuja Gudluru**  

---

## 📜 License
This project is for **educational purposes only**. Feel free to use it for learning, but always give credit where it's due.

---

🔥 **Stay tuned for more projects related to computer architecture, processor design, and embedded systems!**
