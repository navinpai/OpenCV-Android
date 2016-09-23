//
// Created by Navin Pai on 9/24/16.
//
#include <jni.h>
#include <sstream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <android/log.h>

#define LOG_TAG "Native_Lib_JNI"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
int lowThreshold = 10;


extern "C" {
    JNIEXPORT jboolean JNICALL
    Java_navin_tuts_opencv_opencvapp_MainActivity_nativeCanny(JNIEnv *env, jobject instance, long iAddr) {

        cv::Mat* blur = (cv::Mat*) iAddr;
        cv::Canny(*blur, *blur, 80, 100, 3);

        return true;
    }
}