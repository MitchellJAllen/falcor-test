add_falcor_executable(MyProject)

target_sources(MyProject PRIVATE
    MyProject.cpp
    MyProject.h
    MyProject.3d.slang
)

target_copy_shaders(MyProject Samples/MyProject)

target_source_group(MyProject "Samples")
