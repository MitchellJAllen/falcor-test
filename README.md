# falcor-test
Test Sample Project for Falcor

## Description
This repository contains a sample project folder for Falcor. It has an implementation of the IRenderer parent class which builds a simple scene and makes use of a basic Slang shader program. It draws a red quad surrounded by a navy blue background and renders the UI for this constructed scene.

## Usage
To deploy this project for running or debugging within Falcor, first be sure to clone the Falcor Github repository. Next, copy the _MyProject_ directory into the Falcor _Source/Samples_ directory. It should resemble the structure of other sample projects, like _ModelViewer_. Then, add a line "add_subdirectory(MyProject)" to the Falcor _Source/Samples/CMakeLists.txt_ file. Finally, run the Falcor script _setup_vs2022.bat_ (or _setup_vs2019.bat_) so that the generated Falcor project for Visual Studio contains a _MyProject_ entry.

## Troubleshooting
I encountered a few issues while attempting to run Falcor projects. Most of the problems and solutions are mentioned in this Falcor issue post: https://github.com/NVIDIAGameWorks/Falcor/issues/319

Problems:
* Error fetching "tiny-cuda-nn":
  * Open the Falcor _.gitmodules_ file.
  * Replace the url for the "tiny-cuda-nn" entry with https://github.com/NVlabs/tiny-cuda-nn
  * Run the command "git submodule sync".
* Missing "json/json.hpp":
  * Download the file https://github.com/nlohmann/json/raw/develop/single_include/nlohmann/json.hpp
  * Create a folder "nlohmann" in the Falcor _external/include_ folder.
  * Copy the downloaded "json.hpp" file into the new _external/include/nlohmann_ folder.
  * In the Falcor _Source/Falcor/Utils/Settings.h_ file, replace "#include <json/json.hpp>" with "#include <nlohmann/json.hpp>".
* Missing "pybind11_json/pybind11_json.hpp":
  * Download the file https://github.com/pybind/pybind11_json/raw/master/include/pybind11_json/pybind11_json.hpp
  * Create a folder "pybind11_json" in the Falcor _external/include_ folder.
  * Copy the downloaded "pybind11_json.hpp" file into the new _external/include/nlohmann_ folder.
