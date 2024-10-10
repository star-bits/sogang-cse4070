# OS

## 프로젝트 0

```
ssh cse20161277@cspro9.sogang.ac.kr
passwd
logout

# SFTP port number is 22
tar -xvzf pintos_modified.tar.gz

vim ~/.bashrc
# export PATH=/sogang/under/cse20161277/pintos/src/utils:$PATH
source ~/.bashrc

~/pintos/src/threads$ make

~/pintos/src/threads$ pintos -v -- -q run alarm-multiple
```

```
(alarm-multiple) thread 3: duration=40, iteration=6, product=240
(alarm-multiple) thread 4: duration=50, iteration=5, product=250
(alarm-multiple) thread 3: duration=40, iteration=7, product=280
(alarm-multiple) thread 4: duration=50, iteration=6, product=300
(alarm-multiple) thread 4: duration=50, iteration=7, product=350
(alarm-multiple) end
Execution of 'alarm-multiple' complete.
Timer: 579 ticks
Thread: 0 idle ticks, 579 kernel ticks, 0 user ticks
Console: 2954 characters output
Keyboard: 0 keys pressed
Powering off...
cse20161277@cspro9:~/pintos/src/threads$ 
```

## 프로젝트 1

```
~/pintos/src/examples$ make

~/pintos/src/userprog$ make

~/pintos/src/userprog$ pintos --filesys-size=2 -p ../examples/echo -a echo -- -f -q run 'echo x'
```

```
Boot complete.
Extracting ustar archive from scratch device into file system...
Putting 'echo' into the file system...
Erasing ustar archive...
Executing 'echo x':
echo x 
echo: exit(0)
Execution of 'echo x' complete.
Timer: 62 ticks
Thread: 2 idle ticks, 59 kernel ticks, 1 user ticks
hda2 (filesys): 67 reads, 208 writes
hda3 (scratch): 101 reads, 2 writes
Console: 842 characters output
Keyboard: 0 keys pressed
Exception: 0 page faults
Powering off...
```

```
~/pintos/src/userprog$ pintos --filesys-size=2 -p ../examples/additional -a additional -- -f -q run 'additional 10 20 62 40'
```

```
SeaBIOS (version 1.13.0-1ubuntu1.1)
Booting from Hard Disk...
PPiiLLoo  hhddaa1
1
LLooaaddiinngg.......................
Kernel command line: -f -q extract run 'additional 10 20 62 40'
Pintos booting with 3,968 kB RAM...
367 pages available in kernel pool.
367 pages available in user pool.
Calibrating timer...  350,208,000 loops/s.
hda: 5,040 sectors (2 MB), model "QM00001", serial "QEMU HARDDISK"
hda1: 197 sectors (98 kB), Pintos OS kernel (20)
hda2: 4,096 sectors (2 MB), Pintos file system (21)
hda3: 118 sectors (59 kB), Pintos scratch (22)
filesys: using hda2
scratch: using hda3
Formatting file system...done.
Boot complete.
Extracting ustar archive from scratch device into file system...
Putting 'additional' into the file system...
Erasing ustar archive...
Executing 'additional 10 20 62 40':
55 62
additional: exit(0)
Execution of 'additional 10 20 62 40' complete.
Timer: 63 ticks
Thread: 1 idle ticks, 61 kernel ticks, 1 user ticks
hda2 (filesys): 63 reads, 240 writes
hda3 (scratch): 117 reads, 2 writes
Console: 900 characters output
Keyboard: 0 keys pressed
Exception: 0 page faults
Powering off...
```

```
~/pintos/src/userprog$ make check
```

```
FAIL tests/userprog/bad-jump2
FAIL tests/userprog/no-vm/multi-oom
FAIL tests/filesys/base/lg-create
FAIL tests/filesys/base/lg-full
FAIL tests/filesys/base/lg-random
FAIL tests/filesys/base/lg-seq-block
FAIL tests/filesys/base/lg-seq-random
FAIL tests/filesys/base/sm-create
FAIL tests/filesys/base/sm-full
FAIL tests/filesys/base/sm-random
FAIL tests/filesys/base/sm-seq-block
FAIL tests/filesys/base/sm-seq-random
FAIL tests/filesys/base/syn-read
FAIL tests/filesys/base/syn-remove
FAIL tests/filesys/base/syn-write
60 of 80 tests failed.
```

[`compare_dirs.py`](https://gist.github.com/star-bits/3a9b88d246116ec9cf6f16b7250a95c6)

```
Only in ./p1-src-h5:
  src/examples/additional.c

No unique files or folders in ./p1-src-sk

Files with the same name but different contents:
  src/examples/Makefile
  src/lib/syscall-nr.h
  src/lib/user/syscall.c
  src/lib/user/syscall.h
  src/threads/thread.c
  src/threads/thread.h
  src/userprog/exception.c
  src/userprog/process.c
  src/userprog/process.h
  src/userprog/syscall.c
  src/userprog/syscall.h
```


