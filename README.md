---

# Project\_DSA

A C++ application demonstrating **Data Structures & Algorithms (DSA)** through a simple modular management program (patient, service, bill, etc.), running on the **console** with menu-based interaction.

---

## 🎯 Objectives

* Organize source code with **clear modular structure**, reinforcing software design skills.
* Apply **data structures** (vector/list/map, …) and **algorithms** (searching, sorting) in a management problem.
* Provide a foundation for future extensions: data persistence, testing, performance reporting.

## ✨ Key Features

* **Patient Management**: add / edit / delete / search / sort.
* **Service Management**: add / edit / delete / list with prices.
* **Billing**: generate bills for patients & services, calculate totals.
* **Lookup**: by ID / name, filter with basic conditions.
* **Console menu interface**: sequential operations, easy to experiment with.
* *(Optional, if implemented)* **Save/load data** from file.

## 🧱 Architecture & Modules

* `patient.{h,cpp}`: Defines **Patient** (id, name, age, gender, phone, address, …) & related operations.
* `service.{h,cpp}`: Defines **Service** (code, name, price, …) & CRUD.
* `bill.{h,cpp}`: Defines **Bill** (id, patientId, service list, total amount, …).
* `addfunction.{h,cpp}`: Common utility functions (input validation, string/number formatting, error handling, helper I/O, …).
* `menu.{h,cpp}`: Displays menu & routes commands to modules.
* `main.cpp`: Entry point of the program, runs the main menu loop.

## 🛠️ System Requirements

* **Compiler**: C++17 or later (GCC/Clang/MSVC)
* **CMake** *(optional)*: 3.16+
* **Operating System**: Windows / Linux / macOS

## 🚀 Quick Build & Run

**Windows (MinGW):**

```bash
g++ -std=c++17 -O2 -Wall src/*.cpp -o Project_DSA
Project_DSA.exe
```

**Linux/macOS:**

```bash
g++ -std=c++17 -O2 -Wall src/*.cpp -o Project_DSA
./Project_DSA
```

## 🕹️ Usage Guide (example)

When running the program, you will see a menu like:

```
===== MENU =====
1. Patient Management
2. Service Management
3. Billing
4. Lookup
0. Exit
Choose: _
```

Each section provides operations: **Add / Edit / Delete / List / Search / Sort**. Enter the corresponding number following the on-screen instructions.

---
