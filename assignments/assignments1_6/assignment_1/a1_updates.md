---
title:  Assignment 1
subtitle: Linux and C Programming (62558)
author: Mads Richardt (s224948)
date: \today
documentclass: article
geometry: margin=30mm
colorlinks: true 
boxlinks: true
...

# Feedback
## Annotation on PDF Submission
1. Fine, and nice that you use the Alice and Bob analogy but normally the actor trying to get unauthorized access is
called Eve.
2. Fine
3. Fine solution consider setting the GID
4. Maybe also test read and write permissions
5. Fine answer but what about the "t" in the permissions?

# Updates
Based on the feedback, I have made the follow additions to the original submission.

## Changing Group id
```sh 
student@ubuntu-2004:~$ awk '/secrete_group/' /etc/group
secrete_group:x:120:alice,student
student@ubuntu-2004:~$ sudo groupmod -g 121 secrete_group
student@ubuntu-2004:~$ awk '/secrete_group/' /etc/group
secrete_group:x:121:alice,student
```
In the listing above, we changed the group id for the group secrete_group from 120 to 121.

## Changing Permissions 
In the original submission, I forgot to grant Alice write permission on the file secrets.
```sh
student@ubuntu-2004:~$ sudo chown :secrete_group ./shared_folder/secrets 
student@ubuntu-2004:~$ chmod 770 ./shared_folder/secrets 
``` 
Now Alice can read, write and execute the file secretes.

## Testing Permissions
```sh
alice@ubuntu-2004:~$ cat /home/student/shared_folder/secrets 
Secrete stuff...
alice@ubuntu-2004:~$ echo More secrets... >> /home/student/shared_folder/secrets 
alice@ubuntu-2004:~$ cat /home/student/shared_folder/secrets 
Secrete stuff...
More secrets...
```
In the listing above, we see that Alice can now read and write to the file secretes.

## What does "t" mean?
The "t" in the permissions for the tmp folder indicates that the content is "sticky", meaning that only the owner and root have delete permissions. 