# OS

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
~/pintos/src/examples$ make

~/pintos/src/userprog$ make

~/pintos/src/userprog$ pintos --filesys-size=2 -p ../examples/echo -a echo -- -f -q run 'echo x'
```
