add_falcor_executable(DrawCall)

target_sources(DrawCall PRIVATE
    DrawCall.cpp
    DrawCall.h
    DrawCall.3d.slang
)

target_copy_shaders(DrawCall Samples/DrawCall)

target_source_group(DrawCall "Samples")
