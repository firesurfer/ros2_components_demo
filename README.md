#ros2_components_demo
Demo for how to use ros2_components

## Building  on linux
0. Source a ros2 ws like described in:

https://github.com/ros2/ros2/wiki/Ament-Tutorial

1. Create a workspace 
```
mkdir -p demo_ws/src/demo
```

2. Checkout repositories

```
cd demo_ws/src/demo
git clone https://github.com/firesurfer/ros2_components_msg
git clone https://github.com/firesurfer/ros2_components.git
git clone https://github.com/firesurfer/ros2_components_demo
```

###  Building with ament

```
cd ../../
ament build
```



### Building with cmake

```
cd demo_ws/src/demoe/ros2_components_msg/
mkdir -p build
cd build 
ament build ..
```



```
cd demo_ws/src/demo/ros2_components_demo
#use nano or gedit or vim
nano CMakeLists.txt
```
uncomment this line:
```
#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
```

Then go back to the ros2_components repo
```
cd ../ros2_components
nano CMakeLists.txt
```
uncomment this line:
```
#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
```
```
mkdir build
cd build
cmake ..
make
```

Go to the ros2_components_demo repo

```
cd ../ros2_components_demo
mkdir build
cd build
cmake ..
make
```

## Running the demo
In the build folder or if you build it with ament the build/ros2_components_demo folder you will find three executables

* demo_parameter_server
* demo_server
* demo_client

You need two be in a ros2 environment (see 0.)

1. Run the demo_parameter_server 
2. Run the demo_server - It will create two DemoRobots with 100 DemoSensors
3. Run the demo_client - It will rebuild the two DemoRobots

