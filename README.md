# City Simulator

This is a C++ based program that can be used to model the growth of a city based on the specified growth model.

## Getting Started

Just fork/download, compile on any C++ capable system and run. CLI based inputs and CSV based city map files.

### Prerequisites

Be sure to have a C++ compiler installed. Additionally, an IDE is recommended.
Try following this guide for [Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/73855d8b-0999-4c9b-8434-73d49ee4a338)

### Running

Once you've executed the program, your CLI should present a prompt for a config txt file

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/90f0c37f-a0b8-4db2-8390-f01d5f3e080e)

The config should be formatted as such:

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/1d3d9073-e05a-4c67-b34e-5aa970ee8a0a)

The region layout specifies the CSV file (the city map).
The time limit is the number of turns to potentially run.
The refresh rate indicates how many outputs you with to receive by turn count (1 indicates an output every turn).

Give the name of your configt txt file as prompted (make sure that the file is local to the executable)

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/b6c54b8b-8585-41d4-8e7c-7204a8df20f2)

Watch your city grow!

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/15985ac7-f217-44cb-a63f-8e0fc0db1d7d)

Until you reach your final state (either through the time limit or lack of growth to your city).

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/e139dcd7-1d3c-47a3-9fc7-be26d480bf81)

Total pollution produced by the industrial sectors (as simulated by the pollution spread model) will be presented, as well as the final city stats.

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/74c774f3-3e27-481a-8070-a5c254da87c0)

A check for a specific area can then be made by giving a custom box dimension in X and Y units:

![image](https://github.com/SgtR0ck/City_Simulator/assets/8111664/442888fd-7ea9-4b75-a27b-ea260ed6ab13)

## Contributing

Please read [CONTRIBUTING.md](https://github.com/SgtR0ck/City_Simulator) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Chet Lockwood** - *Initial work* - [SgtR0ck](https://github.com/SgtR0ck)

See also the list of [contributors](https://github.com/SgtR0ck/City_Simulator/graphs/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/SgtR0ck/City_Simulator/blob/main/LICENSE.md) file for details

## Acknowledgments

* Thank you to the many guides across the internet on C++
