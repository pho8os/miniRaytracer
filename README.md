# Mini RayTracer

## Introduction
The miniRT program generates images using the Raytracing protocol. Those computer-generated images will each represent a scene, 
as seen from a specific angle and position, defined by simple geometric objects, each with its own lighting system.

## Features

**The program can render the following objects:**
- Sphere
- Cylinder
- Plane

**For the light part:**
- One light source
- Ambient light

## Instalation

### Compilation Mac OS :

```
$> gcl https://github.com/pho8os/miniRaytracer.git
```
Please refer to [**#Compilation On MacOS**](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-macos)

### Compilation On Linux : 

```
$> gcl https://github.com/pho8os/miniRaytracer.git
```
Please refer to [**#Compilation On Linux**](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)

## Usage

```
$> ./miniRT maps/choose_a_map.rt
```
You can change the camera's coordinates, light color, sphere diameter, and other parameters.


**Ambient lightning**: A 0.2 255,255,255

- **identifier**: A
- **ambient lighting ratio in range [0.0,1.0]**: 0.2
- **R,G,B colors in range [0-255]**: 255, 255, 255

**◦ Camera**: C -50.0,0,20 0,0,1 70

- **identifier**: C
- **x,y,z coordinates of the view point**: -50.0,0,20
- **3d normalized orientation vector. In range [-1,1] for each x,y,z axis**:
0.0,0.0,1.0
- **FOV **: Horizontal field of view in degrees in range [0,180]**: 70

**◦ Light**: L -40.0,50.0,0.0 0.6 10,0,255

- **identifier**: L
- **x,y,z coordinates of the light point**: -40.0,50.0,0.0
- **the light brightness ratio in range [0.0,1.0]**: 0.6
- **(unused in mandatory part)R,G,B colors in range [0-255]**: 10, 0, 255

**◦ Sphere**: sp 0.0,0.0,20.6 12.6 10,0,255

- **identifier**: sp
- **x,y,z coordinates of the sphere center**: 0.0,0.0,20.6
- **the sphere diameter**: 12.6
- **R,G,B colors in range [0-255]**: 10, 0, 255
7
miniRT My first RayTracer with miniLibX

**◦ Plane**: pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225

- **identifier**: pl
- **x,y,z coordinates of a point in the plane**: 0.0,0.0,-10.0
- **3d normalized normal vector. In range [-1,1] for each x,y,z axis**: 0.0,1.0,0.0
- **R,G,B colors in range [0-255]**: 0,0,225

**◦ Cylinder**: cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
- **identifier**: cy
- **x,y,z coordinates of the center of the cylinder**: 50.0,0.0,20.6
- **3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis**:
0.0,0.0,1.0
- **the cylinder diameter**: 14.2
- **the cylinder height**: 21.42
- **R,G,B colors in range [0,255]**: 10, 0, 255

## Images Generated Using This Mini RayTracer
