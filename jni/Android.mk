LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	mcu_uart/CMCUUart.cpp \
	UartProxy.cpp \
	IDataChangedListener.cpp \
	DataChangedListener.cpp \
	DeathNotifier.cpp \
	IMcuService.cpp \
	McuService.cpp \
	NotifyDispatcher.cpp \
	McuProvider.cpp \
	McuCommands.cpp \
	McuReader.cpp \
	McuWriter.cpp \
	BTCommands.cpp \
	BTProvider.cpp \
	BTReader.cpp \
	BTWriter.cpp \
	main_mcuserver.cpp \

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libnbaio \
	libutils \
	liblog \
	libbinder \

LOCAL_STATIC_LIBRARIES := \
	libregistermsext

	
LOCAL_MODULE:= mcuserver

include $(BUILD_EXECUTABLE)



#include $(CLEAR_VARS)

#LOCAL_SRC_FILES:= \
#	ISettingsInfoChangedListener.cpp \
#	SettingsInfoChangedListener.cpp \
#	IBTInfoChangedListener.cpp \
#	BTInfoChangedListener.cpp \
#	IRadioInfoChangedListener.cpp \
#	RadioInfoChangedListener.cpp \
#	IDataChangedListener.cpp \
#	DataChangedListener.cpp \
#	IMcuService.cpp \
#	McuServiceClient.cpp \
#	JNIEnterance.cpp \

#LOCAL_SHARED_LIBRARIES := \
#	libcutils \
#	libnbaio \
#	libutils \
#	liblog \
#	libbinder
	
#LOCAL_MODULE:= libmcuserverclient_jni

#include $(BUILD_SHARED_LIBRARY)
