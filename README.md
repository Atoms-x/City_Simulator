<p align="center">
  <img src="https://github.com/SgtR0ck/City_Simulator/assets/8111664/ac60bc95-3be6-4110-99d3-74146b0a4892"
</p>
<h1 align="center"> 
  City Simulator  
</h1>

<p align="center">
  <a href="https://github.com/SgtR0ck/City_Simulator">
    <img src="https://img.shields.io/badge/version-1.0.0-green.svg?style=plastic">
  </a>
  <img src="https://img.shields.io/badge/language-C%2B%2B-%2300599C.svg?style=plastic&logo=C%2B%2B">
  <img src="https://img.shields.io/badge/code%20style-ANSI-orange.svg?style=plastic">
  <a href="https://github.com/SgtR0ck/City_Simulator/blob/main/LICENSE.md">
    <img src="https://img.shields.io/badge/license-MIT-green.svg?style=plastic">
  </a>
</p>

## Table of Contents
  - [Introduction](#introduction)
  - [Growth Model](#growth-model)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Formatting](#formatting)
    - [Running](#running)
  - [Authors](#authors)
  - [License](#license)
  - [Acknowledgments](#acknowledgments)


## Introduction

This is a C++ based program that can be used to model the growth of a city based on the specified growth model.

### Growth Model

The growth model is broken down into three different zones: Residential, Commercial, and Industrial
Go to [GROWTH.md](https://github.com/SgtR0ck/City_Simulator/blob/main/GROWTH.md)

## Getting Started

Just fork/download, compile on any C++ capable system and run. CLI based inputs and CSV based city map files.

### Prerequisites

Be sure to have a C++ compiler installed. Additionally, an IDE is recommended.
Try following this guide for [Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/73855d8b-0999-4c9b-8434-73d49ee4a338)

### Formatting

Before you run the program, ensure you have at least one config file and one CSV based map.

The config should be formatted as such:

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/1d3d9073-e05a-4c67-b34e-5aa970ee8a0a)

The region layout specifies the CSV file (the city map).
The time limit is the number of turns to potentially run.
The refresh rate indicates how many outputs you with to receive by turn count (1 indicates an output every turn).

The map CSV should be formatted as such:

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/6b23626f-dcd2-46d1-b77d-165ea7400783)

The breakdown of the symbols are as such:
1. 'R' are residential zones
2. 'I' are industrial zones
3. 'C' are commercial zones
4. '-' are roads
5. 'T' are powerlines
6. '#' are powerlines over roads
7. 'P' are powerplants

### Running

Once you've executed the program, your CLI should present a prompt for a config txt file

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/90f0c37f-a0b8-4db2-8390-f01d5f3e080e)


Give the name of your config txt file as prompted (make sure that the file is local to the executable)

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/b6c54b8b-8585-41d4-8e7c-7204a8df20f2)

Watch your city grow!

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/15985ac7-f217-44cb-a63f-8e0fc0db1d7d)

Until you reach your final state (either through the time limit or lack of growth to your city).

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/e139dcd7-1d3c-47a3-9fc7-be26d480bf81)

Total pollution produced by the industrial sectors (as simulated by the pollution spread model) will be presented, as well as the final city stats.

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/74c774f3-3e27-481a-8070-a5c254da87c0)

A check for a specific area can then be made by giving a custom box dimension in X and Y units before the end of the simulation:

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/442888fd-7ea9-4b75-a27b-ea260ed6ab13)

## Authors

* **Chet Lockwood** - [SgtR0ck](https://github.com/SgtR0ck)

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/SgtR0ck/City_Simulator/blob/main/LICENSE.md) file for details

## Acknowledgments

* Thank you to the many guides across the internet on C++
