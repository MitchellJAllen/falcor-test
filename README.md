# falcor-test
Test Sample Project for Falcor

## Description
This repository contains a sample project folder for Falcor. It has an implementation of the IRenderer parent class which builds a simple scene and makes use of a basic Slang shader program. It draws a red quad surrounded by a navy blue background and renders the UI for this constructed scene.

## Usage
To deploy this project for running or debugging within Falcor, first be sure to clone the Falcor Github repository. Next, copy the _MyProject_ directory into the Falcor _Source/Samples_ directory. It should resemble the structure of other sample projects, like _ModelViewer_. Then, add a line "add_subdirectory(MyProject)" to the Falcor _Source/Samples/CMakeLists.txt_ file. Finally, run the Falcor script _setup_vs2022.bat_ (or _setup_vs2019.bat_) so that the generated Falcor project for Visual Studio contains a _MyProject_ entry.
