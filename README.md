# procinfo
## Info
Provides CPU information

## Commands:
* all : shows all information available
* cores : shows cores count
* frequency : shows frequency in MHz
* model : shows cpu model name, f.e. Intel Core i9-10900F

## Assumptions
* Supports x86_64 architecture

## Build steps
* Create docker image
``` bash
./docker.sh create
```
* Run container
``` bash
./docker.sh run
```
* Exit
``` bash
exit
```
* Build 
``` bash
./docker.sh build
```
* Access to container
``` bash
./docker.sh cmd
```

## Run tests
``` bash
./docker.sh test_run
```
