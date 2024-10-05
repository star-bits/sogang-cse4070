# OS

## 프로젝트 0

```shell
ssh cse20161277@cspro9.sogang.ac.kr
passwd
logout

# SFTP port number is 22
tar -xvzf pintos_modified.tar.gz

vim ~/.bashrc
# export PATH=/sogang/under/cse20161277/pintos/src/utils:$PATH
source ~/.bashrc

cd ~/pintos/src/threads
make

~/pintos/src/threads$ pintos -v -- -q run alarm-multiple
```

```shell
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

```shell
~/pintos/src/examples$ make

~/pintos/src/userprog$ make

~/pintos/src/userprog$ pintos --filesys-size=2 -p ../examples/echo -a echo -- -f -q run 'echo x'
```

```shell
Formatting file system...done.
Boot complete.
Extracting ustar archive from scratch device into file system...
Putting 'echo' into the file system...
Erasing ustar archive...
Executing 'echo x':
Execution of 'echo x' complete.
Timer: 67 ticks
Thread: 2 idle ticks, 65 kernel ticks, 0 user ticks
hda2 (filesys): 26 reads, 208 writes
hda3 (scratch): 101 reads, 2 writes
Console: 820 characters output
Keyboard: 0 keys pressed
Exception: 0 page faults
Powering off...
cse20161277@cspro9:~/pintos/src/userprog$ 
```
