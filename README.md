# 🖥️ OS Simulator (Round Robin Scheduling in C)

This is a command-line Operating System simulator written in C, built to mimic how process scheduling works at a low level — using Round Robin (RR) scheduling. It simulates CPU bursts, context switching, turnaround/waiting time calculations, and file-based process input.

---

## 🚀 Features

- 🧠 Simulates **Round Robin scheduling**
- 📂 Reads process data from `input.txt`
- 📊 Calculates:
  - Completion time
  - Turnaround time (TAT)
  - Waiting time (WT)
  - Average TAT and WT
- 🧵 Simulates context switching
- 💾 Includes basic file I/O and memory usage
- ✅ Skips invalid processes (e.g., burst time = 0)

---

## 🛠️ Tools & Technologies Used

| Category             | Tools / Concepts                     |
|----------------------|--------------------------------------|
| Programming Language | C (GCC Compiler)                     |
| OS Concepts          | Process lifecycle, CPU Scheduling    |
| Scheduling Algorithm | Round Robin                          |
| Data Handling        | Structs, Arrays                      |
| I/O                  | File handling with `fscanf()`        |
| Build Tool           | `gcc` (Makefile optional)            |
| Platform             | Cross-platform: Linux, macOS, WSL    |
| Version Control      | Git + GitHub                         |

---

## 📁 Folder Structure

os_simulator/
├── main.c # Entry point
├── process.h # Process structure
├── file_io.c/h # File reading logic
├── scheduler.c/h # Round Robin logic
├── input.txt # Input data
└── README.md # You're here

yaml
Copy code

---

## 📄 Sample Input (`input.txt`)

1 0 2 1
2 1 4 2
3 2 3 1

yaml
Copy code

Each line = `PID  ARRIVAL_TIME  BURST_TIME  PRIORITY`

---

## 🧪 How to Run

1. **Compile the project**:
```bash
gcc main.c file_io.c scheduler.c -o os_sim
Run the simulator:

bash
Copy code
./os_sim
Edit input.txt to test different scenarios.

📌 Output Example
sql
Copy code
--- Round Robin Scheduling ---
Time 0: P1 running for 2 units
Time 2: P2 running for 2 units
...

--- Completion Times ---
P1 finished at time 4
P2 finished at time 9
P3 finished at time 12

--- Turnaround and Waiting Times ---
P1 | TAT: 4 | WT: 2
P2 | TAT: 8 | WT: 4
...

Average Turnaround Time = 6.33
Average Waiting Time    = 3.00
🙌 Author
Geetanjali Paturi
💼 Computer Science & OS enthusiast
🌐 github.com/GEETP10

💡 Future Enhancements
 Add Priority Scheduling

 Add Multi-Level Feedback Queue

 Write output to log file

 Add GUI (using ncurses)

