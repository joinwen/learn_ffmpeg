#include <stdio.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswresample/swresample.h"

int main() {
    printf("ffmpeg version is %s\n", av_version_info());

    AVFormatContext *input_format_context = NULL;
    AVStream *input_stream = NULL;


    int input_stream_index;
    int ret;

    char *input_filename = "input.mp3";

    // Initialize ffmpeg
    //av_register_all();  this function is depreciated since ffmpeg 4.0, You can just omit this function call in ffmpeg 4.0 and later
    avformat_network_init();

    // Open input file
    ret = avformat_open_input(&input_format_context, input_filename, NULL, NULL);
    if(ret < 0) {
        // Error handling
        return -1;
    }

    // Get input stream information
    input_stream_index = av_find_best_stream(input_format_context, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
    if(input_stream_index < 0) {
        printf("Could not find an audio stream in input file %s\n", input_filename);
        return -1;
    }

    // Find first audio stream
    input_stream = input_format_context->streams[input_stream_index];

    printf("input.mp3 duration %lld\n", input_stream->duration);
}
