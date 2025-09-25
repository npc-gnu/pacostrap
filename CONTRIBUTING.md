# Contributing Guideline
> For both developers and normal users.
**Firstly, thank you!**

## For Normal Users
- You can test it both in first stage, second stage and ArchISO Edition.
If you are asking,
> What the hell are we going to test?

There is 2 kind of errors *and you should test* .

|------------------------------------|---------------------------------------|
|        User Interface Error        |         Critical Running Error        |
|------------------------------------|---------------------------------------|
| Not Working Animations             | Failed to format, mount your disk,    |
| (Spinning stick and dot animation) | failed to take package name.          |
| No Colors                          | Unrecognized argumant                 |
|------------------------------------|---------------------------------------|
|            /etc.                   |              /etc.                    |
|------------------------------------|---------------------------------------|

- Then add your failed test results to Issues.
- Translate documentations to other languages.
- Fix spelling mistakes.
**You can both open ISSUE in GitHub or Gitlab!**[Pacostrap - GitLab Link](https://gitlab.com/pigames3/pacostrap)

## For developers
- Please use command() instead of fork()/exec() or system(). It's syntax is more easier than fork()/exec() and it prevents itself from shell injections(problem of system()) so it is secure.
- Please use colors and animations(using spinner animation for long things and animatel() for shorter processes.). And if you did not, leave comments on your source code like
```C++
// FIXME AC 
// FIXME ALA
// FIXME ASA
```
> AC means *Add colors*, ALA means *Add long animation*(Spinning animation) and ASA means *Add short animation*(Dot animation).

- When to use which colors will be added here soon.
