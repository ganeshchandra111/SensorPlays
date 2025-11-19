# SensorPlay

## Video:   https://drive.google.com/drive/folders/1yO3PF0WTOi4_OmfPawIY0HI7riB0P-Ta?usp=sharing


> **We play Unique**

SensorPlay is an innovative gaming platform that revolutionizes how we interact with games by using real-world movements instead of traditional mouse and keyboard controls. Experience gaming like never before with motion-controlled gameplay using ultrasonic sensors and ESP32 microcontrollers.

## 🎮 Project Overview

Traditional gaming relies heavily on mouse and keyboard inputs, which can feel monotonous. SensorPlay introduces a fresh approach where your physical movements become the game controller. Want to play the Dino Game? Jump in real life to avoid obstacles. Playing a paddle game? Move your hand to control the paddle's direction.

This project represents a new way to game - a genuine innovation in interactive entertainment.

## 🔧 Hardware Components

### Electronics Setup
- **ESP32 Microcontroller**: Central control unit managing all operations
- **Ultrasonic Sensor**: Detects objects and movements in front of the sensor to capture motion data
- **LED Indicators**: Visual feedback for connection status (WiFi and server connections)
- **Simple & Clean Design**: Minimalist hardware setup to reduce potential errors and maintenance issues

The hardware architecture prioritizes simplicity and reliability, avoiding complex configurations that might require extensive troubleshooting.

## 🌐 Communication System

### Real-Time Data Transfer
- **WebSocket Technology**: Ensures ultra-fast data transfer speeds essential for responsive gaming
- **Local Network Communication**: Utilizes LAN connections via ESP32's IP address
- **Server Architecture**: ESP32 hosts a WebSocket server for seamless game-hardware communication

**Why WebSockets?** Initially developed with Django, but switched to WebSockets for superior speed and real-time performance required for motion-controlled gaming.

## 🎯 Game Development

### Technical Stack
- **Frontend**: HTML, CSS, JavaScript
- **Architecture**: Central JavaScript hub manages all game communications
- **Data Flow**: All sensor data flows through the central hub to individual games
- **Responsive Design**: Games adapt to sensor input in real-time

### Central Hub System
The JavaScript hub acts as the communication bridge between hardware sensors and individual games, ensuring consistent data flow and synchronized responses across all gaming experiences.

## 🎲 Available Games

### Chrome Dino Game
- **Concept**: Motion-controlled version of the classic offline Chrome dinosaur game
- **Controls**: 
  - Place hand at sensor, move up to jump
  - Alternative: Place sensor near feet and jump in real life
- **Objective**: Avoid obstacles by jumping at the right moment

### Paddle Game
- **Concept**: Motion-controlled version inspired by the world's first video game (Pong)
- **Controls**: Move hand left/right to control paddle direction
- **Objective**: Keep the ball from touching the ground using paddle movements

## 👥 Development Team

### Core Contributors
- **Ganesh Chandra** - Full Stack Developer
- **Ganesh** - Electronics Engineer
- **Jaya Deep** - Game Developer
- **Shiva Kumar** - Frontend Developer

## 🌟 Features

- **Motion Detection**: Advanced ultrasonic sensor integration
- **Real-time Communication**: WebSocket-based data transfer
- **Multiple Game Support**: Expandable game library
- **Visual Feedback**: LED status indicators
- **Responsive Design**: Cross-platform web interface
- **Local Network Play**: No internet required for gameplay

## 🚀 Innovation Highlights

- **Physical Gaming**: Transform your body into a game controller
- **Low Latency**: WebSocket communication ensures minimal input delay
- **Scalable Architecture**: Easy to add new games and sensors
- **Educational Value**: Demonstrates IoT, web technologies, and game development integration

## 📱 User Interface

The web interface features:
- **Modern Design**: Clean, responsive layout
- **Game Gallery**: Visual game selection with descriptions
- **Real-time Status**: Server connection indicators
- **Smooth Navigation**: Custom scroll animations
- **Mobile Friendly**: Responsive design for all devices

---

*Hope you appreciate our project and the hard work we put in!*
