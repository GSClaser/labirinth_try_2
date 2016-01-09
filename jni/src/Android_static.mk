LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_SRC_FILES := mouse.cpp main.cpp settings.cpp keyboard.cpp game.cpp display.cpp loop.cpp

LOCAL_STATIC_LIBRARIES := SDL2_static

include $(BUILD_SHARED_LIBRARY)
$(call import-module,SDL)LOCAL_PATH := $(call my-dir)
