# SystemC Univercity sattelite project

**Table of contents:**
- [SystemC Univercity sattelite project](#systemc-univercity-sattelite-project)
	- [Description](#description)
	- [Modules](#modules)
	- [Building](#building)

## Description

Little SystemC project for univercity.

## Modules

Main modules:
- antenna
- camera
- gelio
- cpu
- switch
- gyroscrope

Utils modules:
- defs

## Building
```
mkdir build
cd build
cmake ..
make -j$(nproc)
```
