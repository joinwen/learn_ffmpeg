cmake_minimum_required(VERSION 3.24)
project(learn_ffmpeg C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

link_directories(lib)

add_executable(learn_ffmpeg main.c)

target_link_libraries(learn_ffmpeg avformat avcodec avutil swscale z bz2 iconv ws2_32 schannel kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)

