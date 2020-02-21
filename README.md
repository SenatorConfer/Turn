# Turn
Turn is a basic turn-based RPG game written in C++. 

## History
This program was originally written back in 2013 by tagniam. This project was then forked by Jonathan Confer and Hayden Richter for a project in their Intro to Software Engineering class in Spring 2020 at Wright State University. 

## Screenshots

![Battle screen](screenshots/battle.png)
![Menu screen](screenshots/menu.png)

## How To Play
See the [wiki](https://github.com/tagniam/Turn/wiki) for instructions.

## Getting Started
### Prerequisites
* [CMake](https://cmake.org) is used to generate project files across different platforms.
* Linux users: for audio, SDL_mixer is used. Simply install the SDL2 mixer dev packages on your distro of choice before building (for example on Ubuntu run `sudo apt-get install libsdl2-dev libsdl2-mixer-dev`)

### Building
#### Windows
* To build project files with CMake, simply run [CMake](https://cmake.org/) on the root CMakeLists.txt. `CMake-gui` is recommended for an easy way to select project options.

#### Linux & Mac
```shell
$ git clone https://github.com/SenatorConfer/Turn.git
$ cd Turn/
$ ./configure
```

Run Turn.sln in Visual Studios and Build the project.

Make sure you run the executable from the `Turn` directory so the in-game sounds can work:
```shell
$ ./build/Turn/debug/Turn  # play the game!
```

## Contributing
* Before working on an issue, make sure you comment on it to claim it. This prevents two people working on the same issue at the same time.

## License
* This project is licensed under the MIT License - see the LICENSE file for details.

