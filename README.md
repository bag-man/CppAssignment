### C++ Assignment 1 - Ladybirds and Aphids simulation. 

This is my first attempt at making a project in C++, you can see the specification I was given in the docs folder. 

    Ladybirds and Aphids simulation.

    Usage:
      ./main [--config=<dir>] [--step]

    Options:
      -h --help       Show this screen.
      --version       Show version.
      --config=<dir>  Rirectory to load config files from [default: configs/].
      --step          Require enter press to step through animation, defaults to auto run.

    Configs:
      In the configs folder you need:
      
      * simulation.conf
      * aphids.conf
      * ladybirds.conf

      These will dictate the properties of the creatures and where they begin. 
      Check the docs folder for more information.


### Folder structure of included files. 

├── bin
│   └── main
├── configs
│   ├── aphids.conf
│   ├── ladybirds.conf
│   └── simulation.conf
├── docs
│   ├── demo.mp4
│   ├── latex
│   │   ├── design.jpg
│   │   ├── documentation.pdf
│   │   ├── documentation.tex
│   └── specification.pdf
├── include
│   ├── aphid.h
│   ├── board.h
│   ├── cell.h
│   ├── creature.h
│   ├── direction.h
│   ├── docopt
│   │   ├── docopt.h
│   │   ├── docopt_private.h
│   │   ├── docopt_util.h
│   │   └── docopt_value.h
│   ├── game.h
│   └── ladybird.h
├── Makefile
├── README.md
└── src
    ├── aphid.cpp
    ├── board.cpp
    ├── cell.cpp
    ├── creature.cpp
    ├── direction.cpp
    ├── docopt.cpp
    ├── game.cpp
    └── ladybird.cpp
