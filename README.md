# Cpp-Keylogger (Completed)
Advanced keylogger made in C++ that works on Window 7, 8, 8.1, And 10 - **Use at your own discretion** <br/><br/>
This is a keylogger I learned from Udemy for educational purposes. Please do not use this code for illegal or immoral purposes and keep it open source! The project also includes a decryption program will accepts an encrypted log file and translates it to a human readable language. <br/>
If you would like to take the course yourself, check it out [here](https://www.udemy.com/how-to-create-an-advanced-keylogger-from-scratch-for-windows).

### Features
  * Lots of comments in each of the source files for the user
  * Low-resource usage/non-intensive process and generates no windows when ran
  * Asynchronous execution of processes
  * Capture all keystrokes using system hooks
  * Automatically log the time and date when a log file is produced
  * Uses Base64 encryption with slight modifications and encodes the log multiple times
  * Generates and invokes a powershell script that can attach the encrypted log and email it
  * Lots of customization options in the source code for user to modify:
    * Name of the process
    * Email to send from and send to
    * Time between each log file generation
    * When to enable and disable the keyboard hooks
    * Method of encryption used
    * Format which the keys are recorded

### Prerequisites

What things you need to install the software and how to install them

```
* Visual Studio preferably or any IDE of your choice
* C++11 standards must be enabled and if using GCC compilter, -mwindows flag needs to be checked

```

### Installing

A step by step series of examples that tell you have to get a development environment running

Download the repository using either bash or the browser

```
git clone https://github.com/htmercury/Cpp-Keylogger
```

Open the solution file in Visual Studio using the sln file

```
located at ../Cpp-Keylogger/Keylogger.sln
```

For other IDEs, make a project that includes all source and header files

```
located at ../Cpp-Keylogger/Keylogger
```

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Disclaimer
Any usage of this keylogger on a computer that is not owned by you or do not have permissions, **YOU ARE RESPONSIBLE FOR THE OUTCOME**. Not me.
