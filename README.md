# Cplusplus-Authentication-project

Disclaimer:
This project is created by Liang Fang and Shihao Dong by using C++, and it is for educational purposes only.

***Introduction***
Our authenticator is based on an algorithm combining with epoch time and user’s private key, which is converted from user’s email address. As we all know that email address is unique, once you registered, no one else can have same email address. 
Epoch time is a system for describing a point in time, defined as the number of seconds that have elapsed since 0 o’clock, 0 min, 0 sec On Thursday, January 1st, 1970. For example, we see computer’s time on the right corner is 1:30pm, Wednesday, 5.30.2018, in epoch time, it’s equal to like “1527658482”, it keeps changing every second. In other words, it’s Real Time! 
By going through our algorithm, the generated authentication code can maximized the protection from account being hacked.

**Specifications**
- Implementation of epoch time (standardlized).
- Design encryption algorithm based on user's email address and current time stamp.

**Future Plan**
- Implement hash function to generate a more secure authentication code.
- Develop a more robust algorithm with additional features.
- Use database to save the temporary auth code instead of using the simply file I/O.
