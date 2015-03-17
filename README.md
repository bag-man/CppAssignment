### C++ Assignment 1 - Ladybirds and Aphids simulation. 

#### Build instructions
This project was made using C++11, and GCC 4.9.2. I have also used the [docopt](https://github.com/docopt/docopt.cpp) library, however this is bundled in the repo. 

To build the application, and run it with the --step argument run:
    
    make
    make test

The binary is located in the bin folder, there is not an installation option. 

#### Documentation
Please look in the docs folder for the specification, my written report, a video of the application building and running, as well as a few screenshots. 

#### Usage

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

