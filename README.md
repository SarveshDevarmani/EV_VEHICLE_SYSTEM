# EV_VEHICLE_SYSTEM

A C++ OOP-based Electric Vehicle Management System developed as a team project.

## Project Structure
EV_VEHICLE_SYSTEM/
│
├── .vscode/
│ └── tasks.json
│
├── include/
│ ├── Customer.h
│ └── Vehicle.h
│
├── src/
│ ├── Customer.cpp
│ └── Vehicle.cpp
│
├── build/
│ └── EV_VEHICLE_SYSTEM.exe
│
├── main.cpp
├── .gitignore
└── README.md

text

## Requirements

Install the following:

- [VS Code](https://code.visualstudio.com/)
- C/C++ Extension for VS Code
- MinGW / G++ Compiler
- Git

Check whether G++ is installed:

```bash
g++ --version
```

Check whether Git is installed:

```bash
git --version
```

## Setup

Clone the repository:

```bash
git clone <REPOSITORY-URL>
```

Move into the project folder:

```bash
cd EV_VEHICLE_SYSTEM
```

Open the project in VS Code:

```bash
code .
```

Make sure the project contains the `.vscode` folder with:
.vscode/
└── tasks.json

text

The `tasks.json` file contains the required build configuration.

## Build the Project

After opening the project in VS Code:

1. Press `Ctrl + Shift + B`
2. Select **Build EV Vehicle System** if prompted
3. The project will compile automatically
4. The `build` folder will be created if it does not already exist
5. The executable will be generated inside the `build` folder

Generated executable:
build/EV_VEHICLE_SYSTEM.exe

text

## Run the Program

After a successful build, open the VS Code terminal and run:

```powershell
.\build\EV_VEHICLE_SYSTEM.exe
```

The program will start in the terminal.

## Quick Workflow

Every time you make changes to the code:
Edit Code
↓
Ctrl + Shift + B
↓
Build EV Vehicle System
↓
build/EV_VEHICLE_SYSTEM.exe
↓
.\build\EV_VEHICLE_SYSTEM.exe

text

## Git Notes

The following files are generated locally and should **not** be uploaded to GitHub:

- `build/`
- `*.exe`

The shared VS Code build configuration **should** be kept in GitHub:

- `.vscode/tasks.json`

Personal VS Code configuration files such as `settings.json`, `launch.json`, and `c_cpp_properties.json` are ignored through `.gitignore`.

